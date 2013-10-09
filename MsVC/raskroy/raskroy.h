
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RASKROY_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RASKROY_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef RASKROY_EXPORTS
#define RASKROY_API __declspec(dllexport)
#else
#define RASKROY_API __declspec(dllimport)
#endif

#include "..\..\types.hpp"

RASKROY_API void MakeRaskroy(
	const raskroy::t_parts &parts,
	const raskroy::t_parts &sheets,
	const raskroy::t_factory &factory,
	raskroy::criteria& criteria,
	raskroy::monitor& monitor,
	raskroy::t_results& results
);
