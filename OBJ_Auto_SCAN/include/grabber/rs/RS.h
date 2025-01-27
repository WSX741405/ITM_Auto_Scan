#ifndef  RS
#define RS

#include<pcl/io/ply_io.h>

#include "grabber/Grabber.h"
#include "grabber/rs/rsgrabber/real_sense_grabber.h"
#include "observer/IObserver.h"
#include <mutex>

class ISubject;

class Realsense : IGrabber
{
public:
	Realsense(ISubject* subject, std::string deviceId = "");
	~Realsense();
	void StartCamera();
	void StopCamera();
	void SetDepthConfidence(int depthConfidence);
	std::mutex& GetMutex();

private:
	void CloudCallback(boost::shared_ptr<const pcl::PointCloud<PointT>> cloud);

	std::mutex _mutex;
	boost::function<void(const boost::shared_ptr<const pcl::PointCloud<PointT>>&)> _function;
	boost::signals2::connection _connection;
	pcl::RealSenseGrabber* _grabber;
	ISubject* _subject;
};

#endif