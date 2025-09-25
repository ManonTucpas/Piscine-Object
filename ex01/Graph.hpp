#ifndef _GRAPH_HPP_
# define _GRAPH_HPP_

# include <iostream>
# include <vector>
# include "Vector2.hpp"

class Graph {
    private:
        std::vector<Vector2> _points; // Points' list
        std::vector<std::vector<char> > _grid; // Tab for displaying
        int _width;
        int _height;
       
    public:
        Graph(int width, int height);
        ~Graph();
        void addVector(float x, float y);
        void display();
};

#endif