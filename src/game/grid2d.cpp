#include <game/grid2d.hpp>

Grid2D::Grid2D(){}
Grid2D::Grid2D(const int x, const int y) : data(x*y), xSize(x), ySize(y){}

void Grid2D::SetSize(const int x, const int y){
    xSize = x;
    ySize = y;
    data.resize(x*y);
}

const int& Grid2D::GetSizeX(){
    return xSize;
}

const int& Grid2D::GetSizeY(){
    return ySize;
}

Tile& Grid2D::operator() (size_t x, size_t y){
    return data[xSize * y  + x];
}