#include <ros/ros.h>
#include <yaml-cpp/yaml.h>
#include <ros/package.h>


int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "param_loader");
    ros::NodeHandle nh;

    // 获取YAML文件的路径
    std::string package_path = ros::package::getPath("use_yamlfile");
    std::string file_path = package_path + "/config/params.yaml";

    
    // 加载YAML文件
    YAML::Node yaml_node = YAML::LoadFile(file_path);
    
    // 在文件中查找指定的键，并获取其值
    int my_param1 = yaml_node["my_param1"].as<int>();
    std::string my_param2 = yaml_node["my_param2"].as<std::string>();
    
    // 在这里可以使用参数的值进行其他操作
    ROS_INFO("my_param1: %d", my_param1);
    ROS_INFO("my_param2: %s", my_param2.c_str());

    return 0;
}