#include "PatternGosperGliderGun.hpp"

std::uint8_t PatternGosperGliderGun::getSizeX() const
{
    return 36;
}

std::uint8_t PatternGosperGliderGun::getSizeY() const
{
    return 9;
}

bool PatternGosperGliderGun::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x > getSizeX() - 1 || y > getSizeY() - 1)
    {
        return false;
    }
    return dimensions[y][x];
}
