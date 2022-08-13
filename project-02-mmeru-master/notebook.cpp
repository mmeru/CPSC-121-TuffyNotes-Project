#include "notebook.hpp"

Note create_note() {
  Note combinednote;
  std::string title;
  std::string note;
  std::cout << "\nPlease enter the note's title: ";
  std::cin >> title;
  combinednote.set_title(title);
  std::cout << "Please enter the note: ";
  std::cin >> note;
  combinednote.set_body(note);
  std::cout << "\nNote added!\n\n";
  return combinednote;
}
