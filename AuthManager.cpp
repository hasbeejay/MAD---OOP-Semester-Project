#include "AuthManager.hpp"
#include "User.h"
#include "Utils.h"
#include "Utils.cpp"
#include <fstream>
#include <filesystem>
#include <cstring>
using namespace std;
namespace fs = std::filesystem;

// Handles user login
bool AuthManager::login(string& username) {
    Utils::printBlue("\n-- Login --\n");
    string uname, pwd;
    cout << "Username: "; getline(cin, uname);
    cout << "Password: "; getline(cin, pwd);

    ifstream infile("users.dat", ios::binary);
    char unameBuf[50], pwdBuf[50];
    // Read each user record from file
    while (infile.read(unameBuf, sizeof(unameBuf))) {
        infile.read(pwdBuf, sizeof(pwdBuf));
        // Compare input with stored credentials
        if (uname == unameBuf && pwd == pwdBuf) {
            Utils::printGreen("\n-|#| Login successful!\n");
            username = uname;
            fs::create_directories("UserNotes/" + uname);
            filesystem::create_directories("UserNotes/" + uname);
            return true;
        }
        else {
            Utils::printRed("\n-|X| Invalid username or password.\n");
        }
    }
    return false; // Login failed
};

// Handles user signup
void AuthManager::signup() {
    Utils::printBlue("\n-- Signup --\n");
    string uname, pwd;
    cout << "Choose username: "; getline(cin, uname);
    cout << "Choose password: "; getline(cin, pwd);

    ifstream infile("users.dat", ios::binary);
    char unameBuf[50];
    // Check if username already exists
    while (infile.read(unameBuf, sizeof(unameBuf))) {
        infile.ignore(50); // Skip password
        if (uname == unameBuf) {
            Utils::printYellow("\n-|!| Username already exists.\n");
            return;
        }
    }
    infile.close();

    // Add new user to file
    ofstream outfile("users.dat", ios::app | ios::binary);
    char unameArray[50] = {}, pwdArray[50] = {};
    strncpy(unameArray, uname.c_str(), 49);
    strncpy(pwdArray, pwd.c_str(), 49);
    outfile.write(unameArray, sizeof(unameArray));
    outfile.write(pwdArray, sizeof(pwdArray));
    Utils::printGreen("\n-|#| Signup successful. Please login.\n");
}