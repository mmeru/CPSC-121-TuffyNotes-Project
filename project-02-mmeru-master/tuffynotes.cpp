#include "notebook.hpp"
#include <iostream>

int main() {
  int i = 0;
  Note notes[100];
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
      notes[i++] = create_note();
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
