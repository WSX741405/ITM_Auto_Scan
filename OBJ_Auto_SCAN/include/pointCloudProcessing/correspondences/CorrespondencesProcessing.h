#ifndef CORRESPONDENCES_PROCESSING
#define CORRESPONDENCES_PROCESSING

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/correspondence_rejection_sample_consensus.h>

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZI KeypointT;

class CorrespondencesProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts) = 0;
	virtual void SetDescriptorRadius(float descriptorRadiusSearch) = 0;
	virtual void SetNormalRadius(float normalRadiusSearch) = 0;
	virtual void SetCorrespondencesK(float correspondencesK) = 0;
	virtual void SetRejectorInlierThreshold(float rejectorInlierThreshold) = 0;
	virtual void SetDescriptorKSearch(int kSearch) = 0;
	virtual pcl::CorrespondencesPtr GetCorrespondencesResult() = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetResult() = 0;
private:

};

#endif