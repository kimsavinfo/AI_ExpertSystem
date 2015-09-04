#include "String_Lib.h"


String_Lib::String_Lib(void)
{
}

string String_Lib::trim(string& _str)
{
	size_t first = _str.find_first_not_of(' ');
    size_t last = _str.find_last_not_of(' ');
    return _str.substr(first, (last-first+1));
}

String_Lib::~String_Lib(void)
{
}
