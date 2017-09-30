﻿



  
// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#pragma once


#include "ctf_mod_s2c_common.h"

namespace ctf_mod_s2c {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::ctf_module::Snapshot & snapshot) PN_SEALED; 
	virtual bool Snapshot ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const nan2::module::ctf_module::Snapshot & snapshot)   PN_SEALED;  
	virtual bool FlagCaptured ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID & player_id) PN_SEALED; 
	virtual bool FlagCaptured ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::HostID & player_id)   PN_SEALED;  
	virtual bool FlagDropped ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID & player_id, const float & pos_x, const float & pos_y) PN_SEALED; 
	virtual bool FlagDropped ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::HostID & player_id, const float & pos_x, const float & pos_y)   PN_SEALED;  
	virtual bool FlagReturned ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID & player_id) PN_SEALED; 
	virtual bool FlagReturned ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::HostID & player_id)   PN_SEALED;  
	virtual bool Scored ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID & player_id) PN_SEALED; 
	virtual bool Scored ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::HostID & player_id)   PN_SEALED;  
static const PNTCHAR* RmiName_Snapshot;
static const PNTCHAR* RmiName_FlagCaptured;
static const PNTCHAR* RmiName_FlagDropped;
static const PNTCHAR* RmiName_FlagReturned;
static const PNTCHAR* RmiName_Scored;
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


