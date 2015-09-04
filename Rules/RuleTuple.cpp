#include "RuleTuple.h"


RuleTuple::RuleTuple(Rule* _rule, int _level)
{
	rule = _rule;
	level = _level;
}

Rule* RuleTuple::getRule()
{
	return rule;
}

int RuleTuple::getLevel()
{
	return level;
}

RuleTuple::~RuleTuple(void)
{
}
