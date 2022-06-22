//1.) Search:

		m_apItems[i] = NULL;
	}

// and add before, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
		victim->SenderRecvItem(victim->GetPlayerID(), item);
#endif