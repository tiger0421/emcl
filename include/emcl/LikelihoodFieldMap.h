/*
 *  Copyright (c) 2021, Ryuichi Ueda
 *
 *  All rights reserved.
 *  Some lines are derived from https://github.com/ros-planning/navigation/tree/noetic-devel/amcl. 
 *  So this software is provided under the terms of the GNU Lesser General Public License (LGPL).
 */

#ifndef OCC_GRID_MAP_H__
#define OCC_GRID_MAP_H__

#include <vector>
#include <utility>
#include "emcl/Scan.h"
#include "emcl/Pose.h"
#include "nav_msgs/OccupancyGrid.h"

namespace emcl {

using namespace std;

class LikelihoodFieldMap
{
public: 
	LikelihoodFieldMap(const nav_msgs::OccupancyGrid &map, double likelihood_range);
	~LikelihoodFieldMap();

	void setLikelihood(int x, int y, double range);
	double likelihood(double x, double y);

	vector<double *> likelihoods_;
	int width_;
	int height_;

	double resolution_;
	double origin_x_;
	double origin_y_;

	void drawFreePoses(int num, vector<Pose> &result);
private:
	vector<pair<int, int> > free_cells_;

	void normalize(void);
};

}

#endif

