// world.h
#ifndef WORLD_H_
#define WORLD_H_
    
#include <ctime>
#include <chrono>

#include <set>
#include <map>
#include <vector>
#include <queue>

#include <utility>

#include "scheduler.h"
#include "../gameobject/game_object.h"
#include "../module/module.h"

namespace nan2 {

    // For breaking circular dependency
    // World - Player - Character - Movable - World
    class Player;

    class World {

        static World* instance_;

        std::chrono::high_resolution_clock::time_point last_system_time_;
        Scheduler scheduler_;

        int snapshot_send_timer_;

        int next_internal_game_object_id_;
        std::queue<unsigned short> network_id_pool_;

        std::map<int, GameObject*> game_objects_;
        std::map<int, GameObject*> updatables_;
        std::map<int, GameObject*> rewindables_;

        std::map<int, GameObject*> stagings_;
        std::vector<GameObject*> removings_;

        void initialize();

        void stageGameObjects();
        void removeGameObjects();

        int AcquireInternalID();
        unsigned short AcquireNetworkID();
        void ReleaseNetworkID(uint16_t id);

    public:
        static World* instance();

        World();

        inline Scheduler& scheduler() {
          return scheduler_;
        }

        void Update(int dt);
        void FixedUpdate(int dt);

        bool AddGameObject(GameObject* obj);
        void RemoveGameObject(GameObject* obj);

        template<typename Lambda>
        void IterateGameObjects(Lambda&& lambda) {
            for(auto const &entry : game_objects_) {
              if (entry.second->staging_state() != StagingState::STAGED) continue;
                std::forward<Lambda>(lambda)(entry.second);
            }
        }

        template<class TGameObject, typename Lambda>
        void IterateGameObjects(Lambda&& lambda) {
          // Must be improved later with
          // <GameObject>::Type()
          for (auto const &entry : game_objects_) {
            if (entry.second->staging_state() != StagingState::STAGED) continue;
            if (TGameObject* casted = dynamic_cast<TGameObject*>(entry.second)) {
              if (!std::forward<Lambda>(lambda)(casted)) break;
            }
          }
        }

        template<class Module>
        void ActivateModule(void* args...) {
          Module::Activate(args);
        }

        template<class Module>
        void DeactivateModule() {
          Module::Deactivate();
        }

    };
}

#endif