#include <stdio.h>
#include <string.h>

int str_palindrome(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;

    while (right > left) {
        if (str[left++] != str[right--]) {
            return 0;
        }
    }
    return 1;
}

void checkParity(int num)
{
    if(num % 2 == 0)
        printf("%d is even number.\n", num);
    else
        printf("%d is odd number.\n", num);
}

int main() {
    int num;
    char string[100];

    printf("Enter an integer to check palindrome: ");
    scanf("%d", &num);

    printf("Enter a string to check palindrome: ");
    scanf("%s", string);

    checkParity(num);

    if(str_palindrome(string))
        printf("%s is a palindrome.\n", string);
    else
        printf("%s is not a palindrome.\n", string);

        return 0;
}
