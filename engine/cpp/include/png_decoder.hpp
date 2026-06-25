#pragma once
#include <cstdint>

namespace engine::vision {
    struct PngInfo {
        uint32_t width;
        uint32_t height;
        uint8_t bit_depth;
        uint8_t color_type;
    };

    bool verify_png_signature(const char* filename);
    bool read_png_header(const char* filename, PngInfo& out_info);

}