#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 10

// Function to check if a string is palindrome
int is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random palindrome of a given length
void generate_palindrome(char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        str[i] = 'a' + rand() % 26;
        str[len - 1 - i] = str[i];
    }
    if (len % 2) {
        str[len / 2] = 'a' + rand() % 26;
    }
    str[len] = '\0';
}

// Factorial function to check howw many palindromes
long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Count permutations for palindrome
long long combinations(char *str) {
    int count[26] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        count[str[i] - 'a']++;
    }

    long long num = factorial(len / 2);
    for (int i = 0; i < 26; i++) {
        if (count[i]) {
            num /= factorial(count[i] / 2);
        }
    }

    return num * num;
}

int main() {
    srand(time(NULL));// time function
    char palindrome[MAX_LEN + 1];//array to store string

    generate_palindrome(palindrome, MAX_LEN);//function called to generate palindrome
    printf("Generated palindrome: %s\n", palindrome);

    long long perms = combinations(palindrome);//function called to determine how many palindromes canb e generated
    printf("Number of unique permutations that are palindromes: %lld\n", perms);

    return 0;
}
