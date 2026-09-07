#ifndef UPIPAYMENT_CPP
#define UPIPAYMENT_CPP
#include <iostream>
using namespace std;
#include "Payment.cpp"
//inheritance:
//upipayment inherits from payment base class
class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        char confirm;
        cout << "Confirm payment (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            cout << "[UPI] Rs." << amount << " paid successfully" << endl;
            return true;
        }
        cout << "[UPI] Payment failed" << endl;
        return false;
    }
};
#endif
