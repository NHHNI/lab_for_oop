#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string licensePlate;
    string model;

public:
    static int carCount; // static поле для підрахунку об'єктів

    // Конструктори
    Car() : Car("Unknown", "Unknown") {}
    Car(string lp, string mdl) : licensePlate(lp), model(mdl) {
        carCount++;
    }

    // Конструктор копіювання
    Car(const Car& other) : licensePlate(other.licensePlate), model(other.model) {
        carCount++;
        cout << "Copy constructor called" << endl;
    }

    // Конструктор переміщення
    Car(Car&& other) noexcept : licensePlate(move(other.licensePlate)), model(move(other.model)) {
        cout << "Move constructor called" << endl;
    }

    ~Car() {
        carCount--;
    }

    void display() const {
        cout << "Car: " << model << " [" << licensePlate << "]" << endl;
    }

    // Використання this
    Car& setLicensePlate(string lp) {
        this->licensePlate = lp;
        return *this;
    }

    // Перевантаження оператора ==
    bool operator==(const Car& other) const {
        return (licensePlate == other.licensePlate) && (model == other.model);
    }

    // Перевантаження операторів введення та виведення
    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Car: " << car.model << " [" << car.licensePlate << "]";
        return os;
    }

    friend istream& operator>>(istream& is, Car& car) {
        cout << "Enter model: ";
        is >> car.model;
        cout << "Enter license plate: ";
        is >> car.licensePlate;
        return is;
    }
};

int Car::carCount = 0;

class ParkingLot {
private:
    int capacity;
    int occupied;
    static int totalLots; // static змінна

public:
    ParkingLot() : ParkingLot(50, 0) {}
    ParkingLot(int cap, int occ) : capacity(cap), occupied(occ) {
        totalLots++;
    }
    ~ParkingLot() {}

    bool parkCar() {
        if (occupied < capacity) {
            occupied++;
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Parking Lot: " << occupied << "/" << capacity << " occupied." << endl;
    }

    static int getTotalLots() { // static метод
        return totalLots;
    }
};

int ParkingLot::totalLots = 0;

class Ticket {
private:
    int ticketNumber;
    double price;
public:
    Ticket() : Ticket(0, 10.0) {}
    Ticket(int num, double p) : ticketNumber(num), price(p) {}
    ~Ticket() {}
    void display() const {
        cout << "Ticket #" << ticketNumber << " | Price: $" << price << endl;
    }
};

int main() {
    Car car1("AB1234CD", "Toyota");
    Car car2;
    cin >> car2; // Введення даних
    cout << car2 << endl; // Вивід на екран

    ParkingLot lot(100, 20);
    Ticket ticket1(101, 10.0);

    car1.display();
    lot.display();
    ticket1.display();

    // Демонстрація копіювання та переміщення
    Car car3 = car1; // Copy constructor
    Car car4 = move(car2); // Move constructor

    // Використання static полів та методів
    cout << "Total lots: " << ParkingLot::getTotalLots() << endl;
    cout << "Total cars: " << Car::carCount << endl;

    return 0;
}
