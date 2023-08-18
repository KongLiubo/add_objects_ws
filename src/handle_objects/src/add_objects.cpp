#include "handle_objects/add_objects.h"
#include "tf2/LinearMath/Quaternion.h"


AddObjects::AddObjects(std::string robot_str) : arm("panda_arm")
{
	ros::NodeHandle nh;

	planning_scene_diff_publisher = nh.advertise<moveit_msgs::PlanningScene>("planning_scene", 1);
	while(planning_scene_diff_publisher.getNumSubscribers() < 1)
	{
	  ros::WallDuration sleep_t(0.5);
	  sleep_t.sleep();
	}

}


bool AddObjects::add_meshObject(std::string name, std::string mesh_address) 
{
    // 放置障碍物信息
    moveit_msgs::CollisionObject collision_object;
	collision_object.header.frame_id = arm.getPlanningFrame();
    ROS_INFO("%s",mesh_address.c_str());

    /*-------编辑障碍物信息--------*/
    // 设置名称
    collision_object.id = name;
    
    // mesh文件的信息来源
	shapes::Mesh* m = shapes::createMeshFromResource(mesh_address);
	shape_msgs::Mesh self_mesh;
	shapes::ShapeMsg self_mesh_msg;
	shapes::constructMsgFromShape(m,self_mesh_msg);
	self_mesh = boost::get<shape_msgs::Mesh>(self_mesh_msg);

    // 设置放置物体的姿态信息
	geometry_msgs::Pose self_mesh_pose;
	
	// tf2::Quaternion qtn;
	// // 相对于参考坐标（固定角）
	// qtn.setRPY(1.3, 2.2, 2.9);
    // self_mesh_pose.orientation.x = qtn.getX();
    // self_mesh_pose.orientation.y = qtn.getY();
    // self_mesh_pose.orientation.z = qtn.getZ();
    // self_mesh_pose.orientation.w = qtn.getW();

	// 姿态信息XYZ
	Euler2Quaternion myEuler2Quaternion(1.15, -1.23, 2.81);
	myEuler2Quaternion.change_XYZ(2, 2.1, 1.8);
	myEuler2Quaternion.EulerXYZ();
    self_mesh_pose.orientation.x = myEuler2Quaternion.getQua_x();
    self_mesh_pose.orientation.y = myEuler2Quaternion.getQua_y();
    self_mesh_pose.orientation.z = myEuler2Quaternion.getQua_z();
    self_mesh_pose.orientation.w = myEuler2Quaternion.getQua_w();

	// 位置信息
	self_mesh_pose.position.x =  1.0;
	self_mesh_pose.position.y =  0.0;
	self_mesh_pose.position.z =  0.1;

	ROS_INFO("klb: %f, %f, %f, %f", self_mesh_pose.orientation.x,
								    self_mesh_pose.orientation.y,
								    self_mesh_pose.orientation.z,
								    self_mesh_pose.orientation.w);
	collision_object.meshes.push_back(self_mesh);
	collision_object.mesh_poses.push_back(self_mesh_pose);
	collision_object.operation = collision_object.ADD;

	ROS_INFO("Add an self-mesh into the world");

	moveit_msgs::PlanningScene planning_scene;
	planning_scene.world.collision_objects.push_back(collision_object);
	planning_scene.is_diff = true;
	planning_scene_diff_publisher.publish(planning_scene);
    
    return true;
}

