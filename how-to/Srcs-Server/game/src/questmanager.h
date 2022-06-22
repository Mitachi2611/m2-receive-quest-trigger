//1.) Search:

			void		AttrOut(unsigned int pc, LPCHARACTER ch, int attr);

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
			bool		ReceiveItem(unsigned int pc, LPITEM item);
#endif