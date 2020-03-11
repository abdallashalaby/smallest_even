#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double result;
    int numbers[3];

    printf("Kindly enter 3 numbers to find the smallest possible even number!\n");
    printf("\n enter first number: ");
    scanf("%d", &numbers[0]);
    printf("\n enter second number: ");
    scanf("%d", &numbers[1]);
    printf("\n enter third number: ");
    scanf("%d", &numbers[2]);

    // sorting the array ascendingly
    for(int x = 0; x < 3; x++){
            for(int i = x; i < 3; i++){
                if(numbers[x] > numbers[i]){
                    int temp = numbers[i];
                    numbers[i] = numbers[x];
                    numbers[x] = temp;
                }
            }

    }

    int biggest_even = -1;
    for(int i = 2; i >= 0; i--){
        if(numbers[i] % 2 == 0)
            biggest_even = numbers[i];
    }

    // return error if the user entered only odd numbers
    if(biggest_even == -1){
        printf("ERROR: can not form an even number\n none of the numbers you entered is even");
        return 1;
    }

    // forming the number by putting the biggest even number in the units,
    // then add the rest of numbers in tens and hundreds descendingly
    result = biggest_even;
    for(int i = 2, c = 1; i >= 0; i--){
        if(numbers[i] != biggest_even){
            result += numbers[i] * pow(10.0, c);
            c++;
            }
    }
    printf("\n\n\t\t*************************************************************************");
    printf("\n\t\t*\t\tthe smallest possible even number is: %d \t\t*", (int)result);
    printf("\n\t\t*************************************************************************\n");

    return 0;
}
