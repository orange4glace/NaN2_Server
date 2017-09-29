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

#include "../gameobject/game_object.h"
#include "../module/module.h"
#include "../module/event_listener.h"

namespace nan2 {

    // For breaking circular dependency
    // World - Player - Character - Movable - World
    class Player;

    class World {

        static World* instance_;

        std::chrono::high_resolution_clock::time_point last_system_time_;

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

        void Update(int dt);
        void FixedUpdate(int dt);

        bool AddGameObject(GameObject* obj);
        void RemoveGameObject(GameObject* obj);

        template<typename Lambda>
        void IterateGameObjects(Lambda&& lambda) {
            for(auto const &entry : game_objects_) {
                std::forward<Lambda>(lambda)(entry.second);
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