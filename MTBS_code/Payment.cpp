#ifndef PAYMENT_CPP
#define PAYMENT_CPP
#include <iostream>
using namespace std;
//abstraction:
//payment provides acommon interface
//the actual payment implementation is handled by derived classes
class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual ~Payment() {}
};
#endif
