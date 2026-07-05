#ifndef _PROS_ROBOT_CONFIG_H_
#define _PROS_ROBOT_CONFIG_H_
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/misc.h"
#include "pros/optical.hpp"
#include "distancereset.hpp"

// using namespace WallAngles;
// using namespace FeildWalls;
// using namespace HeadingOffsets;

//drivetrain stuff
extern pros::MotorGroup left_motor_group;
extern pros::MotorGroup right_motor_group;
extern lemlib::Chassis chassis;

//bot motors
extern pros::Motor motor1;
extern pros::Motor motor2;
extern pros::Motor motor3;
extern pros::Motor motor4;

// motor vision sensor if necessary will go here:



//distance sensors
// inline pros::Distance frontDs(12);
// inline pros::Distance leftDs(13);
// inline pros::Distance rightDs(14);

// //distance sensor objects
// inline DistanceSensor frontDistanceSensor(frontDs, 4.95, 4.75, HeadingOffsets::HeadingOffsetFront);
// inline DistanceSensor leftDistanceSensor(leftDs, 5.25, 3, HeadingOffsets::HeadingOffsetLeft);
// inline DistanceSensor rightDistanceSensor(rightDs, 5.25, 3, HeadingOffsets::HeadingOffsetRight);

#endif // _PROS_ROBOT_CONFIG_H_
