#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    double mileage;

public:
    void setDetails(const string& b, const string& m, double mi) {
        brand = b;
        model = m;
        mileage = mi;
    }

    virtual void displayDetails() {
        cout << "Vehicle: " << brand << " " << model << endl;
        cout << "Mileage: " << mileage << " miles" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    double fuel;
    double distance;

public:
    void setCarDetails(double f, double d) {
        fuel = f;
        distance = d;
    }

    void calculateFuelEfficiency() {
        double efficiency = distance / fuel;
        cout << "Fuel Efficiency: " << efficiency << " miles/gallon" << endl;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Car Specific Details:" << endl;
    }
};

class ElectricCar : public Car {
private:
    double batteryCapacity;
    double efficiency;

public:
    void setElectricCarDetails(double bc, double e) {
        batteryCapacity = bc;
        efficiency = e;
    }

    void calculateRange() {
        double range = batteryCapacity * efficiency;
        cout << "Range: " << range << " miles" << endl;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Electric Car Specific Details:" << endl;
    }
};

int main() {
    int vehicleType;
    cout << "Enter vehicle type (1 for Car, 2 for Electric Car): ";
    cin >> vehicleType;

    if (vehicleType == 1) {
        string brand, model;
        double mileage, fuel, distance;
        cout << "Enter brand: ";
        cin.ignore();
        getline(cin, brand);
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter mileage: ";
        cin >> mileage;
        cout << "Enter fuel (gallons): ";
        cin >> fuel;
        cout << "Enter distance covered (miles): ";
        cin >> distance;

        if (mileage < 0 || mileage > 500000 || fuel < 1 || fuel > 100 || distance < 1 || distance > 1000) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        Car car;
        car.setDetails(brand, model, mileage);
        car.setCarDetails(fuel, distance);
        car.displayDetails();
        car.calculateFuelEfficiency();
    } else if (vehicleType == 2) {
        string brand, model;
        double mileage, batteryCapacity, efficiency;
        cout << "Enter brand: ";
        cin.ignore();
        getline(cin, brand);
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter mileage: ";
        cin >> mileage;
        cout << "Enter battery capacity (kWh): ";
        cin >> batteryCapacity;
        cout << "Enter efficiency (miles per kWh): ";
        cin >> efficiency;

        if (mileage < 0 || mileage > 500000 || batteryCapacity < 10 || batteryCapacity > 150 || efficiency < 1 || efficiency > 10) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        ElectricCar electricCar;
        electricCar.setDetails(brand, model, mileage);
        electricCar.setElectricCarDetails(batteryCapacity, efficiency);
        electricCar.displayDetails();
        electricCar.calculateRange();
    } else {
        cout << "Invalid vehicle type." << endl;
    }

    return 0;
}