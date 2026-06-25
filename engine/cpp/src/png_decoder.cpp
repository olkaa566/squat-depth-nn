#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "png_decoder.hpp"

namespace engine::vision {

bool verify_png_signature(const char* filename) {
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    unsigned char signature[8];
    file.read(reinterpret_cast<char*>(signature), 8);

    const unsigned char PNG_MAGIC[8] = {137, 80, 78, 71, 13, 10, 26, 10};

    for (int i = 0; i < 8; ++i) {
        if (signature[i] != PNG_MAGIC[i]) {
            std::cerr << "Invalid PNG signature! File is not a valid PNG." << std::endl;
            return false;
        }
    }

    std::cout << "Success: Valid PNG file detected." << std::endl;
    return true;
}

//big endian: largest byte first
uint32_t read_uint32_big_endian(std::ifstream& file) {
    unsigned char bytes[4];
    file.read(reinterpret_cast<char*>(bytes), 4);
    return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

bool read_png_header(const char* filename, PngInfo& out_info) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) return false;

    file.seekg(8, std::ios::beg);

    uint32_t chunk_length = read_uint32_big_endian(file);

    char chunk_type[5] = {0}; 
    file.read(chunk_type, 4);

    if (std::string(chunk_type) != "IHDR") {
        std::cerr << "Error: First chunk is not IHDR. It is: " << chunk_type << std::endl;
        return false;
    }

    // Read the IHDR Data (Width, Height, Bit Depth, Color Type)
    out_info.width = read_uint32_big_endian(file);
    out_info.height = read_uint32_big_endian(file);
    
    file.read(reinterpret_cast<char*>(&out_info.bit_depth), 1);
    file.read(reinterpret_cast<char*>(&out_info.color_type), 1);

    std::cout << "--- PNG HEADER DECODED ---" << std::endl;
    std::cout << "Width: " << out_info.width << " px" << std::endl;
    std::cout << "Height: " << out_info.height << " px" << std::endl;
    std::cout << "Bit Depth: " << (int)out_info.bit_depth << std::endl;
    std::cout << "Color Type: " << (int)out_info.color_type << std::endl;

    return true;
}

} 