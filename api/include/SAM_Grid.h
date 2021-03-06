#ifndef SAM_GRID_H_
#define SAM_GRID_H_

#include "visibility.h"
#include "SAM_api.h"


#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif

	//
	// Grid Technology Model
	//

	/** 
	 * Create a Grid variable table.
	 * @param def: the set of financial model-dependent defaults to use (None, Residential, ...)
	 * @param[in,out] err: a pointer to an error object
	 */

	SAM_EXPORT typedef void * SAM_Grid;

	SAM_EXPORT SAM_Grid SAM_Grid_construct(const char* def, SAM_error* err);

	/// verbosity level 0 or 1. Returns 1 on success
	SAM_EXPORT int SAM_Grid_execute(SAM_Grid data, int verbosity, SAM_error* err);

	SAM_EXPORT void SAM_Grid_destruct(SAM_Grid system);


	//
	// Lifetime parameters
	//

	/**
	 * Set analysis_period: Lifetime analysis period [years]
	 * options: The number of years in the simulation
	 * constraints: None
	 * required if: system_use_lifetime_output=1
	 */
	SAM_EXPORT void SAM_Grid_Lifetime_analysis_period_nset(SAM_Grid ptr, double number, SAM_error *err);

	/**
	 * Set system_use_lifetime_output: Lifetime simulation [0/1]
	 * options: 0=SingleYearRepeated,1=RunEveryYear
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Grid_Lifetime_system_use_lifetime_output_nset(SAM_Grid ptr, double number, SAM_error *err);


	//
	// Common parameters
	//

	/**
	 * Set enable_interconnection_limit: Enable grid interconnection limit [0/1]
	 * options: Enable a grid interconnection limit
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Grid_Common_enable_interconnection_limit_nset(SAM_Grid ptr, double number, SAM_error *err);

	/**
	 * Set gen: System power generated [kW]
	 * options: Lifetime system generation
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Grid_Common_gen_aset(SAM_Grid ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set grid_interconnection_limit_kwac: Grid interconnection limit [kWac]
	 * options: The number of years in the simulation
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Grid_Common_grid_interconnection_limit_kwac_nset(SAM_Grid ptr, double number, SAM_error *err);

	/**
	 * Set load: Electricity load (year 1) [kW]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Grid_Common_load_aset(SAM_Grid ptr, double* arr, int length, SAM_error *err);


	/**
	 * Lifetime Getters
	 */

	SAM_EXPORT double SAM_Grid_Lifetime_analysis_period_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double SAM_Grid_Lifetime_system_use_lifetime_output_nget(SAM_Grid ptr, SAM_error *err);


	/**
	 * Common Getters
	 */

	SAM_EXPORT double SAM_Grid_Common_enable_interconnection_limit_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Grid_Common_gen_aget(SAM_Grid ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Grid_Common_grid_interconnection_limit_kwac_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Grid_Common_load_aget(SAM_Grid ptr, int* length, SAM_error *err);


	/**
	 * Outputs Getters
	 */

	SAM_EXPORT double SAM_Grid_Outputs_annual_ac_interconnect_loss_kwh_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double SAM_Grid_Outputs_annual_ac_interconnect_loss_percent_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double SAM_Grid_Outputs_annual_energy_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double SAM_Grid_Outputs_annual_energy_pre_interconnect_ac_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double SAM_Grid_Outputs_capacity_factor_interconnect_ac_nget(SAM_Grid ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Grid_Outputs_gen_aget(SAM_Grid ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Grid_Outputs_system_pre_interconnect_kwac_aget(SAM_Grid ptr, int* length, SAM_error *err);

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#endif