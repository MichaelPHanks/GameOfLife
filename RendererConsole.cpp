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

    for (int i = 0; i < simulation.getSizeY(); i++)
    {
        for (int j = 0; j < simulation.getSizeX(); j++)
        {
            bool cell = simulation.getCell(i, j);
            if (map[i][j] != cell)
            {
                rlutil::locate(i, j);
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
}