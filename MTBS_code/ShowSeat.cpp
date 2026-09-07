#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP
#include <iostream>
#include <string>
using namespace std;
#include "Seat.cpp"

class PriceCalculator;
class BookingService;
class Show;

class ShowSeat {
private:
    Seat seat;
    string status;
    friend class PriceCalculator;
    friend class BookingService;
    friend class Show;
class Show;
public:
    ShowSeat(Seat seat, string status) : seat(seat), status(status) {}
    bool isAvailable() { return status == "AVAILABLE"; }
    void book() { status = "BOOKED"; }
    void release() { status = "AVAILABLE"; }
};
#endif
