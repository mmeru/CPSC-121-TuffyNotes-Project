#include <iostream>

class Note {
private:
  std::string title_, body_;

public:
  void set_title(std::string title) { title_ = title; }
  void set_body(std::string body) { body_ = body; }

  std::string title() { return title_; }
  std::string body() { return body_; }
};

Note create_note();
