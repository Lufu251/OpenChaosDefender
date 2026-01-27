#pragma once

#include <vector>
#include <game/tile.hpp>

struct Grid2D{
    std::vector<Tile> data;
    int xSize = 0;
    int ySize = 0;

    Grid2D();
    Grid2D(const int x, const int y);

    void SetSize(const int x, const int y);
    const int& GetSizeX();
    const int& GetSizeY();
    Tile& operator() (size_t x, size_t y);
};