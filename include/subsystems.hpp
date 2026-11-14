#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples


inline pros::MotorGroup lift({8, -9}); // moonshot type lift
inline pros::MotorGroup intake({10, -11}); // something about pins
// inline pros::Rotation toggleRotation(12);
inline pros::Motor rollerToggles(16);
inline pros::Motor wrist(13); // flips the pin from the intake onto the claw
inline pros::Rotation wristRotation(14);
inline pros::Motor claw(17); // its a claw
