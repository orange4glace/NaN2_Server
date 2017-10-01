﻿



  
// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#pragma once


#include "team_mod_s2c_common.h"

namespace TeamModS2C {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot & snapshot) PN_SEALED; 
	virtual bool Snapshot ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const nan2::module::team_module::Snapshot & snapshot)   PN_SEALED;  
	virtual bool TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID & player_id, const int & team) PN_SEALED; 
	virtual bool TeamJoined ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::HostID & player_id, const int & team)   PN_SEALED;  
static const PNTCHAR* RmiName_Snapshot;
static const PNTCHAR* RmiName_TeamJoined;
static const PNTCHAR* RmiName_First;
		Proxy()
		{
			if(m_signature != 1)
				::Proud::ShowUserMisuseError(::Proud::ProxyBadSignatureErrorText);
		}

		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; } 
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

}



