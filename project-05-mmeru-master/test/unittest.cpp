#include "../notebook.hpp"
#include "gtest_ext.h"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

const std::string UNITEST_FILENAME = "my_notes.txt";

class FileIO : public ::testing::Test {
protected:
  void SetUp() override {
    std::ifstream my_empty_file;
    my_empty_file.open(UNITEST_FILENAME);
    if (my_empty_file.good()) {
      rename(UNITEST_FILENAME.c_str(), TEMP_FILENAME.c_str());
      file_exists = true;
    }
    my_empty_file.close();
  }

  void TearDown() override {
    if (file_exists) {
      rename(TEMP_FILENAME.c_str(), UNITEST_FILENAME.c_str());
    } else {
      remove(UNITEST_FILENAME.c_str());
    }
  }
  std::string TEMP_FILENAME = "user_notes.txt";
  bool file_exists = false;
};

TEST(Milestone1, FiniteChoiceLoop) {
  srand(time(NULL));
  ASSERT_DURATION_LE(3, { main_output("tuffynotes", "c\nX\nX\ne"); });
}

TEST(Milestone1, CreateQuestionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nPlease enter "
      "the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\ne\n", unittest_output); });
}

TEST(Milestone3, ListNotesChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nPlease enter "
      "the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: "
      "\nNotes\n1. X\n\n[C] Create a note\n[L] "
      "List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nThank you for "
      "using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\nl\ne\n", unittest_output);
  });
}

TEST(Milestone3, ViewNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nNotes\n1. X\n\nPlease input note index: \n[X]\nX\n\n[C] "
      "Create a note\n[L] List notes\n[V] View note\n[S] Save notes\n[O] Load "
      "notes\n[E] Exit\nChoice: \nThank "
      "you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\nv\n1\ne\n", unittest_output);
  });
}

TEST(Milestone1, QuitChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "e\n", unittest_output); });
}

TEST(Milestone1, InvalidOptionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nInvalid choice. Please try "
      "again.\n\n[C] Create a note\n[L] List notes\n[V] View note\n[S] Save "
      "notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, {ASSERT_EXECIO_EQ("tuffynotes", "x\ne\n", unittest_output)});
}

TEST_F(FileIO, Milestone1_4_ChoiceLoopLowercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!\n\n";
  char choices[] = {'c', 'e', 'l', 'v', 's', 'o', 'L', 'C', 'E', 'V', 'S', 'O'};
  unsigned int note_count = 1;
  unsigned int saved_note_count = note_count;
  std::string note_list = "\nNotes\n";
  std::string saved_note_list = note_list;
  char choice = ' ';
  do {
    choice = choices[rand() % 6];
    unittest_output += "[C] Create a note\n[L] List notes\n[V] View note\n[S] "
                       "Save notes\n[O] Load notes\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'c':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n\n";
      input += "t\\nb\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      break;
    case 'l':
      if (note_count > 1) {
        unittest_output += note_list + "\n";
      } else {
        unittest_output += "\nNo notes have been added.\n\n";
      }
      break;
    case 'v':
      if (note_count > 1) {
        unittest_output +=
            note_list + "\nPlease input note index: \n[t]\nb\n\n";
        input += "1\\n";
      } else {
        unittest_output += "\nNo notes have been added.\n\n";
      }
      break;
    case 's':
      unittest_output += "\nPlease enter filename: Notes saved!\n\n";
      input += UNITEST_FILENAME + "\\n";
      saved_note_count = note_count;
      saved_note_list = note_list;
      break;
    case 'o':
      unittest_output += "\nPlease enter filename: Notes loaded!\n\n";
      input += UNITEST_FILENAME + "\n";
      note_list = saved_note_list;
      note_count = saved_note_count;
      break;
    case 'e':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "Invalid choice. Please try again.\n\n";
    }
  } while (choice != 'e');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST_F(FileIO, Milestone1_4_ChoiceLoopUppercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!\n\n";
  char choices[] = {'c', 'e', 'l', 'v', 's', 'o', 'L', 'C', 'E', 'V', 'S', 'O'};
  unsigned int note_count = 1;
  unsigned int saved_note_count = note_count;
  std::string note_list = "\nNotes\n";
  std::string saved_note_list = note_list;
  char choice = ' ';
  do {
    choice = choices[rand() % 6 + 6];
    unittest_output += "[C] Create a note\n[L] List notes\n[V] View note\n[S] "
                       "Save notes\n[O] Load notes\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'C':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n\n";
      input += "t\\nb\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      break;
    case 'L':
      if (note_count > 1) {
        unittest_output += note_list + "\n";
      } else {
        unittest_output += "\nNo notes have been added.\n\n";
      }
      break;
    case 'V':
      if (note_count > 1) {
        unittest_output +=
            note_list + "\nPlease input note index: \n[t]\nb\n\n";
        input += "1\\n";
      } else {
        unittest_output += "\nNo notes have been added.\n\n";
      }
      break;
    case 'S':
      unittest_output += "\nPlease enter filename: Notes saved!\n\n";
      input += UNITEST_FILENAME + "\\n";
      saved_note_count = note_count;
      saved_note_list = note_list;
      break;
    case 'O':
      unittest_output += "\nPlease enter filename: Notes loaded!\n\n";
      input += UNITEST_FILENAME + "\n";
      note_list = saved_note_list;
      note_count = saved_note_count;
      break;
    case 'E':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "Invalid choice. Please try again.\n\n";
    }
  } while (choice != 'E');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST(Milestone2, NoteClass) {
  Note temp;
  temp.set_title("title");
  temp.set_body("body");
  temp.title();
  temp.body();
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "[title]\nbody\n\n", {
      temp.display();
    });
  });

}

