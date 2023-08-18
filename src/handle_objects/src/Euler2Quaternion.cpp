#include "handle_objects/Euler2Quaternion.h"

double Euler2Quaternion::getQua_x(void)
{
	return value_getQua_x;
}
double Euler2Quaternion::getQua_y(void)
{
	return value_getQua_y;
}
double Euler2Quaternion::getQua_z(void)
{
	return value_getQua_z;
}
// 成员函数定义
double Euler2Quaternion::getQua_w(void)
{
	return value_getQua_w;
}


Euler2Quaternion::Euler2Quaternion(double X, double Y, double Z)
{
	roll_deg = X*180/PI;
	pitch_deg = Y*180/PI;
	yaw_deg = Z*180/PI;
	
	// EulerXYZ();
	
	// value_getQua_x = cos(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2) + sin(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2);
	// value_getQua_y = cos(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2) - sin(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2);
	// value_getQua_z = sin(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2) + cos(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2);
	// value_getQua_w = cos(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2) - sin(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2);
}

void Euler2Quaternion::EulerXYZ(void)
{
	value_getQua_x = cos(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2) + sin(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2);
	value_getQua_y = cos(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2) - sin(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2);
	value_getQua_z = sin(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2) + cos(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2);
	value_getQua_w = cos(yaw_deg*PI/180.0/2)*cos(pitch_deg*PI/180.0/2)*cos(roll_deg*PI/180.0/2) - sin(yaw_deg*PI/180.0/2)*sin(pitch_deg*PI/180.0/2)*sin(roll_deg*PI/180.0/2);
}

void Euler2Quaternion::change_XYZ(double new_X, double new_Y, double new_Z)
{
	roll_deg = new_X*180/PI;
	pitch_deg = new_Y*180/PI;
	yaw_deg = new_Z*180/PI;
}
