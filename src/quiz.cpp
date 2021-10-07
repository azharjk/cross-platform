#include <iostream>
#include <vector>

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
  std::cout << "Answer: ";
  std::cin >> client_answer;

  std::size_t answer_index = client_answer[0] - 97;
  if (q1.answers[answer_index] == q1.correct_answer) {
    std::cout << "Your answer " << static_cast<char>('a' + answer_index) << " is correct\n";
  } else {
    std::cout << "Your answer " << static_cast<char>('a' + answer_index) << " is not correct\n";
  }

  return 0;
}