TEST(Milestone2, TitleGetSet) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  your_note_object.set_title(unittest_title);
  ASSERT_EQ(your_note_object.title(), unittest_title);
}

TEST(Milestone2, BodyGetSet) {
  Note your_note_object;
  std::string unittest_body = generate_string(10);
  your_note_object.set_body(unittest_body);
  ASSERT_EQ(your_note_object.body(), unittest_body);
}

TEST(Milestone5, NoteDefaultConstructor) {
  Note your_note_object;
  ASSERT_EQ(your_note_object.title(), "Untitled");
  ASSERT_EQ(your_note_object.body(), "");
}

TEST(Milestone5, NoteNonDefaultConstructor) {
  std::string unittest_title, unittest_body;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  Note your_note_object(unittest_title, unittest_body);
  ASSERT_EQ(your_note_object.title(), unittest_title);
  ASSERT_EQ(your_note_object.body(), unittest_body);
}

TEST(Milestone5, NoteDisplay) {
  std::string unittest_title, unittest_body, unittest_display;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  unittest_display =  "[" + unittest_title + "]\n" + unittest_body + "\n\n";
  Note your_note_object(unittest_title, unittest_body);
  ASSERT_DURATION_LE(3, ASSERT_SIO_EQ("", unittest_display, {
    your_note_object.display();
  }));
}

TEST(Milestone5, NotebookDefaultConstructor) {
  Notebook your_notebook;
  ASSERT_EQ(your_notebook.capacity(), 100);
  ASSERT_EQ(your_notebook.size(), 0);
}

TEST(Milestone5, NotebookNonDefaultConstructor) {
  int unittest_capacity = rand() % 10;
  Notebook your_notebook(unittest_capacity);
  ASSERT_EQ(your_notebook.capacity(), unittest_capacity);
  ASSERT_EQ(your_notebook.size(), 0);
}

TEST(Milestone5, NotebookAdd) {
  std::string unittest_title, unittest_body, unittest_display;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  Note test_note(unittest_title, unittest_body);
  Notebook your_notebook;
  your_notebook.add(test_note);
  ASSERT_EQ(your_notebook.size(), 1);
  ASSERT_EQ(your_notebook.get(0).title(), unittest_title);
  ASSERT_EQ(your_notebook.get(0).body(), unittest_body);
}

TEST(Milestone5, NotebookGet) {
  int notes_size = rand() % 10 + 1;
  Notebook your_notebook;
  std::string unittest_titles[notes_size];
  std::string unittest_bodies[notes_size];

  for (int i = 0; i < notes_size; i++) {
    Note temp;
    std::string temp_str = generate_string(10);
    unittest_titles[i] = temp_str;
    temp.set_title(temp_str);
    temp_str = generate_string(10);
    unittest_bodies[i] = temp_str;
    temp.set_body(temp_str);
    your_notebook.add(temp);
  }

  for (int i = 0; i < notes_size; i++) {
    std::string unittest_title = unittest_titles[i];
    ASSERT_EQ(your_notebook.get(i).title(), unittest_title);
    std::string unittest_body = unittest_bodies[i];
    ASSERT_EQ(your_notebook.get(i).body(), unittest_body);
  }
}

TEST(Milestone2, CreateNote) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  std::string unittest_body = generate_string(10);
  std::string input = unittest_title + "\n" + unittest_body + "\n";
  std::string unittest_output = "\nPlease enter the note's title: ";
  unittest_output += "Please enter the note: \nNote added!\n\n";
  ASSERT_SIO_EQ(input, unittest_output, { your_note_object = create_note(); });
  ASSERT_EQ(your_note_object.title(), unittest_title);
  ASSERT_EQ(your_note_object.body(), unittest_body);
}

