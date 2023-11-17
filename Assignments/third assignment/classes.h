#include <iostream>
using namespace std;
float pie = 22 / 7.0;

class Shape
{
private:
    float center_x;
    float center_y;

public:
    Shape(float x = 0, float y = 0)
    {
        center_x = x;
        center_y = y;
    }
    Shape(const Shape &obj)
    {
        this->center_x = obj.center_x;
        this->center_y = obj.center_y;
    }
    ~Shape()
    {
    }
    virtual double getArea() const = 0;
    float *getCoordinates()
    {
        float *coordinates = new float[2];
        coordinates[0] = this->center_x;
        coordinates[1] = this->center_y;
        return coordinates;
    }
};
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float R, float x, float y) : Shape(x, y)
    {
        radius = R;
    }
    double getArea() const
    {
        double result;
        result = pie * (this->radius * this->radius);
        return result;
    }
    double operator+(const Circle &obj)
    {
        double result;
        result = obj.getArea() + this->getArea();
        return result;
    }
};
class Rectangle : public Shape
{
private:
    float length;
    float width;

public:
    Rectangle(float w, float l, float x, float y) : Shape(x, y)
    {
        length = l;
        width = w;
    }
    double getArea() const
    {
        double result;
        result = length * width;
        return result;
    }
    double operator+(const Rectangle &obj)
    {
        double result;
        result = obj.getArea() + this->getArea();
        return result;
    }
};

class Triangle : public Shape
{
private:
    float length;
    float height;

public:
    Triangle(float h, float l, float x, float y) : Shape(x, y)
    {
        length = l;
        height = h;
    }
    double getArea() const
    {
        double result;
        result = 0.5 * length * height;
        return result;
    }
    double operator+(const Triangle &obj)
    {
        double result;
        result = obj.getArea() + this->getArea();
        return result;
    }
};

double getShapeArea(Shape *obj)
{
    return obj->getArea();
}