#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double getArea() const override {
        return length * breadth;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return PI * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    int shapeType;
    cout << "Enter shape type (1 for Rectangle, 2 for Circle, 3 for Triangle): ";
    cin >> shapeType;

    Shape* shape = nullptr;

    switch (shapeType) {
        case 1: {
            double length, breadth;
            cout << "Enter length and breadth of the rectangle: ";
            cin >> length >> breadth;
            shape = new Rectangle(length, breadth);
            break;
        }
        case 2: {
            double radius;
            cout << "Enter radius of the circle: ";
            cin >> radius;
            shape = new Circle(radius);
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter base and height of the triangle: ";
            cin >> base >> height;
            shape = new Triangle(base, height);
            break;
        }
        default:
            cout << "Invalid shape type!" << endl;
            return 1;
    }

    if (shape) {
        cout << "The area of the shape is: " << shape->getArea() << endl;
        delete shape;
    }

    return 0;
}