#pragma once

namespace GameS2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_PlayerSnapshot = (::Proud::RmiID)(6000+1);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
