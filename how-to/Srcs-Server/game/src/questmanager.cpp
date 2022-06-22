//1.) Search:

		m_mapEventName.insert(TEventNameMap::value_type("item_informer", QUEST_ITEM_INFORMER_EVENT));

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
		m_mapEventName.insert(TEventNameMap::value_type("receive", QUEST_ITEM_RECEIVE_EVENT));
#endif

//2.) Search:

	void CQuestManager::AttrOut(unsigned int pc, LPCHARACTER ch, int attr)
	{
		...
	}

// and add under the whole function, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
	bool CQuestManager::ReceiveItem(unsigned int pc, LPITEM item)
	{
		if (test_server)
			sys_log(0, "questmanager::ReceiveItem Start : itemVnum : %d PC : %d", item->GetOriginalVnum(), pc);

		PC* pPC;
		if ((pPC = GetPC(pc)))
		{
			if (!CheckQuestLoaded(pPC))
			{
				LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(pc);
				if (ch)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("����Ʈ�� �ε��ϴ� ���Դϴ�. ��ø� ��ٷ� �ֽʽÿ�."));
				}
				return false;
			}

			// call script
			SetCurrentItem(item);

			return m_mapNPC[item->GetVnum()].OnReceive(*pPC);
		}
		else
		{
			sys_err("QUEST RECEIVE_ITEM_EVENT no such pc id : %d", pc);
			return false;
		}
	}
#endif