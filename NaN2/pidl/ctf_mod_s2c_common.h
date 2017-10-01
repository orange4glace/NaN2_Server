#pragma once

namespace CTFModS2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Snapshot = (::Proud::RmiID)(7000+1);
               
    static const ::Proud::RmiID Rmi_FlagCaptured = (::Proud::RmiID)(7000+2);
               
    static const ::Proud::RmiID Rmi_FlagDropped = (::Proud::RmiID)(7000+3);
               
    static const ::Proud::RmiID Rmi_FlagReturned = (::Proud::RmiID)(7000+4);
               
    static const ::Proud::RmiID Rmi_Scored = (::Proud::RmiID)(7000+5);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
