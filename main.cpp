#include "LifeSimulator.hpp"
#include "Pattern.hpp"
#include "PatternAcorn.hpp"
#include "PatternGosperGliderGun.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

#include <iostream>
#include <thread>
int main()
{
    RendererConsole console = RendererConsole();

    LifeSimulator sim = LifeSimulator(static_cast<std::uint8_t>(rlutil::tcols()), static_cast<std::uint8_t>(rlutil::trows()));
    sim.insertPattern(PatternGosperGliderGun(), 1, 1);
    rlutil::cls();

    while (true)
    {
        console.render(sim);
        sim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}