#include "notebook.hpp"
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
