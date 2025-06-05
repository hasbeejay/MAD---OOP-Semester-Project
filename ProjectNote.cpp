#include "ProjectNote.hpp"
#include "Utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void ProjectNote::create() {
    cout << "----------------------------------------------\n";
    cout << "Enter project title: ";
    getline(cin, title);

    cout << "Enter project idea: ";
    getline(cin, idea);

    cout << "Enter target completion date (YYYY-MM-DD): ";
    getline(cin, targetDate);

    cout << "Enter project requirements (type 'done' to finish):\n";
    string item;
    while (true) {
        getline(cin, item);
        if (item == "done") break;
        requirements.push_back(item);
    }

    cout << "Enter things needed for the project (type 'done' to finish):\n";
    while (true) {
        getline(cin, item);
        if (item == "done") break;
        thingsNeeded.push_back(item);
    }

    cout << "Enter milestones (type 'done' to finish):\n";
    while (true) {
        getline(cin, item);
        if (item == "done") break;
        milestones.push_back(item);
    }
}

void ProjectNote::display() const {
    cout << "----------------------------------------------\n";
    cout << "Project Title: "; Utils::printGreen(title);
    cout << "Idea: \n"; Utils::printGreen(idea);
    cout << "Target Date: "; Utils::printGreen(targetDate);

    cout << "\nRequirements:\n";
    for (const auto& r : requirements) {
        Utils::printGreen("- " + r);
    }

    cout << "\nThings Needed:\n";
    for (const auto& t : thingsNeeded) {
        Utils::printGreen("- " + t);
    }

    cout << "\nMilestones:\n";
    for (const auto& m : milestones) {
        Utils::printGreen("- " + m);
    }
}

void ProjectNote::saveToFile(const string& userFolder, const string& filename) const {
    ofstream file(userFolder + "/" + filename);
    file << "ProjectNote\n" << title << "\n";
    file << idea << "\n";
    file << targetDate << "\n";

    file << "REQUIREMENTS\n";
    for (const auto& r : requirements) {
        file << r << "\n";
    }

    file << "THINGS_NEEDED\n";
    for (const auto& t : thingsNeeded) {
        file << t << "\n";
    }

    file << "MILESTONES\n";
    for (const auto& m : milestones) {
        file << m << "\n";
    }
}

void ProjectNote::loadFromFile(ifstream& in) {
    getline(in, title);
    getline(in, idea);
    getline(in, targetDate);

    string line;
    requirements.clear();
    thingsNeeded.clear();
    milestones.clear();

    // Expect "REQUIREMENTS"
    getline(in, line);
    if (line != "REQUIREMENTS") return;

    // Read requirements until "THINGS_NEEDED"
    while (getline(in, line)) {
        if (line == "THINGS_NEEDED") break;
        if (!line.empty())
            requirements.push_back(line);
    }

    // Read things needed until "MILESTONES"
    while (getline(in, line)) {
        if (line == "MILESTONES") break;
        if (!line.empty())
            thingsNeeded.push_back(line);
    }

    // Read milestones till EOF
    while (getline(in, line)) {
        if (!line.empty())
            milestones.push_back(line);
    }
}


string ProjectNote::getType() const {
    return "ProjectNote";
}
