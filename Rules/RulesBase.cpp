#include "RulesBase.h"


RulesBase::RulesBase(void)
{
}


vector<Rule*> RulesBase::getRules()
{
	return rules;
}

void RulesBase::setRules(vector<Rule*> _rules)
{
	rules = _rules;
}

void RulesBase::addRule(Rule* _rule)
{
	rules.push_back(_rule);
}

void RulesBase::removeRule(Rule* _rule)
{
	int position = find(rules.begin(), rules.end(), _rule) - rules.begin();
	rules.erase(rules.begin() + position);
}

void RulesBase::clear()
{
	rules.clear();
}


RulesBase::~RulesBase(void)
{
	clear();
}
