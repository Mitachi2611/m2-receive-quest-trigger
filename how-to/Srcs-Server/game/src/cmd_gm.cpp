//1.) Search:

			if (iEmptyPos != -1)
			{
				item->AddToCharacter(ch, TItemPos(INVENTORY, iEmptyPos));
				LogManager::instance().ItemLog(ch, item, "GM", item->GetName());

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
				ch->SenderRecvItem(ch->GetPlayerID(), item);
#endif