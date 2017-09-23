﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace GameS2C
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool PlayerSnapshots(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, nan2.LocalCharacterSnapshot local_character_snapshot, System.Collections.Generic.List<nan2.RemoteCharacterSnapshot> remote_character_snapshot)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.PlayerSnapshots;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, local_character_snapshot);
		nan2.ProudMarshaler.Write(__msg, remote_character_snapshot);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_PlayerSnapshots, Common.PlayerSnapshots);
}

public bool PlayerSnapshots(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, nan2.LocalCharacterSnapshot local_character_snapshot, System.Collections.Generic.List<nan2.RemoteCharacterSnapshot> remote_character_snapshot)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.PlayerSnapshots;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, local_character_snapshot);
nan2.ProudMarshaler.Write(__msg, remote_character_snapshot);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_PlayerSnapshots, Common.PlayerSnapshots);
}
public bool JoinWorld(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.Collections.Generic.List<Nettention.Proud.HostID> player_ids)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.JoinWorld;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, player_ids);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_JoinWorld, Common.JoinWorld);
}

public bool JoinWorld(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, System.Collections.Generic.List<Nettention.Proud.HostID> player_ids)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.JoinWorld;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, player_ids);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_JoinWorld, Common.JoinWorld);
}
public bool PlayerJoin(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.PlayerJoin;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, player_id);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_PlayerJoin, Common.PlayerJoin);
}

public bool PlayerJoin(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.PlayerJoin;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, player_id);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_PlayerJoin, Common.PlayerJoin);
}
public bool PlayerLeave(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.PlayerLeave;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, player_id);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_PlayerLeave, Common.PlayerLeave);
}

public bool PlayerLeave(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.PlayerLeave;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, player_id);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_PlayerLeave, Common.PlayerLeave);
}
public bool SkillCasted(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, nan2.SkillCastSnapshot snapshot)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.SkillCasted;
		__msg.Write(__msgid);
		nan2.ProudMarshaler.Write(__msg, player_id);
		nan2.ProudMarshaler.Write(__msg, snapshot);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_SkillCasted, Common.SkillCasted);
}

public bool SkillCasted(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, nan2.SkillCastSnapshot snapshot)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.SkillCasted;
__msg.Write(__msgid);
nan2.ProudMarshaler.Write(__msg, player_id);
nan2.ProudMarshaler.Write(__msg, snapshot);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_SkillCasted, Common.SkillCasted);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_PlayerSnapshots="PlayerSnapshots";
const string RmiName_JoinWorld="JoinWorld";
const string RmiName_PlayerJoin="PlayerJoin";
const string RmiName_PlayerLeave="PlayerLeave";
const string RmiName_SkillCasted="SkillCasted";
       
const string RmiName_First = RmiName_PlayerSnapshots;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_PlayerSnapshots="";
const string RmiName_JoinWorld="";
const string RmiName_PlayerJoin="";
const string RmiName_PlayerLeave="";
const string RmiName_SkillCasted="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}

