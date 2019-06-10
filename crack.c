#define _XOPEN_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const string NOTFOUND = "password not found";
string decrypt_password(string tablesalt, string hash, string alphabet, string password, int max_char);
string iterative_decrypt(string tablesalt, string hash, string alphabet, string password, int max_char, int curr_num_char);

int main(int argc, string argv[])
{
    
    if (argc != 2) {
        printf("Usage: ./crack hash");
        return 1;
    }
    char alphabet[53] = {};
    for (char c='a'; c <= 'z'; c++) {
        char tempstring[2] = {c};
        strcat(alphabet, tempstring);
    }
    for (char c='A'; c <= 'Z'; c++) {
        char tempstring[2] = {c};
        strcat(alphabet, tempstring);
    }
    alphabet[52] = '\0';
    char tablesalt[3] = { argv[1][0], argv[1][1], '\0' };
    string password = "";
    string decrypted = iterative_decrypt(tablesalt, argv[1], alphabet, password, 5, 1);
    printf("%s\n", decrypted);
    return 0;
}

string iterative_decrypt(string tablesalt, string hash, string alphabet, string password, int max_char, int curr_num_char) {
    if (curr_num_char > max_char) {
        return NOTFOUND;
    }
    string decrypted = decrypt_password(tablesalt, hash, alphabet, password, curr_num_char);
    if (strlen(decrypted) <= 5) {
        return decrypted;
    } else {
        return iterative_decrypt(tablesalt, hash, alphabet, password, 5, curr_num_char + 1);
    }
}

string decrypt_password(string tablesalt, string hash, string alphabet, string password, int max_char) {
    if (strlen(password) < max_char) {
        for (int i=0, n=strlen(alphabet); i<n; i++) {
            char tempstring[2] = {alphabet[i], '\0'};
            string dup_password = strdup(password);
            strcat(dup_password, tempstring);
            string returned_password = decrypt_password(tablesalt, hash, alphabet, dup_password, max_char);
            if (strlen(returned_password) < 6) {
                return returned_password;
            }
        }
        return NOTFOUND;
    } else if (strlen(password) == max_char) {
        string decrypted_hash = crypt(password, tablesalt);
        if (strcmp(decrypted_hash,hash)==0) {
            return password;
        } else {
            return NOTFOUND;
        }
    } else {
        return NOTFOUND;
    }
}
