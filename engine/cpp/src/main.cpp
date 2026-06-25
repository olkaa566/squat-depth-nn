#include "png_decoder.hpp"
#include <iostream>

int main() {
    std::cout << "--- PNG Engine Booting ---" << std::endl;
    const char* file_path = "../../../assets/test_image.png"; 
    
    engine::vision::PngInfo image_info;

    if (engine::vision::read_png_header(file_path, image_info)) {
        std::cout << "Ready to allocate matrix memory!" << std::endl;
    }
    
    return 0;
}