#ifndef SAM_PVWATTSV5LIFETIME_H_
#define SAM_PVWATTSV5LIFETIME_H_

#include "visibility.h"
#include "SAM_api.h"


#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif

	//
	// Pvwattsv5Lifetime Technology Model
	//

	/** 
	 * Create a Pvwattsv5Lifetime variable table.
	 * @param def: the set of financial model-dependent defaults to use (None, Residential, ...)
	 * @param[in,out] err: a pointer to an error object
	 */

	SAM_EXPORT typedef void * SAM_Pvwattsv5Lifetime;

	SAM_EXPORT SAM_Pvwattsv5Lifetime SAM_Pvwattsv5Lifetime_construct(const char* def, SAM_error* err);

	/// verbosity level 0 or 1. Returns 1 on success
	SAM_EXPORT int SAM_Pvwattsv5Lifetime_execute(SAM_Pvwattsv5Lifetime data, int verbosity, SAM_error* err);

	SAM_EXPORT void SAM_Pvwattsv5Lifetime_destruct(SAM_Pvwattsv5Lifetime system);


	/**
	 * Outputs Getters
	 */

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#endif