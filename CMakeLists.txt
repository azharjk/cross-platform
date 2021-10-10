cmake_minimum_required(VERSION 3.0)
project(QuizApp)

set(QUIZ_DEPS src/question.cpp)

add_executable(quiz src/quiz.cpp ${QUIZ_DEPS})
add_executable(quiz-read src/quiz_read.cpp ${QUIZ_DEPS})

target_include_directories(quiz-read PRIVATE third_party)
