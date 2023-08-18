#pragma once

#include <iostream>
#include <cmath>
 
using namespace std;
 
#define PI 3.14
 
class Euler2Quaternion
{
   public:
   Euler2Quaternion(double X, double Y, double Z);

   void EulerXYZ(void);
   void change_XYZ(double new_X, double new_Y, double new_Z);
   // 成员函数声明
    double getQua_x(void);
    double getQua_y(void);
    double getQua_z(void);
    double getQua_w(void);

   private:
      // X Y Z -3.14~3.14
      // 偏航 Z
	   double yaw_deg; 
      // 俯仰角 Y
 	   double pitch_deg;
      // 翻滚 X
      double roll_deg;
      // 四元数
      double value_getQua_x;
      double value_getQua_y;
      double value_getQua_z;
      double value_getQua_w;

};
 
 
 