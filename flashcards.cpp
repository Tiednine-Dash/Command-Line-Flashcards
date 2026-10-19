/************************************************************/
// System includes
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <vector>

/************************************************************/
// Local Includes
#include "flashcards.hpp"

/************************************************************/
// Using declarations
using std::print;
using std::println;
using std::string;
using std::vector;

/************************************************************/
// Function prototypes / global vars / type definitions
vector<string>
scanTextFile (string path)
{
  std::ifstream file (path);

  if (!file.is_open ())
  {
    println (stderr, "{} isn't open", path);
    return {};
  }

  const long lineCount { std::count (
    std::istreambuf_iterator<char> (file), {}, '\n') };

  file.clear ();
  file.seekg (0);

  vector<string> lines;
  lines.reserve (lineCount);

  for (string s; std::getline (file, s);)
    lines.push_back (std::move (s));

  return lines;
}

void
askQuestions (const vector<string>& questions, const vector<string>& answers)
{
  size_t questionCount = questions.size ();
  vector<bool> answered (questionCount, false);
  string question, answer;

  // size_t generatorIndex, generatorCount;

  // TODO
  // Add feature that creates problems for you
  // e.g. B2U (random number)
  // Will probably be done by making this array of strings one that will be
  // scanned to determine keyword like "B2U" from the question, and then
  // generating a random B2U problem
  // static string generators[MAX_QUESTIONS];
  // generatorCount = scanTextFile(generators, "generators.txt") - 1;

  // Set "seed" for random questions
  srand (time (0));

  for (size_t questionsAnswered { 0 }; questionsAnswered < questionCount;
       ++questionsAnswered)
  {
    int randomQuestion { chooseIndex (answered, questionCount) };

    // if (scanGenerator(generatorIndex, questions[randomQuestion],
    // generatorCount))
    //   question = generateQuestion(generatorIndex, answer);

    // else
    question = questions[randomQuestion];

    // Ask question
    print ("{}/{}. {}", questionsAnswered + 1, questionCount, question);

    // Wait user enter
    // TODO Add some feature to keep track of number of correct and wrong
    // answers
    std::cin.get ();

    // Print answer
    println ("{}", answers[randomQuestion]);

    // Set question to answered
    answered[randomQuestion] = true;
    println ();
  }
}

int
chooseIndex (const std::vector<bool>& chosen, size_t questionCount)
{
  int randomIndex;

  do
  {
    randomIndex = rand () % questionCount;
  } while (chosen[randomIndex]);

  return randomIndex;
}

// bool
// scanGenerator (const string* generators,
//                int& i,
//                const string& generate,
//                int genCount)
// {
//   for (i = 0; i < genCount; ++i)
//     if (generators[i] == generate)
//       return true;
//   return false;
// }
//
// string
// generateQuestion (int index, string& answer)
// {
//   // TODO
//   return "Hello World!";
// }
