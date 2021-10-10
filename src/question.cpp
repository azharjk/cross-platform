#include "question.hpp"

bool Question::Verify(const std::string& answer) const {
  return answer == correct_answer_;
}

std::string Question::text() const {
  return text_;
}

std::vector<std::string> Question::answers() const {
  return answers_;
}

std::string Question::correct_answer() const {
  return correct_answer_;
}
