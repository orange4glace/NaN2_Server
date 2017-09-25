// player.h
#ifndef PLAYER_H_
#define PLAYER_H_
    
#include "../gameobject/character/character.h"

#include <ProudNetServer.h>

namespace nan2 {

using PlayerID = Proud::HostID;

class Player {

    Proud::HostID id_;
    Character* character_;

    int recent_ping_;

public:
    Player(PlayerID id);
    ~Player();

    Character* const character();
    Proud::HostID id() const;

    void SendSnapshotsToRemote() const;
    void CleanSnapshot();

    int GetRecentPing();

};

}

#endif