/*
Replaced by milestone 5 test
TEST(Milestone3, ListNotesEmpty) {
  Note empty_array[0];
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n\n",
                  { list_notes(empty_array, 0); });
  });
}*/

TEST(Milestone5, ListNotesEmpty) {
  Notebook unittest_notebook;
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n\n",
                  { unittest_notebook.list(); });
  });
}

/* Replaced by milestone 5 test
TEST(Milestone3, ListNotesSingle) {
  Note notes[1];
  notes[0].set_title("Buy groceries");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNotes\n1. Buy groceries\n\n",
                  { list_notes(notes, 1); });
  });
}*/
TEST(Milestone5, ListNotesSingle) {
  Notebook unittest_notebook;
  Note temp;
  unittest_notebook.add(temp);

  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNotes\n1. Untitled\n\n",
                  { unittest_notebook.list(); });
  });
}

/* Replaced by milestone 5 test
TEST(Milestone3, ListNotesMultiple) {
  Note notes[3];
  notes[0].set_title("Buy groceries");
  notes[1].set_title("CPSC 121 guide questions");
  notes[2].set_title("Group mates list");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("",
                  "\nNotes\n1. Buy groceries\n2. CPSC 121 guide questions\n3. "
                  "Group mates list\n\n",
                  { list_notes(notes, 3); });
  });
}*/

TEST(Milestone5, ListNotesMultiple) {
  Notebook unittest_notebook;
  Note temp("Buy groceries", "");
  unittest_notebook.add(temp);
  temp.set_title("CPSC 121 guide questions");
  unittest_notebook.add(temp);
  temp.set_title("Group mates list");
  unittest_notebook.add(temp);
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("",
                  "\nNotes\n1. Buy groceries\n2. CPSC 121 guide questions\n3. "
                  "Group mates list\n\n",
                  { unittest_notebook.list(); });
  });
}

/* Replaced by milestone 5 test
TEST(Milestone3, ViewNoteEmpty) {
  Note empty_array[0];
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n\n",
                  { view_note(empty_array, 0); });
  });
}*/
TEST(Milestone5, ViewNoteEmpty) {
  Notebook unittest_notebook;
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n\n",
                  { unittest_notebook.view(); });
  });
}

/* Replaced by milestone 5 test
TEST(Milestone3, ViewNote) {
  Note notes[2];
  notes[0].set_title("Group mates list");
  notes[1].set_title("Buy groceries");
  notes[1].set_body("1 qt. of milk, 5 apples, 1 dozen eggs");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ(
        "2",
        "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease input note "
        "index: \n[Buy groceries]\n1 qt. of milk, 5 apples, 1 dozen eggs\n\n",
        { view_note(notes, 2); });
  });
}*/
TEST(Milestone5, ViewNote) {
  Notebook unittest_notebook;
  Note temp("Group mates list", "");
  unittest_notebook.add(temp);
  temp.set_title("Buy groceries");
  temp.set_body("1 qt. of milk, 5 apples, 1 dozen eggs");
  unittest_notebook.add(temp);

  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ(
        "2",
        "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease input note "
        "index: \n[Buy groceries]\n1 qt. of milk, 5 apples, 1 dozen eggs\n\n",
        { unittest_notebook.view(); });
  });
}

/* Replaced by milestone 5 test
TEST(Milestone3, ViewNoteInvalidIndex) {
  Note notes[2];
  notes[0].set_title("Group mates list");
  notes[1].set_title("Buy groceries");
  notes[1].set_body("1 qt. of milk, 5 apples, 1 dozen eggs");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("8",
                  "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease "
                  "input note index: \nInvalid note index.\n\n",
                  { view_note(notes, 2); });
  });
}*/
TEST(Milestone5, ViewNoteInvalidIndex) {
  Notebook unittest_notebook;
  Note temp("Group mates list", "");
  unittest_notebook.add(temp);
  temp.set_title("Buy groceries");
  temp.set_body("1 qt. of milk, 5 apples, 1 dozen eggs");
  unittest_notebook.add(temp);
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("8",
                  "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease "
                  "input note index: \nInvalid note index.\n\n",
                  { unittest_notebook.view(); });
  });
}

