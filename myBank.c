#include <stdio.h>
#include <math.h>
#include "myBank.h"
#define numOfAccounts 50
#define Columns 2
#define range 901
#define LastUser 950
#define BankStatus 0
#define BankBalance 1
#define BankStatusClose 0
#define BankStatusOpen 1

double accountsOfBank[numOfAccounts][Columns] = {0};

int openAccounts = 0;

/*The function opens an account and saves the initial deposit amount.
Prints the new account number.
Opening an account is only possible if there are less than 50 accounts open.*/
void openAccount(double amount){
    if(openAccounts < numOfAccounts) {
        int index = 0;
        for(int i=0; i<numOfAccounts; i++){
            if(accountsOfBank[i][BankStatusOpen] == BankStatusClose){
                index = i;
                break;
            }
        }
        accountsOfBank[index][BankBalance] = amount;
        accountsOfBank[index][BankStatus] = BankStatusOpen;
        openAccounts++;
        printf("New account number is: %d \n", index + range);
    } else {
        printf("No open account with this number\n");
    }
}

/*The function finds a balance, gets the account number and prints the balance.
This is only allowed if the account is open.*/
double checkBalance (int accountNumber){
    return accountsOfBank[accountNumber - range][BankStatusOpen];
}

/*Deposit function, receives the account number and prints the new balance.
This is only allowed if the account is open.*/
double deposit (int account , double amount){
    accountsOfBank[account - range][BankStatusOpen] += amount;
        return accountsOfBank[account - 901][1];
}   

/*Withdrawal function, receives the account number and prints the new balance.
This is only allowed if the account is open and there is enough cash to withdraw.*/
double withdraw(int account_number, double amount){
    if (accountsOfBank[account_number - range][BankStatusOpen] < amount){
        return -1;
    }
    else
    {
        if (accountsOfBank[account_number - range][BankStatusOpen] -= amount);
        return accountsOfBank[account_number - range][BankStatusOpen];
    }
}

/*Account Closing Function.
Only allowed if the account is open.*/
void closeAccount(int account_number){
    accountsOfBank[account_number - range][BankStatus] = BankStatus;
    accountsOfBank[account_number - range][BankStatusOpen] = BankStatus;
    openAccounts--;
}

/*A function that adds interest at a given percentage rate to all open accounts.*/
void addInterest(double interest_rate){
   for (int i = 0; i < numOfAccounts; i++){
       if (accountsOfBank[i][BankStatus] == BankStatusOpen) {
           accountsOfBank[i][BankStatusOpen] *= BankStatusOpen + interest_rate / 100 ;
       }
   }
}

/*A function that prints all the open accounts and the balance in them.*/
void printAccounts(){
    int counter = range;
    for (int i = 0; i < numOfAccounts; i++){
        if (accountsOfBank[i][BankStatus] == BankStatusOpen){
            printf("The balance of account number %d is: %0.2f\n", counter, accountsOfBank[i][BankBalance]);   
        }
        counter++;
    }
}

/*A function that closes all accounts and exits the program.*/
void closeBank(){
for (int i = 0; i < numOfAccounts; i++){
       if (accountsOfBank[i][BankBalance] == BankStatusOpen){
           accountsOfBank[i][BankBalance] = BankStatusClose;
       }    
    }
}
/*A function that checks that an account number is in the range of 901 to 950*/
int isValid(int account_number) {
    if(account_number >= 901 && account_number <= 950) {
        return 1;
    } else {
        return 0;
    }
}

/*A function that checks whether an account is open or closed*/
int isOpen(int account_number) {
    if(accountsOfBank[account_number - range][0] == 1) {
         return 1;  }
    else {
        return 0;}
}
