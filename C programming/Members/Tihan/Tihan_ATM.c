#include <stdio.h>

int main() {
    int pin = 1234, enteredPin, attempts, loggedIn = 0;
    int balance = 10000, choice, amount;
    int totalDeposited = 0, totalWithdrawn = 0, transactionCount = 0;
    int limit = 15000;

    /* PIN login */
    for (attempts = 1; attempts <= 3; attempts++) {
        printf("Enter 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            while (getchar() != '\n');
            enteredPin = -1;
        }
        if (enteredPin == pin) {
            loggedIn = 1;
            break;
        }
        printf("Wrong PIN. Attempts remaining: %d\n", 3 - attempts);
    }
    if (loggedIn == 0) {
        printf("Card Blocked. Too many failed attempts.\n");
        return 0;
    }

    /* Main menu */
    do {
        printf("\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n");
        printf("4. Session Summary\n5. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:
                printf("Balance: %d\n", balance);
                break;
            case 2:
                printf("Deposit amount: ");
                if (scanf("%d", &amount) != 1) {
                    while (getchar() != '\n');
                    amount = 0;
                }
                if (amount <= 0) {
                    printf("Invalid amount.\n");
                } else {
                    balance += amount;
                    totalDeposited += amount;
                    transactionCount++;
                    printf("Deposited %d.\n", amount);
                }
                break;
            case 3:
                printf("Withdraw amount: ");
                if (scanf("%d", &amount) != 1) {
                    while (getchar() != '\n');
                    amount = 0;
                }
                if (amount <= 0) {
                    printf("Invalid amount.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds.\n");
                } else if (totalWithdrawn + amount > limit) {
                    printf("Session withdrawal limit (%d) exceeded.\n", limit);
                } else {
                    balance -= amount;
                    totalWithdrawn += amount;
                    transactionCount++;
                    printf("Withdrawn %d.\n", amount);
                }
                break;
            case 4:
                printf("\n--- Session Summary ---\n");
                printf("Total Deposited : %d\n", totalDeposited);
                printf("Total Withdrawn : %d\n", totalWithdrawn);
                printf("Transactions    : %d\n", transactionCount);
                printf("Final Balance   : %d\n", balance);
                break;
            case 5:
                printf("\n--- Exit Receipt ---\n");
                printf("Total Deposited : %d\n", totalDeposited);
                printf("Total Withdrawn : %d\n", totalWithdrawn);
                printf("Transactions    : %d\n", transactionCount);
                printf("Final Balance   : %d\n", balance);
                printf("Thank you!, Made by Tihan\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (choice != 5);

    return 0;
}