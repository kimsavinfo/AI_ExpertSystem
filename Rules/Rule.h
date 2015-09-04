#pragma once

#include <vector>

#include "Fact.h"

class Rule : public IToString
{
private:
	vector<Fact*> premises;
	Fact* conclusion;
	string name;

public:
	Rule(vector<Fact*> _premises, Fact* _conclusion, string _name);
	~Rule(void);
	virtual string toString();
	vector<Fact*> getPremises();
	void setPremises(vector<Fact*> _premises);
	Fact* getConclusion();
	void setConclusion(Fact* _conclusion);
	string getName();
	void setName(string _name);
};

