#pragma once

#include "Fact.h"

class IntFact : public Fact
{
public:
	IntFact(string _name, int _value, string _question, int _level = 0);
	~IntFact(void);
	virtual int getValue();
	virtual string toString();
};