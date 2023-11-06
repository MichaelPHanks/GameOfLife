#include "Renderer.hpp"

#include <vector>
#pragma once

class RendererConsole : public Renderer
{
  public:
    RendererConsole();
    virtual void render(const LifeSimulator& simulation);

  private:
    std::vector<std::vector<bool>> map;
};