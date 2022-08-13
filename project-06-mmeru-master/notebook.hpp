#include <fstream>
#include <iostream>

class Note {
protected:
  std::string title_, body_;

public:
  Note() : title_("Untitled"), body_("") {}
  Note(const std::string &title, const std::string &body)
      : title_(title), body_(body) {}

  void set_title(std::string title) { title_ = title; }
  void set_body(std::string body) { body_ = body; }

  std::string title() const { return title_; }
  std::string body() const { return body_; }

  virtual void display() {
    std::cout << '[' << title_ << "]\n";
    std::cout << body_ << "\n\n";
  }
  virtual std::string serialize() {
    return "[Note]\n" + title_ + '\n' + body_ + '\n';
  }
};

class Notebook {
private:
  int capacity_{100}, size_{0};
  Note **notes_;

public:
  Notebook() : notes_(new Note *[100]) {}
  Notebook(int capacity) : capacity_(capacity), notes_(new Note *[capacity_]) {}

  ~Notebook() {
    for (int i = 0; i < capacity_; i++) {
      delete notes_[i];
      notes_[i] = nullptr;
    }
    delete[] notes_;
    notes_ = nullptr;
  }

  int capacity() const { return capacity_; }
  int size() const { return size_; }

  void add(Note *new_note);
  Note *get(int index) const;
  void list() const;
  void view() const;
  void save(const std::string &filename) const;
  void load(const std::string &filename);
};

class EncryptedNote : public Note {
private:
  std::string password_;

public:
  EncryptedNote() : password_("") {}
  EncryptedNote(const std::string &title, const std::string &body,
                const std::string &password)
      : Note(title, body), password_(password) {}

  void display() override {
    std::string pw;
    std::cout << "Please enter password to view note: ";
    std::cin >> pw;
    if (pw == password_) {
      Note::display();
    } else {
      std::cout << "Sorry, you do not have the permission to view note.\n\n";
    }
  }
  std::string serialize() override {
    return "[EncNote]\n" + title_ + '\n' + body_ + '\n' + password_ + '\n';
  }
};

Note *create_note();
EncryptedNote *create_encrypted_note();
