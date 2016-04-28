/**
* ScriptData
* SDName:      npc_custom_box
* SD%Complete: 100
* SDComment:自定义功能
* EndScriptData
**/

//#include "sc_gossip.h"
//#include "GossipDef.h"
//#include "Player.h"
#include "precompiled.h"



/*####################
## npc_tool
######################*/

struct npc_tool : public CreatureScript
{
	npc_tool() : CreatureScript("npc_tool"){}

	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{

		pPlayer->ADD_GOSSIP_ITEM(4, "名字修改--(5000积分)　 ", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(4, "查询当前帐户积分　 "      , GOSSIP_SENDER_MAIN, 99);
		pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		if (!pPlayer)
			return true;

		switch (uiAction)
		{
		case 0: //名字
			if (pPlayer->Getjifen() >= 5000) // 判断积分是否足够.
			{
				pPlayer->Modifyjifen(-(int32)5000);//扣除积分
				pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);//修改名字
				CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = %u", pPlayer->GetGUID());
				pPlayer->GetSession()->SendNotification("你需要重新登录，然后才能修改角色的名字！");
				pPlayer->PlayerTalkClass->CloseGossip();

			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法修改角色名称!");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case 99:
		    {
				pPlayer->GetSession()->SendNotification("你当前帐户积分：%d ", pPlayer->Getjifen());
				pPlayer->PlayerTalkClass->CloseGossip();
			}

		}
		return true;
	}
};

void AddSC_custom_box()
{
	Script* s;
	s = new npc_tool();
	s->RegisterSelf();
}

