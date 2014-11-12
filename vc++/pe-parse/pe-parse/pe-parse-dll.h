#ifdef PEPARSEDLL_EXPORTS
#define PE_PARSE_API __declspec(dllexport) 
#else
#define PE_PARSE_API __declspec(dllimport) 
#endif

extern "C" {
	PE_PARSE_API int pe_parse_init(const char *);
	PE_PARSE_API int pe_parse_getIAT(char *, char *);
	PE_PARSE_API int pe_parse_free();
}