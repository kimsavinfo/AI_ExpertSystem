#include "Fact.h"

Fact::Fact(void)
{
}

string Fact::getName()
{
	return name;
}

int Fact::getLevel()
{
	return level;
}

void Fact::setLevel(int _level)
{
	level = _level;
}

string Fact::getQuestion()
{
	return question;
}


Fact::~Fact(void)
{
}
