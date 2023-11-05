#include "Pattern.hpp"

#include <array>
#pragma once
class PatternGlider : public Pattern
{
  public:
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;

  private:
    const std::array<std::array<bool, 3>, 3> dimensions = { { { false, false, true },
                                                              { true, false, true },
                                                              { false, true, true } } };
};