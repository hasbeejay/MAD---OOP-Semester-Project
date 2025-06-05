#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

// User class definition
class User {
private:
    string username; // Stores the username
    string password; // Stores the password
public:
    User() = default; // Default constructor

    // Parameterized constructor
    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}

    // Getter for username
    string getUsername() const { return username; }

    // Getter for password
    string getPassword() const { return password; }
};

#endif