# Luhn's Algorithm
## Project: Introduction to C

## Project Overview
Credit cards use a system of blocked numbers similar to the ISBN. The first digit of a credit card number is the Major Industry Identifier (MII) and identifies which group issued the card. The next block of numbers is the issue identifier. Including the MII, the Issue Identifier is 6 digits long. The account number begins with the 7th digit and ends with the next-to-last digit. The final digit is the check digit. The process used to calculate the check digit is the Luhn algorithm1 (mod 10 algorithm), named after IBM scientist Hans Peter Luhn. The algorithm is in the public domain and is used to validate Canadian social insurance numbers. It is designed to protect against accidental errors, such as single transpositions of adjacent digits although it won’t detect transposition of two-digit sequences. This algorithm works as follows:

- Double all even-positioned digits when counting from right to left.
- Determine the sum of the undoubled digits from the products (Step 1) and each of the unaffected (odd-positioned) digits in the original number.
- Verify the account number by determining if the sum from step 2 is a multiple of 10.

To be a valid account number, this sum must be evenly divisible by 10. If the check digit were 7, the result would be congruent to (0 mod 10); but because the check digit is 2, the sum is not divisible by 10. Therefore, this account number is not valid.

## Description
Using the information given, write a program that takes a 16-digit credit card number as input, computes the checksum, and interprets whether the credit card number is valid or not. Create the following three functions (apart from the main function) in your program: 

- readCC Read in the 16-digit credit card number, and return it to main. The number should be read in as a string and converted to be stored in an integer array, which is returned from the function. The function should also validate that the ISBN entered has the correct number of digits before proceeding with checking its validity. If it does not have the correct number of digits, provide an appropriate error message and exit the program. 
- isValid Take the credit card number as input, and check its validity, outputting an appropriate message to the user. This function calls the function runLuhn, which returns a checksum. If the value returned is zero, the number is valid, if non zero, it is not valid. 
- runLuhn Take the credit card number as input and calculate the checksum using Luhn’s algorithm, returning its value (i.e. the remainder obtained when the sum value calculated is divided by 10).

The main function should run the function readCC, followed by the function isValid. The input for the function read_CC is: XXXXXXXXXXXXXXXX where the X represents a digit in the number. Your program can assume numbers with 16 digits. 

Your program should use the following three programming structures: 
- functions 
- strings and arrays 
- pass-by-reference