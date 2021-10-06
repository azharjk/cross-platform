#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

class Question {
  public:
    Question(const std::string& text,
             const std::vector<std::string>& answers_,
             const std::string& correct_answer) :
             text_(text), answers_(answers_),
             correct_answer_(correct_answer) {}

  bool Verify(const std::string& answer) const {
    return answer == correct_answer_;
  }

  std::string text() const {
    return text_;
  }

  std::vector<std::string> answers() const {
    return answers_;
  }

  std::string correct_answer() const {
    return correct_answer_;
  }

  private:
    std::string text_;
    std::vector<std::string> answers_;
    std::string correct_answer_;
};

int main() {
  Question q1("How old are you", std::vector<std::string>{"10", "11", "12"}, "10");
  auto copy_answers = q1.answers();

  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(static_cast<unsigned int>(seed));
  std::shuffle(copy_answers.begin(), copy_answers.end(), rng);

  char answer_indicator = 'a';
  std::string client_answer;

  std::cout << q1.text() << std::endl;
  for (auto& answer : copy_answers) {
    std::cout << "(" << answer_indicator++ << ") " << answer << std::endl;
  }

  do {
    std::cout << "Answer: ";
    std::getline(std::cin, client_answer);
    if (!client_answer.empty()) {
      if (client_answer.size() == 1) {
        if (client_answer[0] == 'a' ||
            client_answer[0] == 'b' ||
            client_answer[0] == 'c') {
          break;
        }
      }
      std::cout << "Please enter either a, b, or c\n";
      client_answer.clear();
    }
  } while (client_answer.empty());

  char answer_index = client_answer[0] - 'a';
  assert(answer_index < copy_answers.size());
  char chosen_answer_indicator = 'a' + static_cast<char>(answer_index);
  if (q1.Verify(copy_answers[answer_index])) {
    std::cout << "Your answer " << chosen_answer_indicator << " is correct\n";
  } else {
    std::cout << "Your answer " << chosen_answer_indicator << " is not correct\n";
  }

  return 0;
}
