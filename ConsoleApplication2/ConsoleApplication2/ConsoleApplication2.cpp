#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;
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

    void conclusion() {
        std::cout << "Make: " << make << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
    }

};

class CarBuilder {
public:
    virtual void buildMake() = 0;
    virtual void buildModel() = 0;
    virtual void buildYear() = 0;
    virtual Car* getResult() = 0;
};

class SportsCarBuilder : public CarBuilder {
private:
    Car* car;
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
    //без директора
    /*
    SportsCarBuilder sportsCarBuilder;
    Car* sportsCar = sportsCarBuilder.getResult();
    sportsCar->setMake("Porsche");
    sportsCar->setModel("911");
    sportsCar->setYear(2023);
    sportsCar->conclusion();
    */
    //с директором
    CarDirector director;
    SportsCarBuilder sportsCarBuilder;
    Car* sportsCar = director.createCar(&sportsCarBuilder);
    sportsCar->conclusion();
}