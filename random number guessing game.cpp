// random number guessing game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File Name: Random Number Guessing Game
Programmer: Olivia Ruiz
Date: 4/10/25
Requirements: Make a program that generates a random number and when the number is guessed
to high display "To high, try again" and when the number is guessed to low display
"Too low, try again."
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
   
    srand(static_cast<unsigned int>(time(0)));

   
    int secretNumber = rand() % 100 + 1;
    int guess;

    cout << "Guess the number (between 1 and 100): ";

    
    do {
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high, try again: ";
        }
        else if (guess < secretNumber) {
            cout << "Too low, try again: ";
        }
        else {
            cout << "Congratulations! You guessed the number!" << endl;
        }

    } while (guess != secretNumber);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
