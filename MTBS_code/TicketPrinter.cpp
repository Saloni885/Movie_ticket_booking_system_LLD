#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP
#include <iostream>
using namespace std;
#include "Ticket.cpp"
class TicketPrinter {
public:
    void printTicket(Ticket ticket) {
        cout << "\n================ TICKET ================" << endl;
        ticket.getDetails();
        cout << "=========================================\n" << endl;
    }
};
#endif
