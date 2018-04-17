#ifndef RECONSTRUCT_PROCESSING
#define RECONSTRUCT_PROCESSING

#include "Typedef.h"
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>

class ReconstructProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PolygonMeshPtr GetResult() = 0;
	virtual void SetSearchRadius(double searchRadius) = 0;
	virtual void SetMu(double mu) = 0;
	virtual void SetMaxNearestNeighbors(int maxNearestNeighbors)= 0;
	virtual void SetMaxSurfaceAngle(double maxSurfaceAngle) = 0;
	virtual void SetMinAngle(double minAngle) = 0;
	virtual void SetMaxAngle(double maxAngle) = 0;
	virtual void SetGridResolution(int gridResolutionX, int gridResolutionY, int gridResolutionZ) = 0;
	virtual void SetIsoLevel(float isoLevel) = 0;
	virtual void SetNormalSearchRadius(double normalSearchRadius) = 0;
	virtual void SetReconstructDepth(int depth) = 0;

private:

};

#endif