#ifndef TODONOTE_HPP
#define TODONOTE_HPP
#include "Note.hpp"
#include <vector>
using namespace std;

class ToDoNote : public Note {
private:
    vector<string> tasks; // Store tasks as a vector of strings

public:
    void create() override; // Create a new ToDo note
    void display() const override; // Display the ToDo note
    void loadFromFile(ifstream& in) override;
    void saveToFile(const string& userFolder, const string& filename) const override; // Save note to file
    string getType() const override; // Get the type of note
};

#endif
