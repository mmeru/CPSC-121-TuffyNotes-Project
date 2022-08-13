#include <iostream>

class Note {
private:
  std::string title_, body_;

public:
  Note() : Note("Untitled", "") {}
  Note(const std::string &title, const std::string &body)
      : title_(title), body_(body) {}

  void set_title(const std::string &title) { title_ = title; }
  void set_body(const std::string &body) { body_ = body; }
  std::string title() const { return title_; }
  std::string body() const { return body_; }

  // Displays the title and body of the note using the format:
  // [Note title]
  // Note body
  virtual void display() {
    std::cout << "[" << title_ << "]\n" << body_ << "\n\n";
  }

  // Generates a string representation of the object used for saving and loading
  virtual std::string serialize() const {
    return "[Note]\n" + title_ + "\n" + body_ + "\n";
  }
};

// Representation of an EncryptedNote that derives from the Note object.
// It contains a title, body, and password
// The EncryptedNote can only be viewed with the correct password
class EncryptedNote : public Note {
private:
  std::string password_;

public:
  EncryptedNote(const std::string &title, const std::string &body,
                const std::string &password)
      : Note(title, body), password_(password) {}

  EncryptedNote() : password_("") {}

  // Displays the encrypted note only if the correct password is provided
  void display() override;

  // Generates a string representation of the object used for saving and loading
  std::string serialize() const override {
    return "[EncNote]\n" + title() + "\n" + body() + "\n" + password_ + "\n";
  }
};

class SelfDestructNote : public Note {
private:
  bool read_;

public:
  SelfDestructNote() : read_(false) {}
  SelfDestructNote(const std::string &title, const std::string &body, bool read)
      : Note(title, body), read_(read) {}

  void display() override {
    if (!read_) {
      std::cout << "[" << title() << "]\n"
                << body() << "\n\n"
                << "The note will self-destruct in 3.. 2.. 1..\n\n";
      read_ = true;
    } else {
      std::cout << "The note has already been destroyed.\n\n";
    }
  }
  std::string serialize() {
    return "[SDNote]\n" + title() + "\n" + body() + "\n" +
           std::to_string(read_) + "\n";
  }
};

// Representation of a notebook that contains and manages notes
class Notebook {
private:
  int size_, capacity_;
  Note **notes_;

public:
  Notebook() : Notebook(100) {}

  // The constructor dynamically creates an array of Note pointers
  // added to the Notebook
  Notebook(int capacity)
      : size_(0), capacity_(capacity), notes_(new Note *[capacity]) {}

  // The destructors delete all dynamically created Note and EncryptedNote
  // objects stored in the notebook.
  ~Notebook() {
    for (int i = 0; i < size_; i++) {
      delete notes_[i];
      notes_[i] = nullptr;
    }
    delete[] notes_;
    notes_ = nullptr;
  }

  int capacity() const { return capacity_; }
  int size() const { return size_; }
  // Adds a Note pointer to the notebook. This may be a Note object or any of
  // its subclasses. Take note that the notebook's size increases everytime a
  // Note is added
  void add(Note *new_note) { notes_[size_++] = new_note; }

  // Lists all note titles according to the size parameter provideds
  void list() const;

  // Retrieves a Note pointer in the specified index. Take note that indices
  // start at 0
  Note *get(int index) const { return notes_[index]; }

  // Displays all Note objects then asks the user to provide the Note index to
  // show. It displays an error message when the selected index is outside the
  // range of the note array's indeices
  void view() const;

  // Stores all Note objects to a file named filename.
  void save(const std::string &filename) const;

  // Loads all Note objects stored in a file and updates the size so that it
  // contains the total number of note objects loaded
  void load(const std::string &filename);
};

// Asks the user to create a Note with it's title and body then returns a
// pointer to the Note object containing the user-provided values
Note *create_note();

// Asks the user to create an EncryptedNote with it's title, body, and password
// then returns a pointer to the Encrypted Note object containing the
// user-provided values
EncryptedNote *create_encrypted_note();

SelfDestructNote *create_self_destruct_note();
