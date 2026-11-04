#include<stdio.h>
int main(){
 int n;
    printf("Enter a number: ");
    scanf("%d", &n);
printf("Memory address of n: %p\n", &n);
 printf("Reminder when n is divided by 2: %d\n", n % 2);
printf("Reminder when n is divided by 5: %d\n", n % 5);
    return 0;

}