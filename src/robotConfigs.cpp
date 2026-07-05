#include "main.h"
#include "robotConfigs.h"

// left motor group (put in ports for new robot)
pros::MotorGroup left_motor_group({1, 2}, pros::MotorGears::green);
// right motor group (put in ports for new robot)
pros::MotorGroup right_motor_group({3, 4}, pros::MotorGears::green);


pros::Motor motor1(5, pros::MotorGears::green); // put in port 
pros::Motor motor2(6, pros::MotorGears::green); // put in port 
pros::Motor motor3(7, pros::MotorGears::green); // put in port 
pros::Motor motor4(8, pros::MotorGears::green); // put in port 


// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              10, // 10 inch track width (this is the distance between the left and right wheels, not the distance between the centers of the wheels)
                              lemlib::Omniwheel::NEW_4, // using new 4
                              333.33, // drivetrain rpm is 333.33 rpm
                              2 // horizontal drift is 2 (for now)
);


// odometry settings
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            nullptr // inertial sensor
);

//tuning constants for chassis
// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              47, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              7, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              2                                     // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP) 
                                              0.01, // integral gain (kI)
                                              17, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

