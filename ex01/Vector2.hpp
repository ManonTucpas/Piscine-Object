#ifndef _VECTOR2_HPP_
# define _VECTOR2_HPP_

class Vector2 {
    private:
        float _x;
        float _y;
    public: 
        Vector2(float x = 0.0f, float y = 0.f): _x(x), _y(y) {};
        ~Vector2() {};

        int getX() const { return _x; }
        int getY() const { return _y; }

        void setX(float x) { _x = x; }
        void setY(float y) { _y = y; }
};

#endif