#include "Python.h"

static PyObject*
keywdarg_redirect_set_stderr(PyObject *self, PyObject *args, PyObject *kwds)
{
    char *path="stderr.log";
    int *append=0;
    static char *kwlist [] = {"path", "append", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|si", kwlist, &path, &append))
        return NULL;
    if ( append == 0 ) {
        freopen(path, "w", stderr);
    }
    else {
        freopen(path, "a+", stderr);
    }
    Py_INCREF(Py_None);
    return Py_None;
};

static PyObject*
keywdarg_redirect_set_stdout(PyObject *self, PyObject *args, PyObject *kwds)
{
    char *path="stdout.log";
    int *append=0;
    static char *kwlist [] = {"path", "append", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|si", kwlist, &path))
        return NULL;
    if ( append == 0 ) {
        freopen(path, "w", stdout);
    }
    else {
        freopen(path, "a+", stdout);
    }
    Py_INCREF(Py_None);
    return Py_None;
};

static PyMethodDef keywdarg_methods[] = {
    {"set_stderr", (PyCFunction)keywdarg_redirect_set_stderr, METH_VARARGS | METH_KEYWORDS,
        "\nredirect.set_stderr(path=\"stderr.log\", append=False)\n\n"
        "Set a file path for stderr or uses default \"stderr.log\".\n"
        "Automatically creates a new file if 'path' does not exists, or appends the\n"
        "messages to an existing one if 'append' is True."
    },
    {"set_stdout", (PyCFunction)keywdarg_redirect_set_stdout, METH_VARARGS | METH_KEYWORDS,
        "\nredirect.set_stdout(path=\"stdout.log\", append=False)\n\n"
        "Set a file path for stdout or uses default \"stdout.log\".\n"
        "Automatically creates a new file if 'path' does not exists, or appends the\n"
        "messages to an existing one if 'append' is True."
    },
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initfreopen(void) {
    PyObject *m;
    m = Py_InitModule("freopen", keywdarg_methods);
    if (m == NULL)
        return;
};
