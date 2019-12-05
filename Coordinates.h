#ifndef Coordinates_H
#define Coordinates_H

class Coordinates {
private:
    double c_x;
    double c_y;

public:
    Coordinates(double x, double y);
    double getX() { return c_x; }
    double getY() { return c_y; }
    void setX(double x);
    void setY(double y);
    void move(double x, double y);
    bool contact(Coordinates c);
};

#endif
