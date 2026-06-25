#include <array>
#include <algorithm>
#include "image_utils.hpp"
#include "matrix.hpp"
#include "vision_constants.hpp"
#include "vision.hpp"

using namespace std;

int get_index(int x, int y, int total_image_width){
    return (y * total_image_width) + x;
}

bool bounds_validation(int x, int y, int width, int height){
    return ((x >= 0 && x < width-1) && (y >= 0 && y < height-1));
}

float grayscale_normalizer(int raw_pixel_intensity){
    return raw_pixel_intensity / 255.0f;
}

std::array<Point, 8> get_neighbours(int x, int y, int width, int height){
    std::array<Point, 8> neighbours;

    for(int i = 0; i < 8; i++){
        neighbours[i].isvalid = false;
    }
    for(int count = 0; count < 8; count++){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;

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

void convolve(const Matrix& input, const Kernel& kernel, Matrix& output){
    if (output.get_columns() != input.get_columns() || output.get_rows() != input.get_rows()) {
        output = Matrix(input.get_columns(), input.get_rows());
    }

    for(int i = 1; i < input.get_rows()-1; ++i){
        for(int j = 1; j < input.get_columns()-1; ++j){
            float running_sum = 0.0f;

            for (int ki = -1; ki <= 1; ++ki) {
                for (int kj = -1; kj <= 1; ++kj) {
                    
                    int kernel_index = (ki + 1) * 3 + (kj + 1);
                    float weight = kernel.weights[kernel_index];
                    
                    float pixel = input.at(j + kj, i + ki); 
                    running_sum += (weight * pixel);
                }
            }
            // normalization
            float normalized_value = running_sum / kernel.divisor;
            
            // clamping - 0-255
            float clamped_value = std::clamp(normalized_value, 0.0f, 255.0f);
            
            output.at(j, i) = clamped_value;
        }
    }
}

