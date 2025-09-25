#include "Graph.hpp"

Graph::Graph(int width, int height)
{
    if (width < 0 || height < 0)
    {
        std::cout << "Error - Size can't be set with negative value" << std::endl;
        return;
    }

    // Set width & height
    _width = width;
    _height = height;

    // Initialiaze _grid with '.'
    _grid.resize(height);
    for (std::string::size_type y = 0; y < _grid.size(); y++)
    {
        _grid[y].resize(width, '.');
    }
}

void Graph::addVector(float x, float y) // 1. Validate point 2.Push vector to _points 3. Update _grid
{
    if (_grid.empty())
    {
        std::cout << "Error - No graph found" << std::endl;
        return;
    }
    // Create a vector
    Vector2 point(x, y); // Conversion float->int

    // To fill the grid we need int values as ascii can't handle float
    int grid_x = (int)point.getX();
    int grid_y = (int)point.getY();

    // Validate points
    if ((grid_x < 0 || grid_x >= _width) || (grid_y < 0 || grid_y >= _height))
    {
        std::cout << "Error - Incorrect value" << std::endl;
        return;
    }

    // Push vector to _points
    _points.push_back(point);

    // Update grid
    int ligne = _height - 1 - grid_y;
    _grid[ligne][grid_x] = 'X';
}

void Graph::display()
{
    // Y should be printed reverse: 3,2,1,0 and not 0,1,2,3 if h=4
    for (int y = _height - 1; y >= 0; y--)
    {
        std::cout << ">& " << y << " ";
        int row = _height - y - 1; // Inverse Y for displaying the good point
        for (int x = 0; x < _width; x++)
        {
            std::cout << _grid[row][x] << " ";
        }
        std::cout << std::endl;
    }

    // Displaying X axis
    for (int x = 0; x < _width; x++)
    {
        if (x == 0)
            std::cout << ">&  " << x << " ";
        else
            std::cout << x << " ";
    }
}

Graph::~Graph() {}