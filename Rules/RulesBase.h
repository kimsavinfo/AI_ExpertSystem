#pragma once

#include "Rule.h"
#include "IClear.h"

class RulesBase
{
private:
	vector<Rule*> rules;

public:
	RulesBase(void);
	~RulesBase(void);
	vector<Rule*> getRules();
	void setRules(vector<Rule*> _rules);
	void addRule(Rule* _rule);
	void removeRule(Rule* _rule);
	virtual void clear();
};

