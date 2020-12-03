#include <stdio.h> 
#include <math.h>
#include "myBank.h"

int main(){

    char input;
    int account_number;
    double amount,interest_rate;

    while (input != 'E')
    {
        printf("\nPlease choose a transaction type:");
        printf("\n O-Open Account");    //To open new account please press-> O.
        printf("\n B-Balance Inquiry"); //To find out a balance, get the account number and print out the balance
        printf("\n D-Deposit");         //To deposit money please press-> D.
        printf("\n W-Withdrawal");      //To withdraw money please press-> W.
        printf("\n C-Close Account");   //To close an account please press-> C.
        printf("\n I-Interest");        //To adding interest to all the accounts please press-> I.
        printf("\n P-Print");           //To print all the open accounts and their balance please press-> P.
        printf("\n E-Exit\n");          //To close all the accounts and finish program please press-> E.
        
        scanf(" %c", &input);

        switch (input) {
            case 'O' :
				printf("Please enter amount for deposit: ");
				if (scanf(" %lf", &amount) == 1) {
					openAccount(amount);
                    break;
				}
				else {
					printf("Failed to read the amount\n");
					break;
				}

            case 'B' :
            printf("Please enter account number: ");
				if (scanf("%d", &account_number) == 1) {

                    
                    if(!isOpen(account_number)) {
                        printf("This account is closed\n");
                        break;
                    }
					
                    printf("The balance of account number %d is: %0.2f\n", account_number, checkBalance(account_number));
					break;
				}
				else {
					printf("Failed to read the account number\n");
					break;
				}
            case 'D' :
            printf("Please enter account number: ");
            scanf("%d", &account_number);
                if(!isValid(account_number)) {
                    printf("Failed to read the account number\n");
                    break;
                }
                printf("Please enter amount for deposit: ");
				if (scanf("%lf", &amount) == 1) {
					deposit(account_number,amount);
					break;
				}
				else {
					printf("Failed to read the amount\n");
					break;
				}
            case 'W':
                printf("Please enter account number: ");
                if (scanf(" %d", &account_number) == 1){

                    if(!isOpen(account_number)) {
                        printf("This account is closed\n");
                        break;
                    }

                    printf("Please enter the amount to withdraw: ");
                    scanf(" %lf", &amount);
                    double ans = withdraw(account_number, amount);
                    if(ans == -1) {
                        printf("Cannot withdraw more than the balance\n");
                    } else {
                        printf("The new balance is: %0.2f\n", ans);
                    }
                break;
                }
                else {
					printf("Failed to read the account number\n");
					break;
				}
                
            case 'C':
            printf("Please enter account number: ");
            if(scanf(" %d", &account_number) == 1){
            closeAccount(account_number); 
            break;        
            }
            else {
					printf("Failed to read the account number\n");
					break;
				}  

            case 'I':
            printf("Please enter interest rate: ");
                if(scanf(" %lf", &interest_rate) == 1){
                addInterest(interest_rate);
                break;
            }
            else {
					printf("Failed to read the interest rate\n");
					break;
				} 

            case 'P':
            
                printAccounts();
                break;

            case 'E':
                
                closeBank();
                break;

            default :
                printf("Invalid transaction type\n");
                break;
        }
    }
}