#ifndef RECONSTRUCT_FACTORY
#define RECONSTRUCT_FACTORY

#include "ReconstructProcessing.h"
#include "GreedyProjection.h"
#include "MarchingCubes.h"
#include "MyPoisson.h"
#include "ConcaveHull.h"

class ReconstructFactory
{
public:
	ReconstructFactory();
	ReconstructProcessing* GetGreedyProjection();
	ReconstructProcessing* GetMarchingCubes();
	ReconstructProcessing* GetPoisson();
	ReconstructProcessing* GetConcaveHull();

private:

};

#endif