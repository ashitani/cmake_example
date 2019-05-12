#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>

#include "Open3D/Open3D.h"

using namespace open3d;
using namespace std;

using Eigen::Vector3d;

static vector<Vector3d> vv;
static float t_start;
static auto cloud_ptr = make_shared<geometry::PointCloud>();
 
void step(){
  Vector3d v;
  vv.clear();

  for (int t = 0; t < 2000; t++)
  {
    float T = t_start + t;
    v(2) = (float)t * 0.1;
    v(0) = -10 * sin(T / 1000.0 * 5 * M_PI);
    v(1) =  10 * cos(T/ 1000.0 * 5 * M_PI);
    vv.push_back(v);
  }
  t_start += 50;
  cloud_ptr->points_ = vv;
}


int main()
{

  t_start = 0;
  step();

  visualization::DrawGeometriesWithAnimationCallback(
      {cloud_ptr},
      [&](visualization::Visualizer *vis) {
        step();
        vis->UpdateGeometry();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return false;
      },
      "CloudAnim", 640, 480);
}
