//1.) Search:

		QUEST_ITEM_INFORMER_EVENT,

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
		QUEST_ITEM_RECEIVE_EVENT,
#endif