#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to store user account information.
struct Account
{
    string userId;
    string password;
    double balance;
};

// Map to store all user accounts within the program.
map<string, Account> accounts;

// a popup to show your created details for a new account
void userDetail(string userId, string password)
{
    cout << "" << endl;
    cout << "**** Your Credinals *****" << endl;
    cout << "Username : " << userId << endl;
    cout << "Password : " << password << endl;
    cout << "**** Thanks for Joining Our Bank ******** " << endl;
    cout << "" << endl;
}

// Function to create a new account for the new User.
void createAccount()
{
    string userId, password;
    cout << "Please enter your Username: ";
    cin >> userId;
    cout << "Please enter your Password: ";
    cin >> password;
    accounts[userId] = {userId, password, 0.0};
    cout << "Thank You! Your account has been created!" << endl;

    userDetail(userId, password); // passing the details again
}

// Function to login to an existing account
bool login()
{
    string userId, password;
    cout << "\n\n"
         << endl;
    cout << "**** Login to Our  ATM Machine *****" << endl;
    cout << "" << endl;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;
    if (accounts.find(userId) != accounts.end() && accounts[userId].password == password)
    {
        cout << "" << endl;
        cout << "**** Access Granted! ****" << endl;
        return true;
    }
    else
    {
        cout << "*** LOGIN FAILED! ***" << endl;
        return false;
    }
}

// Function to deposit money
void depositMoney(string userId)
{
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    accounts[userId].balance += amount;
    cout << "***Your Amount is Deposited Successfully *****";
    cout << "\n************************************" << endl;
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

// Function to withdraw money
void withdrawMoney(string userId)
{
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;
    if (amount <= accounts[userId].balance)
    {
        accounts[userId].balance -= amount;
        cout << "***Your Amount is Withdraw Successfully *****";
        cout << "\n************************************" << endl;
    }
    else
    {
        cout << "Insufficient balance!" << endl;
    }
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

// Function to request balance
void requestBalance(string userId)
{
    printf("\n****************************\n");
    cout << "Hello !!$" << userId << "." << endl;
    cout << "" << endl;
    cout << "Your balance is $" << accounts[userId].balance << "." << endl;
    printf("\n****************************\n");
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

int main()
{
    char option;
    string userId;
    bool isLoggedIn = false;

    while (true)
    {
        if (!isLoggedIn)
        {
            cout << "Hi! Welcome to the ATM Machine!!\n"
                 << endl;
            cout << "Please select an option from the menu below:" << endl;
            cout << "l -> Login" << endl;
            cout << "c -> Create New Account" << endl;
            cout << "q -> Quit" << endl;
            printf("Enter your Option [l, c, q]:\t");
            cin >> option;

            switch (option)
            {
            case 'l':
                if (login())
                {
                    isLoggedIn = true;
                }
                break;
            case 'c':
                cout << "" << endl;
                cout << "**** Open New Account With  Us *****\n"
                     << endl;
                createAccount();
                break;
            case 'q':
                cout << "**** Thanks for Banking With Us *****" << endl;
                return 0;
            }
        }
        else
        {
            cout << "d -> Deposit Money" << endl;
            cout << "w -> Withdraw Money" << endl;
            cout << "r -> Request Balance" << endl;
            cout << "q -> Quit" << endl;
            cin >> option;

            switch (option)
            {
            case 'd':
                depositMoney(userId);
                break;
            case 'w':
                withdrawMoney(userId);
                break;
            case 'r':
                requestBalance(userId);
                break;
            case 'q':
                isLoggedIn = false;
                break;
            }
        }
    }

    return 0;
}
