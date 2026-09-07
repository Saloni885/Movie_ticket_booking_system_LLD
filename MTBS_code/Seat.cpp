#ifndef SEAT_CPP
#define SEAT_CPP
#include <iostream>
#include <string>
using namespace std;

class Seat {
private:
    string seatNumber;
    string type;
public:
    Seat(string seatNumber, string type) {
        this->seatNumber = seatNumber;
        this->type = type;
    }
    string getSeatNumber() { return seatNumber; }
    string getType() { return type; }
    double getPrice() {
        if (type == "SILVER") return 150;
        if (type == "GOLD") return 250;
        if (type == "PLATINUM") return 400;
        return 0;
    }
};

#endif