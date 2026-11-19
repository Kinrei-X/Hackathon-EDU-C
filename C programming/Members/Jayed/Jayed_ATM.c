#include <stdio.h>

int main()
{
    // Account information
    int correctPIN = 1234;
    int balance = 10000;
    int newPIN;
    int confirmPIN;

    // Login information
    int enteredPIN;
    int attempts = 0;
    int loginSuccess = 0;

    // Menu information
    int choice;

    // Transaction information
    int amount;
    int totalDeposited = 0;
    int totalWithdrawn = 0;
    int transactionCount = 0;

    // Withdrawal limit
    int withdrawalLimit = 15000;

    // PIN Authentication System
    while (attempts < 3)
    {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == correctPIN)
        {
            printf("\nLogin Successful!\n");
            loginSuccess = 1;
            break;
        }
        else
        {
            attempts++;

            printf("Incorrect PIN!\n");
            printf("Attempts remaining: %d\n", 3 - attempts);
        }
    }

    if (loginSuccess == 0)
    {
        printf("\nCard Blocked. Too many failed attempts.\n");
        return 0;
    }

    // Main Banking Menu
    if (loginSuccess == 1)
    {
        do
        {
            printf("\n================================\n");
            printf("         MAIN BANKING MENU\n");
            printf("================================\n");

            printf("1. Check Balance\n");
            printf("2. Deposit Money\n");
            printf("3. Withdraw Money\n");
            printf("4. Session Summary\n");
            printf("5. Exit\n");
            printf("6. Change PIN\n");

            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("\n========== ACCOUNT BALANCE ==========\n");
                printf("Your Current Balance: BDT %d\n", balance);
                break;

            case 2:
                printf("\n========== DEPOSIT MONEY ==========\n");

                printf("Enter deposit amount: BDT ");
                scanf("%d", &amount);

                if (amount <= 0)
                {
                    printf("Invalid amount! Deposit must be greater than zero.\n");
                }
                else
                {
                    balance = balance + amount;

                    totalDeposited = totalDeposited + amount;

                    transactionCount++;

                    printf("\nDeposit Successful!\n");
                    printf("Deposited Amount: BDT %d\n", amount);
                    printf("Updated Balance: BDT %d\n", balance);
                }

                break;

            case 3:
                printf("\n========== WITHDRAW MONEY ==========\n");

                printf("Enter withdrawal amount: BDT ");
                scanf("%d", &amount);

                if (amount <= 0)
                {
                    printf("Invalid amount! Withdrawal must be greater than zero.\n");
                }
                else if (amount > balance)
                {
                    printf("Insufficient funds!\n");
                }
                else if (totalWithdrawn + amount > withdrawalLimit)
                {
                    printf("Withdrawal limit exceeded!\n");
                    printf("Maximum session withdrawal limit: BDT %d\n", withdrawalLimit);
                    printf("Already withdrawn: BDT %d\n", totalWithdrawn);
                }
                else
                {
                    balance = balance - amount;

                    totalWithdrawn = totalWithdrawn + amount;

                    transactionCount++;

                    printf("\nWithdrawal Successful!\n");
                    printf("Withdrawn Amount: BDT %d\n", amount);
                    printf("Remaining Balance: BDT %d\n", balance);
                }

                break;

            case 4:
                printf("\n================================\n");
                printf("         SESSION SUMMARY\n");
                printf("================================\n");

                printf("Initial Balance: BDT 10000\n");
                printf("Total Deposited: BDT %d\n", totalDeposited);
                printf("Total Withdrawn: BDT %d\n", totalWithdrawn);
                printf("Successful Transactions: %d\n", transactionCount);

                printf("--------------------------------\n");
                printf("Current Balance: BDT %d\n", balance);
                printf("================================\n");

                break;

            case 5:
                printf("\n================================\n");
                printf("           FINAL RECEIPT\n");
                printf("================================\n");

                printf("Initial Balance: BDT 10000\n");
                printf("Total Deposited: BDT %d\n", totalDeposited);
                printf("Total Withdrawn: BDT %d\n", totalWithdrawn);
                printf("Successful Transactions: %d\n", transactionCount);

                printf("--------------------------------\n");
                printf("Final Balance: BDT %d\n", balance);
                printf("================================\n");

                printf("\nThank you for using our ATM!\n");
                printf("Have a nice day!\n");

                break;

            case 6:
                printf("\n========== CHANGE PIN ==========\n");

                printf("Enter your old PIN: ");
                scanf("%d", &enteredPIN);

                if (enteredPIN == correctPIN)
                {
                    printf("Enter your new 4-digit PIN: ");
                    scanf("%d", &newPIN);

                    if (newPIN >= 1000 && newPIN <= 9999)
                    {
                        printf("Confirm your new PIN: ");
                        scanf("%d", &confirmPIN);

                        if (newPIN == confirmPIN)
                        {
                            correctPIN = newPIN;
                            printf("\nPIN changed successfully!\n");
                        }
                        else
                        {
                            printf("\nPIN confirmation does not match!\n");
                        }
                    }
                    else
                    {
                        printf("\nInvalid PIN! Enter exactly 4 digits.\n");
                    }
                }
                else
                {
                    printf("\nIncorrect old PIN! PIN change rejected.\n");
                }

                break;

            default:
                printf("\nInvalid option! Please try again.\n");
            }

        } while (choice != 5);
    }

    return 0;
}
