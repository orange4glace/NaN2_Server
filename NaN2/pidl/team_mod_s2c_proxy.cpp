﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.


#include "team_mod_s2c_proxy.h"

namespace team_mod_s2c {


        
	bool Proxy::Snapshot ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const nan2::module::team_module::Snapshot & snapshot)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_Snapshot;
__msg.Write(__msgid); 
	
__msg << snapshot;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_Snapshot, (::Proud::RmiID)Rmi_Snapshot);
	}

	bool Proxy::Snapshot ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const nan2::module::team_module::Snapshot & snapshot)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_Snapshot;
__msg.Write(__msgid); 
	
__msg << snapshot;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_Snapshot, (::Proud::RmiID)Rmi_Snapshot);
	}
        
	bool Proxy::TeamJoined ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::HostID & player_id, const int & team)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_TeamJoined;
__msg.Write(__msgid); 
	
__msg << player_id;
__msg << team;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_TeamJoined, (::Proud::RmiID)Rmi_TeamJoined);
	}

	bool Proxy::TeamJoined ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::HostID & player_id, const int & team)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_TeamJoined;
__msg.Write(__msgid); 
	
__msg << player_id;
__msg << team;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_TeamJoined, (::Proud::RmiID)Rmi_TeamJoined);
	}
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_Snapshot =_PNT("Snapshot");
#else
const PNTCHAR* Proxy::RmiName_Snapshot =_PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_TeamJoined =_PNT("TeamJoined");
#else
const PNTCHAR* Proxy::RmiName_TeamJoined =_PNT("");
#endif
const PNTCHAR* Proxy::RmiName_First = RmiName_Snapshot;

}


