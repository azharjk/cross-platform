#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

#include "rapidjson/include/rapidjson/document.h"

#include "question.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Too few argument\n";
    return 1;
  }

  std::vector<Question> questions;

  std::ifstream file(argv[1]);
  std::stringstream buffer;
  buffer << file.rdbuf();

  rapidjson::Document d;
  d.Parse(buffer.str().c_str());

  assert(d.IsArray());
  for (rapidjson::SizeType i = 0; i < d.Size(); i++) {
    auto object = d[i].GetObject();

    std::string text = object["text"].GetString();
    std::string correct_answer = object["correct_answer"].GetString();
    std::vector<std::string> answers;

    for (rapidjson::SizeType i = 0; i < object["answers"].Size(); i++) {
      answers.push_back(object["answers"][i].GetString());
    }

    Question temp(std::move(text), std::move(answers), std::move(correct_answer));
    questions.push_back(std::move(temp));
  }

  for (const auto& question : questions) {
    std::cout << question.text() << std::endl;
  }

  return 0;
}
