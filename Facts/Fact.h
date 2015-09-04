#pragma once

using namespace std;

#include "IToString.h"


class Fact
{
protected:
	string name;
	int level;
	int value;
	string question;

public:
	Fact(void);
	string getName();
	int getLevel();
	void setLevel(int _level);
	string getQuestion();
	virtual int getValue() { return value; }
	virtual string toString() { return ""; }
	~Fact(void);
};

