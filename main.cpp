#include "AuthManager.hpp"
#include "NoteManager.hpp"
#include <iostream>
#include <filesystem>
using namespace std;

void showDashboard(const string& username) {
    string userFolder = "userdata/" + username;
    filesystem::create_directories(userFolder);

    NoteManager noteManager(userFolder);

    int choice;
    do {
        cout << "\n==== DASHBOARD ====\n";
        cout << "Welcome, " << username << "!\n";
        cout << "-------------------\n";
        cout << "-------------------\n";
        cout << "1. Add New Note\n";
        cout << "-------------------\n";
        cout << "2. View Your Notes\n";
        cout << "-------------------\n";
        cout << "3. Mark Favorite Note\n";
        cout << "-------------------\n";
        cout << "4. View Favorite Notes\n";
        cout << "-------------------\n";
        cout << "5. View To-Do Lists\n";
        cout << "-------------------\n";
        cout << "6. View Pins\n";
        cout << "-------------------\n";
        cout << "7. Logout\n";
        cout << "-------------------\n";
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                noteManager.addNote();
                break;
            case 2:
                noteManager.viewNotes();
                break;
            case 3:
                noteManager.markFavorite();
                break;
            case 4:
                noteManager.viewFavorites();
                break;
            case 5:
                noteManager.viewToDoLists();
                break;
            case 6:
                noteManager.viewPins();
                break;
            case 7:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 7);
}

int main() {
    AuthManager auth;

    int choice;
    bool validInput;
cout << "\n";
cout << "  .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
cout << "  |                                             |\n";
cout << "  |               W E L C O M E                 |\n";
cout << "  |                   T O                       |\n";
cout << "  |                  M A D                      |\n";
cout << "  |             (Minds and Dots)                |\n";
cout << "  |                                             |\n";
cout << "  .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";

do {
cout << "  .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
cout << "  |      1. Login               2. Signup       |\n";
cout << "  |                 3. Exit                     |\n";
cout << "  .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
cout << "\n  Choose option: ";
    
    validInput = true; // assume input will be valid
    
    if (!(cin >> choice)) {
        // Input was not an integer
        cin.clear(); // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
        cout << "Invalid input. Please enter a number (1-3).\n";
        validInput = false;
    } else if (choice < 1 || choice > 3) {
        cout << "Invalid option. Please choose between 1-3.\n";
        validInput = false;
    }
    
    if (validInput) {
        cin.ignore(); // ignore the newline character
        if (choice == 1) {
            string username;
            if (auth.login(username)) {
                showDashboard(username);
            }
        } else if (choice == 2) {
            auth.signup();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
        }
    }
    } while (choice != 3 || !validInput);

    return 0;
}
