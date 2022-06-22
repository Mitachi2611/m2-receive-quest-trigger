//1.) Search:

	public:
		int		GetSkillPowerByLevel(int level, bool bMob = false) const;

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
		void	SenderRecvItem(unsigned int pc, LPITEM item);
#endif