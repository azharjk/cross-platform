#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "question.hpp"

int GetReadableScore(int score, std::size_t size) {
  return (static_cast<double>(score) / static_cast<double>(size)) * 100;
}

int main() {
  const bool shuffle = true;

  std::vector<Question> questions = {
    Question("What is your name?", std::vector<std::string>{"Mike", "Rock", "Sam"}, "Sam"),
    Question("How old are you?", std::vector<std::string>{"10", "11", "12"}, "10"),
    Question("What do you do for a living", std::vector<std::string>{"Cooking", "Benching", "Gambling"}, "Gambling"),
  };

  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(static_cast<unsigned int>(seed));

  // shuffle the questions
  if (shuffle) {
    std::shuffle(questions.begin(), questions.end(), rng);
  }

  char answer_indicator = 'a';
  int total_score = 0;

  std::string client_answer;
  std::vector<std::string> copy_answers;

  for (const auto& question : questions) {
    copy_answers = question.answers();
    // shuffle the answers
    if (shuffle) {
      std::shuffle(copy_answers.begin(), copy_answers.end(), rng);
    }

    std::cout << question.text() << std::endl;
    for (const auto& answer : copy_answers) {
      std::cout << "(" << answer_indicator++ << ") " << answer << std::endl;
    }
    answer_indicator = 'a';

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
    if (question.Verify(copy_answers[answer_index])) {
      total_score += 1;
    }

    std::cout << "-----------------------------------\n";
  }

  std::cout << "Total Score: " << GetReadableScore(total_score, questions.size()) << std::endl;

  return 0;
}
