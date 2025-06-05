#include "Utils.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Utils::typingEffect(const string& text, int delay) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void Utils::printGreen(const string& text) {
    cout << "\033[32m" << text << "\033[0m" << endl;
}

void Utils::printYellow(const string& text) {
    cout << "\033[33m" << text << "\033[0m" << endl;
}

void Utils::printRed(const string& text) {
    cout << "\033[31m" << text << "\033[0m" << endl;
}
void Utils::printBlue(const string& text) {
    cout << "\033[34m" << text << "\033[0m" << endl;
}
