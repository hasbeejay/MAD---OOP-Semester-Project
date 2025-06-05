#ifndef SIMPLENOTE_HPP
#define SIMPLENOTE_HPP
#include "Note.hpp"
using namespace std;

class SimpleNote : public Note {
private:
    string body; // Body of the note

public:
    void create() override; // Create a new note
    void display() const override; // Display the note
    void saveToFile(const string& userFolder, const string& filename) const override; // Save note to file
    void loadFromFile(ifstream& in) override;
    string getType() const override; // Get the type of the note
};

#endif
