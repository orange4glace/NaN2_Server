// proud_server.cpp
#include "network/proud_server.h"

#include "../pidl/game_s2c_common.cpp"
#include "../pidl/game_s2c_proxy.cpp"
#include "../pidl/game_s2c_stub.cpp"

#include "../pidl/player_input_common.cpp"
#include "../pidl/player_input_proxy.cpp"
#include "../pidl/player_input_stub.cpp"

namespace nan2 {

  ProudServer* ProudServer::instance_ = nullptr;

  const ProudServer* ProudServer::instance() {
    if (instance_ == nullptr) {
      instance_ = new ProudServer();
    }
    return instance_;
  }

  ProudServer::ProudServer() :
  cs_lock_(cs_, false) {
	  server_ = Proud::CNetServer::Create();
    server_->AttachProxy(&s2c_proxy_);
    server_->AttachStub((GameS2C::Stub*)this);
  }

  bool ProudServer::OnConnectionRequest(Proud::AddrPort client_addr, Proud::ByteArray& data, Proud::ByteArray& reply) {
    return true;
  }

  void ProudServer::OnClientJoin(Proud::CNetClientInfo* client_info) {
    Player* player = new Player(client_info->m_HostID);
    players_.Add(client_info->m_HostID, player);
  }
  void ProudServer::OnClientLeave(Proud::CNetClientInfo* client_info, Proud::ErrorInfo* error_info, const Proud::ByteArray& comment) {
    auto player = GetPlayerByHostID(client_info->m_HostID);
    players_.Remove(player->id());
  }
  void ProudServer::OnClientOffline(Proud::CRemoteOfflineEventArgs& args) {
    
  }
  void ProudServer::OnClientOnline(Proud::CRemoteOnlineEventArgs& args) {

  }

  void ProudServer::Lock() {
	  cs_lock_.Lock();
  }

  void ProudServer::Unlock() {
	  cs_lock_.Unlock();
  }

  Player* const ProudServer::GetPlayerByHostID(Proud::HostID host_id) {
    Player* output;
    auto found = players_.TryGetValue(host_id, output);
    if (found) return output;
    return nullptr;
  }

  void ProudServer::SendCharacterSnapshots(Player* player,
    LocalCharacterSnapshot local_character_snapshot, std::vector<RemoteCharacterSnapshot> remote_character_snapshots) {
    s2c_proxy_.PlayerSnapshot(player->id(), Proud::RmiContext::UnreliableSend, local_character_snapshot, remote_character_snapshots);
  }

  DEFRMI_GameC2S_PlayerInput(ProudServer) {
    Lock();
    auto player = GetPlayerByHostID(remote);
    if (!player) return true;
    player->character()->AddInput(player_input_packet);
    Unlock();
    return true;
  }

}