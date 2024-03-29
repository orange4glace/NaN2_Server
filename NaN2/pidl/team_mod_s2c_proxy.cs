﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace TeamModS2C
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool Snapshot(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, nan2.module.TeamModule.Snapshot snapshot)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.Snapshot;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, snapshot);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_Snapshot, Common.Snapshot);
}

public bool Snapshot(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, nan2.module.TeamModule.Snapshot snapshot)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.Snapshot;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, snapshot);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_Snapshot, Common.Snapshot);
}
public bool TeamJoined(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, int team)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.TeamJoined;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, player_id);
		nan2.ProudMarshaler.Write(__msg, team);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_TeamJoined, Common.TeamJoined);
}

public bool TeamJoined(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, int team)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.TeamJoined;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, player_id);
nan2.ProudMarshaler.Write(__msg, team);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_TeamJoined, Common.TeamJoined);
}
public bool TeamLeft(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, int team)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.TeamLeft;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, player_id);
		nan2.ProudMarshaler.Write(__msg, team);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_TeamLeft, Common.TeamLeft);
}

public bool TeamLeft(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, int team)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.TeamLeft;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, player_id);
nan2.ProudMarshaler.Write(__msg, team);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_TeamLeft, Common.TeamLeft);
}
public bool Scored(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int team, int score)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.Scored;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, team);
		nan2.ProudMarshaler.Write(__msg, score);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_Scored, Common.Scored);
}

public bool Scored(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int team, int score)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.Scored;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, team);
nan2.ProudMarshaler.Write(__msg, score);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_Scored, Common.Scored);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_Snapshot="Snapshot";
const string RmiName_TeamJoined="TeamJoined";
const string RmiName_TeamLeft="TeamLeft";
const string RmiName_Scored="Scored";
       
const string RmiName_First = RmiName_Snapshot;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_Snapshot="";
const string RmiName_TeamJoined="";
const string RmiName_TeamLeft="";
const string RmiName_Scored="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}

