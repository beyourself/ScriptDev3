/**
 * ScriptDev3 is an extension for mangos providing enhanced features for
 * area triggers, creatures, game objects, instances, items, and spells beyond
 * the default database scripting in mangos.
 *
 * Copyright (C) 2006-2013  ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2014-2016  MaNGOS  <https://getmangos.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

/**
 * ScriptData
 * SDName:      Item_custom_box
 * SD%Complete: 100
 * SDComment: Items for a range of different items. See content below (in script)
 * SDCategory:  Items
 * EndScriptData
 */

#include "precompiled.h"
#include "Spell.h"

/*#####
# item_display_Sylvanas  希尔瓦娜斯
#####*/

struct item_display_Sylvanas : public ItemScript
{
	item_display_Sylvanas() : ItemScript("item_display_Sylvanas") {}
	bool OnUse(Player* pPlayer, Item* pItem, const SpellCastTargets& /*pTargets*/) override
	{
		pPlayer->SetDisplayId(11657);
		pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f); //设置模型大小
		pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
		return true;
	}
	
};

/*#####
# item_display_Sal  萨尔
#####*/

struct item_display_Sal : public ItemScript
{
	item_display_Sal() : ItemScript("item_display_Sal") {}
	bool OnUse(Player* pPlayer, Item* pItem, const SpellCastTargets& /*pTargets*/) override
	{
		pPlayer->SetDisplayId(4527);
		pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f); //设置模型大小
		pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
		return true;
	}

};

/*#####
# item_display_dana  达那
#####*/

struct item_display_dana : public ItemScript
{
	item_display_dana() : ItemScript("item_display_dana") {}
	bool OnUse(Player* pPlayer, Item* pItem, const SpellCastTargets& /*pTargets*/) override
	{
		pPlayer->SetDisplayId(11048);
		pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f); //设置模型大小
		pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
		return true;
	}

};

/*#####
# item_reset_talent  天赋重置
#####*/
struct item_reset_talent : public ItemScript
{
	item_reset_talent() : ItemScript("item_reset_talent") {}

	bool OnUse(Player* pPlayer, Item* pItem, const SpellCastTargets& /*pTargets*/) override
	{
		if (pPlayer->IsInCombat() || pPlayer->IsTaxiFlying())
		{
			pPlayer->GetSession()->SendNotification("飞行状态与战斗状态无法使用!");
			return false;
		}
		pPlayer->resetTalents(true);
		pPlayer->GetSession()->SendNotification("天赋重置成功!");
		pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
		return true;
		
	}
};

void AddSC_item_custom_box()
{
	Script* s; 
	s = new item_display_Sylvanas();
	s->RegisterSelf();
	s = new item_display_Sal();
	s->RegisterSelf();
	s = new item_display_dana();
	s->RegisterSelf();
	s = new item_reset_talent();
	s->RegisterSelf();
}