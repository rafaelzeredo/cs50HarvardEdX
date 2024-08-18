// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
    // printf("%.2f", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float billTotal = 0;
    float tipf = 0;
    // make tip int into float
    tipf = tip;
    // calculate decimal of tax
    billTotal = (tax/100);
    billTotal = billTotal * bill;
    // add tax to total bill before tip
    billTotal = billTotal + bill;
    // calculate tip after bill tax added
    tipf = tipf/100;
    tipf = tipf * billTotal;
    // Add tip ammount and split the bill
    billTotal = (billTotal + tipf) / 2;
    bill = billTotal;
    return bill;
}
