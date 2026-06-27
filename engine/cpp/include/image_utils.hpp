//inline functions to help map (x,y) to data index
//index = (y * width) + x

#pragma once
//#include <vector>
#include <array>

struct Point{
    int x;
    int y;
    bool isvalid;
};


int get_index(int x, int y, int total_image_width);
bool bounds_validation(int x, int y, int width, int height);

//return the processed float value
float grayscale_normalizer(int raw_pixel_intensity);

std::array<Point, 8> get_neighbours(int x, int y, int width, int length);