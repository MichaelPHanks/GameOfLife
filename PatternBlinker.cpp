#include "PatternBlinker.hpp"

std::uint8_t PatternBlinker::getSizeX() const
{
    return 1;
}

std::uint8_t PatternBlinker::getSizeY() const
{
    return 3;
}

bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x > getSizeX() - 1 || y > getSizeY() - 1)
    {
        return false;
    }
    return dimensions[y][x];
}
