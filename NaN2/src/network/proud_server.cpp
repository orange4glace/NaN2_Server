// proud_server.cpp
#include "network/proud_server.h"

#include "../pidl/game_s2c_common.cpp"
#include "../pidl/game_s2c_proxy.cpp"
#include "../pidl/game_s2c_stub.cpp"

#include "../pidl/game_c2s_common.cpp"
#include "../pidl/game_c2s_proxy.cpp"
#include "../pidl/game_c2s_stub.cpp"

#include "logger/logger.h"

namespace nan2 {

  ProudServer* ProudServer::instance_ = nullptr;

  ProudServer* const ProudServer::instance() {
    if (instance_ == nullptr) {
      instance_ = new ProudServer();
    }
    return instance_;
  }

  ProudServer::ProudServer() :
  cs_lock_(cs_, false) {
  }

  ProudServer::~ProudServer() {
  }

  void ProudServer::Initialize() {
    try
    {
    server_ = Proud::CNetServer::Create();
    Proud::CStartServerParameter server_param;
    Proud::PNGUID guid = { 0x3ae33249, 0xecc6, 0x4980,{ 0xbc, 0x5d, 0x7b, 0xa, 0x99, 0x9c, 0x7, 0x39 } };
    Proud::Guid g_Version = Proud::Guid(guid);
    server_param.m_protocolVersion = g_Version;
    server_param.m_tcpPorts.Add(33334);
    server_->SetEventSink(this);
    server_->AttachProxy(&s2c_proxy_);
    server_->AttachStub((GameC2S::Stub*)this);

      /* Starts the server.
      This function throws an exception on failure.
      Note: As we specify nothing for threading model,
      RMI function by message receive and event callbacks are
      called in a separate thread pool.
      You can change the thread model. Check out the help pages for details. */
      server_->Start(server_param);
    }
    catch (Proud::Exception &e)
    {
      cout << "Server start failed: " << e.what() << endl;
    }
    catch (exception e) {
      cout << e.what() << endl;
    }
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
    delete player;
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

  int ProudServer::GetPlayerPing(Player* player) {
    return server_->GetRecentUnreliablePingMs(player->id());
  }

  void ProudServer::SendCharacterSnapshots(const Player* const player,
    const LocalCharacterSnapshot& local_character_snapshot, const std::vector<RemoteCharacterSnapshot>& remote_character_snapshots) {
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