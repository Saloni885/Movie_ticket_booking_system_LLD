#ifndef CARDPAYMENT_CPP
#define CARDPAYMENT_CPP
#include <iostream>
using namespace std;
#include "Payment.cpp"

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        char confirm;
        cout << "Confirm payment (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            cout << "[Card] Rs." << amount << " paid successfully" << endl;
            return true;
        }
        cout << "[Card] Payment failed" << endl;
        return false;
    }
};
#endif
