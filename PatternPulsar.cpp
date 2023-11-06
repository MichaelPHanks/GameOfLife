#include "PatternPulsar.hpp"

std::uint8_t PatternPulsar::getSizeX() const
{
    return 13;
}

std::uint8_t PatternPulsar::getSizeY() const
{
    return 13;
}

bool PatternPulsar::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x > getSizeX() - 1 || y > getSizeY() - 1)
    {
        return false;
    }
    return dimensions[y][x];
}
