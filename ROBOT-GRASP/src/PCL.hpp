/*
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <string>
#include <pxcprojection.h>
*/

/************************************************************************/
/* namespace std                                                        */
/************************************************************************/
#include "Common.hpp"

/************************************************************************/
/* namespace pcl                                                        */
/************************************************************************/
#include <Eigen/Core>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
using Eigen::Matrix4f;

/************************************************************************/
/* Typedef                                                              */
/************************************************************************/
typedef pcl::PointNormal PointNT;
typedef pcl::PointCloud<PointNT> PointCloudNT;
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

/************************************************************************/
/* Load model and mesh                                                  */
/************************************************************************/
bool  LoadModel(const string model_path, PointCloudT::Ptr &model); //XYZ
bool  LoadModel(const string model_path, PointCloudNT::Ptr &model); //Normal

/************************************************************************/
/* Downsample model point cloud                                         */
/************************************************************************/
void Downsample(PointCloudNT::Ptr &model, float leaf);

/************************************************************************/
/* Estimate FPFH features                                               */
/************************************************************************/
//void EstimateFPFH(PointCloudNT::Ptr &model, FeatureCloudT::Ptr &model_features, float leaf);

/************************************************************************/
/* Output Transformation Matrix                                         */
/************************************************************************/
void print4x4Matrix(const Matrix4f & matrix);

/************************************************************************/
/* Registration with RANSAC and ICP                                     */
/************************************************************************/
/**
*  @brief Registration: register model and mesh with RANSAC+ICP, out Transformation matrix
*  @param model        input 3D points cloud
*  @param mesh         generated by Depth camera and convert to Point Cloud Normal Point
*  @param model_align  output aligned model, which used to reflect to 2D
*  @param leaf		   downsample param
*  @param showGraphic  show graphic result or not
*/
Matrix4f Registration(	PointCloudNT::Ptr &model,
						PointCloudNT::Ptr &mesh,
						PointCloudNT::Ptr &model_align,
						float leaf = 0.01f,
						bool showGraphic = true	);














/*
// Types
typedef pcl::PointNormal PointNT;
typedef pcl::PointCloud<PointNT> PointCloudNT;
typedef pcl::FPFHSignature33 FeatureT;
typedef pcl::PointCloud<FeatureT> FeatureCloudT;

// Align a rigid object to a scene with clutter and occlusions
int pointCloudAlignment(PointCloudNT::Ptr &object, FeatureCloudT::Ptr &object_features,
						PointCloudNT::Ptr &scene, FeatureCloudT::Ptr &scene_features,
						PointCloudNT::Ptr &grasp,
						std::vector<PXCPoint3DF32>& result,
						float leaf, float MaxCorrespondenceDistance, float SimilarityThreshold);

int pointCloudFromRealsense(PointCloudNT::Ptr &scene);

int loadModel(std::string &model_path, PointCloudNT::Ptr &object, FeatureCloudT::Ptr &object_features, float leaf);

int preprocessScene(PointCloudNT::Ptr &scene, FeatureCloudT::Ptr &scene_features, float leaf);

int loadGrasp(std::string &model_path, PointCloudNT::Ptr &grasp);

*/