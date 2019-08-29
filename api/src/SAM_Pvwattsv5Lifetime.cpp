#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>

#include <ssc/sscapi.h>

#include "SAM_api.h"
#include "ErrorHandler.h"
#include "SAM_Pvwattsv5Lifetime.h"

SAM_EXPORT SAM_Pvwattsv5Lifetime SAM_Pvwattsv5Lifetime_construct(const char* def, SAM_error* err){
	SAM_Pvwattsv5Lifetime result = nullptr;
	translateExceptions(err, [&]{
		result = ssc_data_create();
	});
	return result;
}

SAM_EXPORT int SAM_Pvwattsv5Lifetime_execute(SAM_Pvwattsv5Lifetime data, int verbosity, SAM_error* err){
	int n_err = 0;
	translateExceptions(err, [&]{
		n_err += SAM_module_exec("pvwattsv5_lifetime", data, verbosity, err);
	});
	return n_err;
}


SAM_EXPORT void SAM_Pvwattsv5Lifetime_destruct(SAM_Pvwattsv5Lifetime system)
{
	ssc_data_free(system);
}

