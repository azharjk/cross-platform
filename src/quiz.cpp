#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

struct Question {
  std::string text;
  std::vector<std::string> answers;
  std::string correct_answer;
};

int main() {
  Question q1;
  q1.text = "How old are you?";
  q1.answers.push_back("10");
  q1.answers.push_back("11");
  q1.answers.push_back("12");
  q1.correct_answer = "10";

  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(seed);
  std::shuffle(q1.answers.begin(), q1.answers.end(), rng);

  char answer_indicator = 'a';
  std::string client_answer;

  std::cout << q1.text << std::endl;
  for (auto& answer : q1.answers) {
    std::cout << "(" << answer_indicator++ << ") " << answer << std::endl;
  }

  do {
    std::cout << "Answer: ";
    std::getline(std::cin, client_answer);
    if (!client_answer.empty()) {
      if (client_answer.size() != 1) {
        std::cout << "Please enter either a, b, or c\n";
        client_answer.clear();
      } else if (client_answer[0] == 'a'
                 || client_answer[0] == 'b'
                 || client_answer[0] == 'c') {
        break;
      }
    }
  } while (client_answer.empty());

  std::size_t answer_index = client_answer[0] - 97;
  assert(answer_index < q1.answers.size());
  char chosen_answer_indicator = 'a' + answer_index;
  if (q1.answers[answer_index] == q1.correct_answer) {
    std::cout << "Your answer " << chosen_answer_indicator << " is correct\n";
  } else {
    std::cout << "Your answer " << chosen_answer_indicator << " is not correct\n";
  }

  return 0;
}
