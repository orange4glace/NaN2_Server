// player.h
#ifndef PLAYER_H_
#define PLAYER_H_
    
#include "../gameobject/character/character.h"

#include <ProudNetServer.h>

namespace nan2 {

    class Player {

        Proud::HostID id_;
        Character* character_;

        int recent_ping_;

    public:
        Player(Proud::HostID id);
        ~Player();

        Character* const character();
        Proud::HostID id() const;

        void SendSnapshotsToRemote() const;

        int GetRecentPing();

    };
}

#endif