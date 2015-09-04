#include "Factfactory.h"


Factfactory::Factfactory(void)
{
	string_lib = new String_Lib();
}

Fact* Factfactory::createFact(Fact* _fact, HumanInterface* _ihm)
{
	Fact* newFact = NULL;

	if( typeid(*_fact) == typeid(IntFact) )
	{
		int value = _ihm->askIntValue(_fact->getQuestion());
		newFact = new IntFact(_fact->getName(), value, "", 0);
	}
	else
	{
		bool value = _ihm->askBoolValue(_fact->getQuestion());
		newFact = new BoolFact(_fact->getName(), value, "", 0);
	}

	return newFact;
}

Fact* Factfactory::createFact(string _factStr)
{
	Fact* newFact = NULL;

	_factStr = string_lib->trim(_factStr);
	if(_factStr.find('=') != string::npos)
	{
		newFact = createIntFact(_factStr);
	}
	else
	{
		newFact = createBoolFact(_factStr);
	}

	return newFact;
}

Fact* Factfactory::createIntFact(string _factStr)
{
	Fact* newFact = NULL;

	int namePos =  _factStr.find("=");
	int valuePos =  _factStr.find("(");
	int questionPos =  _factStr.size()-1 - (valuePos+1);

	if(namePos != string::npos 
		&& valuePos != string::npos 
		&& questionPos != string::npos)
	{
		string name = _factStr.substr(0, namePos);
		int value = stoi(  _factStr.substr(namePos+1, (valuePos - namePos+1)) );
		string question = _factStr.substr(valuePos+1, questionPos);
		newFact = new IntFact(name, value, question);
	}

	return newFact;
}

Fact* Factfactory::createBoolFact(string _factStr)
{
	bool value = true;
	string name = _factStr;
	string question = "";

	// Is it true or false ?
	if(_factStr.find('!') != string::npos)
	{
		value = false;
		// We remove the "!"
		_factStr = _factStr.substr(0, 1);
	}

	// Get the name and the question if available
	int namePos =  _factStr.find("(");
	int questionPos =  _factStr.size()-1 - (namePos+1);
	if(namePos != string::npos 
		&& questionPos != string::npos)
	{
		name = _factStr.substr(0, namePos);
		question = _factStr.substr(namePos+1, questionPos);
	}

	return new BoolFact(name, value, question);
}

Factfactory::~Factfactory(void)
{
}
