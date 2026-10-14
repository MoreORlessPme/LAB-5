#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const int MONTHS_PER_YEAR = 12;
    double loan_amount;
    double annual_rate;
    double monthly_rate;
    double power_term;
    double monthly_payment;
    double amount_paid_back;
    double interest_paid;
    double monthly_rate_percent;
    int number_of_payments;

    cout << "Loan amount: ";
    cin >> loan_amount;
    cout << "Annual interest rate (%): ";
    cin >> annual_rate;
    cout << "Number of monthly payments: ";
    cin >> number_of_payments;

    if (!cin || loan_amount <= 0 || annual_rate <= 0 || number_of_payments <= 0)
    {
        cout << "Enter positive numbers and a whole number of payments.\n";
        return 1;
    }

    monthly_rate = annual_rate / 100.0 / MONTHS_PER_YEAR;
    power_term = pow(1.0 + monthly_rate, number_of_payments);
    monthly_payment = monthly_rate * power_term
                      / (power_term - 1.0) * loan_amount;
    // Keep all available decimal places in the payment when calculating the totals.
    amount_paid_back = monthly_payment * number_of_payments;
    interest_paid = amount_paid_back - loan_amount;
    monthly_rate_percent = monthly_rate * 100.0;

    cout << fixed << setprecision(2);
    cout << "\nMonthly Loan Payment\n";
    cout << left << setw(24) << "Loan Amount:" << "$" << loan_amount << '\n';
    cout << setw(24) << "Monthly Interest Rate:"
         << setprecision(4) << monthly_rate_percent << "%\n";
    cout << setprecision(2);
    cout << setw(24) << "Number of Payments:" << number_of_payments << '\n';
    cout << setw(24) << "Monthly Payment:" << "$" << monthly_payment << '\n';
    cout << setw(24) << "Amount Paid Back:" << "$" << amount_paid_back << '\n';
    cout << setw(24) << "Interest Paid:" << "$" << interest_paid << '\n';

    return 0;
}
