#include "IntFact.h"

IntFact::IntFact(string _name, int _value, string _question, int _level)
{
	name = _name;
	value = _value;
	question = _question;
	level = _level;
}

int IntFact::getValue()
{
	return value;
}

string IntFact::toString()
{
	return name + "=" + to_string(value) + " (" + to_string(level) + ")";
}

IntFact::~IntFact(void)
{
}