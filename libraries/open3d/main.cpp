#include <iostream>

#include "Open3D/Open3D.h"

using namespace open3d;
using namespace std;

int main()
{

  string filename = "../../../data/torus.ply";

  auto cloud_ptr = make_shared<geometry::PointCloud>();

  if (!io::ReadPointCloud(filename, *cloud_ptr))
  {
    cout << "Failed to read " << filename << endl;
    return 1;
  }
 
  visualization::DrawGeometries({cloud_ptr}, "Cloud", 640,480);

}
