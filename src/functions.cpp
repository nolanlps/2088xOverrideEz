#include "main.h"

static constexpr double MAX_MV = 5000.0; // move_voltage limit (millivolts)
int target = 0;

static int lastWristPos = 0;

void flipperLoop() {
    
    const double kp = 20;
    const double kd = 5;

    int pos = wrist.get_position();
    if (pos == PROS_ERR) return;

    double error = target - pos;
    double velocity = pos - lastWristPos;
    lastWristPos = pos;

    double output = (kp * error) - (kd * velocity);
    output = std::clamp(output, -MAX_MV, MAX_MV);

    wrist.move_voltage(static_cast<int32_t>(output));
}

void setTarget(int degrees) {
    target = degrees * 10;
}

bool flipped = false;
void wristFlip() {
    if (!flipped) {
    setTarget(34);
    flipped = !flipped;
    } else if (flipped) {
    setTarget(0);
    flipped = !flipped;
    }
}

void flipUnflip() {
    setTarget(80);
    pros::delay(300);
    setTarget(0);
}

