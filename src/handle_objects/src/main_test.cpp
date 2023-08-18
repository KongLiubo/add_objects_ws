#include "ros/ros.h"
#include "handle_objects/add_objects.h"

int main(int argc, char *argv[])
{
    /* code */
	ROS_INFO("Starting add objects node ");
	ros::init(argc, argv, "add_objects_node");
    AddObjects addObjects("panda_arm");

    std::string mesh_address = "package://handle_objects/collision_objects/robotiq_fts150.stl";

    addObjects.add_meshObject("shelf", mesh_address);

    // ros::spin();
    ros::Rate rate(1);

    rate.sleep();

    return 0;
}
