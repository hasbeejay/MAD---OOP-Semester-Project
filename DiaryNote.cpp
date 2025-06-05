#include "DiaryNote.hpp"
#include "Note.hpp"
#include <iostream>
#include <fstream>
#include "Utils.h"
using namespace std;

// Create a new diary note by asking the user for date and entry
void DiaryNote::create() {
    cout << "----------------------------------------------\n";
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date); // Get the date from user input
    cout << "Write your diary entry:\n";
    getline(cin, entry); // Get the diary entry from user input
    title = date;  // Set the title to the date for consistency
}

// Display the diary note's date and entry
void DiaryNote::display() const {
    cout << "----------------------------------------------\n";
    cout << "Dairy Date: "; Utils::printYellow(date + "\n");
    cout << "Entry:\n"; Utils::printYellow(entry + "\n");
}

// Save the diary note to a file in the specified user folder
void DiaryNote::saveToFile(const string& userFolder, const string& filename) const {
    ofstream file(userFolder + "/" + filename); // Open file for writing
    file << "DiaryNote\n" << date << "\n" << entry << "\n"; // Write note type, date, and entry
}

void DiaryNote::loadFromFile(ifstream& in) {
    getline(in, date); // Correct: this is the 2nd line after "DiaryNote"
    title = date;      // Consistent with create() and display()
    
    string line;
    entry.clear();
    while (getline(in, line)) {
        entry += line + "\n";
    }
}



// Return the type of the note as a string
string DiaryNote::getType() const {
    return "DiaryNote";
}


//cout << "Diary Date: " << date << "\nEntry:\n" << entry << "\n";