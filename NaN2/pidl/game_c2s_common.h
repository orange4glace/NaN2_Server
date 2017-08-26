#pragma once

namespace GameC2S {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_PlayerInput = (::Proud::RmiID)(5000+1);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
