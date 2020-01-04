#include <iostream>
using namespace std;

class Rectangle
{
    //private: /*default access level is private in class definition*/
    double m_width, m_height; //member variables are made private
    double m_area;
    void compute_area() { m_area = m_width * m_height; } //a private mem func.
public:                                                  /*public member functions*/
    void setRect(double, double);
    double getArea() { return m_area; }     //provide access functions for priv.
    double getWidth() { return m_width; }   // short func. defined in class
    double getHeight() { return m_height; } // these are taken as ‘inline’
};
void Rectangle::setRect(double width, double height)
{
    m_width = width;
    m_height = height;
    compute_area(); //compute area for rectangle
}

int main()
{
    Rectangle r = Rectangle(); //create an instance ‘r’ with a copy of member var.
    r.setRect(10, 20);
}