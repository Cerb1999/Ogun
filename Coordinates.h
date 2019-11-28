class Coordinates {
public:
    Coordinates(double x, double y);
    double getX();
    double getY();
    void move(double x, double y);

private:   
    double x;
    double y;
};