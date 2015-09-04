#include "Rule.h"


Rule::Rule(vector<Fact*> _premises, Fact* _conclusion, string _name)
{
	premises = _premises;
	conclusion = _conclusion;
	name = _name;
}

string Rule::toString()
{
	string ruleStr = name + " : IF (";

	int size = premises.size();
	for(int iPremise = 0; iPremise < size; iPremise++)
	{
		ruleStr += premises.at(iPremise)->toString();

		if(iPremise == size)
		{
			ruleStr += " AND ";
		}
	}
	ruleStr += ") THEN " + conclusion->toString();

	return ruleStr;
}

vector<Fact*> Rule::getPremises()
{
	return premises;
}
	
void Rule::setPremises(vector<Fact*> _premises)
{
	premises = _premises;
}
	
Fact* Rule::getConclusion()
{
	return conclusion;
}

void Rule::setConclusion(Fact* _conclusion)
{
	conclusion = _conclusion;
}

string Rule::getName()
{
	return name;
}

void Rule::setName(string _name)
{
	name = _name;
}

Rule::~Rule(void)
{
}
