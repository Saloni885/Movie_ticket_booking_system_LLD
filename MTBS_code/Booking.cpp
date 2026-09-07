#ifndef BOOKING_CPP
#define BOOKING_CPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Customer.cpp"
#include "Show.cpp"
#include "ShowSeat.cpp"

enum BookingStatus { PENDING, CONFIRMED, CANCELLED, FAILED };
class BookingService;
//static member:
//generates unique booking ids shared by all booking objects
class Booking {
private:
    static int nextBookingId;
    string bookingId;
    Customer customer;
    Show show;
    vector<ShowSeat> selectedSeats;
    double totalAmount;
    string status;
    friend class BookingService;
    //this pointer
    //refers to the current object
public:
    Booking(string bookingId, Customer customer, Show show)
        : customer(customer), show(show), totalAmount(0), status("PENDING") {
        if (bookingId == "")
            this->bookingId = "BK" + to_string(1000 + nextBookingId++);
        else
            this->bookingId = bookingId;
    }
    double calculateTotal() { return totalAmount; }
    void confirm() { status = "CONFIRMED"; }
    void cancel() { status = "CANCELLED"; }
    BookingStatus getStatus() {
        if (status == "CONFIRMED") return CONFIRMED;
        if (status == "CANCELLED") return CANCELLED;
        if (status == "FAILED") return FAILED;
        return PENDING;
    }
};
int Booking::nextBookingId = 1;
#endif
