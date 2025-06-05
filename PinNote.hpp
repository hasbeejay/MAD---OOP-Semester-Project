#ifndef PINNOTE_HPP
#define PINNOTE_HPP
#include "Note.hpp"
#include <vector>
#include <string>
using namespace std;

class PinNote : public Note {
private:
    vector<string> keywords; // List of keywords for the pinned note

public:
    void create() override;
    void display() const override;
    void saveToFile(const string& userFolder, const string& filename) const override;
    void loadFromFile(ifstream& in) override;
    string getType() const override;
};

#endif
