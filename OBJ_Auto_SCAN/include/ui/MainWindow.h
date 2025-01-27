#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <pcl/keypoints/harris_3d.h>
#include "Typedef.h"

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <QtWidgets/QMainWindow>

#include <QMetaType>
Q_DECLARE_METATYPE(pcl::PointCloud<PointT>::Ptr);

#include <QVTKWidget.h>
#include<QMessageBox>
#include <QFileDialog>
#include<QInputDialog>
#include <QSpinBox>
#include <QCloseEvent>

#include <pcl/filters/filter.h>

#include "ui_MainWindow.h"
#include "ui/BoundingBoxTestDialog.h";
#include "ui/Viewer.h"
#include "observer/ObserverFactory.h"
#include "file/FileFactory.h"
#include "grabber/GrabberFactory.h"
#include "pointCloud/PointCloudElements.h"
#include "arduino/Arduino.h"
#include "Conversion.h"
#include "pointCloudProcessing/keypoint/KeypointFactory.h"
#include "pointCloudProcessing/filter/FilterFactory.h"
#include "pointCloudProcessing/correspondences/CorrespondencesFactory.h"
#include "pointCloudProcessing/regestration/RegestrationFactory.h"
#include "pointCloudProcessing/reconstruct/ReconstructFactory.h"
#include "pointCloudProcessing/smoothing/SmoothingFactory.h"
#include "kinfuApp/KinfuApp.h"
//#include "kinfuApp/KinfuLSApp.h"

class UIObserver;
class ISubject;
class SubjectFactory;
class IGrabber;
class GrabberFactory;
class Arduino;

