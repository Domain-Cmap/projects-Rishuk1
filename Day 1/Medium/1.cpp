#include <bits/stdc++.h>
using namespace std;

float area(int radius)
{
    double area = 3.14 * radius * radius;
    return area;
}

int area(int length, int breadth)
{
    int area = length * breadth;
    return area;
}

int area(float base, float height)
{
    int area = 0.5 * base * height;
    return area;
}

int main()
{
    int radius, length, breadth;
    float base, height;
    cin >> radius >> length >> breadth >> base >> height;

    float circle = area(radius);
    int rectangle = area(length, breadth);
    int triangle = area(base, height);
    cout << "Circle Area: " << circle << endl;
    cout << "Rectangle Area: " << rectangle << endl;
    cout << "Traingle Area: " << triangle << endl;
    return 0;
}