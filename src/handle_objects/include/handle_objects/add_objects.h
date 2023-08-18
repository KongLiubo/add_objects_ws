#pragma once

#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "string"

#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_messages.h"
#include <geometric_shapes/shape_operations.h>


#include "moveit/move_group_interface/move_group_interface.h"
#include "moveit/planning_scene_interface/planning_scene_interface.h"

#include "handle_objects/Euler2Quaternion.h"


class AddObjects
{
    public:
        AddObjects(std::string robot_str);
        bool add_meshObject(std::string name, std::string mesh_address);
        bool remove_Object(std::string name);

    
    private:
        moveit::planning_interface::MoveGroupInterface arm;
		ros::NodeHandle nh;
        ros::Publisher planning_scene_diff_publisher;
        std::string mesh_address;



};
