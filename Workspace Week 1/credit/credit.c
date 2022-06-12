#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long getCardNumber(void);
int getCardLength(long long cardNumber);
int LuhnsAlgorithm(long long cc);
void checkCompany(long long cc);
int main(void)
{
    //4003600000000014
    //378282246310005
    long long cardNumber = getCardNumber(); //Using long long because it stores more digits than long
    int cardlen = getCardLength(cardNumber);
    checkCompany(cardNumber);
}


long long getCardNumber(void)
{
    long long returnvalue;

    returnvalue = get_long("Number: ");

    return returnvalue;
}

int getCardLength(long long cardNumber)
{
    return floor(log10(llabs(cardNumber))) + 1; // Gets the length of the number...
}
void toArray(long long cc, int digits[])
{
    int i = 0;

    while (cc > 0)
    {
        digits[i] = cc % 10;
        cc /= 10;
        i++;
    }

}
int LuhnsAlgorithm(long long cc) // Implements Luhn's Algorithm...
{
    int length = getCardLength(cc);

    int arr[length];

    toArray(cc, arr); // Converting cc into an array of digits...

    int sum = 0;

    for (int i = 0; i < length; i++) // Looping through array of digits...
    {
        int digit = arr[i];
        if (i % 2 != 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
    }
    return sum % 10;
}

void checkCompany(long long cc)
{
    int length = getCardLength(cc) - 1;

    int arr[length];

    toArray(cc, arr);
    int correct = LuhnsAlgorithm(cc);
    if (correct != 0)
    {
        printf("INVALID\n");
        return;
    }
    if ((length + 1 != 13) && (length + 1 != 15) && (length + 1 != 16))
    {
        // If the card isn't the specified lengths than it's Invalid
        printf("INVALID\n");
        return;
    }
    if ((arr[length] == 3 && arr[length - 1] == 7 && correct == 0) || (arr[length] == 3 && arr[length - 1] == 4 && correct == 0))
    {
        // Checking American Express Numbers
        printf("AMEX\n");
        return;
    }
    else if ((arr[length] == 5 && arr[length - 1] == 1 && correct == 0) || (arr[length] == 5 && arr[length - 1] == 2 && correct == 0))
    {
        printf("MASTERCARD\n");
        return;
    }
    else if ((arr[length] == 5 && arr[length - 1] == 3 && correct == 0) || (arr[length] == 5 && arr[length - 1] == 4 && correct == 0))
    {
        printf("MASTERCARD\n");
        return;
    }
    else if ((arr[length] == 5 && correct == 0) && (arr[length - 1] == 5 && correct == 0)) // Checking mastercard numbers...
    {
        printf("MASTERCARD\n");
        return;
    }
    if (arr[length] == 4 && correct == 0)// Checking Visa numbers...
    {
        printf("VISA\n");
        printf(""); // IMPORTANT if you remove this empty printf you will get a segmentation fault.
        return;
    }
    else // If the rest of the checks are false than we can assume it's invalid...
    {
        printf("INVALID\n");
        return;
    }

}