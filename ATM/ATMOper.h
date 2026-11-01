#ifndef ATM_H
#define ATM_H

#include <stdio.h>
#include <stdlib.h>

enum enOper { 
    BALANCE = 1, 
    DEPOSIT = 2, 
    WITHDRAW = 3, 
    EXIT = 4 
};

int ReadChoice(void) {
    int choice;
    do {
        printf("\nChoose an option : ");
        scanf("%d", &choice);
        if (choice > 4 || choice < 1) {
            printf("Error : invalid choice");
        }
    } while (choice > 4 || choice < 1);

    return choice;
}

void checkBalance(float bal) {
    printf("Current balance: %.2f MAD", bal);
}

void deposit(float* bal) {
    float dpoAmount;
    do {
        printf("\nEnter deposit amount:");
        scanf("%f", &dpoAmount);
        if (dpoAmount <= 0) {
            printf("\nError : Invalid Amount try again");
        }
    } while (dpoAmount <= 0);
    *bal += dpoAmount;
    printf("\nDeposit successful!");
    printf("\nNew balance: %.2f MAD", *bal);
}

void withdraw(float* bal) {
    float wdrAmount;
    float tra;
    do {
        printf("\nEnter Withdrawal amount:");
        scanf("%f", &wdrAmount);
        tra = *bal - wdrAmount;
        if (tra < 0 || wdrAmount <= 0) {
            printf("\nError : Invalid Amount try again");
        }
    } while (tra < 0 || wdrAmount <= 0);
    *bal -= wdrAmount;
    printf("\nWithdrawal successful!");
    printf("\nNew balance: %.2f MAD", *bal);
}

void showExitMessage(void) {
    system("cls");
    printf("\n--- thank your for being our client ---\n");
}

void menu(float* bal) {
    int c;
    do {
        printf("\n\n========== ATM MENU ==========");
        printf("\n1. Check balance");
        printf("\n2. Deposit money");
        printf("\n3. Withdraw money");
        printf("\n4. Exit");
        c = ReadChoice();
        switch (c) {
            case BALANCE:
                checkBalance(*bal);
                break;
            case DEPOSIT:
                deposit(bal);
                break;
            case WITHDRAW:
                withdraw(bal);
                break;
            case EXIT:
                showExitMessage();
                break;
        }
    } while (c != EXIT);
}

#endif