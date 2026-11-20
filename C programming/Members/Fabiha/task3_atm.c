#include <stdio.h>

int main()
{
    //Variable Declaration

  int correctPin =1234;
  int pin , attempt;
  int loggedIn = 0;
  int choice;
  int balance =10000;
  int deposit , withdraw;

  int totalDeposited =0;
  int totalWithdrawn =0;
  int transactionCount =0;
  // 1 : PIN Security System
  printf("=======================\n");
  printf("  WELCOME TO SMART ATM\n");
  printf("=======================\n");
  for (attempt =1; attempt <=3; attempt++)
  {
    printf("\nEnter your 4-digit PIN: ");
    scanf("%d", &pin);

    if (pin ==correctPin)
    {
        printf("\nLogin Successful!\n");
        loggedIn =1;
        break;
    }
  else
  {
    printf("\nIncorrect PIN!\n");
    if (attempt <3)
    {
        printf("attempts remaining %d\n", 3 - attempt);
    }
  }

}
//Card Blocking System
if(loggedIn ==0)
  {
printf("\nCard Blocked . Too many failed attempts.\n");
  return 0;
}
//2.MAIN BANKING MENU 
do
{
 printf("\n=======================\n");
 printf("  MAIN BANKING MENU\n");
 printf("=========================\n");

 printf("1. Check Balance\n");
 printf("2. Deposit Money\n");
 printf("3. Withdraw Money\n");
 printf("4. Session Summary\n");
 printf("5. Exit\n");

 printf("\nEnter your choice: ");
 scanf("%d", &choice);

 switch (choice)
 {
   //OPTION 1 : CHECK BALANCE
    case 1 :
     printf("\nCurrent Balance: %d TAKA\n",balance);
     
     break;
     //OPTION 2 : DEPOSIT MONEY 
     case 2 :

     printf("\nEnter deposit amount: ");
     scanf("%d", &deposit);

     if (deposit <= 0)
     {
      printf("\nInvalid deposit amount!\n");
     }
     else
     {
      balance = balance + deposit ;
      totalDeposited = totalDeposited + deposit;
      transactionCount++;
      printf("\nDeposit Successful!\n");
      printf("Deposited Amount:%d Taka\n", deposit);
      printf("New Balance: %d Taka\n", balance);
     }

     break;
     // OPTION 3 : WITHDRAW MONEY 

     case 3 :
      printf("\nEnter withdrawal amount: ");
      scanf("%d", &withdraw);
      if (withdraw <= 0)
      {
        printf("\nInvalid withdrawal amount!\n");
      }
      else if(withdraw > balance)
      {
        printf("\nInsufficient funds!\n");
      }
      else if (withdraw > (15000 - totalWithdrawn))
      {
         printf("\nSession withdrawal limit exceeded!\n");

         printf("Remaining withdrawal limit: %d Taka\n", 15000- totalWithdrawn);
      }
      else
      {
        balance = balance - withdraw;
        totalWithdrawn = totalWithdrawn + withdraw;
        transactionCount++;

        printf("\nWithdrawal Successful!\n");
        printf("New Balance: %d Taka\n", balance);
      }

      break;

    //OPTION 4 : SESSION SUMMARY

    case 4:

    printf("\n=============================\n");
    printf("  SESSION SUMMARY\n");
    printf("===============================\n");

    printf("Total Deposited : %d Taka\n", totalDeposited);

    printf("Total Withdrawn : %d Taka\n", totalWithdrawn);

    printf("Total Transactions : %d\n", transactionCount);

    printf("Final Balance: %d\n", balance);

    break;

    //option 5: EXIT

    case 5 :

    printf("\n=======================\n");
    printf("    EXIT RECEIPT\n");
    printf("========================\n");

    printf("Total Deposited: %d Taka\n", totalDeposited);

    printf("Total Withdrawn : %d Taka\n", totalWithdrawn);

    printf("Final Balance : %d Taka\n", balance);

    printf("\nThank you for using SMART ATM!\n");

    break;

    // INVAILD MENU CHOICE

    default:

     printf("\nInvaild option! Please try again.\n");

     }

  
   } while(choice !=5); 
   return 0;

}
