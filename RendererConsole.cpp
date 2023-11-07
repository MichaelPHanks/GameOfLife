#include "RendererConsole.hpp"

#include "LifeSimulator.hpp"
#include "rlutil.h"

RendererConsole::RendererConsole()
{

    for (int i = 0; i < rlutil::trows(); i++)
    {
        std::vector<bool> newVec;
        map.push_back(newVec);
        for (int j = 0; j < rlutil::tcols(); j++)
        {
            map[i].push_back(false);
        }
    }
}

void RendererConsole::render(const LifeSimulator& simulation)
{
    rlutil::hidecursor();

    for (std::uint8_t i = 0; i < simulation.getSizeY(); i++)
    {
        for (std::uint8_t j = 0; j < simulation.getSizeX(); j++)
        {

            bool cell = simulation.getCell(j, i);
            if (map[i][j] != cell)
            {

                rlutil::locate(j, i);
                if (cell)
                {
                    rlutil::setChar('X');
                }
                else
                {
                    rlutil::setChar(' ');
                }
            }
            map[i][j] = cell;
        }
    }
    rlutil::showcursor();
    std::cout << std::flush;
}