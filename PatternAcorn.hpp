#include "Pattern.hpp"
#pragma once

#include <array>
#include <cstdint>
class PatternAcorn : public Pattern
{
  public:
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;

  private:
    const std::array<std::array<bool, 7>, 3> dimensions = { { { false, true, false, false, false, false, false },
                                                              { false, false, false, true, false, false, false },
                                                              { true, true, false, false, true, true, true } } };
};