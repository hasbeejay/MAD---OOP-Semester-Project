#ifndef NOTE_HPP
#define NOTE_HPP
#include <string>
using namespace std;

class Note {
protected:
    string title; // Title of the note

public:
    virtual ~Note() {}
    virtual void create() = 0; // Pure virtual function to create a note
    virtual void display() const = 0; // Pure virtual function to display a note
    virtual void saveToFile(const string& userFolder, const string& filename) const = 0; // Save note to file
    virtual void loadFromFile(ifstream& in) = 0; // Load note data from file
    virtual string getType() const = 0; // Get the type of the note
};

#endif
