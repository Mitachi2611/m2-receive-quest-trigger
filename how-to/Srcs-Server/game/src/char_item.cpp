//1.) Search:

							item2->SetCount(item2->GetCount() + bCount2);

							if (bCount == 0)
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("아이템 획득: %s"), item2->GetName());
								M2_DESTROY_ITEM(item);
								if (item2->GetType() == ITEM_QUEST)
									quest::CQuestManager::instance().PickupItem (GetPlayerID(), item2);

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
								SenderRecvItem(GetPlayerID(), item2);
#endif

//2.) Search:

				char szHint[32+1];
				snprintf(szHint, sizeof(szHint), "%s %u %u", item->GetName(), item->GetCount(), item->GetOriginalVnum());
				LogManager::instance().ItemLog(this, item, "GET", szHint);
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("아이템 획득: %s"), item->GetName());

				if (item->GetType() == ITEM_QUEST)
					quest::CQuestManager::instance().PickupItem (GetPlayerID(), item);

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
				SenderRecvItem(GetPlayerID(), item);
#endif

//3.) Search:

			if (owner == this)
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("아이템 획득: %s"), item->GetName());
			else
			{
				owner->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("아이템 획득: %s 님으로부터 %s"), GetName(), item->GetName());
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("아이템 전달: %s 님에게 %s"), owner->GetName(), item->GetName());
			}

			if (item->GetType() == ITEM_QUEST)
				quest::CQuestManager::instance().PickupItem (owner->GetPlayerID(), item);

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
			owner->SenderRecvItem(owner->GetPlayerID(), item);
#endif