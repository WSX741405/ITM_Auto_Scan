#ifndef FILTER_FACTORY
#define FILTER_FACTORY

#include "FilterProcessing.h"
#include "VoxelGridFilter.h"
#include "BoundingBoxFilter.h"
#include "OutlierRemovalFilter.h"
#include "DepthImageBoundingBoxFilter.h"

class FilterFactory
{
public:
	FilterFactory();
	FilterProcessing* GetVoixelGridFilter();
	FilterProcessing* GetBoundingBoxFilter();
	FilterProcessing* GetOutlierRemovalFilter();
	FilterProcessing* GetDepthImageBoundingBoxFilter();

private:

};

#endif