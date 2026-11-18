#include <iostream>
#include <string>
using namespace std;
#include <limits>

/*
    GCC BANKING SYSTEM

    This programme allows users to:
    1. Deposit money.
    2. Withdraw money.
    3. Send cash to another user.
    4. Check their account balance.

    Users must enter the correct account number
    and PIN to access banking services.
*/

//Bank User Information
string names [3]={"Thando", "Lebo", "Sipho"};
string accountNumbers[3]={"1001", "1002", "1003"};
string pins[3]={"1898", "2007", "1980"};
double balances[3]={15000.00, 2000.00, 3000.00};


//Function To Display Banking Menu
void displayMenu()

{
    cout<<"====== GCC BANKING SYSTEM ======="<<endl;
    cout<<"1.Deposit"<<endl;
    cout<<"2.Withdraw"<<endl;
    cout<<"3.Send cash"<<endl;
    cout<<"4.Check balance"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter your choice:"<<endl;

}
// Function to display bank users
void displayUsers(int size)
{
    cout << "\n===== BANK USERS =====" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << names[i] << endl;
        cout << "Account Number: "
             << accountNumbers[i] << endl;
        cout << "-------------------" << endl;
    }
}
// Function to verify account number and PIN
int authenticateUser(string accountNumbers[], string pins[], int size)
{
    string account, pin;

    cout << "Enter account number: ";
    cin >> account;

    cout << "Enter PIN: ";
    cin >> pin;

    for (int i = 0; i < size; i++)
    {
        if (accountNumbers[i] == account && pins[i] == pin)
        {
            return i;
        }
    }

    return -1;
}

// Function to deposit money
void deposit(string accountNumbers[], string pins[], double balances[], int size)
{

    double amount;

    int index = authenticateUser(accountNumbers, pins, size);

    if (index == -1)
{
    cout << "Incorrect account number or PIN!" << endl;
}
    else
    {
        cout << "Enter deposit amount: R";
s
        if (!(cin >> amount))
         {
             cout << "Invalid input! Please enter numbers only." << endl;

             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');

             return;
         }

        if (amount > 0)
        {
            balances[index] = balances[index] + amount;

            cout << "Deposit successful!" << endl;
            cout << "New balance: R" << balances[index] << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }
}
// Function to withdraw money
void withdraw(string accountNumbers[],string pins[], double balances[], int size)
{
    double amount;

    int index = authenticateUser(accountNumbers, pins, size);


    if (index == -1)
    {
        cout << "Incorrect number or PIN!" << endl;
    }
    else
    {
        cout << "Enter withdrawal amount: R";

       if (!(cin >> amount))
       {
         cout << "Invalid input! Please enter numbers only." << endl;

         cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return;
}

        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
        }
        else if (amount > balances[index])
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balances[index] = balances[index] - amount;

            cout << "Withdrawal successful!" << endl;
            cout << "New balance: R" << balances[index] << endl;
        }
    }
}
// Function to send cash
void sendCash(string accountNumbers[], string pins[], double balances[], int size)
{
    string receiverAccount;
    double amount;

    int senderIndex = authenticateUser(accountNumbers, pins, size);
    int receiverIndex = -1;

    if (senderIndex == -1)
    {
        cout << "Incorrect account number or PIN!" << endl;
        return;
    }

    cout << "Enter receiver account number: ";
    cin >> receiverAccount;

    for (int i = 0; i < size; i++)
    {
        if (accountNumbers[i] == receiverAccount)
        {
            receiverIndex = i;
            break;
        }
    }

    if (receiverIndex == -1)
    {
        cout << "Receiver account not found!" << endl;
    }
    else if (senderIndex == receiverIndex)
    {
        cout << "You cannot send money to your own account!" << endl;
    }
  else
{
    cout << "Enter amount to send: R";

    if (!(cin >> amount))
    {
        cout << "Invalid input! Please enter numbers only." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
    }

    if (amount <= 0)
    {
        cout << "Invalid amount!" << endl;
    }
    else if (amount > balances[senderIndex])
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        balances[senderIndex] -= amount;
        balances[receiverIndex] += amount;

        cout << "Cash sent successfully!" << endl;
        cout << "Your new balance: R" << balances[senderIndex] << endl;
        cout << "Receiver new balance: R" << balances[receiverIndex] << endl;
    }
}


        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
        }
        else if (amount > balances[senderIndex])
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balances[senderIndex] -= amount;
            balances[receiverIndex] += amount;

            cout << "Cash sent successfully!" << endl;
            cout << "Your new balance: R" << balances[senderIndex] << endl;
            cout << "Receiver new balance: R" << balances[receiverIndex] << endl;
        }
    }

// Function to check balance
void checkBalance(string accountNumbers[], string pins[], double balances[], int size)
{
    int index = authenticateUser(accountNumbers, pins, size);

    if (index == -1)
    {
        cout << "Incorrect account number or PIN!" << endl;
    }
    else
    {
        cout << "Your current balance is: R" << balances[index] << endl;
    }
}
int main()
{
    int choice = 0;

    displayUsers(3);

    while (choice != 5)
    {
        displayMenu();

        if (!(cin >> choice))
{
    cout << "Invalid input! Please enter a number." << endl;

    cin.clear();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    continue;
}

switch (choice)
        {
            case 1:
                deposit(accountNumbers,pins, balances, 3);
                break;

            case 2:
                withdraw(accountNumbers,pins, balances, 3);
                break;

            case 3:
                sendCash(accountNumbers,pins, balances, 3);
                break;
            case 4:
                checkBalance(accountNumbers,pins, balances, 3);
                break;

            case 5:
                cout << "Thank you for using GCC Bank!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}





