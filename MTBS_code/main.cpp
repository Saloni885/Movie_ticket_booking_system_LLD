#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

#include "Cinema.cpp"
#include "BookingService.cpp"

int main() {
    Cinema cinema("PVR Cinema", "Haridwar");
    BookingService bookingService;

    Movie movie1("3 Idiots", "Hindi", 170);
    Movie movie2("Mirzapur:The Movie", "Hindi", 150);

    Screen screen1(1);
    Screen screen2(2);

    vector<Show> shows1;
    shows1.push_back(Show(movie1, screen1, "06:00 PM"));
    shows1.push_back(Show(movie1, screen2, "09:00 PM"));

    vector<Show> shows2;
    shows2.push_back(Show(movie2, screen1, "06:00 PM"));
    shows2.push_back(Show(movie2, screen2, "09:00 PM"));

    vector<Movie> movies = {movie1, movie2};

    Customer customer("Customer", "9999999999");

    while (true) {
        cout << "\n===== MOVIE TICKET BOOKING =====" << endl;
        cout << "1. Movies   2. Book   3. Cancel   4. My tickets   0. Exit" << endl;
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid menu choice. Please enter a number.\n";
            continue;
        }

        try {
            if (choice < 0 || choice > 4)
                throw invalid_argument("Invalid menu choice.");

            if (choice == 0) {
                cout << "Thank you!\n";
                break;
            }

            if (choice == 1) {
                for (int i = 0; i < (int)movies.size(); ++i) {
                    cout << "[" << i + 1 << "] ";
                    movies[i].displayDetails();
                    cout << endl;
                }

                int movieChoice;
                cout << "\nChoose movie: ";
                cin >> movieChoice;
                if (cin.fail() || movieChoice < 1 || movieChoice > 2) {
                    cin.clear(); cin.ignore(1000, '\n');
                    cout << "Invalid movie choice.\n";
                    continue;
                }

                vector<Show>& selectedShows = (movieChoice == 1) ? shows1 : shows2;
                for (int i = 0; i < (int)selectedShows.size(); ++i) {
                    cout << "[" << i + 1 << "] Screen-" << (i + 1)
                         << "  " << (i == 0 ? "06:00 PM" : "09:00 PM") << endl;
                }
            }
            else if (choice == 2) {
                for (int i = 0; i < (int)movies.size(); ++i) {
                    cout << "[" << i + 1 << "] ";
                    movies[i].displayDetails();
                    cout << endl;
                }

                int movieChoice;
                cout << "\nChoose movie: ";
                cin >> movieChoice;
                if (cin.fail() || movieChoice < 1 || movieChoice > 2) {
                    cin.clear(); cin.ignore(1000, '\n');
                    cout << "Invalid movie choice.\n";
                    continue;
                }

                vector<Show>& selectedShows = (movieChoice == 1) ? shows1 : shows2;
                for (int i = 0; i < (int)selectedShows.size(); ++i) {
                    cout << "[" << i + 1 << "] Screen-" << (i + 1)
                         << "  " << (i == 0 ? "06:00 PM" : "09:00 PM") << endl;
                }

                bookingService.createBooking(selectedShows, customer);
            }
            else if (choice == 3) {
                bookingService.cancelBooking();
            }
            else if (choice == 4) {
                bookingService.showTickets();
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
