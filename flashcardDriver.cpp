/************************************************************/
// System includes
#include <cstdlib>

/************************************************************/
// Local Inludes
#include "flashcards.hpp"

/************************************************************/

int
main ()
{
  askQuestions (scanTextFile ("questions.txt"), scanTextFile ("answers.txt"));

  return EXIT_SUCCESS;
}
