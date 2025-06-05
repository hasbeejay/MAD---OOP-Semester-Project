# 💡 MAD - Mind and Dots 🧠📌

A powerful and modular **Notion-style note-taking application** built entirely in **C++ (CLI)** as a semester project. MAD offers a beautifully structured command-line interface that combines creativity, productivity, and programming principles.

---

## 🚀 Features

- 🌟 **User Authentication**
  - New user registration with username conflict checking
  - Secure login with encrypted password storage

- 📂 **Modular Note Types** (OOP with Inheritance & Polymorphism)
  - 📝 **Simple Notes**: Plain text notes
  - ✅ **To-Do Notes**: Tasks with checkboxes
  - 📌 **Pinned Notes**: High-priority notes
  - 📖 **Diary Notes**: Time-stamped daily entries
  - 🎯 **Project Notes**: Milestones and tracking

- 💾 **File Handling System**
  - Each user gets a unique folder in `UserNotes/`
  - Credentials securely stored in `UserData/`

- 🧰 **Other Functionalities**
  - Export notes to PDF (planned)
  - Search, delete, view, and edit features for each note type
  - Folder-level management
  - Well-decorated CLI using ASCII and formatting

---

## 🧠 Technologies & Concepts

- **Language**: C++
- **Paradigms**: Object-Oriented Programming
- **Concepts Used**:
  - Encapsulation, Abstraction, Inheritance, Polymorphism
  - File I/O
  - Templates
  - CLI Design

---

## 🔧 Project Structure

MAD/
├── src/
│ ├── main.cpp
│ ├── Note.h / Note.cpp
│ ├── SimpleNote.h / .cpp
│ ├── ToDoNote.h / .cpp
│ ├── DiaryNote.h / .cpp
│ ├── ProjectNote.h / .cpp
│ ├── PinNote.h / .cpp
│ └── UserManager.h / .cpp
├── UserData/ # Encrypted login data
├── UserNotes/ # User-specific note storage
├── README.md
└── LICENSE


---

## 🛠️ Installation & Usage

```bash
# Clone the repository
git clone https://github.com/your-username/MAD.git
cd MAD

# Compile the project (example using g++)
"g++ -std=c++17 -o MAD main.cpp AuthManager.cpp DiaryNote.cpp NoteManager.cpp PinNote.cpp ProjectNote.cpp SimpleNote.cpp ToDoNote.cpp"

# Run the app
"./MAD"
