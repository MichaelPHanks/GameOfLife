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
    std::cout << "Width: " << sim.getSizeX() << " Height: " << sim.getSizeY();
    while (true)
    {
        rlutil::hidecursor();
        sim.update();
        console.render(sim);
        rlutil::showcursor();
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}