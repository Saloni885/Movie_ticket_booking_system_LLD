#ifndef CASHPAYMENT_CPP
#define CASHPAYMENT_CPP
#include <iostream>
using namespace std;
#include "Payment.cpp"

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        char confirm;
        cout << "Confirm payment (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            cout << "[Cash] Rs." << amount << " paid successfully" << endl;
            return true;
        }
        cout << "[Cash] Payment failed" << endl;
        return false;
    }
};
#endif
