﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "game_s2c_common.h"

     
namespace GameS2C {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool PlayerSnapshots ( ::Proud::HostID, ::Proud::RmiContext& , const nan2::LocalCharacterSnapshot  & , const std::vector<nan2::RemoteCharacterSnapshot>  & )		{ 
			return false;
		} 

#define DECRMI_GameS2C_PlayerSnapshots bool PlayerSnapshots ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::LocalCharacterSnapshot  & local_character_snapshot, const std::vector<nan2::RemoteCharacterSnapshot>  & remote_character_snapshot) PN_OVERRIDE

#define DEFRMI_GameS2C_PlayerSnapshots(DerivedClass) bool DerivedClass::PlayerSnapshots ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::LocalCharacterSnapshot  & local_character_snapshot, const std::vector<nan2::RemoteCharacterSnapshot>  & remote_character_snapshot)
#define CALL_GameS2C_PlayerSnapshots PlayerSnapshots ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::LocalCharacterSnapshot  & local_character_snapshot, const std::vector<nan2::RemoteCharacterSnapshot>  & remote_character_snapshot)
#define PARAM_GameS2C_PlayerSnapshots ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::LocalCharacterSnapshot  & local_character_snapshot, const std::vector<nan2::RemoteCharacterSnapshot>  & remote_character_snapshot)
               
		virtual bool JoinWorld ( ::Proud::HostID, ::Proud::RmiContext& , const std::vector<Proud::HostID>  & )		{ 
			return false;
		} 

#define DECRMI_GameS2C_JoinWorld bool JoinWorld ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const std::vector<Proud::HostID>  & player_ids) PN_OVERRIDE

#define DEFRMI_GameS2C_JoinWorld(DerivedClass) bool DerivedClass::JoinWorld ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const std::vector<Proud::HostID>  & player_ids)
#define CALL_GameS2C_JoinWorld JoinWorld ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const std::vector<Proud::HostID>  & player_ids)
#define PARAM_GameS2C_JoinWorld ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const std::vector<Proud::HostID>  & player_ids)
               
		virtual bool PlayerJoin ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & )		{ 
			return false;
		} 

#define DECRMI_GameS2C_PlayerJoin bool PlayerJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id) PN_OVERRIDE

#define DEFRMI_GameS2C_PlayerJoin(DerivedClass) bool DerivedClass::PlayerJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id)
#define CALL_GameS2C_PlayerJoin PlayerJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id)
#define PARAM_GameS2C_PlayerJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id)
               
		virtual bool PlayerLeave ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & )		{ 
			return false;
		} 

#define DECRMI_GameS2C_PlayerLeave bool PlayerLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id) PN_OVERRIDE

#define DEFRMI_GameS2C_PlayerLeave(DerivedClass) bool DerivedClass::PlayerLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id)
#define CALL_GameS2C_PlayerLeave PlayerLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id)
#define PARAM_GameS2C_PlayerLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id)
               
		virtual bool SkillCasted ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & , const nan2::SkillCastSnapshot  & )		{ 
			return false;
		} 

#define DECRMI_GameS2C_SkillCasted bool SkillCasted ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const nan2::SkillCastSnapshot  & snapshot) PN_OVERRIDE

#define DEFRMI_GameS2C_SkillCasted(DerivedClass) bool DerivedClass::SkillCasted ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const nan2::SkillCastSnapshot  & snapshot)
#define CALL_GameS2C_SkillCasted SkillCasted ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const nan2::SkillCastSnapshot  & snapshot)
#define PARAM_GameS2C_SkillCasted ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const nan2::SkillCastSnapshot  & snapshot)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_PlayerSnapshots;
		static const PNTCHAR* RmiName_JoinWorld;
		static const PNTCHAR* RmiName_PlayerJoin;
		static const PNTCHAR* RmiName_PlayerLeave;
		static const PNTCHAR* RmiName_SkillCasted;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const nan2::LocalCharacterSnapshot  & , const std::vector<nan2::RemoteCharacterSnapshot>  & ) > PlayerSnapshots_Function;
		virtual bool PlayerSnapshots ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::LocalCharacterSnapshot  & local_character_snapshot, const std::vector<nan2::RemoteCharacterSnapshot>  & remote_character_snapshot) 
		{ 
			if (PlayerSnapshots_Function==nullptr) 
				return true; 
			return PlayerSnapshots_Function(remote,rmiContext, local_character_snapshot, remote_character_snapshot); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const std::vector<Proud::HostID>  & ) > JoinWorld_Function;
		virtual bool JoinWorld ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const std::vector<Proud::HostID>  & player_ids) 
		{ 
			if (JoinWorld_Function==nullptr) 
				return true; 
			return JoinWorld_Function(remote,rmiContext, player_ids); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & ) > PlayerJoin_Function;
		virtual bool PlayerJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id) 
		{ 
			if (PlayerJoin_Function==nullptr) 
				return true; 
			return PlayerJoin_Function(remote,rmiContext, player_id); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & ) > PlayerLeave_Function;
		virtual bool PlayerLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id) 
		{ 
			if (PlayerLeave_Function==nullptr) 
				return true; 
			return PlayerLeave_Function(remote,rmiContext, player_id); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & , const nan2::SkillCastSnapshot  & ) > SkillCasted_Function;
		virtual bool SkillCasted ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const nan2::SkillCastSnapshot  & snapshot) 
		{ 
			if (SkillCasted_Function==nullptr) 
				return true; 
			return SkillCasted_Function(remote,rmiContext, player_id, snapshot); 
		}

	};
#endif

}


