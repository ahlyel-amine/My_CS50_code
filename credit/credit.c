#include <cs50.h>
#include <stdio.h>
#include <math.h>


int get_digits(double nbr);
int check_checksum(double nbr, int digits);
int check_amex(double nbr, int digits);
int check_16(double nbr, int digits);
int check_13(double nbr, int digits);
int check_leng(int digits);
int checksum(double nbr, int digits, int mult, int jump);
int add_checksum(int checksum, int current_checksum);

int main(void)
{
    double  nbr;
    int     digits;

    nbr = get_long("Number: "); // get the card number
    digits = get_digits(nbr); // call function that count number of digits
    if (!check_leng(digits)) //
    {
        return 0;
    }
    else if (!check_checksum(nbr, digits))
    {
        return 0;
    }
    else if (!check_amex(nbr, digits))
    {
        return 0;
    }
    else if (!check_16(nbr, digits))
    {
        return 0;
    }
    else if (!check_13(nbr, digits))
    {
        return 0;
    }
}

int check_13(double nbr, int digits)
{
    int strt;

    strt = (int)(nbr / pow(10, digits - 1));
    if (digits == 13)//at this point the checksum is validated if number of digits is 15
    {
        if (strt == 4)
        {
            printf("VISA\n");// and the card number start with 34 / 37 is a AMEX card
            return 0;
        }
        printf("INVALID\n");
        return 0;
    }
    return 1;
}

int check_16(double nbr, int digits)
{
    int strt;

    strt = (int)(nbr / pow(10, digits - 2));
    if (digits == 16)//at this point the checksum is validated if number of digits is 15
    {
        if (strt == 51 || strt == 52 || strt == 53 || strt == 54 || strt == 55)
        {
            printf("MASTERCARD\n");// and the card number start with 51/52/53/54/55 is a MASTERCARD card
            return 0;
        }
        else if (strt / 10 == 4)
        {
            printf("VISA\n");// and the card number start with 4 is a VISA card
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    return 1;
}

int check_amex(double nbr, int digits)
{
    int strt;

    strt = (int)(nbr / pow(10, digits - 2));
    if (digits == 15) //at this point the checksum is validated if number of digits is 15
    {
        if (strt == 34 || strt == 37) // and the card number start with 34 / 37 is a AMEX card
        {
            printf("AMEX\n");
            return 0;
        }
        printf("INVALID\n");
        return 0;
    }
    return 1;
}

int check_checksum(double nbr, int digits)
{
    int sum;
    // for the parameter number 4 : if we have 16 number we strat callculating checksum from first digit from left for the first step and from the second for the second step
    if (digits == 16)
    {
        sum = checksum(nbr, digits, 2, 1);  // for parameter number 3 describe mult for the checksum calc for the first step is 2
        sum += checksum(nbr, digits, 1, 2);  // for parameter number 3 describe mult for the checksum calc for the first step is 1
    }
    else// for the parameter number 4 : if we have 16 number we strat callculating checksum from second  digit from left for the first step and from the first for the second step
    {
        sum = checksum(nbr, digits, 2, 2);
        sum += checksum(nbr, digits, 1, 1);
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    return 1;
}

int check_leng(int digits)
{
    if (digits != 13 && digits != 15 && digits != 16) // if number of digits invalid print INVALID program stop
    {
        printf("INVALID\n");
        return 0;
    }
    return 1;
}

int get_digits(double nbr) //function that count number of digits
{
    int digits;

    digits = 0;
    while (nbr  > 1)
    {
        nbr /= 10;
        digits++;
    }
    return (digits);
}

int add_checksum(int checksum, int current_checksum) // function do the addition for checksum
{
    if (current_checksum < 10)
    {
        checksum += current_checksum;
    }
    else // for take the  units and take the dozens like units
    {
        checksum += (int)(current_checksum / 10);
        checksum += (int)(current_checksum % 10);
    }
    return checksum;
}

int checksum(double nbr, int digits, int mult, int jump)
{
    int checksum, current_checksum;

    checksum = 0;
    while (digits > 0) // loop each digit
    {
        jump -= 1;
        current_checksum = (int)(nbr / pow(10, digits - 1));
        current_checksum *= mult;
        if (jump == 0) //
        {
            checksum = add_checksum(checksum, current_checksum); // call function  do the addition for checksum
            jump += 2;  // for jump from digit to the next by 2 steps { cause loop jump by 1 step}
        }
        nbr -= (current_checksum / mult) * pow(10, digits - 1); // do subtraction for digits already taken
        digits--;
    }
    return checksum;
}