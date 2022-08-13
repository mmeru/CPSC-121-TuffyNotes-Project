#include "notebook.hpp"
#include <iostream>

int main() {
  int i = 0;
  Note notes[100];
  char choice;
  std::string filename;
  std::cout << "Welcome to TuffyNotes!\n\n";

  do {
    std::cout << "[C] Create a note"
              << "\n[L] List notes"
              << "\n[V] View note"
              << "\n[S] Save notes"
              << "\n[O] Load notes"
              << "\n[E] Exit"
              << "\nChoice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 'c':
    case 'C':
      notes[i++] = create_note();
      break;
    case 'l':
    case 'L':
      list_notes(notes, i);
      break;
    case 'v':
    case 'V':
      view_note(notes, i);
      break;
    case 's':
    case 'S':
      std::cout << "\nPlease enter filename: ";
      std::cin >> filename;
      save_notes(filename, notes, i);
      break;
    case 'o':
    case 'O':
      std::cout << "\nPlease enter filename: ";
      std::cin >> filename;
      load_notes(filename, notes, &i);
      break;
    case 'e':
    case 'E':
      std::cout << "\nThank you for using TuffyNotes!\n";
      return 0;
    default:
      std::cout << "\nInvalid choice. Please try again.\n\n";
      break;
    }
  } while (choice != 'E' && choice != 'e');
}
