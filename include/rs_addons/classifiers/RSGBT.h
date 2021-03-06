//developed by: Rakib

#ifndef RSGBT_HEADER
#define RSGBT_HEADER

#include <iostream>
#include <string>

#include<ros/package.h>
#include<boost/filesystem.hpp>

#if CV_MAJOR_VERSION == 2
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#elif CV_MAJOR_VERSION == 3
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/ml.hpp>
#endif

#include <rs_addons/classifiers/RSClassifier.h>

class RSGBT : public RSClassifier
{

public:

  RSGBT();

  void trainModel(std::string train_matrix_name, std::string train_label_name, std::string trained_file_name);

  void classify(std::string trained_file_name,std::string test_matrix_name, std::string test_label_name,std::string obj_classInDouble);

  void classifyOnLiveData(std::string trained_file_name_saved, cv::Mat test_mat, double &det,double &confi);

  void RsAnnotation (uima::CAS &tcas, std::string class_name, std::string feature_name, std::string database_name, rs::Cluster &cluster, std::string set_mode, double &confi);

  ~ RSGBT();
};

#endif
