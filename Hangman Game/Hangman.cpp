#include "Hangman.h"
#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
//#include <cstdlib>
//# include<iostream.h>
#include <string>
#include <algorithm>
//#include <ctime>
using std::string;
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool contains (string array[], string guess, int wordLength){
    for (int i = 0; i < wordLength; i++){
        if (array[i] == guess){
            return true;
        }
    }
    return false;
}

int main(){
	string list[] = {"Stanley", "Emily", "Karen","Austin"};
	string word = list[rand() % (sizeof(list)/sizeof(list[0]))];

	//TODO: Pick a random word from list
	//srand((int)time(0));
	//string word = list[rand() % sizeof(list)];

	string wordArray[word.length()];
	for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
		wordArray[i] = word.at(i);
	}

	string displayArray[word.length()];
	for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
		displayArray[i] = "_";
	}

	int wordLength = word.length();
	int correctGuessIterator = 0;
	int wrongGuessIterator = 0;

	int numOfGuessesLeft = 5;
	int maxNumOfWrongGuesses = 5;
	int numOfCorrectGuesses = 0;
	bool gameOver = false;
	bool youWin = false;

	string correctGuessArray[word.length()];
	string wrongGuessArray[maxNumOfWrongGuesses];
	string wordAllLowerArray[word.length()];

	//DIALOGUE
	std::cout << "SAW:" << endl;
	std::cout << "Hello, I want to play a game." << endl;
	std::cout << "The game is simple." << endl;
	std::cout << "Guess all the correct letters in the word." << endl;
	std::cout << "But be careful, make " << maxNumOfWrongGuesses << " incorrect guesses... and you hang to your death." << endl;
	std::cout << "Live or die, make your choice." << endl;
	std::cout << "Let the games begin." << endl;
	std::cout << "__________________________________________________________________________________________________________________________________________________________" <<endl;
	std::cout << endl;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	while ((gameOver == false) && (youWin == false)){
		std::cout << "     ";
		for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
			std::cout << displayArray[i] + " ";
		}

		std::cout << endl;
		std::cout << endl;

		string guess;
		cout << "Guess a letter: " << endl;
		cin >> guess;
		//guess = "q";

		// TODO: Allow user to guess entire word
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		/*
		TODO:
		lowercase all the words, limit to only one character, and no special characters
		guess = guess.toLower();
		 */
		if ((word.find(guess) != std::string::npos) && (contains(correctGuessArray, guess, wordLength) == false)){ //if guess is correct and not already guessed
			for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
				if (wordArray[i] == guess){
					displayArray[i] = wordArray[i];
					numOfCorrectGuesses++;
					correctGuessArray[correctGuessIterator] = guess;
					correctGuessIterator++;
				}
			}
			std::cout << endl;
		}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		else if ((word.find(guess) == std::string::npos) && (contains(wrongGuessArray, guess, wordLength) == false)){ //if guess is wrong and not already guessed
			wrongGuessArray[wrongGuessIterator] = guess;
			wrongGuessIterator++;
			numOfGuessesLeft--;
			std::cout << endl;
		}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if (numOfGuessesLeft == 0){
			std::cout << "GAME OVER, HAHAHAHAHAHAHA.";
			gameOver = true;
		}
		else{
			std::cout << "Wrong guesses: ";

			for (int i = 0; i < maxNumOfWrongGuesses; i++){
				std::cout << wrongGuessArray[i] << " ";
			}
			std::cout << endl;
			std::cout << endl;
			if ((numOfCorrectGuesses != wordLength) && (numOfGuessesLeft > 1)){
				std::cout << "You have " << numOfGuessesLeft << " guesses left." << std::endl;
				std::cout << endl;
			}
			if ((numOfCorrectGuesses != wordLength) && (numOfGuessesLeft == 1)){
				std::cout << "You have " << numOfGuessesLeft << " guess left." << std::endl;
				std::cout << endl;
			}
		}
		if (contains(displayArray,"_", wordLength) == false){
			youWin = true;
		}
	} //End of while loop
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (youWin == true){
		std::cout << endl;
		std::cout << endl;
		for (int i = 0; i < wordLength; i++){
			std::cout << displayArray[i] + " ";
		}
		std::cout << endl;
		std::cout << endl;
		std::cout << "You made it, congratulations." << endl;
		std::cout << "The next room awaits you." << endl;
		return 0;
	}
	//TODO: Include would you like to play again? "Yes" or "No"?
}
