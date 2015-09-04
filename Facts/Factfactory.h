#pragma once

#include "String_Lib.h"

#include "IntFact.h"
#include "BoolFact.h"
#include "HumanInterface.h"

class Factfactory
{
private:
	String_Lib* string_lib;
	Fact* createIntFact(string _factStr);
	Fact* createBoolFact(string _factStr);

public:
	Factfactory(void);
	~Factfactory(void);
	Fact* createFact(Fact* _fact, HumanInterface* _ihm);
	Fact* createFact(string _factStr);
};

