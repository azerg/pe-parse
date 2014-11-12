

#include <stdio.h>
#include <Windows.h>

typedef int (*pinit)(const char *);
typedef int (*pget)(char *, char *);
typedef int (*pfree)();

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("> this.exe <exe file path>\n");
		return 1;
	}
	
	HMODULE h = LoadLibraryA("pe-parse-dll.dll");
	pinit a = (pinit)GetProcAddress(h, "pe_parse_init");
	pget  b = (pget) GetProcAddress(h, "pe_parse_getIAT");
	pfree c = (pfree)GetProcAddress(h, "pe_parse_free");

	int sz = a(argv[1]);
	for(int i=0; i < sz; i++){
		char mod[1024];
		char sym[1024];
		b(mod, sym);
		printf("%04d: %s, %s\n", i, mod, sym);
	}
	c();
	return 0;
}