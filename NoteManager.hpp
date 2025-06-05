#ifndef NOTEMANAGER_HPP
#define NOTEMANAGER_HPP
#include "Note.hpp"
#include <vector>
#include <string>
#include <memory>
#include <map>
using namespace std;

class NoteManager {
private:
    string userFolder; // Folder for user's notes
    vector<shared_ptr<Note>> notes; // List of notes
    map<string, bool> favorites;  // filename -> favorite

public:
    NoteManager(const string& folder);

    void loadNotes();
    void addNote();
    void viewNotes();
    void markFavorite();
    void viewFavorites();
    void viewToDoLists();
    void viewPins();

private:
    shared_ptr<Note> createNoteByType(int type);
};

#endif
