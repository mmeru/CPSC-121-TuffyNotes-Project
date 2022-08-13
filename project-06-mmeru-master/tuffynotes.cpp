#include "notebook.hpp"
#include <iostream>

int main() {
  Notebook note;
  Note new_note;
  EncryptedNote new_enc_note;
  char choice;
  std::string filename;
  std::cout << "Welcome to TuffyNotes!\n\n";

  do {
    std::cout << "[C] Create a note"
              << "\n[N] Create an encrypted note"
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
      note.add(create_note());
      break;
    case 'n':
    case 'N':
      note.add(create_encrypted_note());
      break;
    case 'l':
    case 'L':
      note.list();
      break;
    case 'v':
    case 'V':
      note.view();
      break;
    case 's':
    case 'S':
      std::cout << "\nPlease enter filename: ";
      std::cin >> filename;
      note.save(filename);
      break;
    case 'o':
    case 'O':
      std::cout << "\nPlease enter filename: ";
      std::cin >> filename;
      note.load(filename);
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
