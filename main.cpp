#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// Constants
const string Default_Pin = "0000"; // Default PIN
const float Default_Balance = 1000.00; // Default balance
const int Max_Pin_Tries = 3; // Maximum number of PIN tries before program exits

// Global variables
string pin = Default_Pin;
float balance = Default_Balance;

// Function prototypes
bool authenticate();
void resetPin();
void checkBalance();
void sendMoney();
//void exitProgram();

int main() {
    int choice;

cout << "\n\n\tWelcome to SWIFT MOBILE MONEY SERVICES" << endl;
cout << "\n\n\tCreated by: Jeff_Rey\n\n\n" << endl;
cout << "\tNOTE: 1. YOU NEED TO ENTER YOUR PIN FOR AUTHENTICATION" << endl;
cout << "\n\n\t      2. ENTERING THE WRONG PIN MORE THAN 3 TIMES WILL CAUSE THE PROGRAM TO EXIT" << endl;
cout << "\n\n\t Thank you for using SWIFT MOBILE MONEY SERVICES\n\n\n" << endl;
system("pause");
system("cls");
    do {
        // Display menu
	
        cout << "\n\n\tMAIN MENU" << endl;
        cout << "\n\n\t1. Authenticate" << endl;
        cout << "\n\n\t2. Reset PIN" << endl;
        cout << "\n\n\t3. Check balance" << endl;
        cout << "\n\n\t4. Send money" << endl;
        cout << "\n\n\t5. Exit" << endl;
        cout << "\n\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!authenticate()) {
                    cout << "Authentication failed." << endl;
                    exit(0);
                }
                break;
                system("cls");
                
            case 2:
                resetPin();
                break;
                system("cls");
            case 3:
                checkBalance();
                break;
                system("cls");
            case 4:
                sendMoney();
                break;
                system("cls");
            case 5:
              exit(0);
                break;
                system("cls");
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
                system("cls");
        }
    } while (choice != 5);

    
}

// Authenticates user PIN
bool authenticate() {
    string userPin;
    int pinTries = 0;

    while (pinTries < Max_Pin_Tries) {
        cout << "Enter your PIN: ";
        cin >> userPin;
        
    system("cls");

        if (userPin == pin) {
            cout << "Authentication successful." << endl;
            return true;
            system("pause");
            system("cls");
        }
        else {
            cout << "Authentication failed. Please try again." << endl;
            pinTries++;
            
            system("pause");
            system("cls");
            }
        
    }
    

    // max number of PIN tries reached, exit program
    if (pinTries == Max_Pin_Tries) {
        cout << "Maximum number of tries reached." << endl;
         exit(0);
     }

    return false;
}

// Resets the user's PIN
void resetPin() {
    string newPin;

    if (authenticate()) {
        cout << "\nEnter your new PIN: \n\n";
        cin >> newPin;
        pin = newPin;
        cout << "\nPIN reset successful." << endl;
        
            system("pause");
            system("cls");
    }
}

// Displays the user's balance
void checkBalance() {
    if (authenticate()) {
        cout << "Your balance is: " << balance << " cedis." << endl;
        system("pause");
        system("cls");
    }
}

// Sends money to another user
void sendMoney() {
    string recipient;
    float amount;

    if (authenticate()) {
        cout << "\n\n\tEnter recipient's mobile number: \n\n";
        cin >> recipient;
        cout << "\n\n\tEnter amount to send: \n\n";
        cin >> amount;

        if (amount > balance) {
            cout << "\n\n\tInsufficient balance. Transaction failed." << endl;
            system("pause");
            system("cls");
        }
        else {
            balance -= amount;
            cout << "\n\n\tTransaction successful. " << amount << " cedis" << " sent to " << recipient << "." << endl;
            system("pause");
            system("cls");
        }
    }
    
     return ; 
}




    
  

