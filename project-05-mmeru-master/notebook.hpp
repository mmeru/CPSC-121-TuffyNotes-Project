
#include <fstream>
#include <iostream>

class Note {
private:
  std::string title_, body_;

public:
  Note() : title_("Untitled"), body_("") {}
  Note(const std::string &title, const std::string &body)
      : title_(title), body_(body) {}

  void set_title(std::string title) { title_ = title; }
  void set_body(std::string body) { body_ = body; }

  std::string title() { return title_; }
  std::string body() { return body_; }

  void display() {
    std::cout << '[' << title_ << "]\n";
    std::cout << body_ << "\n\n";
  }
};

class Notebook {
private:
  int capacity_{100}, size_{0};
  Note *notes_;

public:
  Notebook() : notes_(new Note[100]) {}
  Notebook(int capacity) : capacity_(capacity), notes_(new Note[capacity_]) {}

  ~Notebook() {
    delete[] notes_;
    notes_ = nullptr;
  }

  int capacity() { return capacity_; }
  int size() { return size_; }

  void add(Note &new_note);
  Note get(int index) const;
  void list() const;
  void view() const;
  void save(const std::string &filename) const;
  void load(const std::string &filename);
};

Note create_note();
