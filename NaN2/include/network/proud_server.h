// proud_server.h
#ifndef PROUD_SERVER_H_
#define PROUD_SERVER_H_

#include <ProudNetServer.h>

#include "../world/player.h"
#include "player_input_packet.h"

#include "../pidl/player_input_common.h"
#include "../pidl/player_input_proxy.h"
#include "../pidl/player_input_stub.h"

namespace nan2 {

  using Players = Proud::CFastMap<Proud::HostID, Player*>;

  class ProudServer : public Proud::INetServerEvent, public GameC2S::Stub {

    DECRMI_GameC2S_PlayerInput;

    static ProudServer* instance_;
	
    ProudServer();

    Proud::CNetServer* server_;
	  Proud::CriticalSection cs_;
	  Proud::CriticalSectionLock cs_lock_;

    Players players_;

  public:
    static const ProudServer* instance();

	  void Lock();
	  void Unlock();

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

    }
    void OnWarning(Proud::ErrorInfo* e) override {

    }
    void OnInformation(Proud::ErrorInfo* e) override {

    }
    void OnException(const Proud::Exception& e) override {

    }
    void OnNoRmiProcessed(Proud::RmiID rmiID) override {

    }

	
    Player* const GetPlayerByHostID(Proud::HostID host_id);
  };

}

#endif