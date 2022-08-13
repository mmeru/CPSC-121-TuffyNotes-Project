#include "notebook.hpp"
#include <fstream>
#include <iostream>

void Notebook::add(Note *new_note) { notes_[size_++] = new_note; }

Note *create_note() {
  std::string title;
  std::string note;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, note);
  Note *combinednote = new Note(title, note);
  std::cout << "\nNote added!\n\n";
  return combinednote;
}

EncryptedNote *create_encrypted_note() {
  std::string title;
  std::string note;
  std::string pw;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, note);
  std::cout << "Please enter the password: ";
  getline(std::cin, pw);
  EncryptedNote *encnote = new EncryptedNote(title, note, pw);
  std::cout << "\nEncrypted Note added!\n\n";
  return encnote;
}

Note *Notebook::get(int index) const { return notes_[index]; }

void Notebook::list() const {
  if (size_ == 0) {
    std::cout << "\nNo notes have been added.\n\n";
  } else {
    std::cout << "\nNotes\n";
    for (int i = 0; i < size_; i++) {
      std::cout << i + 1 << ". " << notes_[i]->title() << '\n';
    }
    std::cout << '\n';
  }
}

void Notebook::view() const {
  int choice = 0;
  list();
  if (size_ > 0) {
    std::cout << "Please input note index: \n";
    std::cin >> choice;
    if (choice <= 0 || choice > size_) {
      std::cout << "\nInvalid note index.\n";
    } else {
      get(choice - 1)->display();
    }
  }
}

void Notebook::save(const std::string &filename) const {
  std::ofstream savefile;
  savefile.open(filename);
  savefile << size_ << '\n';
  for (int i = 0; i < size_; i++) {
    savefile << get(i)->serialize();
  }
  savefile.close();
  std::cout << "Notes saved!\n\n";
}

void Notebook::load(const std::string &filename) {
  for (int i = 0; i < size(); i++) {
    delete notes_[i];
  }
  size_ = 0;
  std::string list, note, title, body, pw;
  std::ifstream savefile;
  savefile.open(filename);
  savefile >> size_;
  std::getline(savefile, list);
  for (int i = 0; i < size_; i++) {
    std::getline(savefile, note);
    std::getline(savefile, title);
    std::getline(savefile, body);
    if (note == "[Note]") {
      notes_[i] = new Note(title, body);
    } else {
      std::getline(savefile, pw);
      notes_[i] = new EncryptedNote(title, body, pw);
    }
  }
  savefile.close();
  std::cout << "Notes loaded!\n\n";
}
