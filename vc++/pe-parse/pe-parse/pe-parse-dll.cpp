
#include <iostream>
#include <sstream>
#include "parse.h"

#include "pe-parse-dll.h"

using namespace std;
using namespace boost;

#include <vector>

int g_i = 0;
vector<string> *_x; // for modName
vector<string> *_y; // for symName

int printImports(void *N, VA impAddr, string &modName, string &symName)
{
	_x->push_back(modName);
	_y->push_back(symName);
	return 0;
}

PE_PARSE_API int pe_parse_init(const char *name)
{
	g_i = 0;
	_x = new vector<string>;
	_y = new vector<string>;
	parsed_pe *p = ParsePEFromFile(name);
	IterImpVAString(p, printImports, NULL);
	return _x->size();
}

PE_PARSE_API int pe_parse_getIAT(char *_a, char *_b)
{
	strcpy(_a, (*_x)[g_i].c_str());
	strcpy(_b, (*_y)[g_i].c_str());
	g_i += 1;
	return g_i;
}

PE_PARSE_API int pe_parse_free()
{
	delete _x;
	delete _y;
	return 0;
}
