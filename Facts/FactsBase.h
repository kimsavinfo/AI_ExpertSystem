#pragma once

#include <vector>

#include "Fact.h"
#include "IClear.h"

class FactsBase : public IClear
{
private:
	vector<Fact*> facts;

public:
	FactsBase(void);
	~FactsBase(void);
	Fact* getFact(string _name);
	int getFactValue(string _name);
	vector<Fact*> getFacts();
	void addFact(Fact* _fact);
	virtual void clear();
};

