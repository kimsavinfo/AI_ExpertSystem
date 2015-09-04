#include "BoolFact.h"

BoolFact::BoolFact(string _name, bool _value, string _question, int _level)
{
	name = _name;
	value = _value;
	question = _question;
	level = _level;
}

int BoolFact::getValue()
{
	return value ? 1 : 0;
}

string BoolFact::toString()
{
	string factStr = "";
	factStr += value ? "" : "!";
	factStr += name + " (" + to_string(level) + ")";
	return factStr;
}

BoolFact::~BoolFact(void)
{
}
