// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the H2RANK_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// H2RANK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef H2RANK_EXPORTS
#define H2RANK_API __declspec(dllexport)
#else
#define H2RANK_API __declspec(dllimport)
#endif

// This class is exported from the H2Rank.dll
class H2RANK_API CH2Rank {
public:
	CH2Rank(void);
	// TODO: add your methods here.
};

extern H2RANK_API int nH2Rank;

H2RANK_API int fnH2Rank(void);

void Intialize();