// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <math.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float half_value;

    // Get sale tax value
    float tax_value = (bill / 100) * tax;

    // Get tip value
    float tip_value = (bill + tax_value) / 100 * (float) tip;

    // Get final value
    float final_value = bill + tax_value + tip_value;

    // Get half value
    half_value = final_value / 2;

    return half_value;
}
