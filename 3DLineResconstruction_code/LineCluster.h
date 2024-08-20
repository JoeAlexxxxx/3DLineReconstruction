//
//  LineCluster.h
//  line cluster
//
//  Created by Alexxxxx on 2024/7/14.
//
#ifndef LINECLUSTER_PROGRAM
#define LINECLUSTER_PROGRAM

#include <iostream>
#include <filesystem>
#include <fstream>
#include <istream>
#include <random>

#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <boost/filesystem.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/math/distributions.hpp>
#include <boost/math/distributions/normal.hpp>
#include <nlopt.hpp>

#include "Triangulate3Dlines.h"
#include "nfa.h"
#include "LineSweep.h"

void lineCluster(SfMManager* sfm, MergeProcess* mergeProc, std::string inputFolder);

#endif // !LINECLUSTER_PROGRAM