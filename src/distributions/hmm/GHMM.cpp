/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2007 Soeren Sonnenburg
 * Copyright (C) 1999-2007 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "distributions/hmm/GHMM.h"

bool CGHMM::train()
{
	return false;
}

INT CGHMM::get_num_model_parameters()
{
	return 0;
}

DREAL CGHMM::get_log_model_parameter(INT param_num)
{
	return 0;
}

DREAL CGHMM::get_log_derivative(INT param_num, INT num_example)
{
	return 0;
}

DREAL CGHMM::get_log_likelihood_example(INT num_example)
{
	return 0;
}

