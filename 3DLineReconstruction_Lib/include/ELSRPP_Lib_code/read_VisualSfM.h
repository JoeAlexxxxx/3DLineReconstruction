#ifndef  READ_VSFM__H
#define  READ_VSFM__H



#include <boost/filesystem.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include "IO.h"
#include "SfMManager.h"
#include "MatchManager.h"

int read_VisualSfM(
	SfMManager* sfm,
	MatchManager* match,
	int knn_image,
	int connectionNum,
	bool fromcolmap);
#endif // ! READ_VSFM__H