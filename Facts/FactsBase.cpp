#include "FactsBase.h"


FactsBase::FactsBase(void)
{
}

Fact* FactsBase::getFact(string _name)
{
	Fact* theFact = NULL;

	bool isPresent = false;
	int iFact = 0;
	int size = facts.size();

	while(iFact < size && !isPresent)
	{
		if( (facts.at(iFact))->getName() == _name )
		{
			isPresent = true;
			theFact = facts.at(iFact);
		}

		iFact++;
	}

	return theFact;
}

int FactsBase::getFactValue(string _name)
{
	int value = NULL;

	Fact* theFact = getFact(_name);
	if(theFact != NULL)
	{
		value = theFact->getValue();
	}

	return value;
}

vector<Fact*> FactsBase::getFacts()
{
	return facts;
}

void FactsBase::addFact(Fact* _fact)
{
	facts.push_back(_fact);
}
	
void FactsBase::clear()
{
	facts.clear();
}

FactsBase::~FactsBase(void)
{
	clear();
}
