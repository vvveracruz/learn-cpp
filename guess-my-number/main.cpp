// Guess My Number
// The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

int tries = 0;
int guess = 0;
int secretNumber = 0;
bool humanGuessing = true;

bool chooseGameType() {

  string player;

  cout << "Enter player: " << endl;
  cin >> player;

  if ( player == "computer") {
    humanGuessing = false;
  } else {
    humanGuessing = true;
  }

  return humanGuessing;

}

int getSecretNumber() {

  if ( humanGuessing ) {

    srand(static_cast<unsigned int>(time(0)));  //seed random number generator
  	secretNumber = rand() % 100 + 1;  // random number between 1 and 100

  } else {

    cout << "Enter a number for the computer to guess from 1 to 100: " << endl;
    cin >> secretNumber;

  }

  return secretNumber;

}

int getGuess() {

  if ( humanGuessing ) {

    cout << "Enter a guess: ";
    cin >> guess;

  } else {

    sleep(2);
  	guess = rand() % 100 + 1;
    cout << guess << endl;

  }

  return guess;

}

int main() {

  cout << "\tWelcome to Guess My Number\n\n";

  humanGuessing = chooseGameType();

  secretNumber = getSecretNumber();

	while (guess != secretNumber) {

    guess = getGuess();
		++tries;

		if (guess > secretNumber) {

			cout << "Too high!\n\n";

		} else if (guess < secretNumber) {

			cout << "Too low!\n\n";

		} else {

			cout << "\nThat's it! You got it in " << tries << " guesses!\n";

		}
	}

  return 0;
}
