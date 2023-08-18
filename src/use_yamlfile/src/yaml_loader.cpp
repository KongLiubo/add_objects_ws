#include <ros/ros.h>
#include <ros/package.h>
#include <yaml-cpp/yaml.h>

#include<fstream> 

int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "param_saver");
    ros::NodeHandle nh;

    // 定义要保存的参数
    int my_param1 = 42;
    std::string my_param2 = "hello";

    // 创建YAML节点
    YAML::Node yaml_node;
    yaml_node["my_param1"] = my_param1;
    yaml_node["my_param2"] = my_param2;

    // 获取保存文件的路径
    std::string package_path = ros::package::getPath("use_yamlfile");
    std::string file_path = package_path + "/config/params.yaml";

    // 将YAML节点保存到文件
    std::ofstream file(file_path);
    if (file)
    {
        file << yaml_node;
        ROS_INFO("Parameters saved to %s", file_path.c_str());
    }
    else
    {
        ROS_ERROR("Failed to save parameters.");
    }

    return 0;
}