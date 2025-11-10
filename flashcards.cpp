////////////////
////INCLUDES////
////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <stack>
#include "generations.hpp"

/////////////
////USING////
/////////////

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::time;
using std::srand;
using std::rand;
using std::vector;
using std::ifstream;

/////////////////
////CONSTANTS////
/////////////////

const int MAX_QUESTIONS = 1024;
string generators[MAX_QUESTIONS];

///////////////
////GLOBALS////
///////////////

size_t questionCount = 0;

///////////////
////HEADERS////
///////////////

/* 
 * NAME 
 *   scanTextFile - insert each line of a text file into an array of strings
 *
 * DESCRIPTION
 *   scanTextFile takes two parameters, an array of strings, and a string for the file.
 *   This array of strings will be where each line of the text file will be inserted into.
 *   The file string is the path within the working directory where the text file will be located.
 *   This function returns an integer, which is how many lines were scanned;
 */
int
scanTextFile(string arrOut[MAX_QUESTIONS], string file);

/*
 * NAME
 *   initBools - initialize an array of booleans to value
 *
 * DESCRIPTION
 *   initBools takes one parameter, a boolean value.
 *   This function will return an array of booleans that is initialized to all be the same value as value.
 */
bool*
initBools(bool value);

/*
 * NAME
 *   askQuestions - ask questions
 *
 * DESCRIPTION
 *   ask questions :>
 *   Not sure why I felt the need to turn this into a seperate function but here we are.
 */
void
askQuestions(const string* questions, const string* answers);

/*
 * NAME
 *   chooseIndex - chooses random unchosen number
 *
 * DESCRIPTION
 *   chooseIndex takes one parameter, an array of booleans.
 *   This function will return an integer, this integer will be chosen at random as is guarenteed to not have been chosen since the beginning of the askQuestions function.
 */
int
chooseIndex(const bool* chosen);

/*
 * NAME
 *   scanGenerator - scans through the generators for keywords
 *
 * DESCRIPTION
 *   scanGenerator takes three parameters, an int, a string, and an int
 *   The first int is used to grab the index of the keyword in the string array and will overwrite whatever value was passed in for that index.
 *   The string is the potential keyword.
 *   The second int is the about of generators there are, is used for better optimization when scanning through the generators array.
 *   This function will return a bool, true if a match was found, false if a match wasn't found.
 */
bool
scanGenerator (int& i, const string& generate, int genCount);

/*
 * NAME
 *   generateQuestion - generates question using value from generators as template to create a question
 * 
 * DESCRIPTION
 *   generateQuestion takes one parameter, an int, and a string.
 *   The int is the index in generators that contains the template of the question
 *   The string is the answer to the question that was generated, and will overwrite whatever value was passed in for the answer.
 *   This function will return a string, which is the question that will be displayed to the user.
 */
string
generateQuestion (int index, const string& generate);

/////////////////
////FUNCTIONS////
/////////////////

int
main()
{
  static string questions[MAX_QUESTIONS];
  static string answers[MAX_QUESTIONS];

  questionCount = scanTextFile(questions, "questions.txt") - 1;
  scanTextFile(answers, "answers.txt");

  askQuestions(questions, answers);

  return EXIT_SUCCESS;
}

int
scanTextFile(string arrOut[MAX_QUESTIONS], string file)
{
  int lineCount = 0;
  ifstream fileIn(file);

  if (fileIn.is_open())
  {
    string line;

    for (int i = 0; !fileIn.fail() || i >= MAX_QUESTIONS; ++i, ++lineCount)
      getline(fileIn, arrOut[i]);

    fileIn.close();
  }
  else
    cout << file << " isn't open" << endl;
  return lineCount;
}

bool*
initBools(bool value)
{
  static bool arrOut[MAX_QUESTIONS];

  for (int i = 0; i < MAX_QUESTIONS; ++i)
    arrOut[i] = value;

  return arrOut;
}
  
void
askQuestions(const string* questions, const string* answers)
{
  bool* answered = initBools(false);
  string question, answer;
  //int generatorIndex, generatorCount;

  // TODO
  // Add feature that creates problems for you
  // e.g. B2U (random number)
  // Will probably be done by making this array of strings one that will be scanned to determine keyword like "B2U" from the question, and then generating a random B2U problem
  //generatorCount = scanTextFile(generators, "generators.txt") - 1;

  // Set "seed" for random questions
  srand(time(0));

  int randomQuestion;
  for (size_t questionsAnswered = 0; questionsAnswered < questionCount; ++questionsAnswered)
  {
    randomQuestion = chooseIndex(answered);

    //if (scanGenerator(generatorIndex, questions[randomQuestion], generatorCount))
    //  question = generateQuestion(generatorIndex, answer);

    //else
      question = questions[randomQuestion];

    // Ask question
    cout << questionsAnswered + 1 << ". " << question;

    // Wait user enter
    // TODO Add some feature to keep track of number of correct and wrong answers
    cin.get();

    // Print answer
    cout << answers[randomQuestion] << endl;

    // Set question to answered
    answered[randomQuestion] = true;
    cout << endl;
  }
}

int
chooseIndex(const bool* chosen)
{
  int randomIndex;

  do
  {
    randomIndex = rand() % questionCount;
  } while (chosen[randomIndex]);

  return randomIndex;
}

bool
scanGenerator (int& i, const string& generate, int genCount)
{
  for (i = 0; i < genCount; ++i)
    if (generators[i] == generate)
      return true;
  return false;
}

string
generateQuestion (int index, string& answer) 
{
  return "Hello World!";
}
