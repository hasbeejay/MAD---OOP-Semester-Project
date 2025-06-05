#ifndef PROJECTNOTE_HPP
#define PROJECTNOTE_HPP
#include "Note.hpp"
#include <vector>
#include <string>

using namespace std;

class ProjectNote : public Note {
private:
    string idea;
    string targetDate;
    vector<string> requirements;
    vector<string> thingsNeeded;
    vector<string> milestones;

public:
    void create() override;
    void display() const override;
    void loadFromFile(ifstream& in) override;
    void saveToFile(const string& userFolder, const string& filename) const override;
    string getType() const override;
};

#endif
