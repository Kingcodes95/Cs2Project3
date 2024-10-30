#include "Project3.h"
#include "BankAccount.h"

void ReadFile(vector<Accounts> &BankAccounts) {
    ifstream File("AccountSave.txt");
    if (File.is_open()) {
        string line;
        while (getline(File, line)) {
            stringstream ss(line);
            string AccountNumberStr, Name, BalanceStr;
            getline(ss, AccountNumberStr, ',');
            getline(ss, Name, ',');
            getline(ss, BalanceStr, ',');
            float Balance = stof(BalanceStr);
            int AccountNumber = stoi(AccountNumberStr);
            BankAccounts.push_back(Accounts(AccountNumber, Name, Balance));
            
        }

    } else {
        cerr << "File could not open." << '\n';
    }

    File.close();
}
void PrintBankList(vector<Accounts> BankAccounts) {

     for (int i = 0; i < BankAccounts.size(); i++) {
        BankAccounts[i].PrintInfo();
    }

}
void OpenAccount(vector<Accounts> &BankAccounts) {
    cin.ignore();
    Accounts newAccount;
    int newAccountNumber;
    string newName;
    float newBalance;

    cout << "Enter your Name: ";
    getline(cin, newName);

    cout << "Enter how much you wish to initially deposit: ";
    cin >> newBalance;

    newAccountNumber = newAccount.StartingAccountNumber;
    for (int i = 0; i < BankAccounts.size(); i++) {
       if (BankAccounts[i].GetAccountNumber() == newAccountNumber) {
            newAccountNumber++;
       }

    }

    BankAccounts.push_back(Accounts(newAccountNumber, newName, newBalance));
}
void UpdateFile(vector<Accounts> BankAccounts) {
    ofstream File("AccountSave.txt");

    if (File.is_open()) {
        for (int i = 0; i < BankAccounts.size(); i++) {
            File << BankAccounts[i].GetAccountNumber() << "," << BankAccounts[i].GetName() << "," << BankAccounts[i].GetBalance() << '\n';
        }
    } else {
        cerr << "Error: File could not open." << '\n';
    }

    File.close();

}
void DepositMoney(vector<Accounts> &BankAccounts) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    float newDeposit;
    int AccessAccountNumber;
    string AccessAccountName;

    cout << "Please Enter the account you would like to access: ";
    cin >> AccessAccountNumber;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "Enter the Account Name for verification Purposes(Capitalization Matters): ";
    getline(cin, AccessAccountName);
    cout << "How much would you like to deposit: ";
    cin >> newDeposit;

    bool BankFound = false;
    for (int i = 0; i < BankAccounts.size(); i++) {
        if (BankAccounts[i].GetAccountNumber() == AccessAccountNumber && BankAccounts[i].GetName() == AccessAccountName) {
            BankAccounts[i].Deposit(newDeposit);
            BankFound = true;
            cout << "You just Deposited: " << newDeposit << '\n';
            cout << "Your current Balance is: " << BankAccounts[i].GetBalance() << endl;
            break;
        }
    }
    if (!BankFound) {
        cout << "Bank Account Not found/Wrong Information." << endl;
    }

}
void WithdrawMoney(vector<Accounts> &BankAccounts) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    float newWithdraw;
    int AccessAccountNumber;
    string AccessAccountName;

    cout << "Please Enter the number of the Account you would like to access: ";
    cin >> AccessAccountNumber;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Enter the Account Name for verification Purposes(Capitalization Matters): ";
    getline(cin, AccessAccountName);
    cout << "How much would you like to Withdraw: ";
    cin >> newWithdraw;

    bool BankFound = false;
    for (int i = 0; i < BankAccounts.size(); i++) {
        if (BankAccounts[i].GetAccountNumber() == AccessAccountNumber && BankAccounts[i].GetName() == AccessAccountName) {
            if (newWithdraw <= BankAccounts[i].GetBalance()) {
                BankAccounts[i].Withdraw(newWithdraw);
                BankFound = true;
                cout << "You just Withdrew: " << newWithdraw << '\n';
                cout << "Your current Balance is: " << BankAccounts[i].GetBalance() << endl;
                break;
            }
            BankFound = true;
            cout << "Insufficient funds." << '\n';
            break;
        }
    }
    if (!BankFound) {
        cout << "Bank Account Not found/Wrong Information." << endl;
    }

}
void FastTransfer40(vector<Accounts> &BankAccounts) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    int Add40Account;
    int Minus40Account;
    
    cout << "Enter the account number you would like to Withdraw 40$ from: ";
    cin >> Minus40Account;
    
    cout << "Enter the account number you would like to Add 40$ to: ";
    cin >> Add40Account;
    
    bool MinusAccountFound = false;
    bool AddAccountFound = false;
    
    for (int i = 0; i < BankAccounts.size(); i++) {
        if (BankAccounts[i].GetAccountNumber() == Minus40Account && BankAccounts[i].GetBalance() >= 40) {
            MinusAccountFound = true;
        }
        if (BankAccounts[i].GetAccountNumber() == Add40Account) {
            AddAccountFound = true;
        }
        if (MinusAccountFound && AddAccountFound) {
            break;
        }
    }
    
    if (MinusAccountFound && AddAccountFound) {
        for (int i = 0; i < BankAccounts.size(); i++) {
            if (BankAccounts[i].GetAccountNumber() == Minus40Account) {
                BankAccounts[i].Withdraw(40);
                break;
            }
        }
        for (int i = 0; i < BankAccounts.size(); i++) {
            if (BankAccounts[i].GetAccountNumber() == Add40Account) {
                BankAccounts[i].Deposit(40);
                cout << "Transfer Complete." << endl;
                break;
            }
        }
    } else {
        cout << "One or both of the accounts were not found." << endl;
    }
}
int main() {

    vector<Accounts> BankAccounts;

    ReadFile(BankAccounts);

    int Choice = 1;

    cout << "+----------------------------------------------------+" << endl;
    cout << "|        Computer Science and Engineering            |" << endl;
    cout << "|       CSCE 1040 - Computer Programming II          |" << endl;
    cout << "|  Ronald Perez  11340043   Ronaldperez@my.unt.edu   |" << endl;
    cout << "+----------------------------------------------------+" << endl;


    while (Choice != 6) {

        cout << endl;
        cout << "********************* MENU ******************" << endl;
        cout << "| 1. Open Account                           |" << endl;
        cout << "| 2. Deposit To Account                     |" << endl;
        cout << "| 3. Withdraw from Account                  |" << endl;
        cout << "| 4. Fast Transfer 40$                      |" << endl;
        cout << "| 5. Print Account Info                     |" << endl;
        cout << "| 6. Exit Bank                              |" << endl;
        cout << "*********************************************" << endl;
        cout << "--->: ";

        cin >> Choice;

        switch (Choice) {

            case OPEN:
            OpenAccount(BankAccounts);
            UpdateFile(BankAccounts);
            break;

            case DEPOSIT:
            DepositMoney(BankAccounts);
            UpdateFile(BankAccounts);
            break;

            case WITHDRAW:
            WithdrawMoney(BankAccounts);
            UpdateFile(BankAccounts);
            break;

            case FAST_TRANSFER:
            FastTransfer40(BankAccounts);
            UpdateFile(BankAccounts);
            break;

            case PRINT:
            PrintBankList(BankAccounts);
            break;

            case EXIT:
            cout << "Programming Terminating." << '\n';
            break;

            default:
            cout << "Enter a number 1 - 6." << '\n';
            break;

        }

    }

    return 0;
}