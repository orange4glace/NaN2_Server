// world.cpp
#include "world/world.h"

#include "world_time.h"
#include "world/player.h"
#include "network/proud_server.h"

#include "gameobject/static_collider.h"

#include "logger/logger.h"

namespace nan2 {

  Player* player;

  World* World::instance_ = nullptr;

  World* World::instance() {
    if (instance_ == nullptr) {
      instance_ = new World();
    }
    return instance_;
  }

  World::World() :
  next_internal_game_object_id_(0),
  snapshot_send_timer_(0) {
    auto serv = ProudServer::instance();
    // Pool network ids
    for (int i = 1; i < 65536; i ++) network_id_pool_.push(i);

    StaticCollider* sc = new StaticCollider(Vector2(50, 0), Vector2(20, 20));
    AddGameObject(sc);
  }

  void World::Update(int dt) {
    Time::delta_time(dt);

    stageGameObjects();
    for(auto const &entry : updatables_) {
      auto object = entry.second;
      if (object->staging_state() == StagingState::REMOVING) continue;
      object->Update();
    }

    // Check snapshot send timer
    snapshot_send_timer_ += dt;
    if (snapshot_send_timer_ > 28) {
      snapshot_send_timer_ = 0;
      ProudServer::instance()->IteratePlayers([](Player* player) -> bool {
        player->SendSnapshotsToRemote();
        return true;
      });
      ProudServer::instance()->IteratePlayers([](Player* player) -> bool {
        player->CleanSnapshot();
        return true;
      });
    }

    for (auto const &entry : rewindables_) {
      entry.second->RecordCurrent();
    }
    removeGameObjects();
  }

  void World::FixedUpdate(int dt) {

  }

  bool World::AddGameObject(GameObject* object) {
    uint16_t network_id = 0;
    int internal_id = AcquireInternalID();
    if (internal_id < 0) return false;
    if (object->is_network_object()) {
      network_id = AcquireNetworkID();
      if (network_id == 0) return false;
    }
    L_DEBUG << "Assign " << internal_id << " " << network_id << " " << object;
    object->AssignID(internal_id, network_id);
    object->InitializeComponents();
    object->set_staging_state(StagingState::STAGING);
    stagings_[object->internal_id()] = object;
    return true;
  }

  void World::RemoveGameObject(GameObject* object) {
    if (object->staging_state() == StagingState::NONE) return;
    if (object->is_network_object()) {
      auto network_id = object->network_id();
      ReleaseNetworkID(network_id);
    }
    else if (object->staging_state() == StagingState::STAGING) {
      stagings_.erase(object->internal_id());
    }
    else if (object->staging_state() == StagingState::STAGED) {
      object->set_staging_state(StagingState::REMOVING);
      removings_.emplace_back(object);
    }
  }

  void World::stageGameObjects() {
    for (auto& kv : stagings_) {
      auto object = kv.second;
      assert(!object->rewindable() || (object->rewindable() && object->GetComponent<RecorderInterface>() != nullptr));
      game_objects_.insert({object->internal_id(), object});
      if (object->updatable())
        updatables_.insert({object->internal_id(), object});
      if (object->rewindable())
        rewindables_.insert({object->internal_id(), object});
      object->set_staging_state(StagingState::STAGED);
    }
    stagings_.clear();
  }

  void World::removeGameObjects() {
    for (auto& object : removings_) {
      game_objects_.erase(object->internal_id());
      if (object->updatable())
        updatables_.erase(object->internal_id());
      if (object->rewindable())
        rewindables_.erase(object->internal_id());
      object->OnDestroy();
      delete object;
    }
    removings_.clear();
  }

  int World::AcquireInternalID() {
    if (next_internal_game_object_id_ == 2147483647) return -1;
    return next_internal_game_object_id_++;
  }

  unsigned short World::AcquireNetworkID() {
    if (network_id_pool_.size() == 0) return 0;
    unsigned short id = network_id_pool_.front();
    network_id_pool_.pop();
    return id;
  }

  void World::ReleaseNetworkID(uint16_t id) {
    network_id_pool_.push(id);
  }

}


/*


  std::chrono::high_resolution_clock::time_point cur_system_time(std::chrono::high_resolution_clock::now());
  std::chrono::duration<double, std::milli> time_span = cur_system_time - last_system_time_;
  last_system_time_ = cur_system_time;
  float u_dt = (float)time_span.count() / 1000.0f;
  Time::delta_time(u_dt);

  int dt = Time::delta_time();
  snapshot_send_timer_ += dt;
  ping_send_timer_ += dt;

  int current_fixed_time = Time::current_time();
  Time::current_time(Time::current_time() + dt);

*/