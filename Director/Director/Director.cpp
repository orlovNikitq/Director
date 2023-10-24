#include <iostream>
#include <string>

class Car {
public:
    void setMake(const std::string& make) {
        this->make = make;
    }

    void setModel(const std::string& model) {
        this->model = model;
    }

    void setYear(int year) {
        this->year = year;
    }

    void describe() {
        std::cout << "Make: " << make << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
    }

private:
    std::string make;
    std::string model;
    int year;
};

class CarBuilder {
public:
    virtual void buildMake() = 0;
    virtual void buildModel() = 0;
    virtual void buildYear() = 0;
    virtual Car* getResult() = 0;
};

class SportsCarBuilder : public CarBuilder {
public:
    SportsCarBuilder() {
        car = new Car();
    }

    void buildMake() override {
        car->setMake("Porsche");
    }

    void buildModel() override {
        car->setModel("911");
    }

    void buildYear() override {
        car->setYear(2023);
    }

    Car* getResult() override {
        return car;
    }

private:
    Car* car;
};

class CarDirector {
public:
    Car* createCar(CarBuilder* builder) {
        builder->buildMake();
        builder->buildModel();
        builder->buildYear();
        return builder->getResult();
    }
};

int main() {
    CarDirector director;
    SportsCarBuilder sportsCarBuilder;

    Car* sportsCar = director.createCar(&sportsCarBuilder);
    sportsCar->describe();

}
