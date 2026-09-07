#ifndef TICKET_CPP
#define TICKET_CPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BookingService;

class Ticket {
private:
    string bookingId;
    string movie;
    string screen;
    string time;
    vector<string> seatNumbers;
    double amount;
    string status;
    friend class BookingService;
public:
    Ticket(string bookingId, string movie, string screen, string time, vector<string> seatNumbers, double amount, string status) {
        this->bookingId = bookingId;
        this->movie = movie;
        this->screen = screen;
        this->time = time;
        this->seatNumbers = seatNumbers;
        this->amount = amount;
        this->status = status;
    }
    void getDetails() {
        cout << "Booking ID : " << bookingId << endl;
        cout << "Movie      : " << movie << endl;
        cout << "Screen     : " << screen << "  " << time << endl;
        cout << "Seats      : ";
        for (int i = 0; i < (int)seatNumbers.size(); ++i) {
            cout << seatNumbers[i];
            if (i + 1 < (int)seatNumbers.size()) cout << ",";
        }
        cout << endl;
        cout << "Amount     : Rs." << amount << "    Status: " << status << endl;
    }
};
#endif
