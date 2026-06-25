#include <array>
#include "matrix.hpp"
#include "vision_constants.hpp"

void convolve(const Matrix& input, const Kernel& kernel, Matrix& ouput);