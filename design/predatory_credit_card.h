#pragma once
#include <iostream>           // provides std::ostream
#include <string>             // provides std::string
#include <cmath>              // provides pow function
#include "credit_card.h"

namespace dsac::design {

class PredatoryCreditCard : public CreditCard {
  private:
    double apr;               // annual percentage rate

  public:
    /// Constructs a new predatory credit card.
    PredatoryCreditCard(std::string cust, std::string bk, std::string acnt, int lim, double initial_bal, double rate)
        : CreditCard{cust, bk, acnt, lim, initial_bal}, apr{rate} {}

    // A new function for assessing monthly interest charges
    void process_month() {
        if (balance > 0) {               // only charge interest on a positive balance
            double monthly_factor = pow(1 + apr, 1.0/12);      // compute monthly rate
            balance *= monthly_factor;                         // assess interest
        }
    }
    
    // Overriding the charge function defined in the superclass
    bool charge(double price) {
        bool is_success{CreditCard::charge(price)};            // call inherited version
        if (!is_success)
            balance += 5;                                      // assess a $5 penalty
        return is_success;
    }    

}; // PredatoryCreditCard class

}  // namespace dsac::design
