#include <stdio.h>

int main() {
    int pin = 1234;
    int enteredPin;
    int attempts = 3;
    int choice;
    int amount;
    int balance = 10000;
    int totalDeposited = 0;
    int totalWithdrawn = 0;
    int transactionCount = 0;
    int withdrawalLimit = 15000;
    int totalSessionWithdrawn = 0;
    int oldPin, newPin, confirmPin;

    printf("Welcome to the ATM Simulator!\n");

    while (attempts > 0) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            break;
        } else {
            attempts--;
            printf("Incorrect PIN. Attempts remaining: %d\n", attempts);
        }
    }

    if (attempts == 0) {
        printf("Card Blocked. Too many failed attempts.\n");
        return 0;
    }

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Session Summary\n");
        printf("5. Exit\n");
        printf("6. Change PIN\n");
        printf("Select an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid option\n");
            scanf("%*s");
            continue;
        }

        if (choice == 1) {
            printf("Current balance: %d\n", balance);
        } else if (choice == 2) {
            printf("Enter deposit amount: ");
            if (scanf("%d", &amount) != 1) {
                printf("Invalid amount.\n");
                scanf("%*s");
            } else if (amount <= 0) {
                printf("Deposit amount must be greater than zero.\n");
            } else {
                balance += amount;
                totalDeposited += amount;
                transactionCount++;
                printf("Deposit successful. New balance: %d\n", balance);
            }
        } else if (choice == 3) {
            printf("Enter withdrawal amount: ");
            if (scanf("%d", &amount) != 1) {
                printf("Invalid amount.\n");
                scanf("%*s");
            } else if (amount <= 0) {
                printf("Withdrawal amount must be greater than zero.\n");
            } else if (amount % 500 != 0) {
                printf("Withdrawal amount must be divisible by 500.\n");
            } else if (amount > balance) {
                printf("Insufficient funds.\n");
            } else if (amount > withdrawalLimit - totalSessionWithdrawn) {
                printf("Session withdrawal limit of 15000 exceeded.\n");
                printf("Remaining withdrawal limit: %d\n",
                       withdrawalLimit - totalSessionWithdrawn);
            } else {
                balance -= amount;
                totalWithdrawn += amount;
                totalSessionWithdrawn += amount;
                transactionCount++;

                printf("Withdrawal successful.\n");
                printf("1000 notes dispensed: %d\n", amount / 1000);
                printf("500 notes dispensed: %d\n", (amount % 1000) / 500);
                printf("New balance: %d\n", balance);
            }
        } else if (choice == 4) {
            printf("\n--- Session Summary ---\n");
            printf("Total deposited: %d\n", totalDeposited);
            printf("Total withdrawn: %d\n", totalWithdrawn);
            printf("Successful transactions: %d\n", transactionCount);
            printf("Current balance: %d\n", balance);
        } else if (choice == 5) {
            printf("\n--- Final Session Summary ---\n");
            printf("Total deposited: %d\n", totalDeposited);
            printf("Total withdrawn: %d\n", totalWithdrawn);
            printf("Successful transactions: %d\n", transactionCount);
            printf("Final balance: %d\n", balance);
            printf("Thank you for using the ATM Simulator.\n");
            return 0;
        } else if (choice == 6) {
            printf("Enter your current PIN: ");
            scanf("%d", &oldPin);

            if (oldPin != pin) {
                printf("Incorrect current PIN. PIN was not changed.\n");
            } else {
                printf("Enter a new 4-digit PIN: ");
                scanf("%d", &newPin);

                if (newPin < 1000 || newPin > 9999) {
                    printf("PIN must be a 4-digit number. PIN was not changed.\n");
                } else {
                    printf("Confirm your new PIN: ");
                    scanf("%d", &confirmPin);

                    if (confirmPin != newPin) {
                        printf("PIN confirmation does not match. PIN was not changed.\n");
                    } else {
                        pin = newPin;
                        printf("PIN changed successfully.\n");
                    }
                }
            }
        } else {
            printf("Invalid option\n");
        }
    }

    return 0;
}
