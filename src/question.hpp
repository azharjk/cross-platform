#include <string>
#include <vector>

class Question {
public:
  Question(const std::string& text,
           const std::vector<std::string>& answers,
           const std::string& correct_answer) :
           text_(text), answers_(answers),
           correct_answer_(correct_answer) {}

  bool Verify(const std::string& answer) const;

  std::string text() const;

  std::vector<std::string> answers() const;

  std::string correct_answer() const;

private:
  std::string text_;
  std::vector<std::string> answers_;
  std::string correct_answer_;
};

