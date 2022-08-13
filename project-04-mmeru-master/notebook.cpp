#include "notebook.hpp"
#include <fstream>
#include <iostream>

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

void list_notes(Note arr[], int index) {
  if (index == 0) {
    std::cout << "\nNo notes have been added.\n\n";
  } else {
    std::cout << "\nNotes\n";
    for (int i = 0; i < index; i++) {
      std::cout << i + 1 << ". " << arr[i].title() << '\n';
    }
    std::cout << '\n';
  }
}

void view_note(Note arr[], int index) {
  int choice;
  list_notes(arr, index);
  if (index != 0) {
    std::cout << "Please input note index: ";
    std::cin >> choice;
    if (choice <= 0 || choice > index || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "\nInvalid note index.\n\n";
    } else {
      std::cout << "\n[" << arr[choice - 1].title() << ']' << '\n'
                << arr[choice - 1].body() << "\n\n";
    }
  }
}

void save_notes(std::string filename, Note arr[], int index) {
  std::ofstream savefile;
  savefile.open(filename);
  savefile << index;
  for (int i = 0; i < index; i++) {
    savefile << "\n[Note]\n" << arr[i].title() << '\n' << arr[i].body();
  }
  std::cout << "Notes saved!\n\n";
  savefile.close();
}

void load_notes(std::string filename, Note arr[], int *ptr_index) {
  std::string list, note, title, body;
  std::ifstream savefile;
  savefile.open(filename);
  savefile >> *ptr_index;
  std::getline(savefile, list);
  for (int i = 0; i < *ptr_index; i++) {
    std::getline(savefile, note);
    std::getline(savefile, title);
    std::getline(savefile, body);
    arr[i].set_title(title);
    arr[i].set_body(body);
  }
  savefile.close();
  std::cout << "Notes loaded!\n\n";
}
