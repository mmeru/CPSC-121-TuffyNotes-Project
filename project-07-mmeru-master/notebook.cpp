#include "notebook.hpp"
#include <fstream>
#include <iostream>

Note *create_note() {
  std::string title, body;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, body);
  std::cout << "\n";
  Note *my_note = new Note(title, body);
  std::cout << "Note added!\n\n";
  return my_note;
}

EncryptedNote *create_encrypted_note() {
  std::string title, body, password;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, body);
  std::cout << "Please enter the password: ";
  getline(std::cin, password);
  std::cout << "\n";
  EncryptedNote *my_note = new EncryptedNote(title, body, password);
  std::cout << "Encrypted Note added!\n\n";
  return my_note;
}

SelfDestructNote *create_self_destruct_note() {
  std::string title, body, password;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, body);
  std::cout << "\n";
  SelfDestructNote *my_note = new SelfDestructNote(title, body, false);
  std::cout << "Self-destruct Note added!\n\n";
  return my_note;
}

void Notebook::list() const {
  if (size_ == 0) {
    std::cout << "\nNo notes have been added.\n\n";
  } else {
    std::cout << "\nNotes\n";
    for (unsigned int i = 0; i < size_; i++) {
      std::cout << i + 1 << ". " << notes_[i]->title() << "\n";
    }
    std::cout << "\n";
  }
}

void Notebook::view() const {
  list();
  if (size_ > 0) {
    unsigned int index = 0;
    std::cout << "Please input note index: ";
    std::cin >> index;
    std::cin.ignore();
    if (index - 1 >= size_) {
      std::cout << "\nInvalid note index.\n\n";
    } else {
      std::cout << "\n";
      notes_[index - 1]->display();
    }
  }
}

void Notebook::save(const std::string &filename) const {
  std::ofstream save_file;
  save_file.open(filename);
  save_file << size_ << "\n";
  for (int i = 0; i < size_; i++) {
    save_file << notes_[i]->serialize();
  }
  save_file.close();
  std::cout << "Notes saved!\n\n";
}

void Notebook::load(const std::string &filename) {
  size_ = 0;
  for (int i = 0; i < size_; i++) {
    delete notes_[i];
    notes_[i] = nullptr;
  }
  delete[] notes_;
  notes_ = new Note *[capacity_];

  std::ifstream load_file;
  load_file.open(filename);
  load_file >> size_;
  load_file.ignore();
  std::string note_type, title, body, password;
  for (int i = 0; i < size_; i++) {
    getline(load_file, note_type);
    getline(load_file, title);
    getline(load_file, body);
    if (note_type == "[Note]") {
      notes_[i] = new Note(title, body);
    } else if (note_type == "[EncNote]") {
      getline(load_file, password);
      notes_[i] = new EncryptedNote(title, body, password);
    } else if (note_type == "[SDNote]") {
      notes_[i] = new SelfDestructNote(title, body, false);
    }
  }
  load_file.close();
  std::cout << "Notes loaded!\n\n";
}

void EncryptedNote::display() {
  std::string password;
  std::cout << "Please enter password to view note: ";
  getline(std::cin, password);
  if (password == password_) {
    Note::display();
  } else {
    std::cout << "Sorry, you do not have the permission to view note.\n\n";
  }
}
