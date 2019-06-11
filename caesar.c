#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i=0, n=strlen(argv[1]); i<n; i++){
        if ((int) argv[1][i] > 57 || (int) argv[1][i] < 48) {
             printf("Usage: ./caesar key\n");
             return 1;
        }
    } 
    string plaintext = get_string("plaintext: ");
    for (int i=0, n=strlen(plaintext); i<n; i++) {
        if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z')) {
            plaintext[i] = (plaintext[i] - 'a' + atoi(argv[1])) % 26 + 'a';
        }
        else if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z')) {
            plaintext[i] = (plaintext[i] - 'A' + atoi(argv[1])) % 26 + 'A';
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
