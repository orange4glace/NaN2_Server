﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.


#include "team_mod_c2s_proxy.h"

namespace TeamModC2S {


        
	bool Proxy::JoinTeam ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & team)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_JoinTeam;
__msg.Write(__msgid); 
	
__msg << team;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_JoinTeam, (::Proud::RmiID)Rmi_JoinTeam);
	}

	bool Proxy::JoinTeam ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & team)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_JoinTeam;
__msg.Write(__msgid); 
	
__msg << team;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_JoinTeam, (::Proud::RmiID)Rmi_JoinTeam);
	}
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_JoinTeam =_PNT("JoinTeam");
#else
const PNTCHAR* Proxy::RmiName_JoinTeam =_PNT("");
#endif
const PNTCHAR* Proxy::RmiName_First = RmiName_JoinTeam;

}



