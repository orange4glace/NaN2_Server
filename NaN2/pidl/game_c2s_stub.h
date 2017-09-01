﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "game_c2s_common.h"

     
namespace GameC2S {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool PlayerInput ( ::Proud::HostID, ::Proud::RmiContext& , const nan2::PlayerInputPacket  & )		{ 
			return false;
		} 

#define DECRMI_GameC2S_PlayerInput bool PlayerInput ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::PlayerInputPacket  & player_input_packet) PN_OVERRIDE

#define DEFRMI_GameC2S_PlayerInput(DerivedClass) bool DerivedClass::PlayerInput ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::PlayerInputPacket  & player_input_packet)
#define CALL_GameC2S_PlayerInput PlayerInput ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::PlayerInputPacket  & player_input_packet)
#define PARAM_GameC2S_PlayerInput ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::PlayerInputPacket  & player_input_packet)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_PlayerInput;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const nan2::PlayerInputPacket  & ) > PlayerInput_Function;
		virtual bool PlayerInput ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::PlayerInputPacket  & player_input_packet) 
		{ 
			if (PlayerInput_Function==nullptr) 
				return true; 
			return PlayerInput_Function(remote,rmiContext, player_input_packet); 
		}

	};
#endif

}


