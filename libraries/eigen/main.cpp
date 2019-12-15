#include <iostream>
#include <Eigen/Dense>
#include <vector>
using Eigen::MatrixXd;
using Eigen::Vector3d;
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;

 Vector3d v(0,0,0);

 std::vector<Vector3d> vv;

 for(int i=0;i<10;i++){
    v(0)=i;
    vv.push_back(v);
 }

    for(int i=0;i<10;i++){
     std::cout << i << ":" << vv[i] << std::endl;
    }
}