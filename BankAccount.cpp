#include "Project3.h"
#include "BankAccount.h"

int Accounts::StartingAccountNumber = 1000;
Accounts::Accounts() {
    AccountNumber = 0;
    Name = " ";
    Balance = 0;
}
Accounts::Accounts(int newAccountNumber, string newName, float newBalance) {
    AccountNumber = newAccountNumber;
    Name = newName;
    Balance = newBalance;
}
Accounts::~Accounts() {
    //deconstructor
}
void Accounts::SetAccountNumber(int newAccountNumber) {
    AccountNumber = newAccountNumber;
}
int Accounts::GetAccountNumber() {
    return AccountNumber;
}
void Accounts::SetName(string newName) {
    Name = newName;
}
string Accounts::GetName() {
    return Name;
}
void Accounts::SetBalance(float newBalance) {
    Balance = newBalance;
}
float Accounts::GetBalance() {
    return Balance;
}
void Accounts::PrintInfo() {
    cout << endl;
    cout << "+----------------------------+" << endl;
    cout << "   Account #: " << AccountNumber << endl;
    cout << "   Account Name: " << Name << endl;
    cout << "   Current Balance: " << fixed << setprecision(2) << Balance << endl;
    cout << "+----------------------------+" << endl;
    cout << endl;
}
void Accounts::Deposit(float newDeposit) {
    Balance += newDeposit;
}
void Accounts::Withdraw(float newWithdraw) {
    Balance -= newWithdraw;
}
