#include "PatternAcorn.hpp"

#include <cstdint>

std::uint8_t PatternAcorn::getSizeX() const
{
    return 7;
}

std::uint8_t PatternAcorn::getSizeY() const
{
    return 3;
}

bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x > getSizeX() - 1 || y > getSizeY() - 1)
    {
        return false;
    }
    return dimensions[y][x];
}
