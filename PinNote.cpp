#include "PinNote.hpp"
#include <iostream>
#include <fstream>
#include "Utils.h"
using namespace std;

void PinNote::create() {
    cout << "----------------------------------------------\n";
    cout << "Enter main work topic (title): ";
    getline(cin, title);
    cout << "Enter pin keywords (type 'done' to finish):\n";
    string word;
        getline(cin, word);
        if (word == "done"){
        keywords.push_back(word);
}

    while (word != "done") {
        if (!word.empty()) {
            keywords.push_back(word);
        }
        getline(cin, word);
    }
    if (keywords.empty()) {
        cout << "----------------------------------------------\n";
        Utils::printRed("No keywords entered. PinNote creation failed.");
        return;
    }
}

void PinNote::display() const {
    cout << "Pinned: " << title;
    Utils::printBlue("\n\nDeduction chain: ");
    for (size_t i = 0; i < keywords.size(); ++i) {
        cout << keywords[i];
        if (i != keywords.size() - 1) cout << " :---: ";
    }
    cout << "\n";
}

void PinNote::saveToFile(const string& userFolder, const string& filename) const {
    ofstream file(userFolder + "/" + filename);
    file << "PinNote\n" << title << "\n";
    for (const auto& w : keywords) {
        file << w << "\n";
    }
}

void PinNote::loadFromFile(ifstream& in) {
    getline(in, title); // First actual data line after "PinNote"

    string line;
    keywords.clear(); // Just in case
    while (getline(in, line)) {
        if (!line.empty())
            keywords.push_back(line);
    }
}



string PinNote::getType() const {
    return "PinNote";
}
