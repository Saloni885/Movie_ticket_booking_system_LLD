#ifndef CINEMA_CPP
#define CINEMA_CPP
#include <iostream>
#include <string>
using namespace std;

class Cinema {
private:
    string name;
    string location;
public:
    Cinema(string name, string location) {
        this->name = name;
        this->location = location;
    }
    string getName() { return name; }
    string getLocation() { return location; }
    void displayShows() {
        cout << "Cinema: " << name << endl;
        cout << "Location: " << location << endl;
    }
};
#endif
