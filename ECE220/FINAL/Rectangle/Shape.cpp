#include <iostream>
using namespace std;

class Shape
{
protected:
    double m_width, m_height; //allows derived classes to inherit
public:
    void PrintShape() { cout << "Shape size : "
                             << m_width
                             << " x "
                             << m_height
                             << endl; }
    Shape() {};
    virtual ~Shape() {};
    Shape(double, double);
    Shape(const Shape&);
};
//derived class
class Rectangle : public Shape
{
    double m_area;

public:
    Rectangle(double a, double b); //constructor function for Rectangle
    void PrintShape();             //bring PrintShape to Rectangle’s scope
private:
    void compute_area() { m_area = m_width * m_height; }
};

//defining the constructor function of Rectangle
Rectangle::Rectangle(double a, double b)
{
    m_width = a;
    m_height = b; //set fields and compute area
    compute_area();
}
//overriding Shape::PrintSize
void Rectangle::PrintShape()
{
    cout << "Rectangle size : "
         << m_width
         <<" x "
         << m_height
         << ", " << m_area << endl;
}

//another derived class
class Triangle : public Shape
{
    double m_area;

public:
    Triangle(double a, double b)
    { //constructor function for Triangle class
        m_width = a;
        m_height = b; //set fields and compute area
        compute_area();
    }
    //overriding Shape::PrintSize
    void PrintShape() { cout << "Triangle size : "
                             << m_width
                             << " x "
                             << m_height
                             << ", " << m_area << endl; }

private:
    void compute_area() { m_area = .5f * m_width * m_height; }
};

int main()
{
    Rectangle rec(3, 5);
    Triangle tri(3, 5);
    rec.PrintShape(); //Rectangle size: 3x5, 15
    tri.PrintShape(); //Triangle size: 3x5, 7.5
    Shape *ptr = &rec;
    ptr->PrintShape(); //What would this one print?
    return 0;
}