#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include "Booking.cpp"
#include "PriceCalculator.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "TicketPrinter.cpp"

class BookingService {
private:
    vector<Booking> bookings;
    vector<Ticket> tickets;
    PriceCalculator calculator;
    TicketPrinter printer;

    string seatName(int i) {
        if (i < 3) return "A" + to_string(i + 1);
        if (i < 6) return "B" + to_string(i - 2);
        return "C" + to_string(i - 5);
    }

    int seatIndex(string name) {
        for (int i = 0; i < 8; ++i)
            if (seatName(i) == name) return i;
        return -1;
    }

public:
    void createBooking(vector<Show>& shows, Customer customer) {
        int showChoice;
        cout << "Choose show: ";
        cin >> showChoice;
        if (cin.fail() || showChoice < 1 || showChoice > (int)shows.size()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid show choice.\n";
            return;
        }

        Show& show = shows[showChoice - 1];
        show.displaySeatStatus();

        string input;
        cout << "\nSeats (e.g. A1,B2): ";
        cin >> input;

        vector<string> names;
        string token;
        stringstream ss(input);
        while (getline(ss, token, ',')) names.push_back(token);
        if (names.empty()) {
            cout << "Invalid seat input.\n";
            return;
        }

        vector<int> indexes;
        for (string name : names) {
            int index = seatIndex(name);
            if (index == -1) {
                cout << "Invalid seat number: " << name << ".\n";
                return;
            }
            for (int old : indexes) {
                if (old == index) {
                    cout << "Seat " << name << " entered more than once.\n";
                    return;
                }
            }
            if (!show.showSeats[index].isAvailable()) {
                cout << "Seat " << name << " is already BOOKED. Booking rejected.\n";
                return;
            }
            indexes.push_back(index);
        }

        vector<ShowSeat*> selected;
        vector<ShowSeat> selectedCopies;
        for (int index : indexes) {
            selected.push_back(&show.showSeats[index]);
            selectedCopies.push_back(show.showSeats[index]);
        }

        double total = calculator.calculateTotal(selected);
        for (int index : indexes) {
            cout << show.showSeats[index].seat.getSeatNumber()
                 << " " << show.showSeats[index].seat.getType()
                 << " Rs." << show.showSeats[index].seat.getPrice() << endl;
        }
        cout << "TOTAL          Rs." << total << endl;

        int paymentChoice;
        cout << "\nPay by: 1.UPI  2.Card  3.Cash > ";
        cin >> paymentChoice;
        if (cin.fail() || paymentChoice < 1 || paymentChoice > 3) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid payment method.\n";
            return;
        }
          //runtime polymorphism:
          //payment* can point to upipayment,cardpayment or cashpayment
        Payment* payment = nullptr;
        if (paymentChoice == 1) payment = new UpiPayment();
        else if (paymentChoice == 2) payment = new CardPayment();
        else payment = new CashPayment();

        for (int index : indexes) show.showSeats[index].book();

        bool success = payment->pay(total);
        delete payment;

        Booking booking("", customer, show);
        booking.selectedSeats = selectedCopies;
        booking.totalAmount = total;

        if (success) {
            booking.confirm();
            bookings.push_back(booking);

            vector<string> seatNumbers;
            for (int index : indexes) seatNumbers.push_back(show.showSeats[index].seat.getSeatNumber());

            string movieName = show.movie.getTitle();
            string screenName = "Screen-" + to_string(showChoice);
            Ticket ticket(booking.bookingId, movieName, screenName, show.startTime,
                          seatNumbers, total, "CONFIRMED");
            tickets.push_back(ticket);
            printer.printTicket(ticket);
        } else {
            for (int index : indexes) show.showSeats[index].release();
            booking.cancel();
            cout << "Payment failed. Seats released. Booking not confirmed.\n";
        }
    }

    void processPayment(Payment* payment, double amount) {
        if (payment != nullptr) payment->pay(amount);
    }

    void cancelBooking() {
        if (bookings.empty()) {
            cout << "No confirmed bookings found.\n";
            return;
        }
        string id;
        cout << "Enter booking ID: ";
        cin >> id;
        for (Booking& booking : bookings) {
            if (booking.bookingId == id && booking.status == "CONFIRMED") {
                for (ShowSeat& selected : booking.show.showSeats) {
                    for (ShowSeat& bookedSeat : booking.selectedSeats) {
                        if (selected.seat.getSeatNumber() == bookedSeat.seat.getSeatNumber())
                            selected.release();
                    }
                }
                booking.cancel();
                vector<Ticket> activeTickets;
                for (Ticket& ticket : tickets) {
                    if (ticket.bookingId != id) activeTickets.push_back(ticket);
                }
                tickets = activeTickets;
                cout << "Booking " << id << " cancelled. Seats are AVAILABLE again.\n";
                return;
            }
        }
        cout << "Booking ID not found.\n";
    }

    void showTickets() {
        if (tickets.empty()) {
            cout << "No tickets found.\n";
            return;
        }
        for (Ticket ticket : tickets) printer.printTicket(ticket);
    }
};
#endif
