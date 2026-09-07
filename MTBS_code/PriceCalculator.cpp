#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP
#include <iostream>
#include <vector>
using namespace std;
#include "ShowSeat.cpp"
//compile-time polymorphism:
//same method name with different parameters
class PriceCalculator {
public:
    double calculateTotal(ShowSeat* seat) {
        if (seat == nullptr) return 0;
        return seat->seat.getPrice();
    }
    double calculateTotal(vector<ShowSeat*> seats) {
        double total = 0;
        for (ShowSeat* seat : seats) {
            if (seat != nullptr) total += seat->seat.getPrice();
        }
        return total;
    }
};
#endif