class MainWindow : public QMainWindow
{
	Q_OBJECT
		int ARDUINO_SLEEP_TIME = 300;
	char* COM_PORT = "com4";
public:
	MainWindow(QWidget *parent = Q_NULLPTR);

signals:
	std::string ShowDialog(bool* ok, const char* title = "", const char* label = "", const char* text = "");

public slots:
	//****************************************************************
	//										UI
	//****************************************************************
	void UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr pointCloud);
	void TableItemChangeSlot(QTableWidgetItem* item);
	std::string ShowInputDialogSlot(bool* ok, const char* title = "", const char* label = "", const char* text = "");
	void GetDialogResultSlot(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	//****************************************************************
	//										File
	//****************************************************************
	void OpenFileSlot();
	void SaveFileSlot();
	//****************************************************************
	//										Viewer
	//****************************************************************
	void SetViewBackgroundToBlackSlot();
	void SetViewWhiteBackgroundToWhiteSlot();
	//****************************************************************
	//										Camera
	//****************************************************************
	void StartFlexxCameraSlot();
	void StartRSCameraSlot();
	void StartXtionProCameraSlot();
	void StopCameraSlot();
	void SetCameraDepthConfidenceSlot();
	//****************************************************************
	//										Arduino
	//****************************************************************
	void GetNumberOfBytesSlot();
	void GetCharSlot();
	void GetArraySlot();
	void ControlMotorSlot();
	//****************************************************************
	//										Point Cloud
	//****************************************************************
	void KeepOneFrameSlot();
	void KeepContinueFrameSlot();
	void KeepFrameArrivedSlot(pcl::PointCloud<PointT>::Ptr pointCloud);
	void RemoveSelectedPointCloudSlot();
	void RemoveAllPointCloudSlot();
	void SelectAllPointCloudSlot();
	void UnselectAllPointCloudSlot();
	void CombinePointCloudSlot();
	void GetMinNegativeNumberSlot();
	void ProcessICP1Slot();
	void ProcessICP2Slot();
	void ProcessICP3Slot();
	void ShiftPointCloudSlot();
	void MultiplicationPointCloudSlot();
	void RemoveNANSlot();
	//****************************************************************
	//										Keypoint
	//****************************************************************
	void ProcessKeypointSlot();
	void ChangeKeypointTabSlot(int index);
	void SetKeypointScalesSlot();
	void SetKeypointMinContrastSlot();
	void SetKeypointRadiusSlot();
	void SetKeypointRadiusSearchSlot();
	void SetKeypointMethodSlot(int index);
	//****************************************************************
	//										Filter
	//****************************************************************
	void ChangeFilterTabSlot(int index);
	void ProcessFilterSlot();
	void SetFilterVoxelGridXYZSlot();
	void SetFilterBoundingBoxSlot();
	void SetFilterMeanKSlot(int meanK);
	void SetFilterStddevMulThreshSlot(double stddevMulThresh);
	void TestBoundingBoxSlot();
	//****************************************************************
	//										Correspondences
	//****************************************************************
	void ChangeCorrespondencesTabSlot(int index);
	void ProcessCorrespondencesSlot();
	void SetCorrespondenceDescriptorRadiusSlot(double descriptorRadius);
	void SetCorrespondenceDescriptorKSearchSpinBoxSlot(int kSearch);
	void SetCorrespondenceNormalRadiusSlot(double normalRadius);
	void SetCorrespondencesKSlot(int correspondencesK);
	void SetRejectorInlierThresholdSlot(double rejectorInlierThreshold);
	//****************************************************************
	//										Regestration
	//****************************************************************
	void ProcessRegestrationSlot();
	void SetRegestrationCorrespondenceDistanceSlot(double correspondenceDistance);
	void SetRegestrationOutlierThresholdSlot(double outlierThreshold);
	void SetEuclideanFitnessEpsilonSlot(double euclideanFitnessEpsilon);
	void SetRegestrationMaxIterationsSlot(int maxIterations);
	//****************************************************************
	//										Reconstruct
	//****************************************************************
	void ChangeReconstructTabSlot(int index);
	void ProcessReconstructSlot();
	void SetReconstructSearchRadiusSlot(double searchRadius);
	void SetReconstructMuSlot(double mu);
	void SetReconstructMaxNearestNeighborsSlot(int maxNearestNeighbors);
	void SetReconstructMaxSurfaceAngleSlot(int maxSurfaceAngle);
	void SetReconstructMinAngleSlot(int minAngle);
	void SetReconstructMaxAngleSlot(int maxAngle);
	void SetReconstructGridResolutionXYZSlot();
	void SetReconstructIsoLevelSlot(double isoLevel);
	void SetReconstructNormalSearchRadiusSlot(double normalSearchRadius);
	void SetReconstructDepthSlot(int);
	void SetReconstructAlphaSlot(double);
	//****************************************************************
	//										Smoothing
	//****************************************************************
	void ChangeSmoothingTabSlot(int index);
	void ProcessSmoothingSlot();
	void SetSmoothingNumIterSlot(int numIter);
	void SetSmoothingConvergenceSlot(double convergence);
	void SetSmoothingRelaxationFactorMaxAngleSlot(double relaxationFactor);
	void SetSmoothingFeatureAngleSlot(int featureAngle);
	void SetSmoothingSearchRadiusSlot(double searchRadius);
	//****************************************************************
	//										Kinect Fusion
	//****************************************************************
	void ProcessKinfuTestBoundingBoxSlot();
	void GetKinfuTestBoundingBoxSlot();
	void ProcessSegmentedKinfuCloudSlot();
	void ProcessIgnoreResetKinfuCloudSlot();
	void SaveRTMatrix(std::vector<Eigen::Matrix<float, 3, 3, Eigen::RowMajor>> r, std::vector<Eigen::Vector3f> t);

private:
	void InitialMemberVariable();
	void InitialConnectSlots();
	void InitialPointCloudViewer();
	void InitialPointCloudTable();
	void InitialTabWidget();
	void UpdatePointCloudViewer();
	void UpdatePointCloudTable();
	void RegisterObserver();
	void closeEvent(QCloseEvent *event);
	void OpenFile(std::string dir, std::string filter);
	void SaveFile(std::string dir, std::string filter);

	Viewer* _viewer;
	UIObserver* _uiObserver;
	FileFactory* _fileFactory;
	GrabberFactory* _grabberFactory;
	IGrabber* _grabber;
	SubjectFactory* _subjectFactory;
	int _keepFrameNumber;
	std::string _keepCloudName;
	pcl::PointCloud<PointT>::Ptr _tmpPointCloud;
	pcl::PointCloud<PointT>::Ptr _boundingBoxPointCloud;
	PointCloudElements* _elements;
	Arduino* _arduino;
	Ui::MainWindowForm* _ui;

	KeypointFactory* _keypointFactory;
	KeypointProcessing* _keypointProcessing;
	FilterFactory* _filterFactory;
	FilterProcessing* _filterProcessing;
	CorrespondencesFactory* _correspondencesFactory;
	CorrespondencesProcessing* _correspondencesProcessing;
	RegestrationFactory* _regestrationFactory;
	RegestrationProcessing* _regestrationProcessing;
	ReconstructFactory* _reconstructFactory;
	ReconstructProcessing* _reconstructProcessing;
	SmoothingFactory* _smoothingFactory;
	SmoothingProcessing* _smoothingProcessing;

	BoundingBoxTestDialog* _dialog;

	const double FRAME_PITCH = 0.3;	//	(sec)
	clock_t _preFrameTime;

	//		Kinfu
	bool _isTestedKinfuBoundingBox;
};

#endif