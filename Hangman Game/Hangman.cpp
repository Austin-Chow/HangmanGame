#include "Hangman.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
//#include <ctime>
//#include <cstdlib>

using std::string;
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool contains (string array[], string guess, int wordLength){ //contains() method to check whether an array has a certain letter
    for (int i = 0; i < wordLength; i++){
        if (array[i] == guess){
            return true;
        }
    }
    return false;
}

int main(){
	string list[] = {"Stanley", "Emily", "Karen","Austin"}; //list of words
	string word = list[rand() % (sizeof(list)/sizeof(list[0]))]; //Chose a random word from the list

	//TODO: Pick a random word from list
	//srand((int)time(0));
	//string word = list[rand() % sizeof(list)];

	string wordArray[word.length()]; //The array that contains the word and displays the letter when user guesses correctly
	for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
		wordArray[i] = word.at(i);
	}

	string displayArray[word.length()]; //The array that substitutes each letter in the word with "_" until the user has guessed correctly
	for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
		displayArray[i] = "_";
	}

	int wordLength = word.length();
	int correctGuessIterator = 0; //iterates through the array that contains all the correct letters
	int wrongGuessIterator = 0; //iterates through the array that contains all the incorrect letters

	int numOfGuessesLeft = 5; //number of incorrect guesses left the user is allowed to make
	int maxNumOfWrongGuesses = 5; //number of incorrect guesses the user is allowed to make in the game
	int numOfCorrectGuesses = 0; //to keep track of when the user wins the game
	bool gameOver = false; //game Over
	bool youWin = false; //user wins game

	string correctGuessArray[word.length()]; //array that contains all the correct guesses
	string wrongGuessArray[maxNumOfWrongGuesses]; //array that contains all the incorrect guesses
	//string wordAllLowerArray[word.length()]; //array that allows the user to guess uppercase letters in the word using lowercase letters

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
	while ((gameOver == false) && (youWin == false)){ //while the game is not over
		std::cout << "     ";
		for (unsigned int i = 0; i < static_cast<unsigned int>(word.length()); i++){
			std::cout << displayArray[i] + " ";
		}

		std::cout << endl;
		std::cout << endl;

		string guess; //user input
		cout << "Guess a letter: " << endl;
		cin >> guess;
		//guess = "q";

		// TODO: Allow user to guess entire word or phrases
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
		else if ((word.find(guess) == std::string::npos) && (contains(wrongGuessArray, guess, wordLength) == false)){ //if guess is incorrect and not already guessed
			wrongGuessArray[wrongGuessIterator] = guess;
			wrongGuessIterator++;
			numOfGuessesLeft--;
			std::cout << endl;
		}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if (numOfGuessesLeft == 0){	//if user has 0 guesses left
			std::cout << "GAME OVER, HAHAHAHAHAHAHA.";
			gameOver = true;
		}
		else{ //if user has more than 0 guesses left
			std::cout << "Wrong guesses: ";	//displays any incorrect guesses user has made

			for (int i = 0; i < maxNumOfWrongGuesses; i++){
				std::cout << wrongGuessArray[i] << " ";
			}

			std::cout << endl;
			std::cout << endl;

			if ((numOfCorrectGuesses != wordLength) && (numOfGuessesLeft > 1)){ //Grammatical - more than 1 guess left
				std::cout << "You have " << numOfGuessesLeft << " guesses left." << std::endl;
				std::cout << endl;
			}
			if ((numOfCorrectGuesses != wordLength) && (numOfGuessesLeft == 1)){ //Grammatical - 1 guess left
				std::cout << "You have " << numOfGuessesLeft << " guess left." << std::endl;
				std::cout << endl;
			}
		}
		if (contains(displayArray,"_", wordLength) == false){ //if the displayArray does not contain any "_", user wins the game
			youWin = true;
		}
	} //End of while loop
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (youWin == true){ //if user wins game, display the word and congratulatory message
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
	//TODO: Implement would you like to play again? "Yes" or "No"?
}
