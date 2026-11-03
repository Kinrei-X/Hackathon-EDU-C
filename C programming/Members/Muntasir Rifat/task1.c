#include <stdio.h>
int main (){
    int num;

    printf("Enter a number :");
    scanf("%d", &num);
    printf("Memory address: %p\n", &num);
    printf("Remainder divided by 2: %d\n", num%2);
    printf("Remainder divided by 5: %d\n", num%5);

}
