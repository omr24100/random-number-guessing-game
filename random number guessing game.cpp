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
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\n----- NUMBER GUESSING GAME MENU -----" << endl;
    cout << "1. Display Existing Sessions" << endl;
    cout << "2. Play a New Session" << endl;
    cout << "3. Delete Previous Sessions" << endl;
    cout << "4. Exit the Program" << endl;
    cout << "Choose an option (1-4): ";
}

void displaySessions() {
    ifstream inFile("sessions.txt");
    if (!inFile) {
        cout << "\nNo session history found." << endl;
        return;
    }

    string line;
    cout << "\n--- Previous Sessions ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void playNewSession() {
    string playerName;
    cout << "\nEnter your name: ";
    cin.ignore(); // Clear newline from previous input
    getline(cin, playerName);

    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "\nHi " << playerName << "! Let's play. Guess the number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high, try again!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low, try again!" << endl;
        } else {
            cout << " Well done, " << playerName << "! You guessed the number in " << attempts << " attempt(s)!" << endl;

            // Log to file
            ofstream outFile("sessions.txt", ios::app);
            outFile << "Player: " << playerName << " | Attempts: " << attempts << endl;
            outFile.close();
        }

    } while (guess != secretNumber);
}

void deleteSessions() {
    ofstream outFile("sessions.txt", ios::trunc); // Clears the file
    outFile.close();
    cout << "\nAll previous sessions have been deleted." << endl;
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displaySessions();
                break;
            case 2:
                playNewSession();
                break;
            case 3:
                deleteSessions();
                break;
            case 4:
                cout << "\nExiting program. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please choose 1-4." << endl;
        }

    } while (choice != 4);

    return 0;
}

