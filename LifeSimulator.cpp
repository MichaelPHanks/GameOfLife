#include "LifeSimulator.hpp"

#include <iostream>
#include <vector>
LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    width(sizeX),
    height(sizeY)
{
    std::cout << "eyah";
    for (int i = 0; i < height; i++)
    {
        std::vector<bool> newVec;
        map.push_back(newVec);
        for (int j = 0; j < width; j++)
        {
            map[i].push_back(false);
        }
    }
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    std::uint8_t temp = startX;
    for (int i = 0; i < pattern.getSizeY(); i++)
    {
        startX = temp;
        for (int j = 0; j < pattern.getSizeX(); j++)
        {
            if (startX >= 0 && startX < width && startY >= 0 && startY < height)
            {

                map[startY][startX] = pattern.getCell(j, i);
                startX++;
            }
        }
        startY++;
    }
    /*for (int k = 0; k < getSizeY(); k++)
    {
        for (int l = 0; l < getSizeX(); l++)
        {
            std::cout << map[k][l];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;*/
}

std::uint8_t LifeSimulator::getNeighbors(unsigned int y, unsigned int x) const
{
    std::uint8_t total = 0;
    if (x > 0)
    {
        if (map[y][x - 1])
        {
            total++;
        }
        if (y > 0)
        {
            if (map[y - 1][x - 1])
            {
                total++;
            }
        }
        if (y < height - 1)
        {
            if (map[y + 1][x - 1])
            {
                total++;
            }
        }
    }
    if (x < width - 1)
    {
        if (map[y][x + 1])
        {
            total++;
        }
        if (y > 0)
        {
            if (map[y - 1][x + 1])
            {
                total++;
            }
        }
        if (y < height - 1)
        {
            if (map[y + 1][x + 1])
            {
                total++;
            }
        }
    }

    if (y > 0)
    {
        if (map[y - 1][x])
        {
            total++;
        }
    }
    if (y < height - 1)
    {
        if (map[y + 1][x])
        {
            total++;
        }
    }

    return total;
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> newMap = map;
    for (unsigned int i = 0; i < height; i++)
    {
        for (unsigned int j = 0; j < width; j++)
        {
            std::uint8_t totalNeighbors = getNeighbors(i, j);
            if (map[i][j])
            {
                if (totalNeighbors == 2 || totalNeighbors == 3)
                {
                    newMap[i][j] = true;
                }
                else
                {
                    newMap[i][j] = false;
                }
            }
            else
            {
                if (totalNeighbors == 3)
                {
                    newMap[i][j] = true;
                }
            }
        }
    }
    map = newMap;
}

std::uint8_t LifeSimulator::getSizeX() const
{
    return width;
}

std::uint8_t LifeSimulator::getSizeY() const
{
    return height;
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x > width - 1 || y > height - 1)
    {
        return false;
    }
    return map[y][x];
}
