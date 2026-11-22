
#include <stdio.h>
#include <limits.h>

int main() {

    // 1. PIN Security System
    int correctPIN = 1234;
    int enteredPIN;
    int attempts = 0;
    int loginSuccess = 0;

    // 2. Account Information
    int initialBalance = 10000;
    int balance = 10000;

    int choice;
    int amount;

    // 3. Transaction Tracking
    int totalDeposited = 0;
    int totalWithdrawn = 0;
    int transactionCount = 0;

    int withdrawalLimit = 15000;

    // 4. PIN Change Variables
    int oldPIN, newPIN, confirmPIN;

    // 5. Denomination Variables
    int thousandNotes;
    int fiveHundredNotes;

    // 6. Input Handling
    int ch;

    // ==========================================
    //             PIN VERIFICATION
    // ==========================================

    while (attempts < 3) {

        printf("\nEnter your 4-digit PIN: ");

        if (scanf("%d", &enteredPIN) != 1) {

            if (feof(stdin)) {
                return 0;
            }

            printf("Invalid input! Enter numbers only.\n");

            while ((ch = getchar()) != '\n' && ch != EOF) {
            }

            attempts++;

            printf("Attempts remaining: %d\n", 3 - attempts);

            continue;
        }

        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        if (enteredPIN == correctPIN) {

            printf("\nLogin Successful!\n");

            loginSuccess = 1;

            break;
        }

        else {

            attempts++;

            printf("Incorrect PIN!\n");
            printf("Attempts remaining: %d\n", 3 - attempts);
        }
    }

    if (loginSuccess == 0) {

        printf("\nCard Blocked. Too many failed attempts.\n");

        return 0;
    }

    // ==========================================
    //                MAIN MENU
    // ==========================================

    do {

        printf("\n========================================\n");
        printf("          SMART ATM BANKING SYSTEM\n");
        printf("========================================\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Session Summary\n");
        printf("5. Exit\n");
        printf("6. Change PIN\n");

        printf("----------------------------------------\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {

            if (feof(stdin)) {
                return 0;
            }

            printf("\nInvalid option! Please enter a number.\n");

            while ((ch = getchar()) != '\n' && ch != EOF) {
            }

            continue;
        }

        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        switch (choice) {

            // ==================================
            //          1. CHECK BALANCE
            // ==================================

            case 1:

                printf("\n========== ACCOUNT BALANCE ==========\n");

                printf("Current Balance: BDT %d\n", balance);

                break;


            // ==================================
            //          2. DEPOSIT MONEY
            // ==================================

            case 2:

                printf("\n========== DEPOSIT MONEY ==========\n");

                printf("Enter deposit amount: BDT ");

                if (scanf("%d", &amount) != 1) {

                    if (feof(stdin)) {
                        return 0;
                    }

                    printf("Invalid input! Enter numbers only.\n");

                    while ((ch = getchar()) != '\n' && ch != EOF) {
                    }

                    break;
                }

                while ((ch = getchar()) != '\n' && ch != EOF) {
                }

                if (amount <= 0) {

                    printf("Invalid amount! Deposit must be greater than zero.\n");
                }

                else if (amount > INT_MAX - balance) {

                    printf("Deposit rejected! Balance limit exceeded.\n");
                }

                else if (amount > INT_MAX - totalDeposited) {

                    printf("Deposit rejected! Session total limit exceeded.\n");
                }

                else if (transactionCount == INT_MAX) {

                    printf("Transaction count limit reached.\n");
                }

                else {

                    balance = balance + amount;

                    totalDeposited = totalDeposited + amount;

                    transactionCount++;

                    printf("\nDeposit Successful!\n");

                    printf("Deposited Amount: BDT %d\n", amount);

                    printf("Updated Balance: BDT %d\n", balance);
                }

                break;


            // ==================================
            //          3. WITHDRAW MONEY
            // ==================================

            case 3:

                printf("\n========== WITHDRAW MONEY ==========\n");

                printf("Enter withdrawal amount: BDT ");

                if (scanf("%d", &amount) != 1) {

                    if (feof(stdin)) {
                        return 0;
                    }

                    printf("Invalid input! Enter numbers only.\n");

                    while ((ch = getchar()) != '\n' && ch != EOF) {
                    }

                    break;
                }

                while ((ch = getchar()) != '\n' && ch != EOF) {
                }

                if (amount <= 0) {

                    printf("Invalid amount! Withdrawal must be greater than zero.\n");
                }

                else if (amount > balance) {

                    printf("Insufficient funds!\n");
                }

                else if (amount > withdrawalLimit - totalWithdrawn) {

                    printf("\nWithdrawal limit exceeded!\n");

                    printf("Session Withdrawal Limit: BDT %d\n",
                           withdrawalLimit);

                    printf("Already Withdrawn: BDT %d\n",
                           totalWithdrawn);

                    printf("Remaining Withdrawal Limit: BDT %d\n",
                           withdrawalLimit - totalWithdrawn);
                }

                else if (amount % 500 != 0) {

                    printf("\nInvalid amount!\n");

                    printf("ATM only dispenses BDT 500 and BDT 1000 notes.\n");

                    printf("Enter an amount divisible by 500.\n");
                }

                else if (transactionCount == INT_MAX) {

                    printf("Transaction count limit reached.\n");
                }

                else {

                    // Calculate denomination breakdown

                    thousandNotes = amount / 1000;

                    fiveHundredNotes = (amount % 1000) / 500;

                    // Update account

                    balance = balance - amount;

                    totalWithdrawn = totalWithdrawn + amount;

                    transactionCount++;

                    printf("\nWithdrawal Successful!\n");

                    printf("Withdrawn Amount: BDT %d\n", amount);

                    printf("Remaining Balance: BDT %d\n", balance);

                    printf("\n----- DENOMINATION BREAKDOWN -----\n");

                    printf("1000 Taka Notes: %d\n", thousandNotes);

                    printf("500 Taka Notes: %d\n", fiveHundredNotes);

                    printf("----------------------------------\n");

                    printf("Remaining Withdrawal Limit: BDT %d\n",
                           withdrawalLimit - totalWithdrawn);
                }

                break;


            // ==================================
            //          4. SESSION SUMMARY
            // ==================================

            case 4:

                printf("\n========== SESSION SUMMARY ==========\n");

                printf("Initial Balance: BDT %d\n", initialBalance);

                printf("Total Deposited: BDT %d\n", totalDeposited);

                printf("Total Withdrawn: BDT %d\n", totalWithdrawn);

                printf("Successful Transactions: %d\n", transactionCount);

                printf("--------------------------------------\n");

                printf("Current Balance: BDT %d\n", balance);

                printf("Remaining Withdrawal Limit: BDT %d\n",
                       withdrawalLimit - totalWithdrawn);

                printf("======================================\n");

                break;


            // ==================================
            //          5. EXIT
            // ==================================

            case 5:

                printf("\n============ FINAL RECEIPT ============\n");

                printf("Initial Balance: BDT %d\n", initialBalance);

                printf("Total Deposited: BDT %d\n", totalDeposited);

                printf("Total Withdrawn: BDT %d\n", totalWithdrawn);

                printf("Successful Transactions: %d\n", transactionCount);

                printf("---------------------------------------\n");

                printf("Final Balance: BDT %d\n", balance);

                printf("=======================================\n");

                printf("\nThank you for using our ATM!\n");

                printf("Have a nice day!\n");

                break;


            // ==================================
            //          6. CHANGE PIN
            // ==================================

            case 6:

                printf("\n============= CHANGE PIN =============\n");

                printf("Enter your old PIN: ");

                if (scanf("%d", &oldPIN) != 1) {

                    if (feof(stdin)) {
                        return 0;
                    }

                    printf("Invalid input! Enter numbers only.\n");

                    while ((ch = getchar()) != '\n' && ch != EOF) {
                    }

                    break;
                }

                while ((ch = getchar()) != '\n' && ch != EOF) {
                }

                if (oldPIN == correctPIN) {

                    printf("Enter your new 4-digit PIN: ");

                    if (scanf("%d", &newPIN) != 1) {

                        if (feof(stdin)) {
                            return 0;
                        }

                        printf("Invalid input! Enter numbers only.\n");

                        while ((ch = getchar()) != '\n' && ch != EOF) {
                        }

                        break;
                    }

                    while ((ch = getchar()) != '\n' && ch != EOF) {
                    }

                    if (newPIN >= 1000 && newPIN <= 9999) {

                        printf("Confirm your new PIN: ");

                        if (scanf("%d", &confirmPIN) != 1) {

                            if (feof(stdin)) {
                                return 0;
                            }

                            printf("Invalid input! Enter numbers only.\n");

                            while ((ch = getchar()) != '\n' && ch != EOF) {
                            }

                            break;
                        }

                        while ((ch = getchar()) != '\n' && ch != EOF) {
                        }

                        if (newPIN == confirmPIN) {

                            correctPIN = newPIN;

                            printf("\nPIN changed successfully!\n");
                        }

                        else {

                            printf("\nPIN confirmation does not match!\n");
                        }
                    }

                    else {

                        printf("\nInvalid PIN! Enter exactly 4 digits.\n");
                    }
                }

                else {

                    printf("\nIncorrect old PIN! PIN change rejected.\n");
                }

                break;


            // ==================================
            //          INVALID OPTION
            // ==================================

            default:

                printf("\nInvalid option! Please try again.\n");

                break;
        }

    } while (choice != 5);

    return 0;
}
