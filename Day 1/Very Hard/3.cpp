#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    void setComplex(double r, double i) {
        real = r;
        imaginary = i;
    }

    Complex add(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex multiply(const Complex& other) {
        double realPart = real * other.real - imaginary * other.imaginary;
        double imaginaryPart = real * other.imaginary + imaginary * other.real;
        return Complex(realPart, imaginaryPart);
    }

    double magnitude() {
        return sqrt(real * real + imaginary * imaginary);
    }

    void display() {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i";
        else
            cout << real << " - " << -imaginary << "i";
    }
};

int main() {
    int operationType;
    cout << "Select operation (1 for Addition, 2 for Multiplication, 3 for Magnitude): ";
    cin >> operationType;

    if (operationType == 1) {
        double real1, imaginary1, real2, imaginary2;
        cout << "Enter real and imaginary parts of the first complex number: ";
        cin >> real1 >> imaginary1;
        cout << "Enter real and imaginary parts of the second complex number: ";
        cin >> real2 >> imaginary2;

        Complex c1(real1, imaginary1);
        Complex c2(real2, imaginary2);
        Complex result = c1.add(c2);

        cout << "Result: ";
        result.display();
        cout << endl;

    } else if (operationType == 2) {
        double real1, imaginary1, real2, imaginary2;
        cout << "Enter real and imaginary parts of the first complex number: ";
        cin >> real1 >> imaginary1;
        cout << "Enter real and imaginary parts of the second complex number: ";
        cin >> real2 >> imaginary2;

        Complex c1(real1, imaginary1);
        Complex c2(real2, imaginary2);
        Complex result = c1.multiply(c2);

        cout << "Result: ";
        result.display();
        cout << endl;

    } else if (operationType == 3) {
        double real, imaginary;
        cout << "Enter real and imaginary parts of the complex number: ";
        cin >> real >> imaginary;

        Complex c(real, imaginary);
        double mag = c.magnitude();

        cout << "Result: Magnitude = " << mag << endl;

    } else {
        cout << "Invalid operation type." << endl;
    }

    return 0;
}