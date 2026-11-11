# Lab 5: Compound Interest and Loan Payments

Peter Morales  
Course section: CIS-165-W099

## Compound Interest Plan

My program asks for the starting savings balance, annual interest rate, and number of compounding periods. I divide the percentage by 100 and store it as `rate`.

I use `amount = principal * pow(1.0 + rate / times_compounded, times_compounded)` to calculate the balance after one year. Then I subtract the starting balance to get `interest_earned`.
