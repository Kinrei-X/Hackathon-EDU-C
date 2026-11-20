#include <stdio.h>

int main() {
    // Security & Account State Variables
    int pin = 1234;
    int enteredPin;
    int attempts = 0;
    int maxAttempts = 3;
    int isAuthenticated = 0;

    // Financial & Tracking Variables
    int balance = 10000;
    int sessionWithdrawLimit = 15000;
    int totalDeposited = 0;
    int totalWithdrawn = 0;
    int transactionCount = 0;

    int choice;
    int amount;

    // 1. PIN Login Loop
    printf("=== WELCOME TO SMART ATM ===\n");
    while (attempts < maxAttempts) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            isAuthenticated = 1;
            printf("Login successful!\n");
            break;
        } else {
            attempts++;
            if (attempts < maxAttempts) {
                printf("Incorrect PIN. Attempts remaining: %d\n", maxAttempts - attempts);
            }
        }
    }

    if (isAuthenticated == 0) {
        printf("\nCard Blocked. Too many failed attempts.\n");
        return 0;
    }

    // 2. Main Banking Menu Loop
    do {
        printf("\n----------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Session Summary\n");
        printf("5. Change PIN (Bonus)\n");
        printf("6. Exit\n");
        printf("----------------------------\n");
        printf("Select an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCurrent Balance: %d BDT\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%d", &amount);

                if (amount <= 0) {
                    printf("Error: Deposit amount must be greater than 0.\n");
                } else {
                    balance += amount;
                    totalDeposited += amount;
                    transactionCount++;
                    printf("Successfully deposited %d BDT.\n", amount);
                    printf("Updated Balance: %d BDT\n", balance);
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw (multiples of 500): ");
                scanf("%d", &amount);

                if (amount <= 0) {
                    printf("Error: Withdrawal amount must be greater than 0.\n");
                } else if (amount % 500 != 0) {
                    printf("Error: ATM only dispenses 500 and 1000 BDT notes.\n");
                } else if (amount > balance) {
                    printf("Error: Insufficient funds. Available balance: %d BDT\n", balance);
                } else if (totalWithdrawn + amount > sessionWithdrawLimit) {
                    printf("Error: Exceeds session withdrawal limit of %d BDT.\n", sessionWithdrawLimit);
                    printf("Remaining limit for this session: %d BDT\n", sessionWithdrawLimit - totalWithdrawn);
                } else {
                    balance -= amount;
                    totalWithdrawn += amount;
                    transactionCount++;

                    // Bonus: Note breakdown
                    int notes1000 = amount / 1000;
                    int notes500 = (amount % 1000) / 500;

                    printf("Please collect your cash: %d BDT\n", amount);
                    printf("Notes Dispensed -> 1000 BDT: %d | 500 BDT: %d\n", notes1000, notes500);
                    printf("Updated Balance: %d BDT\n", balance);
                }
                break;

            case 4:
                printf("\n=== SESSION SUMMARY ===\n");
                printf("Total Transactions : %d\n", transactionCount);
                printf("Total Deposited    : %d BDT\n", totalDeposited);
                printf("Total Withdrawn    : %d BDT\n", totalWithdrawn);
                printf("Current Balance    : %d BDT\n", balance);
                break;

            case 5: {
                int oldPin, newPin, confirmPin;
                printf("\nEnter current PIN: ");
                scanf("%d", &oldPin);

                if (oldPin != pin) {
                    printf("Error: Incorrect current PIN.\n");
                } else {
                    printf("Enter new 4-digit PIN: ");
                    scanf("%d", &newPin);
                    printf("Confirm new 4-digit PIN: ");
                    scanf("%d", &confirmPin);

                    if (newPin < 1000 || newPin > 9999) {
                        printf("Error: PIN must be a 4-digit number (1000-9999).\n");
                    } else if (newPin != confirmPin) {
                        printf("Error: PINs do not match.\n");
                    } else {
                        pin = newPin;
                        printf("PIN updated successfully!\n");
                    }
                }
                break;
            }

            case 6:
                printf("\n=== FINAL EXIT RECEIPT ===\n");
                printf("Total Transactions : %d\n", transactionCount);
                printf("Total Deposited    : %d BDT\n", totalDeposited);
                printf("Total Withdrawn    : %d BDT\n", totalWithdrawn);
                printf("Final Balance      : %d BDT\n", balance);
                printf("Thank you for using Smart ATM!\n");
                break;

            default:
                printf("\nInvalid option. Please choose between 1 and 6.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}