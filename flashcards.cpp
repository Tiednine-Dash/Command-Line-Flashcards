/************************************************************/
// System includes
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <print>
#include <string>

/************************************************************/
// Local Includes
#include "flashcards.hpp"

/************************************************************/
// Using declarations
using std::cin;
using std::ifstream;
using std::print;
using std::println;
using std::rand;
using std::srand;
using std::string;
using std::time;

/************************************************************/
// Function prototypes / global vars / type definitions
int
scanTextFile (string arrOut[MAX_QUESTIONS], string file)
{
  int lineCount = 0;
  ifstream fileIn (file);

  if (fileIn.is_open ())
  {
    string line;

    for (int i = 0; !fileIn.fail () || i >= MAX_QUESTIONS; ++i, ++lineCount)
      getline (fileIn, arrOut[i]);

    fileIn.close ();
  }
  else
    println (stderr, "{} isn't open", file);

  return lineCount;
}

bool*
initBools (bool value)
{
  static bool arrOut[MAX_QUESTIONS];

  for (int i = 0; i < MAX_QUESTIONS; ++i)
    arrOut[i] = value;

  return arrOut;
}

void
askQuestions (const string* questions,
              const string* answers,
              size_t questionCount)
{
  bool* answered = initBools (false);
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

  int randomQuestion;
  for (size_t questionsAnswered = 0; questionsAnswered < questionCount;
       ++questionsAnswered)
  {
    randomQuestion = chooseIndex (answered, questionCount);

    // if (scanGenerator(generatorIndex, questions[randomQuestion],
    // generatorCount))
    //   question = generateQuestion(generatorIndex, answer);

    // else
    question = questions[randomQuestion];

    // Ask question
    print ("{}. {}", questionsAnswered + 1, question);

    // Wait user enter
    // TODO Add some feature to keep track of number of correct and wrong
    // answers
    cin.get ();

    // Print answer
    println ("{}", answers[randomQuestion]);

    // Set question to answered
    answered[randomQuestion] = true;
    println ();
  }
}

int
chooseIndex (const bool* chosen, size_t questionCount)
{
  int randomIndex;

  do
  {
    randomIndex = rand () % questionCount;
  } while (chosen[randomIndex]);

  return randomIndex;
}

bool
scanGenerator (const string* generators,
               int& i,
               const string& generate,
               int genCount)
{
  for (i = 0; i < genCount; ++i)
    if (generators[i] == generate)
      return true;
  return false;
}

string
generateQuestion (int index, string& answer)
{
  // TODO
  return "Hello World!";
}
