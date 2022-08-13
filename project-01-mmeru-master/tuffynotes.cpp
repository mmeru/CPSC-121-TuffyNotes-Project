#include <iostream>

// This file asks the user if they want to create a note

// Collects note title and note body input from user
void add_note() {
  std::string title;
  std::string note;
  std::cout << "\nPlease enter the note's title: ";
  std::cin >> title;
  std::cout << "Please enter the note: ";
  std::cin >> note;
}

int main() {

  char choice;
  std::cout << "Welcome to TuffyNotes!\n";

  do {
    std::cout << "[C] Create a note"
              << "\n[E] Exit"
              << "\nChoice: ";
    std::cin >> choice;

    switch (choice) {
    case 'c':
    case 'C':
      add_note();
      std::cout << "\nNote added!\n\n";
      break;
    case 'e':
    case 'E':
      std::cout << "\nThank you for using TuffyNotes!\n";
      return 0;
    default:
      std::cout << "\nInvalid choice. Please try again.\n\n";
      break;
    }
  } while (choice != 'E' || choice != 'e');
}
