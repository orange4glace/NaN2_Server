#pragma once

namespace GameS2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_PlayerSnapshots = (::Proud::RmiID)(6000+1);
               
    static const ::Proud::RmiID Rmi_JoinWorld = (::Proud::RmiID)(6000+2);
               
    static const ::Proud::RmiID Rmi_PlayerJoin = (::Proud::RmiID)(6000+3);
               
    static const ::Proud::RmiID Rmi_PlayerLeave = (::Proud::RmiID)(6000+4);
               
    static const ::Proud::RmiID Rmi_SkillCasted = (::Proud::RmiID)(6000+5);
               
    static const ::Proud::RmiID Rmi_CharacterSpawned = (::Proud::RmiID)(6000+6);
               
    static const ::Proud::RmiID Rmi_CharacterDied = (::Proud::RmiID)(6000+7);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
