#include "PatternGlider.hpp"

std::uint8_t PatternGlider::getSizeX() const
{
    return 3;
}

std::uint8_t PatternGlider::getSizeY() const
{
    return 3;
}

bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x > getSizeX() - 1 || y > getSizeY() - 1)
    {
        return false;
    }
    return dimensions[y][x];
}
