#ifndef myBank
#define myBank

void openAccount(double);
double checkBalance(int);
double deposit (int , double);
double withdraw(int , double);
void closeAccount(int);
void addInterest(double);
void printAccounts();
void closeBank();
int isValid(int);
int isOpen(int);

#endif