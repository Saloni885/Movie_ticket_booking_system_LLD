#ifndef MOVIE_CPP
#define MOVIE_CPP
#include <iostream>
#include <string>
using namespace std;
//encapulation:
//Data members are private and accessed through public methods.
class Movie {
private:
    string title;
    string language;
    int duration;
public:
    Movie(string title, string language, int duration) {
        this->title = title;
        this->language = language;
        this->duration = duration;
    }
    string getTitle() { return title; }
    string getLanguage() { return language; }
    int getDuration() { return duration; }
    void displayDetails() {
        cout << title << "  " << language << "  " << duration << " min";
    }
};
#endif