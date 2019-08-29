#include <Python.h>

#include <SAM_Pvwattsv5Lifetime.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Outputs Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Pvwattsv5Lifetime data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "Outputs")){
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

static PyGetSetDef Outputs_getset[] = {
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.Outputs",             /*tp_name*/
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
 * Pvwattsv5Lifetime
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Pvwattsv5Lifetime   data_ptr;
} Pvwattsv5LifetimeObject;

static PyTypeObject Pvwattsv5Lifetime_Type;

static Pvwattsv5LifetimeObject *
newPvwattsv5LifetimeObject(void* data_ptr)
{
	Pvwattsv5LifetimeObject *self;
	self = PyObject_New(Pvwattsv5LifetimeObject, &Pvwattsv5Lifetime_Type);

	PySAM_TECH_ATTR("Pvwattsv5Lifetime", SAM_Pvwattsv5Lifetime_construct)

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* Pvwattsv5Lifetime methods */

static void
Pvwattsv5Lifetime_dealloc(Pvwattsv5LifetimeObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Pvwattsv5Lifetime_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Pvwattsv5Lifetime_execute(Pvwattsv5LifetimeObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv5Lifetime_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv5Lifetime_assign(Pvwattsv5LifetimeObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv5Lifetime"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv5Lifetime_export(Pvwattsv5LifetimeObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Pvwattsv5Lifetime_methods[] = {
		{"execute",            (PyCFunction)Pvwattsv5Lifetime_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv5Lifetime_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Outputs': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv5Lifetime_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv5Lifetime_getattro(Pvwattsv5LifetimeObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv5Lifetime_setattr(Pvwattsv5LifetimeObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv5Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime",            /*tp_name*/
		sizeof(Pvwattsv5LifetimeObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv5Lifetime_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv5Lifetime_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv5Lifetime_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"This class contains all the variable information for running a simulation. Variables are grouped together in the subclasses as properties. If property assignments are the wrong type, an error is thrown.",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Pvwattsv5Lifetime_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new Pvwattsv5Lifetime object */

static PyObject *
Pvwattsv5Lifetime_new(PyObject *self, PyObject *args)
{
	Pvwattsv5LifetimeObject *rv;
	rv = newPvwattsv5LifetimeObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv5Lifetime_wrap(PyObject *self, PyObject *args)
{
	Pvwattsv5LifetimeObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv5LifetimeObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv5Lifetime_default(PyObject *self, PyObject *args)
{
	Pvwattsv5LifetimeObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv5LifetimeObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv5Lifetime", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv5LifetimeModule_methods[] = {
		{"new",             Pvwattsv5Lifetime_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv5Lifetime")},
		{"default",             Pvwattsv5Lifetime_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv5Lifetime\n\nUse financial model-specific default attributes\n"
				"config options:\n\n- \"FuelCellCommercial\"\n- \"FuelCellSingleOwner\"")},
		{"wrap",             Pvwattsv5Lifetime_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv5Lifetime\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "PVWatts photovoltaic system model for multi-year lifetime analysis");


static int
Pvwattsv5LifetimeModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	Pvwattsv5Lifetime_Type.tp_dict = PyDict_New();
	if (!Pvwattsv5Lifetime_Type.tp_dict) { goto fail; }

	/// Add the Outputs type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv5Lifetime type object to the module
	if (PyType_Ready(&Pvwattsv5Lifetime_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv5Lifetime",
				(PyObject*)&Pvwattsv5Lifetime_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv5LifetimeModule_slots[] = {
		{Py_mod_exec, Pvwattsv5LifetimeModule_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv5LifetimeModule = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv5Lifetime",
		module_doc,
		0,
		Pvwattsv5LifetimeModule_methods,
		Pvwattsv5LifetimeModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv5Lifetime(void)
{
	return PyModuleDef_Init(&Pvwattsv5LifetimeModule);
}