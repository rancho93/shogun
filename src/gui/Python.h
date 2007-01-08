/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2007 Soeren Sonnenburg
 * Copyright (C) 1999-2007 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#if defined(HAVE_PYTHON) && !defined(HAVE_SWIG)

#ifndef __SHOGUN_PYTHON__
#define __SHOGUN_PYTHON__

extern "C" {
#include <Python.h>

	PyMODINIT_FUNC initsg(void);
	void exitsg(void);
}
#endif //HAVE_SWIG
#endif
