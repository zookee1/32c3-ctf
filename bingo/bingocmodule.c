#include <Python.h>
#include <stdlib.h>     /* srand, rand */

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return Py_BuildValue("i", sts);
}

static PyObject *
bingoc_srand(PyObject *self, PyObject *args)
{
    int seed;

    if (!PyArg_ParseTuple(args, "i", &seed))
        return NULL;

    srand(seed);
    return Py_BuildValue("i", seed);
}

static PyObject *
bingoc_rand(PyObject *self, PyObject *args)
{
    return Py_BuildValue("i", rand());
}


static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},
    {"srand",  bingoc_srand, METH_VARARGS,
     "SRAND()"},
    {"rand",  bingoc_rand, METH_VARARGS,
     "RAND()"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC
initbingoc(void)
{
    (void) Py_InitModule("bingoc", SpamMethods);
}
