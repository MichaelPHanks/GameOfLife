#include "Pattern.hpp"
#pragma once

#include <cstdint>
#include <vector>
class LifeSimulator
{
  public:
    LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);

    void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY);
    void update();

    std::uint8_t getSizeX() const;
    std::uint8_t getSizeY() const;
    bool getCell(std::uint8_t x, std::uint8_t y) const;

  private:
    const std::uint8_t width;
    const std::uint8_t height;
    std::vector<std::vector<bool>> map;
    std::uint8_t getNeighbors(unsigned int y, unsigned int x) const;
};