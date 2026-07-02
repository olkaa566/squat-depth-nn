#include "matrix.hpp"
#include "geometry.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Error: Expected 4 coordinates, but got " << (argc - 1) << endl;
        return -1;
    }

    float hip_x   = stof(argv[1]);
    float hip_y   = stof(argv[2]);
    float knee_x  = stof(argv[3]);
    float knee_y  = stof(argv[4]);

    float angle = calculate_knee_angle(hip_x, hip_y, knee_x, knee_y);

    cout << "\nANALYSIS" << endl;
    cout << "Knee Angle: " << angle << " degrees" << endl;

    if (angle < 85.0f) {
        cout << "Depth: EXCELLENT!" << endl;
    } 

    else if (angle <= 95.0f) {
        cout << "Depth: GOOD! Parallel." << endl;
    } 

    else {
        cout << "Depth: TOO HIGH!" << endl;
    }

    return 0;
}