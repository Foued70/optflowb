#ifndef MULTIGRID_H_
#define MULTIGRID_H_

#include "FAS.h"
//maximal number of multigrid iterations
#define MAX_ITERATIONS 1
//maximal number of multigrid levels
#define MAX_LEVELS 2
#define DEFECT_FACTOR 10
#define V_CYCLE 1
#define W_CYCLE 2
//tested on w=1, cycleType = V_CYCLE, preIterations=1 , postIterations=1
vector<float> * multigrid(vector<float>* (*solver)(SparseMat<float> *A, vector<float> *X,vector<float> *B, float w, int numOfIterations),
				SparseMat<float>& A, vector<float>& B,float w,vector<float>& X,
				int preIterations,int postIterations,int cycleType);
int getMULTIGRIDIterations();
#endif /*MULTIGRID_H_*/