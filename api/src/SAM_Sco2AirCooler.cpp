#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>

#include <ssc/sscapi.h>

#include "SAM_api.h"
#include "ErrorHandler.h"
#include "SAM_Sco2AirCooler.h"

SAM_EXPORT SAM_Sco2AirCooler SAM_Sco2AirCooler_construct(const char* def, SAM_error* err){
	SAM_Sco2AirCooler result = nullptr;
	translateExceptions(err, [&]{
		result = ssc_data_create();
	});
	return result;
}

SAM_EXPORT int SAM_Sco2AirCooler_execute(SAM_Sco2AirCooler data, int verbosity, SAM_error* err){
	int n_err = 0;
	translateExceptions(err, [&]{
		n_err += SAM_module_exec("sco2_air_cooler", data, verbosity, err);
	});
	return n_err;
}


SAM_EXPORT void SAM_Sco2AirCooler_destruct(SAM_Sco2AirCooler system)
{
	ssc_data_free(system);
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_P_co2_hot_in_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "P_co2_hot_in", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_T_amb_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "T_amb", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_T_co2_cold_out_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "T_co2_cold_out", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_T_co2_hot_in_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "T_co2_hot_in", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_W_dot_fan_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "W_dot_fan", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_deltaP_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "deltaP", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_q_dot_reject_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "q_dot_reject", number);
	});
}

SAM_EXPORT void SAM_Sco2AirCooler_Common_site_elevation_nset(SAM_Sco2AirCooler ptr, double number, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_number(ptr, "site_elevation", number);
	});
}

SAM_EXPORT double SAM_Sco2AirCooler_Common_P_co2_hot_in_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "P_co2_hot_in", &result))
		make_access_error("SAM_Sco2AirCooler", "P_co2_hot_in");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_T_amb_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "T_amb", &result))
		make_access_error("SAM_Sco2AirCooler", "T_amb");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_T_co2_cold_out_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "T_co2_cold_out", &result))
		make_access_error("SAM_Sco2AirCooler", "T_co2_cold_out");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_T_co2_hot_in_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "T_co2_hot_in", &result))
		make_access_error("SAM_Sco2AirCooler", "T_co2_hot_in");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_W_dot_fan_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "W_dot_fan", &result))
		make_access_error("SAM_Sco2AirCooler", "W_dot_fan");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_deltaP_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "deltaP", &result))
		make_access_error("SAM_Sco2AirCooler", "deltaP");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_q_dot_reject_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "q_dot_reject", &result))
		make_access_error("SAM_Sco2AirCooler", "q_dot_reject");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Common_site_elevation_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "site_elevation", &result))
		make_access_error("SAM_Sco2AirCooler", "site_elevation");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_UA_total_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "UA_total", &result))
		make_access_error("SAM_Sco2AirCooler", "UA_total");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_d_tube_in_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "d_tube_in", &result))
		make_access_error("SAM_Sco2AirCooler", "d_tube_in");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_d_tube_out_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "d_tube_out", &result))
		make_access_error("SAM_Sco2AirCooler", "d_tube_out");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_depth_footprint_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "depth_footprint", &result))
		make_access_error("SAM_Sco2AirCooler", "depth_footprint");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_length_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "length", &result))
		make_access_error("SAM_Sco2AirCooler", "length");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_m_V_hx_material_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "m_V_hx_material", &result))
		make_access_error("SAM_Sco2AirCooler", "m_V_hx_material");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_n_passes_series_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "n_passes_series", &result))
		make_access_error("SAM_Sco2AirCooler", "n_passes_series");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_number_of_tubes_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "number_of_tubes", &result))
		make_access_error("SAM_Sco2AirCooler", "number_of_tubes");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_parallel_paths_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "parallel_paths", &result))
		make_access_error("SAM_Sco2AirCooler", "parallel_paths");
	});
	return result;
}



SAM_EXPORT double SAM_Sco2AirCooler_Outputs_width_footprint_nget(SAM_Sco2AirCooler ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "width_footprint", &result))
		make_access_error("SAM_Sco2AirCooler", "width_footprint");
	});
	return result;
}



