#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <string>
using namespace std;

// AuthManager handles user authentication logic
class AuthManager {
public:
    // Attempts to log in a user with the given username.
    // Returns true if login is successful, false otherwise.
    bool login(string& username);

    // Handles user signup process.
    void signup();
};

#endif