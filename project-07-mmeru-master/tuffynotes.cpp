#include "notebook.hpp"
#include <iostream>

int main() {
  char choice;
  std::string filename;
  Notebook tuffynotes;

  std::cout << "Welcome to TuffyNotes!\n\n";
  do {
    std::cout << "[C] Create a note\n";
    std::cout << "[N] Create an encrypted note\n";
    std::cout << "[X] Create a self-destruct note\n";
    std::cout << "[L] List notes\n";
    std::cout << "[V] View note\n";
    std::cout << "[S] Save notes\n";
    std::cout << "[O] Load notes\n";
    std::cout << "[E] Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 'c':
    case 'C':
      tuffynotes.add(create_note());
      break;
    case 'n':
    case 'N':
      tuffynotes.add(create_encrypted_note());
      break;
    case 'x':
    case 'X':
      tuffynotes.add(create_self_destruct_note());
      break;
    case 'l':
    case 'L':
      tuffynotes.list();
      break;
    case 'e':
    case 'E':
      std::cout << "\nThank you for using TuffyNotes!\n";
      break;
    case 'v':
    case 'V':
      tuffynotes.view();
      break;
    case 's':
    case 'S':
      std::cout << "\nPlease enter filename: ";
      getline(std::cin, filename);
      tuffynotes.save(filename);
      break;
    case 'o':
    case 'O':
      std::cout << "\nPlease enter filename: ";
      getline(std::cin, filename);
      tuffynotes.load(filename);
      break;
    default:
      std::cout << "\nInvalid choice. Please try again.\n\n";
    }
  } while (choice != 'e' && choice != 'E');

  return 0;
}
