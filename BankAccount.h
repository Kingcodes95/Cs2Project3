#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Accounts {
    private:
    int AccountNumber;
    string Name;
    float Balance;

    public:
    int static StartingAccountNumber;
    Accounts();
    Accounts(int newAccountNumber, string newName, float newBalance);
    ~Accounts();
    void SetAccountNumber(int newAccountNumber);
    int GetAccountNumber();
    void SetName(string newName);
    string GetName();
    void SetBalance(float newBalance);
    float GetBalance();
    void PrintInfo();
    void Deposit(float newDeposit);
    void Withdraw(float newWithdraw);
};

#endif