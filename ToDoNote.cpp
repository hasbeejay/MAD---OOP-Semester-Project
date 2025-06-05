#include "ToDoNote.hpp"
#include <iostream>
#include "Utils.h"
#include <fstream>
using namespace std;

void ToDoNote::create() {
    cout << "----------------------------------------------\n";
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter tasks (type 'done' to finish):\n";
    string task;
    while (true) {
        getline(cin, task);
        if (task == "done") break;
        tasks.push_back(task);
    }
}

void ToDoNote::display() const {
    cout << "----------------------------------------------\n";
    cout << "To-Do: " << title << "\nTasks:\n";
    for (const auto& t : tasks) {
        Utils::printGreen("- " + t + "\n"); 
    }
}

void ToDoNote::saveToFile(const string& userFolder, const string& filename) const {
    ofstream file(userFolder + "/" + filename);
    file << "ToDoNote\n" << title << "\n";
    for (const auto& t : tasks) {
        file << t << "\n";
    }
}

void ToDoNote::loadFromFile(ifstream& in) {
    getline(in, title);
    tasks.clear();

    string task;
    while (getline(in, task)) {
        if (!task.empty())
            tasks.push_back(task);
    }
}


string ToDoNote::getType() const {
    return "ToDoNote";
}
