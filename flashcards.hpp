/************************************************************/
// System includes
#include <string>
#include <vector>

/************************************************************/
// Function prototypes / global vars / type definitions
#include "generations.hpp"

/************************************************************/
// Function prototypes / global vars / type definitions

/*
 * NAME
 *   scanTextFile - insert each line of a text file into an array of strings
 *
 * DESCRIPTION
 *   scanTextFile takes two parameters, an array of strings, and a string for
 * the file. This array of strings will be where each line of the text file will
 * be inserted into. The file string is the path within the working directory
 * where the text file will be located. This function returns an integer, which
 * is how many lines were scanned;
 */
std::vector<std::string>
scanTextFile (std::string path);

/*
 * NAME
 *   askQuestions - ask questions
 *
 * DESCRIPTION
 *   ask questions :>
 *   Not sure why I felt the need to turn this into a seperate function but here
 * we are.
 */
void
askQuestions (const std::vector<std::string>& questions,
              const std::vector<std::string>& answers);

/*
 * NAME
 *   chooseIndex - chooses random unchosen number
 *
 * DESCRIPTION
 *   chooseIndex takes one parameter, an array of booleans.
 *   This function will return an integer, this integer will be chosen at random
 * as is guarenteed to not have been chosen since the beginning of the
 * askQuestions function.
 */
int
chooseIndex (const std::vector<bool>& chosen, size_t questionCount);

/*
 * NAME
 *   scanGenerator - scans through the generators for keywords
 *
 * DESCRIPTION
 *   scanGenerator takes three parameters, an int, a string, and an int
 *   The first int is used to grab the index of the keyword in the string array
 * and will overwrite whatever value was passed in for that index. The string is
 * the potential keyword. The second int is the about of generators there are,
 * is used for better optimization when scanning through the generators array.
 *   This function will return a bool, true if a match was found, false if a
 * match wasn't found.
 */
// bool
// scanGenerator (const std::string* generators,
//                int& i,
//                const std::string& generate,
//                int genCount);

/*
 * NAME
 *   generateQuestion - generates question using value from generators as
 * template to create a question
 *
 * DESCRIPTION
 *   generateQuestion takes one parameter, an int, and a string.
 *   The int is the index in generators that contains the template of the
 * question The string is the answer to the question that was generated, and
 * will overwrite whatever value was passed in for the answer. This function
 * will return a string, which is the question that will be displayed to the
 * user.
 */
// std::string
// generateQuestion (int index, const std::string& generate);
