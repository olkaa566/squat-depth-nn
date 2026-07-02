#include "biomechanics.hpp"
#include <cmath>

// ax, ay = Hip 
// bx, by = Knee
float calculate_joint_angle(float ax, float ay, float bx, float by) {
    float cx = bx;
    float cy = by + 1.0f;

    float v_hip_x = ax - bx;
    float v_hip_y = ay - by;

    float v_bottom_x = cx - bx; 
    float v_bottom_y = cy - by;

    float mag_hip = std::sqrt((v_hip_x * v_hip_x) + (v_hip_y * v_hip_y));
    float mag_bottom = std::sqrt((v_bottom_x * v_bottom_x) + (v_bottom_y * v_bottom_y));

    float dot_product = (v_hip_x * v_bottom_x) + (v_hip_y * v_bottom_y);
    float cos_angle = dot_product / (mag_hip * mag_bottom);
    
    if (cos_angle > 1.0f) {
        cos_angle = 1.0f;
    }

    if (cos_angle < -1.0f) {
        cos_angle = -1.0f;
    }

    float angle_radians = std::acoshl(cos_angle);
    float angle_degrees = angle_radians * (180.0f / 3.14159265f);

    return angle_degrees;
}