#include "flashcards.hpp"

int
main()
{
  static std::string questions[MAX_QUESTIONS];
  static std::string answers[MAX_QUESTIONS];

  static size_t questionCount = scanTextFile(questions, "questions.txt") - 1;
  scanTextFile(answers, "answers.txt");

  askQuestions(questions, answers, questionCount);

  return EXIT_SUCCESS;
}
