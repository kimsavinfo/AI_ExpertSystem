#pragma once

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Fact.h"
#include "Rule.h"

class HumanInterface
{
private:
	vector<Fact*> getFactsLevelHigher(vector<Fact*> _facts, int _level);

public:
	HumanInterface(void);
	~HumanInterface(void);
	int askIntValue(string _question);
	bool askBoolValue(string _question);
	void printFacts(vector<Fact*> _facts);
	void printRules(vector<Rule*> _rules);
};

