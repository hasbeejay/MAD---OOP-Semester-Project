#include "SimpleNote.hpp"
#include <iostream>
#include <fstream>
#include "Utils.h"
#include <filesystem>
using namespace std;

void SimpleNote::create() {
    cout << "----------------------------------------------\n";
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter note body:\n";
    getline(cin, body);
}

void SimpleNote::display() const {
    cout << "----------------------------------------------\n";
    cout << "Title:"; Utils::printYellow(title + "\n");
    cout << "Body: \n"; Utils::printYellow(body + "\n");
}

void SimpleNote::saveToFile(const string& userFolder, const string& filename) const {
    // Save the note to a file in the specified user folder
    ofstream file(userFolder + "/" + filename);
    file << "SimpleNote\n" << title << "\n" << body << "\n";
}

void SimpleNote::loadFromFile(ifstream& in) {
    getline(in, title);
    string line, bodyContent;
    while (getline(in, line)) {
        bodyContent += line + "\n";
    }
    body = bodyContent;
}


string SimpleNote::getType() const {
    // Return the type of the note
    return "SimpleNote";
}
