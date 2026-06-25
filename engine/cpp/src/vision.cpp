#include <array>
#include "image_utils.hpp"
#include "matrix.hpp"
#include "vision_constants.hpp"

using namespace std;

int get_index(int x, int y, int total_image_width){
    return (y * total_image_width) + x;
}

bool bounds_validation(int x, int y, int width, int height){
    return ((x > 0 && x < width-1) && (y > 0 && y < height-1));
}

float grayscale_normalizer(int raw_pixel_intensity){
    return raw_pixel_intensity / 255.0f;
}

std::array<Point, 8> get_neighbours(int x, int y, int width, int height){
    std::array<Point, 8> neighbours;

    for(int i = 0; i < 7; i++){
        neighbours[i].isvalid = false;
    }
    for(int count = 0; count < 7; count++){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 & j == 0) continue;

                int neighbour_x = x + i;
                int neihgbour_y = y + j;

                if (bounds_validation(neighbour_x, neihgbour_y, width, height)){
                    neighbours[count].x = neighbour_x;
                    neighbours[count].y = neihgbour_y;
                    neighbours[count].isvalid = true;
                }
            }
        }
        return neighbours;
    }
} 

