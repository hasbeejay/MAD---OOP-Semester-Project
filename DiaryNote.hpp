#ifndef DIARYNOTE_HPP
#define DIARYNOTE_HPP
#include "Note.hpp"
using namespace std;

class DiaryNote : public Note {
private:
    string date;   // Date of the diary note
    string entry;  // Content of the diary entry

public:
    void create() override;
    void display() const override;
    void loadFromFile(ifstream& in) override;
    void saveToFile(const string& userFolder, const string& filename) const override;
    string getType() const override;
};

#endif
