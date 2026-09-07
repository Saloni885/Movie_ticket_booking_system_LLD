#ifndef SCREEN_CPP
#define SCREEN_CPP
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Seat.cpp"

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;
public:
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
        seats.push_back(Seat("A1", "SILVER"));
        seats.push_back(Seat("A2", "SILVER"));
        seats.push_back(Seat("A3", "SILVER"));
        seats.push_back(Seat("B1", "GOLD"));
        seats.push_back(Seat("B2", "GOLD"));
        seats.push_back(Seat("B3", "GOLD"));
        seats.push_back(Seat("C1", "PLATINUM"));
        seats.push_back(Seat("C2", "PLATINUM"));
    }
    Seat getSeat(string seatNumber) {
        for (Seat seat : seats) {
            if (seat.getSeatNumber() == seatNumber) return seat;
        }
        return Seat("", "");
    }
    void displaySeats() {
        for (Seat seat : seats)
            cout << seat.getSeatNumber() << " - " << seat.getType() << endl;
    }
};
#endif
