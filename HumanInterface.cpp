#include "HumanInterface.h"


HumanInterface::HumanInterface(void)
{
}

int HumanInterface::askIntValue(string _question)
{
	cout << "\n" + _question + " (only int accepted) ";

	int intValue = 0;
	while(!(cin >> intValue))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	return intValue;
}

bool HumanInterface::askBoolValue(string _question)
{
	char type;
	do
	{
		cout << "\n" + _question + " (y/n) " ;
		cin >> type;
	}
	while( !cin.fail() && type!='y' && type!='n' );

	return type == 'y' ? true : false;
}

vector<Fact*> HumanInterface::getFactsLevelHigher(vector<Fact*> _facts, int _level)
{
	vector<Fact*> factsToShow;

	int size = _facts.size();
	for(int iFact = 0; iFact < size; iFact++)
	{
		if(_facts.at(iFact)->getLevel() > _level)
		{
			factsToShow.push_back(_facts.at(iFact));
		}
	}

	return factsToShow;
}

void HumanInterface::printFacts(vector<Fact*> _facts)
{
	string str = "Solution(s) : \n";

	// We only show the facts with a level higher than 0
	vector<Fact*> factsToShow = getFactsLevelHigher(_facts, 0);

	int size = factsToShow.size();
	if(size > 0)
	{
		// Sorting : highest level to lowest level thanks to a lambda expressions
		auto sortFactByLevelDESC = [](Fact* _factA, Fact* _factB) 
		{ 
			return _factA->getLevel() > _factB->getLevel(); 
		};
		sort(factsToShow.begin(), factsToShow.end(), sortFactByLevelDESC);

		for(int iFact = 0; iFact < size; iFact++)
		{
			cout << factsToShow.at(iFact)->toString() + "\n";
		}
	}
}

void HumanInterface::printRules(vector<Rule*> _rules)
{
	int size = _rules.size();

	for(int iRule = 0; iRule < size; iRule++)
	{
		cout << _rules.at(iRule)->toString() + "\n";
	}
}

HumanInterface::~HumanInterface(void)
{
}
