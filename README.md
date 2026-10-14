[README(1).md](https://github.com/user-attachments/files/33416074/README.1.md)
# Lab 5: Compound Interest and Loan Payments
Peter Morales 
Course section: CIS-165-W099

## Compound Interest Plan

We are going to ask for the starting savings balance, annual interest rate, and compounding periods. Divide the percentage by 100 and store it as `rate`. Use `amount = principal * pow(1.0 + rate / times_compounded, times_compounded)` to calculate the balance after one year. Subtract the starting balance and store it as `interest_earned`. Display the annual rate, compounding periods, principal, interest earned, and amount in savings. First test $1,000 at 4.25% compounded 12 times. Then test $6,326 at 33% compounded quarterly, or four times a year, calculating the expected results before running it.

## Loan Payment Plan

We are going to ask for the loan amount, annual rate, and payment count. Divide the percentage by 100, then by 12, and store it as `monthly_rate`. Use `pow(1.0 + monthly_rate, number_of_payments)` and store it as `power_term`. Calculate `monthly_payment = monthly_rate * power_term / (power_term - 1.0) * loan_amount`. Multiply the payment, keeping all available decimal places, by the payment count to get `amount_paid_back`. Subtract the loan amount to get `interest_paid`. Display the loan amount, monthly rate, payment count, monthly payment, total paid, and interest paid. First test $10,000 at 12% with 36 payments. Then make ours an $11,110 loan at 22% with 12 payments. Calculate the expected results before running the tests and compare them with the output.

## Variables

Each variable is declared on its own line. Balances, rates, and results use `double`. Counts use `int`. `MONTHS_PER_YEAR` is a constant set to 12.

### Compound interest

`principal` - Starting savings balance  
`annual_rate` - Annual percentage entered by the user  
`times_compounded` - Compounding periods in one year  
`rate` - Annual percentage divided by 100  
`amount` - Savings balance after one year  
`interest_earned` - Final balance minus starting balance  

### Loan payment

`MONTHS_PER_YEAR` - Fixed value of 12  
`loan_amount` - Starting loan balance  
`annual_rate` - Annual percentage entered by the user  
`number_of_payments` - Total monthly payments over the loan  
`monthly_rate` - Annual percentage divided by 100 and 12  
`power_term` - Result of the power calculation  
`monthly_payment` - Payment each month  
`amount_paid_back` - Payment multiplied by payment count  
`interest_paid` - Total paid minus loan amount  
`monthly_rate_percent` - Monthly decimal rate times 100 for display  

## Compile and Run

Use a terminal in the folder containing the source files. A C++ compiler such as g++ must be installed.

```bash
g++ -std=c++17 -Wall -Wextra compound_interest.cpp -o compound_interest
./compound_interest

g++ -std=c++17 -Wall -Wextra loan_payment.cpp -o loan_payment
./loan_payment
```

Enter numbers without dollar signs, commas, or percent signs. For quarterly compounding, enter 4. Run each program again for its second test. Enter positive balances and rates and positive whole-number counts. These programs are intended for the positive-input cases in this lab; the loan program rejects a zero rate.

Both programs use `fixed`, `setprecision(2)`, and `setw` for monetary reports. The loan's monthly percentage is displayed to four decimal places. Display formatting does not change the stored values.

## Expected Calculations

Expected results were calculated before the test runs and checked separately with Python Decimal arithmetic.

1. Assigned savings: `1000 * (1 + 0.0425 / 12)^12 = 1043.3377163096...`. Subtract 1000 for interest of `43.3377163096...`.
2. Changed savings: `6326 * (1 + 0.33 / 4)^4 = 8686.4196685721...`. Subtract 6326 for interest of `2360.4196685721...`.
3. Assigned loan: monthly rate `12 / 100 / 12 = 0.01`. Let `q = (1.01)^36`. Payment `10000 * 0.01 * q / (q - 1) = 332.1430981285...`. Total paid is `11957.1515326264...`; interest is `1957.1515326264...`.
4. Changed loan: monthly rate `22 / 100 / 12 = 0.0183333333...`. Let `q = (1 + 0.22 / 12)^12`. Payment `11110 * (0.22 / 12) * q / (q - 1) = 1039.8335578236...`. Total paid is `12478.0026938829...`; interest is `1368.0026938829...`.

Here, `^` means a mathematical exponent in the written calculations. The C++ programs use `pow`, not `^`.

## Test Results

Recorded C++ test results are below. Personal verification on my computer is pending.

**Compound interest: assigned**

Inputs - 1000, 4.25%, 12  
Expected results - Interest $43.34; savings $1,043.34  
Actual results - Interest $43.34; savings $1,043.34  
Match or correction - Match  

**Compound interest: changed**

Inputs - 6326, 33%, 4  
Expected results - Interest $2,360.42; savings $8,686.42  
Actual results - Interest $2,360.42; savings $8,686.42  
Match or correction - Match  

**Loan payment: assigned**

Inputs - 10000, 12%, 36  
Expected results - Payment $332.14; total $11,957.15; interest $1,957.15  
Actual results - Payment $332.14; total $11,957.15; interest $1,957.15  
Match or correction - Match  

**Loan payment: changed**

Inputs - 11110, 22%, 12  
Expected results - Payment $1,039.83; total $12,478.00; interest $1,368.00  
Actual results - Payment $1,039.83; total $12,478.00; interest $1,368.00  
Match or correction - Match  

Both source files compiled successfully with the commands above and produced no warnings. Additional checks rejected a negative balance, a zero period/payment count, and nonnumeric input. No calculation corrections were needed for the four financial tests.

## Explain the Code

1. **Why divide a percentage by 100?** Percent means out of 100. Dividing 33 by 100 gives 0.33, which is the value needed in the formula.

2. **How does pow represent exponentiation?** `pow(base, exponent)` raises the first number to the power of the second. For example, `pow(2, 3)` gives 8.

3. **What do compounding periods change?** They control how often interest is added. More frequent compounding earns more interest on earlier interest when the annual rate is positive.

4. **How is the annual rate converted to monthly?** Divide the annual percentage by 100, then by 12. An annual rate of 12% becomes 0.01 per month, or 1%.

5. **Why use double?** Balances and rates contain decimals. `double` stores decimal values with more precision than `float`. An `int` cannot keep the fractional part.

6. **Why keep full precision?** Rounding during calculations can change the totals. For example, $332.14 times 36 gives $11,957.04, but using the stored payment of about 332.143098 gives $11,957.15. Only the displayed money is rounded to two decimal places.

7. **How are total paid and interest calculated?** Multiply the monthly payment by the number of payments for the total paid. Subtract the original loan amount from that total for the interest paid.

8. **Why store calculations in variables?** Variables name the results so they are easier to check and reuse. This also keeps formulas out of `cout`.
