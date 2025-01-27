#ifndef MY_PFHRGB
#define MY_PFHRGB

#include "Typedef.h"
#include <pcl/features/normal_3d.h>
#include <pcl/features/pfhrgb.h>
#include <pcl/registration/correspondence_rejection_sample_consensus.h>
#include <pcl/registration/icp.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/filters/filter.h>

#include "CorrespondencesProcessing.h"

class MyPFHRGB : public CorrespondencesProcessing
{
public:
	MyPFHRGB();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts);
	void SetDescriptorRadius(float descriptorRadiusSearch);
	void SetNormalRadius(float normalRadiusSearch);
	void SetCorrespondencesK(float correspondencesK);
	void SetRejectorInlierThreshold(float rejectorInlierThreshold);
	void SetDescriptorKSearch(int kSearch);
	pcl::CorrespondencesPtr GetCorrespondencesResult();
	pcl::PointCloud<PointT>::Ptr GetResult();

private:
	pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr ProessingDescriptor(pcl::PointCloud<PointT>::Ptr cloud, pcl::PointCloud<KeypointT>::Ptr keypoints);
	std::vector<int> ProcessingCorrespondences(pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr source, pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr target);
	pcl::CorrespondencesPtr ProcessingFilterCorrespondences(pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, std::vector<int> source2Target, std::vector<int> target2Source);
	void DetermineInitialTransformation(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, pcl::CorrespondencesPtr correspondences);

	pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr _sourceDescriptor;
	pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr _targetDescriptor;
	pcl::PointCloud<PointT>::Ptr _transformedSource;
	pcl::CorrespondencesPtr _correspondencesResult;

	int _kSearch;
	float _normalRadiusSearch;
	int _correspondencesK;
	float _rejectorInlierThreshold;
};

#endif