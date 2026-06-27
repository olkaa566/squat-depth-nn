#include "biomechanics.hpp"
#include <cmath>

// Calculates the angle at joint B given three points (A, B, C)
// cos(theta) = (BA · BC) / (|BA| * |BC|)
float calculate_joint_angle(float ax, float ay, float bx, float by, float cx, float cy) {
    float ba_x = ax - bx;
    float ba_y = ay - by;
    float bc_x = cx - bx;
    float bc_y = cy - by;

    float dot_prod = (ba_x * bc_x) + (ba_y * bc_y);
    float mag_ba = std::sqrt(ba_x * ba_x + ba_y * ba_y);
    float mag_bc = std::sqrt(bc_x * bc_x + bc_y * bc_y);

    if (mag_ba * mag_bc == 0.0f) {
        return 0.0f;
    } 

    float angle_rad = std::acos(dot_prod / (mag_ba * mag_bc));
    float angle_deg = angle_rad * (180.0f / 3.14159265358979323846f);

    return angle_deg;
}