#include <iostream>
#include <vector>
#include <cassert>
#include <string>

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

  assert(client_answer.size() == 1);

  std::size_t answer_index = client_answer[0] - 97;
  if (q1.answers[answer_index] == q1.correct_answer) {
    std::cout << "Your answer " << static_cast<char>('a' + answer_index) << " is correct\n";
  } else {
    std::cout << "Your answer " << static_cast<char>('a' + answer_index) << " is not correct\n";
  }

  return 0;
}
