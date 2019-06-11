#include <cs50.h>
#include <stdio.h>

int length_num(long num);
bool luhns_algorithm(long num);
int first_digit(long num);
int first_two_digits(long num);
bool value_in_array(int val, int arr[], int size);

int main(void)
{
    int am_ex[2] = { 34, 37 };
    int mastercard[5] = {51, 52, 53, 54, 55};
    long credit_card_num;
    credit_card_num = get_long("Number: ");
    int credit_card_num_length = length_num(credit_card_num);
    int first_two = first_two_digits(credit_card_num);
    if (!luhns_algorithm(credit_card_num)) {
        printf("INVALID\n");
    } 
    else if (first_digit(credit_card_num) == 4) {
        if (credit_card_num_length == 13 || credit_card_num_length == 16) {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else if (value_in_array(first_two, am_ex, 2)) {
        if (credit_card_num_length == 15) {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    }
    else if (value_in_array(first_two, mastercard, 5)) {
        if (credit_card_num_length == 16) {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}

int length_num(long num) {
    if (num < 10) 
    {
        return 1;
    } 
    else 
    {
        return 1 + length_num(num / 10);
    }
}

int sum_digits(int num) {
    if (num < 10) {
        return num;
    }
    else {
        return num % 10 + sum_digits(num / 10);
    }
}

bool luhns_algorithm(long num) {
    int final_sum = 0;
    while (num >= 10) {
        final_sum += (num % 10);
        num /= 10;
        final_sum += sum_digits(2 * (num % 10));
        num /= 10;
    }
    final_sum += num;
    if (final_sum % 10 == 0) {
        return true;
    } else {
        return false;
    }
}

int first_digit(long num) {
    while (num > 10) {
        num /= 10;
    }
    return num;
}
int first_two_digits(long num) {
    while (num > 100) {
        num /= 10;
    }
    return num;
}

bool value_in_array(int val, int arr[], int size) {
    for (int i=0; i < size; i++) {
        if (val == arr[i]) {
            return true;
        }
    }
    return false;
}
