#include "main.h"

static constexpr double MAX_MV = 12000.0; // move_voltage limit (millivolts)
int target = 0;

static int lastWristPos = 0;

void flipperLoop() {
    
    const double kp = 3;
    const double kd = 15;

    int pos = wristRotation.get_position();
    if (pos == PROS_ERR) return;

    double error = target - pos;
    double velocity = pos - lastWristPos;
    lastWristPos = pos;

    double output = (kp * error) - (kd * velocity);
    output = std::clamp(output, -MAX_MV, MAX_MV);

    wrist.move_voltage(static_cast<int32_t>(output));
}

void setTarget(int degrees) {
    target = degrees * 100;
}

bool flipped = false;
void wristFlip() {
    if (bool flipped = false) {
    setTarget(100);
    } else if (bool flipped = true) {
    setTarget(0);
    }
}

void flipUnflip() {
    setTarget(100);
    pros::delay(300);
    setTarget(0);
}

