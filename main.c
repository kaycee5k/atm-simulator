// file: atm_simulator.c


#include "include/input_utils.h"
#include <stdio.h>

#define MAX_WITHDRAW 1000  // max per transaction

int main() {
    float balance = 500.0;
    int choice;
    float amount;

    while (1) {
        printf("\n=== ATM Simulator ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Current Balance: $%.2f\n", balance);
        } else if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Deposited. New Balance: $%.2f\n", balance);
            } else {
                printf("Invalid amount.\n");
            }
        } else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > balance) {
                printf("Insufficient funds.\n");
            } else if (amount > MAX_WITHDRAW) {
                printf("Exceeds max withdrawal limit ($%d).\n", MAX_WITHDRAW);
            } else if (amount <= 0) {
                printf("Invalid amount.\n");
            } else {
                balance -= amount;
                printf("Withdrawn. New Balance: $%.2f\n", balance);
            }
        } else if (choice == 4) {
            printf("Thank you for using ATM. Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
