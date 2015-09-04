#pragma once

#include "Rule.h"

class RuleTuple
{
private:
	Rule* rule;
	int level;

public:
	RuleTuple(Rule* _rule, int _level);
	~RuleTuple(void);
	Rule* getRule();
	int getLevel();
};

