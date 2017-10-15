﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace CTFModS2C
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool SnapshotDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, nan2.module.CTFModule.Snapshot snapshot);  
		public SnapshotDelegate Snapshot = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, nan2.module.CTFModule.Snapshot snapshot)
		{ 
			return false;
		};
		public delegate bool FlagCapturedDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id);  
		public FlagCapturedDelegate FlagCaptured = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id)
		{ 
			return false;
		};
		public delegate bool FlagDroppedDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, float pos_x, float pos_y);  
		public FlagDroppedDelegate FlagDropped = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID player_id, float pos_x, float pos_y)
		{ 
			return false;
		};
		public delegate bool FlagReturnedDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int team_id, Nettention.Proud.HostID player_id);  
		public FlagReturnedDelegate FlagReturned = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int team_id, Nettention.Proud.HostID player_id)
		{ 
			return false;
		};
	public override bool ProcessReceivedMessage(Nettention.Proud.ReceivedMessage pa, Object hostTag) 
	{
		Nettention.Proud.HostID remote=pa.RemoteHostID;
		if(remote==Nettention.Proud.HostID.HostID_None)
		{
			ShowUnknownHostIDWarning(remote);
		}

		Nettention.Proud.Message __msg=pa.ReadOnlyMessage;
		int orgReadOffset = __msg.ReadOffset;
        Nettention.Proud.RmiID __rmiID = Nettention.Proud.RmiID.RmiID_None;
        if (!__msg.Read( out __rmiID))
            goto __fail;
					
		switch(__rmiID)
		{
case Common.Snapshot:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		nan2.module.CTFModule.Snapshot snapshot; nan2.ProudMarshaler.Read(__msg,out snapshot);	
core.PostCheckReadMessage(__msg, RmiName_Snapshot);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=snapshot.ToString()+",";
			NotifyCallFromStub(Common.Snapshot, RmiName_Snapshot,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.Snapshot;
			summary.rmiName = RmiName_Snapshot;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=Snapshot (remote,ctx , snapshot );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_Snapshot);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.Snapshot;
			summary.rmiName = RmiName_Snapshot;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.FlagCaptured:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.HostID player_id; nan2.ProudMarshaler.Read(__msg,out player_id);	
core.PostCheckReadMessage(__msg, RmiName_FlagCaptured);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=player_id.ToString()+",";
			NotifyCallFromStub(Common.FlagCaptured, RmiName_FlagCaptured,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.FlagCaptured;
			summary.rmiName = RmiName_FlagCaptured;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=FlagCaptured (remote,ctx , player_id );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_FlagCaptured);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.FlagCaptured;
			summary.rmiName = RmiName_FlagCaptured;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.FlagDropped:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.HostID player_id; nan2.ProudMarshaler.Read(__msg,out player_id);	
float pos_x; nan2.ProudMarshaler.Read(__msg,out pos_x);	
float pos_y; nan2.ProudMarshaler.Read(__msg,out pos_y);	
core.PostCheckReadMessage(__msg, RmiName_FlagDropped);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=player_id.ToString()+",";
parameterString+=pos_x.ToString()+",";
parameterString+=pos_y.ToString()+",";
			NotifyCallFromStub(Common.FlagDropped, RmiName_FlagDropped,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.FlagDropped;
			summary.rmiName = RmiName_FlagDropped;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=FlagDropped (remote,ctx , player_id, pos_x, pos_y );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_FlagDropped);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.FlagDropped;
			summary.rmiName = RmiName_FlagDropped;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.FlagReturned:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int team_id; nan2.ProudMarshaler.Read(__msg,out team_id);	
Nettention.Proud.HostID player_id; nan2.ProudMarshaler.Read(__msg,out player_id);	
core.PostCheckReadMessage(__msg, RmiName_FlagReturned);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=team_id.ToString()+",";
parameterString+=player_id.ToString()+",";
			NotifyCallFromStub(Common.FlagReturned, RmiName_FlagReturned,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.FlagReturned;
			summary.rmiName = RmiName_FlagReturned;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=FlagReturned (remote,ctx , team_id, player_id );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_FlagReturned);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.FlagReturned;
			summary.rmiName = RmiName_FlagReturned;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
		default:
			 goto __fail;
		}
		return true;
__fail:
	  {
			__msg.ReadOffset = orgReadOffset;
			return false;
	  }
	}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_Snapshot="Snapshot";
const string RmiName_FlagCaptured="FlagCaptured";
const string RmiName_FlagDropped="FlagDropped";
const string RmiName_FlagReturned="FlagReturned";
       
const string RmiName_First = RmiName_Snapshot;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_Snapshot="";
const string RmiName_FlagCaptured="";
const string RmiName_FlagDropped="";
const string RmiName_FlagReturned="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

