#ifndef test7_57.h
#define test7_57.h

#include <stdio.h>
#include <string>

class Account {
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double newrate) { interestRate = newrate; }

    private:
        std::string owner;
        double amount;
        static double interestRate;
        static constexpr double todayrate = 42.11;
        static double initRate() { return todayrate; }
};

double Account::interestRate = initRate();

#endif
