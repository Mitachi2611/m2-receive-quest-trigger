//1.) Search:

int	CHARACTER::GetSkillPowerByLevel(int level, bool bMob) const
{
	return CTableBySkill::instance().GetSkillPowerByLevelFromType(GetJob(), GetSkillGroup(), MINMAX(0, level, SKILL_MAX_LEVEL), bMob); 
}

// and add under, this:

#ifdef ENABLE_QUEST_RECEIVE_ITEM
void CHARACTER::SenderRecvItem(unsigned int pc, LPITEM item)
{
	quest::CQuestManager::instance().ReceiveItem(pc, item);
}
#endif