#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/common/io.h>
#include <pcl/io/pcd_io.h>


using namespace pcl;
using namespace std;


int main(int argc, char** argv)
{

     // Load the actual pointcloud.
    pcl::PointCloud<pcl::PointXYZI>::Ptr ptcloud (new pcl::PointCloud<pcl::PointXYZI>);

    const size_t kMaxNumberOfPoints = 1e6;  // From Readme for raw files.
    ptcloud->clear();
    ptcloud->reserve(kMaxNumberOfPoints);

    std::string filename = "001468.bin";

    std::ifstream input(filename, std::ios::in | std::ios::binary);
    if (!input) {
        std::cout << "Could not open pointcloud file.\n";
        return false;
    }

    for (size_t i = 0; input.good() && !input.eof(); i++) {
        pcl::PointXYZI point;
        input.read((char*)&point.x, 3 * sizeof(float));
        input.read((char*)&point.intensity, sizeof(float));
        ptcloud->push_back(point);
    }
    input.close();

    // pcl::PCDWriter writer;
    // writer.write<pcl::PointXYZI> ("test.pcd", *ptcloud, false);

    pcl::io::savePCDFileASCII ("001468.pcd", *ptcloud);
    std::cerr << "Saved " << ptcloud->points.size () << " data points to test_pcd.pcd." << std::endl;


    return 0;

}
