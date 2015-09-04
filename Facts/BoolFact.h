#pragma once

#include "Fact.h"

class BoolFact : public Fact
{
public:
	BoolFact(string _name, bool _value, string _question, int _level = 0);
	virtual int getValue();
	virtual string toString();
	~BoolFact(void);
};

