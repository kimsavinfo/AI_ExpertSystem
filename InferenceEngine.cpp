#include "InferenceEngine.h"


InferenceEngine::InferenceEngine()
{
	factsBase = new FactsBase();
	rulesBase = new RulesBase();
	ihm = new HumanInterface();
	factFactory = new Factfactory();
}

int InferenceEngine::askIntValue(string _question)
{
	return ihm->askIntValue(_question);
}

int InferenceEngine::askBoolValue(string _question)
{
	return ihm->askBoolValue(_question);
}

int InferenceEngine::canApply(Rule* _rule)
{
	int maxLevel = 0;

	vector<Fact *> premises = _rule->getPremises();
	int size = premises.size();
	int iPremise = 0;
	Fact* foundFact;
	Fact* premise;

	// Is each premise true ?
	while(iPremise < size && maxLevel > -1)
	{
		premise = premises.at(iPremise);
		foundFact = factsBase->getFact(premise->getName());

		// Does the fact exist in the FactsBase ?
		if(foundFact == NULL)
		{
			// The fact doesn't exist in the FactsBase
			if(premises.at(iPremise)->getQuestion() != "")
			{
				// Ask the user and add it to the base
				foundFact = factFactory->createFact(premises.at(iPremise), ihm);
				factsBase->addFact(foundFact);
				maxLevel = max(maxLevel, 0);
			
			}
			else
			{
				// The rule does not apply
				maxLevel = -1;
			}
		}

		// IF a fact is in the base THEN we check its value
		// This step can be done after adding a rule
		if(foundFact != NULL)
		{
			if(foundFact->getValue() == premises.at(iPremise)->getValue())
			{
				// It matches !
				maxLevel = max(maxLevel, foundFact->getLevel());
			}
			else
			{
				maxLevel = -1;
			}
		}
		
		iPremise++;
	}

	return maxLevel;
}

RuleTuple* InferenceEngine::FindUsableRule(RulesBase* _rulesBase)
{
	RuleTuple* usableRule = NULL;

	bool isPresent = false;
	int iRule = 0;
	vector<Rule*> rules = _rulesBase->getRules();
	int size = rules.size();
	int level;

	// Test all the rules until we find 1 application
	while(iRule < size && !isPresent)
	{
		level = canApply(rules.at(iRule));
		if(level != -1)
		{
			usableRule = new RuleTuple(rules.at(iRule), level);
			isPresent = true;
		}

		iRule++;
	}

	return usableRule;
}

void InferenceEngine::solve()
{
	// Make a copie of the rule and create an empty base
	bool moreRules = true;
	RulesBase* usableRules = new RulesBase();
	usableRules = rulesBase;
	factsBase->clear();

	while(moreRules)
	{
		// Search a rule to apply
		RuleTuple* ruleTuple = FindUsableRule(usableRules);

		if(ruleTuple == NULL)
		{
			// No more possible rules : we can stop
			moreRules = false;
		}
		else
		{
			// Apply the rule
			Fact* newFact = ruleTuple->getRule()->getConclusion();
			newFact->setLevel(ruleTuple->getLevel() + 1);
			// Add then new fact to the base
			factsBase->addFact(newFact);

			// Remove rule from copy of rules
			usableRules->removeRule(ruleTuple->getRule());
		}
	}

	// Show the results for the user
	ihm->printFacts(factsBase->getFacts());
}

void InferenceEngine::addRule(string _ruleStr)
{
	int namePos =  _ruleStr.find(":");

	if(namePos != string::npos)
	{
		// Rule's name
		string name = _ruleStr.substr(0, namePos - 1);
		
		int ifPos = _ruleStr.find("IF") +4;
		int thenPos = _ruleStr.find("THEN");
		if(ifPos != string::npos && thenPos!= string::npos)
		{
			string premisesStr = _ruleStr.substr(ifPos, (thenPos - 2 - ifPos));
			
			// Rule's premises
			vector<Fact*> premises;
			int andPos = premisesStr.find("AND");
			while(andPos != string::npos)
			{
				string premiseStr = premisesStr.substr(0, (andPos-1));
				premises.push_back( factFactory->createFact(premiseStr) );
				premisesStr = premisesStr.substr(andPos+4, premisesStr.size() - (andPos+4));
				andPos = premisesStr.find("AND");
			}
			premises.push_back( factFactory->createFact(premisesStr) );

			// Rule's Conclusion
			string conclusionStr = _ruleStr.substr(thenPos+5, _ruleStr.size() - (thenPos+5));

			Fact* conclusion = factFactory->createFact(conclusionStr);

			// Add the rule
			rulesBase->addRule(new Rule(premises,conclusion,name));
		}
	}
}


InferenceEngine::~InferenceEngine(void)
{
}
