// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: $");
    float tax_percent = get_float("Sale Tax Percent: %%");
    int tip_percent = get_int("Tip percent: %%");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

float half(float bill, float tax, int tip)
{
    // Calculates the tax added to the bill
    float tax_value = ((float) tax / 100.0) * (float) bill;

    // Calculates the tip
    float tip_value = ((float) tip / 100.0) * (float)(bill + tax_value);

    // Calculates the final amount for each
    float half = (tip_value + tax_value + bill) / 2.0;
    return half;
}
