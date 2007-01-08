/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2007 Soeren Sonnenburg
 * Copyright (C) 1999-2007 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "lib/common.h"
#include "lib/io.h"
#include "kernel/SparseNormSquaredKernel.h"
#include "features/Features.h"
#include "features/SparseFeatures.h"

CSparseNormSquaredKernel::CSparseNormSquaredKernel(INT size)
  : CSparseKernel<DREAL>(size)
{
}

CSparseNormSquaredKernel::~CSparseNormSquaredKernel() 
{
	cleanup();
}
  
bool CSparseNormSquaredKernel::init(CFeatures* l, CFeatures* r, bool do_init)
{
	CSparseKernel<DREAL>::init(l, r, do_init); 

	return true;
}

void CSparseNormSquaredKernel::cleanup()
{
}

bool CSparseNormSquaredKernel::load_init(FILE* src)
{
	return false;
}

bool CSparseNormSquaredKernel::save_init(FILE* dest)
{
	return false;
}
  
DREAL CSparseNormSquaredKernel::compute(INT idx_a, INT idx_b)
{
  INT alen, blen;
  bool afree, bfree;

  TSparseEntry<DREAL>* avec=((CSparseFeatures<DREAL>*) lhs)->get_sparse_feature_vector(idx_a, alen, afree);
  TSparseEntry<DREAL>* bvec=((CSparseFeatures<DREAL>*) rhs)->get_sparse_feature_vector(idx_b, blen, bfree);
  
  DREAL result=0;

  INT i,j;

  for (i=0; i<alen; i++)
	  result+= avec[i].entry * avec[i].entry;

  for (i=0; i<blen; i++)
	  result+= bvec[i].entry * bvec[i].entry;


  if (alen<=blen)
  {
	  j=0;
	  for (i=0; i<alen; i++)
	  {
		  INT a_feat_idx=avec[i].feat_index;

		  while ( (j<blen) && (bvec[j].feat_index < a_feat_idx) )
			  j++;

		  if ( (j<blen) && (bvec[j].feat_index == a_feat_idx) )
		  {
			  result-= 2*(avec[i].entry*bvec[j].entry);
			  j++;
		  }
	  }
  }
  else
  {
	  j=0;
	  for (i=0; i<blen; i++)
	  {
		  INT b_feat_idx=bvec[i].feat_index;

		  while ( (j<alen) && (avec[j].feat_index < b_feat_idx) )
			  j++;

		  if ( (j<alen) && (avec[j].feat_index == b_feat_idx) )
		  {
			  result-= 2*(bvec[i].entry*avec[j].entry);
			  j++;
		  }
	  }
  }

  ((CSparseFeatures<DREAL>*) lhs)->free_feature_vector(avec, idx_a, afree);
  ((CSparseFeatures<DREAL>*) rhs)->free_feature_vector(bvec, idx_b, bfree);

  return result;
}
