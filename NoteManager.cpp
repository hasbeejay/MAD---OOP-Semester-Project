#include "NoteManager.hpp"
#include "SimpleNote.hpp"
#include "ToDoNote.hpp"
#include "ProjectNote.hpp"
#include "DiaryNote.hpp"
#include "PinNote.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
using namespace std;
namespace fs = filesystem;

NoteManager::NoteManager(const string& folder) : userFolder(folder) {
    loadNotes();
}

void NoteManager::loadNotes() {
    for (const auto& entry : fs::directory_iterator(userFolder)) {
        ifstream file(entry.path());
        if (!file.is_open()) {
            cerr << "Failed to open file: " << entry.path() << endl;
            continue;
        }

        string type;
        getline(file, type);  // First line contains type

        shared_ptr<Note> note;
        if (type == "SimpleNote") note = make_shared<SimpleNote>();
        else if (type == "ToDoNote") note = make_shared<ToDoNote>();
        else if (type == "ProjectNote") note = make_shared<ProjectNote>();
        else if (type == "DiaryNote") note = make_shared<DiaryNote>();
        else if (type == "PinNote") note = make_shared<PinNote>();
        else {
            cerr << "Unknown note type in file: " << entry.path() << endl;
            continue;
        }

        note->loadFromFile(file); // Populate note content
        notes.push_back(note);
    }
}


void NoteManager::addNote() {
    cout << "----------------------------------------------\n";
    cout << "Select note type:\n"
         << "----------------------------------------------\n"
         << "----------------------------------------------\n"
         << "1. Simple Note\n"
         << "----------------------------------------------\n"
         << "2. To-Do List\n"
         << "----------------------------------------------\n"
         << "3. Project\n"
         << "----------------------------------------------\n"
         << "4. Dear Diary\n"
         << "----------------------------------------------\n"
         << "5. Pins\n"
         << "----------------------------------------------\n"
         << "Choice: ";
    int choice;
    cin >> choice;
    cin.ignore();

    auto note = createNoteByType(choice);
    if (note) {
        note->create();

        // Generate filename with timestamp
        time_t t = time(nullptr);
        string filename = note->getType() + "_" + to_string(t) + ".txt";
        note->saveToFile(userFolder, filename);
        notes.push_back(note);
        cout << "----------------------------------------------\n";
        cout << "Note saved successfully.\n";
    }
}

void NoteManager::viewNotes() {
    cout << "----------------------------------------------\n";
    cout << "Your Notes:\n";
    for (size_t i = 0; i < notes.size(); ++i) {
        cout << i + 1 << ". ";
        notes[i]->display();
    }
}

void NoteManager::markFavorite() {
    cout << "----------------------------------------------\n";
    cout << "Enter note number to mark as favorite: ";
    int num;
    cin >> num;
    cin.ignore();
    if (num > 0 && num <= notes.size()) {
        favorites[to_string(num)] = true;
        cout << "----------------------------------------------\n";
        cout << "Note marked as favorite.\n";
    }
}

void NoteManager::viewFavorites() {
    cout << "----------------------------------------------\n";
    cout << "Favorite Notes:\n";
    for (const auto& [key, fav] : favorites) {
        if (fav) {
            int idx = stoi(key) - 1;
            if (idx >= 0 && idx < notes.size()) {
                notes[idx]->display();
            }
        }
    }
}

void NoteManager::viewToDoLists() {
    cout << "----------------------------------------------\n";
    cout << "Your To-Do Lists:\n";
    for (const auto& note : notes) {
        if (note->getType() == "ToDoNote") {
            note->display();
        }
    }
}

void NoteManager::viewPins() {
    cout << "----------------------------------------------\n";
    cout << "Your Pins:\n";
    for (const auto& note : notes) {
        if (note->getType() == "PinNote") {
            note->display();
        }
    }
}

shared_ptr<Note> NoteManager::createNoteByType(int type) {
    // Create the appropriate note type based on user input
    switch (type) {
        case 1: return make_shared<SimpleNote>();
        case 2: return make_shared<ToDoNote>();
        case 3: return make_shared<ProjectNote>();
        case 4: return make_shared<DiaryNote>();
        case 5: return make_shared<PinNote>();
        cout << "----------------------------------------------\n";
        default: cout << "Invalid type.\n"; return nullptr;
    }
}
