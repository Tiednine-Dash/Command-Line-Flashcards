# Command Line Flashcards
Very simple program to simulate the use of flashcards within the command line.

# How to build
Compile the program with your favorite C++ compiler or make

# How to use
Type your question entries in a file named "questions.txt" seperated by newlines in the same directory.
Type your answer entries in a file named "answers.txt" seperated by newlines, also in the same directory.
./flashcardDriver will read a random line from "questions.txt", and will wait for you to hit ENTER before giving you answer from the same line in "answers.txt"

# Known issues
Undefined behaviour if "questions.txt" and/or "answers.txt" are not found.
Program terminates with "questions.txt" and "answers.txt" are empty.
No ability to generate random questions for user, yet.
If characters other than ENTER are typed before hitting enter, questions will be skipped.
There is no indication on number of "flashcards" left or in total.
