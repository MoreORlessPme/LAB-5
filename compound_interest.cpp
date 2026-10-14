#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double principal;
    double annual_rate;
    double rate;
    double amount;
    double interest_earned;
    int times_compounded;

    cout << "Principal balance: ";
    cin >> principal;
    cout << "Annual interest rate (%): ";
    cin >> annual_rate;
    cout << "Times compounded in one year: ";
    cin >> times_compounded;

    if (!cin || principal <= 0 || annual_rate <= 0 || times_compounded <= 0)
    {
        cout << "Enter positive numbers and a whole number of periods.\n";
        return 1;
    }

    rate = annual_rate / 100.0;
    amount = principal * pow(1.0 + rate / times_compounded,
                             times_compounded);
    interest_earned = amount - principal;

    cout << fixed << setprecision(2);
    cout << "\nCompound Interest\n";
    cout << left << setw(24) << "Interest Rate:" << annual_rate << "%\n";
    cout << setw(24) << "Times Compounded:" << times_compounded << '\n';
    cout << setw(24) << "Principal:" << "$" << principal << '\n';
    cout << setw(24) << "Interest Earned:" << "$" << interest_earned << '\n';
    cout << setw(24) << "Amount in Savings:" << "$" << amount << '\n';

    return 0;
}