/* Replaced by milestone 5 test
TEST_F(FileIO, Milestone4_SaveNotes) {
  int notes_size = rand() % 10 + 1;
  Note unittest_notes[notes_size];
  for (int i = 0; i < notes_size; i++) {
    Note temp;
    temp.set_title(generate_string(10));
    temp.set_body(generate_string(10));
    unittest_notes[i] = temp;
  }
  ASSERT_SIO_EQ("", "Notes saved!\n\n",
                { save_notes(UNITEST_FILENAME, unittest_notes, notes_size); });
  std::ifstream the_file;
  the_file.open(UNITEST_FILENAME);
  std::string your_file_output = "";
  std::getline(the_file, your_file_output);
  the_file.close();
  ASSERT_GT(your_file_output.length(), 0)
      << "   Your file appears to be empty. Check your code to see if the file "
         "is saved properly.";
}*/
TEST_F(FileIO, Milestone5_SaveNotes) {
  int notes_size = rand() % 10 + 1;
  Notebook unittest_notebook;
  std::string unittest_file_output = std::to_string(notes_size) + "\n";
  for (int i = 0; i < notes_size; i++) {
    Note temp;
    std::string temp_str = generate_string(10);
    temp.set_title(temp_str);
    unittest_file_output += "[Note]\n" + temp_str + "\n";
    temp_str = generate_string(10);
    temp.set_body(temp_str);
    unittest_file_output += temp_str + "\n";
    unittest_notebook.add(temp);
  }
  ASSERT_SIO_EQ("", "Notes saved!\n\n",
                { unittest_notebook.save(UNITEST_FILENAME); });
  std::ifstream the_file;
  the_file.open(UNITEST_FILENAME);
  std::string your_file_output = "", temp_str = "";
  while (std::getline(the_file, temp_str)) {
    your_file_output += temp_str + "\n";
  }
  the_file.close();
  ASSERT_GT(your_file_output.length(), 0)
      << "   Your file appears to be empty. Check your code to see if the file "
         "is saved properly.";
  ASSERT_EQ(your_file_output, unittest_file_output) << "   Your file does not seem to follow the expected format.";
}

/* Replaced by milestone 5 test
TEST_F(FileIO, Milestone4_LoadNotes) {
  int unittest_notes_size = rand() % 10 + 1;
  Note unittest_notes[unittest_notes_size];

  std::ofstream the_file;
  the_file.open(UNITEST_FILENAME);
  the_file << unittest_notes_size << "\n";
  for (int i = 0; i < unittest_notes_size; i++) {
    Note temp;
    the_file << "[Note]\n";

    std::string temp_string = generate_string(10);
    temp.set_title(temp_string);
    the_file << temp_string << "\n";

    temp_string = generate_string(10);
    temp.set_body(temp_string);
    the_file << temp_string << "\n";

    unittest_notes[i] = temp;
  }
  the_file.close();

  int your_file_notes_size = 0;
  Note your_notes[100];
  ASSERT_SIO_EQ("", "Notes loaded!\n\n", {
    load_notes(UNITEST_FILENAME, your_notes, &your_file_notes_size);
  });

  ASSERT_EQ(your_file_notes_size, unittest_notes_size)
      << "  Your code did not load the correct number of notes.";
  for (int i = 0; i < unittest_notes_size; i++) {
    ASSERT_EQ(your_notes[i].title(), unittest_notes[i].title())
        << "  The title of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ASSERT_EQ(your_notes[i].body(), unittest_notes[i].body())
        << "  The body of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ;
  }
}*/
TEST_F(FileIO, Milestone5_LoadNotes) {
  int unittest_notes_size = rand() % 10 + 1;
  Notebook unittest_notebook;
  std::ofstream the_file;
  the_file.open(UNITEST_FILENAME);
  the_file << unittest_notes_size << "\n";
  for (int i = 0; i < unittest_notes_size; i++) {
    Note temp;
    the_file << "[Note]\n";

    std::string temp_string = generate_string(10);
    temp.set_title(temp_string);
    the_file << temp_string << "\n";

    temp_string = generate_string(10);
    temp.set_body(temp_string);
    the_file << temp_string << "\n";
    unittest_notebook.add(temp);
  }
  the_file.close();

  Notebook your_notebook;
  ASSERT_SIO_EQ("", "Notes loaded!\n\n", {
    your_notebook.load(UNITEST_FILENAME);
  });

  ASSERT_EQ(your_notebook.size(), unittest_notebook.size())
      << "  Your code did not load the correct number of notes.";
  for (int i = 0; i < unittest_notes_size; i++) {
    ASSERT_EQ(your_notebook.get(i).title(), unittest_notebook.get(i).title())
        << "  The title of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ASSERT_EQ(your_notebook.get(i).body(), unittest_notebook.get(i).body())
        << "  The body of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ;
  }
}

TEST_F(FileIO, Milestone4_SaveNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter filename: Notes saved!\n\n"
      "[C] Create a note\n[L] List notes\n[V] View note\n[S] Save notes\n[O] "
      "Load "
      "notes\n[E] Exit\nChoice: \nThank "
      "you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    std::string input = "c\nX\nX\ns\n" + UNITEST_FILENAME + "\ne\n";
    ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output);
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
