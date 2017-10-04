#pragma once

namespace TeamModS2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Snapshot = (::Proud::RmiID)(8000+1);
               
    static const ::Proud::RmiID Rmi_TeamJoined = (::Proud::RmiID)(8000+2);
               
    static const ::Proud::RmiID Rmi_TeamLeft = (::Proud::RmiID)(8000+3);
               
    static const ::Proud::RmiID Rmi_Scored = (::Proud::RmiID)(8000+4);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
