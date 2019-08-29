#include <Python.h>

#include <SAM_Grid.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Lifetime Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Grid   data_ptr;
} LifetimeObject;

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Grid data_ptr)
{
	PyObject* new_obj = Lifetime_Type.tp_alloc(&Lifetime_Type,0);

	LifetimeObject* Lifetime_obj = (LifetimeObject*)new_obj;

	Lifetime_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Lifetime methods */

static PyObject *
Lifetime_assign(LifetimeObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_export(LifetimeObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Lifetime_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lifetime_get_analysis_period(LifetimeObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(LifetimeObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n*Info*: The number of years in the simulation\n\n*Required*: if ?=1"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime simulation [0/1]\n\n*Options*: 0=SingleYearRepeated,1=RunEveryYear\n\n*Constraints*: BOOLEAN\n\n*Required*: if ?=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GridModel.Lifetime",             /*tp_name*/
		sizeof(LifetimeObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Lifetime_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Lifetime_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Grid Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Grid   data_ptr;
} GridObject;

static PyTypeObject Grid_Type;

static PyObject *
Grid_new(SAM_Grid data_ptr)
{
	PyObject* new_obj = Grid_Type.tp_alloc(&Grid_Type,0);

	GridObject* Grid_obj = (GridObject*)new_obj;

	Grid_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Grid methods */

static PyObject *
Grid_assign(GridObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Grid")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Grid_export(GridObject *self, PyObject *args)
{
	PyTypeObject* tp = &Grid_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Grid_methods[] = {
		{"assign",            (PyCFunction)Grid_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Grid_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Grid_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Grid_get_enable_interconnection_limit(GridObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Grid_enable_interconnection_limit_nget, self->data_ptr);
}

static int
Grid_set_enable_interconnection_limit(GridObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_Grid_enable_interconnection_limit_nset, self->data_ptr);
}

static PyObject *
Grid_get_grid_interconnection_limit_kwac(GridObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Grid_grid_interconnection_limit_kwac_nget, self->data_ptr);
}

static int
Grid_set_grid_interconnection_limit_kwac(GridObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_Grid_grid_interconnection_limit_kwac_nset, self->data_ptr);
}

static PyGetSetDef Grid_getset[] = {
{"enable_interconnection_limit", (getter)Grid_get_enable_interconnection_limit,(setter)Grid_set_enable_interconnection_limit,
	PyDoc_STR("*float*: Enable grid interconnection limit [0/1]\n\n*Info*: Enable a grid interconnection limit"),
 	NULL},
{"grid_interconnection_limit_kwac", (getter)Grid_get_grid_interconnection_limit_kwac,(setter)Grid_set_grid_interconnection_limit_kwac,
	PyDoc_STR("*float*: Grid interconnection limit [kWac]\n\n*Info*: The number of years in the simulation"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Grid_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GridModel.Grid",             /*tp_name*/
		sizeof(GridObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Grid_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Grid_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Common Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Grid   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Grid data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	CommonObject* Common_obj = (CommonObject*)new_obj;

	Common_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(CommonObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(CommonObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_gen(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Common_gen_aget, self->data_ptr);
}

static int
Common_set_gen(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Common_gen_aset, self->data_ptr);
}

static PyObject *
Common_get_load(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Common_load_aget, self->data_ptr);
}

static int
Common_set_load(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Common_load_aset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"gen", (getter)Common_get_gen,(setter)Common_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n*Info*: Lifetime system generation"),
 	NULL},
{"load", (getter)Common_get_load,(setter)Common_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GridModel.Common",             /*tp_name*/
		sizeof(CommonObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * LossAdjustments Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Grid   data_ptr;
} LossAdjustmentsObject;

static PyTypeObject LossAdjustments_Type;

static PyObject *
LossAdjustments_new(SAM_Grid data_ptr)
{
	PyObject* new_obj = LossAdjustments_Type.tp_alloc(&LossAdjustments_Type,0);

	LossAdjustmentsObject* LossAdjustments_obj = (LossAdjustmentsObject*)new_obj;

	LossAdjustments_obj->data_ptr = data_ptr;

	return new_obj;
}

/* LossAdjustments methods */

static PyObject *
LossAdjustments_assign(LossAdjustmentsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "LossAdjustments")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LossAdjustments_export(LossAdjustmentsObject *self, PyObject *args)
{
	PyTypeObject* tp = &LossAdjustments_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LossAdjustments_methods[] = {
		{"assign",            (PyCFunction)LossAdjustments_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``LossAdjustments_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)LossAdjustments_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LossAdjustments_get_grid_curtailment(LossAdjustmentsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_LossAdjustments_grid_curtailment_aget, self->data_ptr);
}

static int
LossAdjustments_set_grid_curtailment(LossAdjustmentsObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_LossAdjustments_grid_curtailment_aset, self->data_ptr);
}

static PyGetSetDef LossAdjustments_getset[] = {
{"grid_curtailment", (getter)LossAdjustments_get_grid_curtailment,(setter)LossAdjustments_set_grid_curtailment,
	PyDoc_STR("*sequence*: Grid curtailment [%]\n\n*Required*: False"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LossAdjustments_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GridModel.LossAdjustments",             /*tp_name*/
		sizeof(LossAdjustmentsObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		LossAdjustments_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LossAdjustments_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Outputs Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Grid   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Grid data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_annual_ac_curtailment_loss_kwh(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_curtailment_loss_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_curtailment_loss_percent(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_curtailment_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_interconnect_loss_kwh(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_interconnect_loss_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_interconnect_loss_percent(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_interconnect_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_pre_curtailment_ac(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_energy_pre_curtailment_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_pre_interconnect_ac(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_energy_pre_interconnect_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_curtailment_ac(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_capacity_factor_curtailment_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_interconnect_ac(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_capacity_factor_interconnect_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_pre_curtailment_kwac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_system_pre_curtailment_kwac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_pre_interconnect_kwac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_system_pre_interconnect_kwac_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_ac_curtailment_loss_kwh", (getter)Outputs_get_annual_ac_curtailment_loss_kwh,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from curtailment (year 1) [kWh]"),
 	NULL},
{"annual_ac_curtailment_loss_percent", (getter)Outputs_get_annual_ac_curtailment_loss_percent,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from curtailment (year 1) [%]"),
 	NULL},
{"annual_ac_interconnect_loss_kwh", (getter)Outputs_get_annual_ac_interconnect_loss_kwh,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from interconnection limit (year 1) [kWh]"),
 	NULL},
{"annual_ac_interconnect_loss_percent", (getter)Outputs_get_annual_ac_interconnect_loss_percent,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from interconnection limit (year 1) [%]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC  (year 1) [kWh]"),
 	NULL},
{"annual_energy_pre_curtailment_ac", (getter)Outputs_get_annual_energy_pre_curtailment_ac,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC pre-curtailment (year 1) [kWh]"),
 	NULL},
{"annual_energy_pre_interconnect_ac", (getter)Outputs_get_annual_energy_pre_interconnect_ac,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC pre-interconnection (year 1) [kWh]"),
 	NULL},
{"capacity_factor_curtailment_ac", (getter)Outputs_get_capacity_factor_curtailment_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor of the curtailment (year 1) [%]"),
 	NULL},
{"capacity_factor_interconnect_ac", (getter)Outputs_get_capacity_factor_interconnect_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor of the interconnection (year 1) [%]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"system_pre_curtailment_kwac", (getter)Outputs_get_system_pre_curtailment_kwac,(setter)0,
	PyDoc_STR("*sequence*: System power before grid curtailment [kW]"),
 	NULL},
{"system_pre_interconnect_kwac", (getter)Outputs_get_system_pre_interconnect_kwac,(setter)0,
	PyDoc_STR("*sequence*: System power before grid interconnect [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GridModel.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * GridModel
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Grid   data_ptr;
} GridModelObject;

static PyTypeObject GridModel_Type;

static GridModelObject *
newGridModelObject(void* data_ptr)
{
	GridModelObject *self;
	self = PyObject_New(GridModelObject, &GridModel_Type);

	PySAM_TECH_ATTR("GridModel", SAM_Grid_construct)

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* Grid_obj = Grid_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Grid", Grid_obj);
	Py_DECREF(Grid_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* LossAdjustments_obj = LossAdjustments_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LossAdjustments", LossAdjustments_obj);
	Py_DECREF(LossAdjustments_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* GridModel methods */

static void
GridModel_dealloc(GridModelObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Grid_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
GridModel_execute(GridModelObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Grid_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GridModel_assign(GridModelObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Grid"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GridModel_export(GridModelObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef GridModel_methods[] = {
		{"execute",            (PyCFunction)GridModel_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)GridModel_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)GridModel_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GridModel_getattro(GridModelObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
GridModel_setattr(GridModelObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject GridModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GridModel",            /*tp_name*/
		sizeof(GridModelObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)GridModel_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)GridModel_setattr,   /*tp_setattr*/
		0,                      