//1.) Search:

	bool NPC::OnTakeItem(PC& pc)
	{
		...
	}

// and add before, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
	bool NPC::OnReceive(PC& pc)
	{
		if (m_vnum == 0)
			return HandleReceiveAllEvent(pc, QUEST_ITEM_RECEIVE_EVENT);
		else
			return HandleEvent(pc, QUEST_ITEM_RECEIVE_EVENT);
	}
#endif