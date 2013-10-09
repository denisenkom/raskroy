// raskroy.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "raskroy.h"
#include "..\..\raskroy.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


RASKROY_API void MakeRaskroy(const raskroy::t_parts &parts,
							 const raskroy::t_parts &sheets,
							 const raskroy::t_factory &factory,
							 raskroy::criteria& criteria,
							 raskroy::monitor& monitor,
							 raskroy::t_results& results)
{
	raskroy::gilotine gilotine;
	gilotine.run(parts, sheets, factory, criteria, monitor, results);
}