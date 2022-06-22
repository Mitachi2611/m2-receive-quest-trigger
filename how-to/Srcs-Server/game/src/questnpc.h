//1.) Search:

			bool	OnAttrOut(PC& pc);

// and add after, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
			bool	OnReceive(PC& pc);
#endif