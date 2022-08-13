#include "notebook.hpp"
#include <fstream>
#include <iostream>

void Notebook::add(Note &new_note) { notes_[size_++] = new_note; }

Note create_note() {
  std::string title;
  std::string note;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, note);
  Note combinednote;
  combinednote.set_title(title);
  combinednote.set_body(note);
  std::cout << "\nNote added!\n\n";
  return combinednote;
}

Note Notebook::get(int index) const { return *(notes_ + index); }

void Notebook::list() const {
  if (size_ == 0) {
    std::cout << "\nNo notes have been added.\n\n";
  } else {
    std::cout << "\nNotes\n";
    for (int i = 0; i < size_; i++) {
      std::cout << i + 1 << ". " << notes_[i].title() << '\n';
    }
    std::cout << '\n';
  }
}

void Notebook::view() const {
  int choice = 0;
  list();
  if (size_ > 0) {
    std::cout << "Please input note index: ";
    std::cin >> choice;
    if (choice <= 0 || choice > size_) {
      std::cout << "\nInvalid note index.\n\n";
    } else {
      std::cout << "\n[" << notes_[choice - 1].title() << ']' << '\n'
                << notes_[choice - 1].body() << "\n\n";
    }
  }
}

void Notebook::save(const std::string &filename) const {
  std::ofstream savefile;
  savefile.open(filename);
  savefile << size_;
  for (int i = 0; i < size_; i++) {
    savefile << "\n[Note]\n" << notes_[i].title() << '\n' << notes_[i].body();
  }
  savefile.close();
  std::cout << "Notes saved!\n\n";
}

void Notebook::load(const std::string &filename) {
  std::string list, note, title, body;
  std::ifstream savefile;
  savefile.open(filename);
  savefile >> size_;
  std::getline(savefile, list);

  for (int i = 0; i < size_; i++) {
    std::getline(savefile, note);
    std::getline(savefile, title);
    std::getline(savefile, body);
    notes_[i].set_title(title);
    notes_[i].set_body(body);
  }
  savefile.close();
  std::cout << "Notes loaded!\n\n";
}
