#include "Pattern.hpp"

#include <array>
#pragma once
class PatternPulsar : public Pattern
{
  public:
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;

  private:
    const std::array<std::array<bool, 13>, 13> dimensions = { { { false, false, true, true, true, false, false, false, true, true, true, false, false },
                                                                { false, false, false, false, false, false, false, false, false, false, false, false, false },
                                                                { true, false, false, false, false, true, false, true, false, false, false, false, true },
                                                                { true, false, false, false, false, true, false, true, false, false, false, false, true },
                                                                { true, false, false, false, false, true, false, true, false, false, false, false, true },
                                                                { false, false, true, true, true, false, false, false, true, true, true, false, false },
                                                                { false, false, false, false, false, false, false, false, false, false, false, false, false },
                                                                { false, false, true, true, true, false, false, false, true, true, true, false, false },
                                                                { true, false, false, false, false, true, false, true, false, false, false, false, true },
                                                                { true, false, false, false, false, true, false, true, false, false, false, false, true },
                                                                { true, false, false, false, false, true, false, true, false, false, false, false, true },
                                                                { false, false, false, false, false, false, false, false, false, false, false, false, false },
                                                                { false, false, true, true, true, false, false, false, true, true, true, false, false }

    } };
};