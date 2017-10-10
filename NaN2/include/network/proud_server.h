// proud_server.h
#ifndef PROUD_SERVER_H_
#define PROUD_SERVER_H_

#include <ProudNetServer.h>
#include "collection_marshaler.h"
#include "marshaler.h"

#include "../world/player.h"
#include "player_input_packet.h"
#include "local_character_snapshot.h"
#include "remote_character_snapshot.h"
#include "skill_cast_snapshot.h"

#include "../pidl/game_s2c_common.h"
#include "../pidl/game_s2c_proxy.h"
#include "../pidl/game_s2c_stub.h"

#include "../pidl/game_c2s_common.h"
#include "../pidl/game_c2s_proxy.h"
#include "../pidl/game_c2s_stub.h"

namespace nan2 {

  using Players = Proud::CFastMap<Proud::HostID, Player*>;

  class ProudServer : public Proud::INetServerEvent, public GameC2S::Stub, public GameS2C::Proxy {

    DECRMI_GameC2S_PlayerInput;

    static ProudServer* instance_;
	
    ProudServer();
    ~ProudServer();

    Proud::CNetServer* server_;
    Proud::CThreadPool* thread_;
	Proud::CriticalSection cs_;
	Proud::CriticalSectionLock cs_lock_;

    GameS2C::Proxy s2c_proxy_;

    Players players_;

  public:
    static ProudServer* const instance();

    void Initialize();

	void Lock();
	void Unlock();

    void Process();

    void AttachProxy(Proud::IRmiProxy* proxy);
    void AttachStub(Proud::IRmiStub* stub);

    bool OnConnectionRequest(Proud::AddrPort client_addr, Proud::ByteArray& data, Proud::ByteArray& reply) override;
	void OnClientJoin(Proud::CNetClientInfo* client_info) override;
	void OnClientLeave(Proud::CNetClientInfo* client_info, Proud::ErrorInfo* error_info, const Proud::ByteArray& comment) override;
	void OnClientOffline(Proud::CRemoteOfflineEventArgs& args) override;
	void OnClientOnline(Proud::CRemoteOnlineEventArgs& args) override;
    
    // Not used
    void OnP2PGroupJoinMemberAckComplete(Proud::HostID group_host_id, Proud::HostID member_host_id, Proud::ErrorType result) override {}
    void OnUserWorkerThreadBegin() override {}
    void OnUserWorkerThreadEnd() override {}
    void OnClientHackSuspected(Proud::HostID client_id, Proud::HackType hack_type) override {}
    void OnP2PGroupRemoved(Proud::HostID group_id) override {}

    void OnError(Proud::ErrorInfo* e) override {
      L_DEBUG_W << "Proud Error " << e->ToString().c_str() << endl;
    }
    void OnWarning(Proud::ErrorInfo* e) override {
      L_DEBUG_W << "Proud Warning " << e->ToString().c_str() << endl;
    }
    void OnInformation(Proud::ErrorInfo* e) override {
      L_DEBUG_W << "Proud Info "  << e->ToString().c_str() << endl;
    }
    void OnException(const Proud::Exception& e) override {
      L_DEBUG << e.what() << endl;
    }
    void OnNoRmiProcessed(Proud::RmiID rmiID) override {

    }

	
    Player* const GetPlayerByHostID(Proud::HostID host_id);
    int GetPlayerPing(Player* player);

    void SendCharacterSnapshots(const Player* const player,
      const LocalCharacterSnapshot& local_character_snapshot, const std::vector<RemoteCharacterSnapshot>& remote_character_snapshots);

    void SendSkillCastSnapshot(const Player* const player, const SkillCastSnapshot& skill_cast_snapshot);

    void ProxyCharacterSpawned(Character* const character, const Vector2& position);
    void ProxyCharacterDied(Character* const character);

    template<typename Lambda>
    void IteratePlayers(Lambda&& lambda) {
      for (auto const &entry : players_) {
        std::forward<Lambda>(lambda)(entry.GetSecond());
      }
    }
  };

}

#endif