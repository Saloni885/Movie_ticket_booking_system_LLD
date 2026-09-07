#ifndef SHOW_CPP
#define SHOW_CPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Movie.cpp"
#include "Screen.cpp"
#include "ShowSeat.cpp"

class BookingService;

class Show {
private:
    Movie movie;
    Screen screen;
    string startTime;
    vector<ShowSeat> showSeats;
    friend class BookingService;
public:
    Show(Movie movie, Screen screen, string startTime)
        : movie(movie), screen(screen), startTime(startTime) {
        showSeats.push_back(ShowSeat(screen.getSeat("A1"), "AVAILABLE"));
        showSeats.push_back(ShowSeat(screen.getSeat("A2"), "BOOKED"));
        showSeats.push_back(ShowSeat(screen.getSeat("A3"), "AVAILABLE"));
        showSeats.push_back(ShowSeat(screen.getSeat("B1"), "AVAILABLE"));
        showSeats.push_back(ShowSeat(screen.getSeat("B2"), "AVAILABLE"));
        showSeats.push_back(ShowSeat(screen.getSeat("B3"), "BOOKED"));
        showSeats.push_back(ShowSeat(screen.getSeat("C1"), "AVAILABLE"));
        showSeats.push_back(ShowSeat(screen.getSeat("C2"), "AVAILABLE"));
    }
    void displayDetails() {
        cout << "Movie: ";
        movie.displayDetails();
        cout << "  Start Time: " << startTime << endl;
    }
    void displaySeatStatus() {
        cout << "SILVER ";
        for (int i = 0; i < 3; i++)
            cout << showSeats[i].seat.getSeatNumber() << "[" << (showSeats[i].isAvailable() ? " " : "X") << "] ";
        cout << endl << "GOLD   ";
        for (int i = 3; i < 6; i++)
            cout << showSeats[i].seat.getSeatNumber() << "[" << (showSeats[i].isAvailable() ? " " : "X") << "] ";
        cout << endl << "PLATINUM ";
        for (int i = 6; i < 8; i++)
            cout << showSeats[i].seat.getSeatNumber() << "[" << (showSeats[i].isAvailable() ? " " : "X") << "] ";
        cout << endl;
    }
    vector<ShowSeat> getShowSeats() { return showSeats; }
};
#endif
