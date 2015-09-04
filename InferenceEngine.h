#pragma once

#include "FactsBase.h"
#include "RulesBase.h"
#include "HumanInterface.h"
#include "Factfactory.h"
#include "RuleTuple.h"

class InferenceEngine
{
private:
	FactsBase* factsBase;
	RulesBase* rulesBase;
	HumanInterface* ihm;
	Factfactory* factFactory;

	RuleTuple* FindUsableRule(RulesBase* _rulesBase);

public:
	InferenceEngine();
	~InferenceEngine(void);
	int askIntValue(string _question);
	int askBoolValue(string _question);
	int canApply(Rule* _rule);
	void solve();
	void addRule(string _ruleStr);
};

