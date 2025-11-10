#include <string>

#define HEX 16
#define DIGITS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz+/"

/*
 * NAME
 *   convertDecimalToHex - converts decimal number to hexadecimal
 * 
 * DESCRIPTION
 *   convertDecimalToHex takes one parameter, a size_t.
 *   This function will return a string, this string will be the hexadecimal equivalent to the decimal number that was entered.
 */
std::string
convertDecimalToHex (size_t decimal);

/*
 * NAME
 *   convertDecimalToBase - converts decimal number to a number in a different base up to base64
 * 
 * DESCRIPTION
 *   convertDecimalToBase takes two parameters, a size_t, and an int.
 *   This function will return a string, this string is representative of the same decimal number that was entered in the base that was also entered.
 */
std::string
convertDecimalToBase (size_t decimal, int base);
