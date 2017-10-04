﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "team_mod_s2c_common.h"

     
namespace TeamModS2C {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool Snapshot ( ::Proud::HostID, ::Proud::RmiContext& , const nan2::module::team_module::Snapshot  & )		{ 
			return false;
		} 

#define DECRMI_TeamModS2C_Snapshot bool Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot  & snapshot) PN_OVERRIDE

#define DEFRMI_TeamModS2C_Snapshot(DerivedClass) bool DerivedClass::Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot  & snapshot)
#define CALL_TeamModS2C_Snapshot Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot  & snapshot)
#define PARAM_TeamModS2C_Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot  & snapshot)
               
		virtual bool TeamJoined ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & , const int  & )		{ 
			return false;
		} 

#define DECRMI_TeamModS2C_TeamJoined bool TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team) PN_OVERRIDE

#define DEFRMI_TeamModS2C_TeamJoined(DerivedClass) bool DerivedClass::TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team)
#define CALL_TeamModS2C_TeamJoined TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team)
#define PARAM_TeamModS2C_TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team)
               
		virtual bool TeamLeft ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & , const int  & )		{ 
			return false;
		} 

#define DECRMI_TeamModS2C_TeamLeft bool TeamLeft ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team) PN_OVERRIDE

#define DEFRMI_TeamModS2C_TeamLeft(DerivedClass) bool DerivedClass::TeamLeft ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team)
#define CALL_TeamModS2C_TeamLeft TeamLeft ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team)
#define PARAM_TeamModS2C_TeamLeft ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team)
               
		virtual bool Scored ( ::Proud::HostID, ::Proud::RmiContext& , const int  & , const int  & )		{ 
			return false;
		} 

#define DECRMI_TeamModS2C_Scored bool Scored ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int  & team, const int  & score) PN_OVERRIDE

#define DEFRMI_TeamModS2C_Scored(DerivedClass) bool DerivedClass::Scored ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int  & team, const int  & score)
#define CALL_TeamModS2C_Scored Scored ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int  & team, const int  & score)
#define PARAM_TeamModS2C_Scored ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int  & team, const int  & score)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_Snapshot;
		static const PNTCHAR* RmiName_TeamJoined;
		static const PNTCHAR* RmiName_TeamLeft;
		static const PNTCHAR* RmiName_Scored;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const nan2::module::team_module::Snapshot  & ) > Snapshot_Function;
		virtual bool Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot  & snapshot) 
		{ 
			if (Snapshot_Function==nullptr) 
				return true; 
			return Snapshot_Function(remote,rmiContext, snapshot); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & , const int  & ) > TeamJoined_Function;
		virtual bool TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team) 
		{ 
			if (TeamJoined_Function==nullptr) 
				return true; 
			return TeamJoined_Function(remote,rmiContext, player_id, team); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::HostID  & , const int  & ) > TeamLeft_Function;
		virtual bool TeamLeft ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID  & player_id, const int  & team) 
		{ 
			if (TeamLeft_Function==nullptr) 
				return true; 
			return TeamLeft_Function(remote,rmiContext, player_id, team); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const int  & , const int  & ) > Scored_Function;
		virtual bool Scored ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int  & team, const int  & score) 
		{ 
			if (Scored_Function==nullptr) 
				return true; 
			return Scored_Function(remote,rmiContext, team, score); 
		}

	};
#endif

}


