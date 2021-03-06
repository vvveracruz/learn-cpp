//
//  A game of Hangman based on the one given in Chapter 4.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <unistd.h>
#include <fstream>

using namespace std;

const int MAX_GUESSES = 8;
const int MESSAGE_WIDTH = 50;
const int MESSAGE_BREAK = 15;

vector<string> readCSV( string filepath ) {

  ifstream fin;
  fin.open(filepath);

  vector<string> dictionary;
  string line;

  while( !fin.eof() ){

    fin >> line;
    dictionary.push_back(line);

  }

  return dictionary;
}

void centerString( string message, int messageWidth ) {

  int sides = ( messageWidth - message.length() ) / 2;
  bool evenSides = false;

  if ( ( messageWidth - message.length() ) % 2 == 0 ) {
    evenSides = true;
  }

  for ( int i = 0; i < sides; i ++) {
    cout << " ";
  }

  cout << message;

  if ( evenSides == true ) {

    for ( int i = 0; i < sides; i ++) {
      cout << " ";
    }

  } else {

    for ( int i = 0; i < sides + 1; i ++) {

      cout << " ";
      
    }
  }
}

void welcomeMessage() {

  cout << "\n";

  for ( int i = 0; i < MESSAGE_WIDTH; i++ ) {
    cout << "=";
  }
  cout << "\n";

  cout << "|";
  centerString( " ", MESSAGE_WIDTH - 2);
  cout << "|\n";

  cout << "|";
  centerString( "Welcome to Hagman.", MESSAGE_WIDTH - 2);
  cout << "|\n";

  cout << "|";
  centerString( " ", MESSAGE_WIDTH - 2);
  cout << "|\n";

  cout << "|";
  centerString( "You have " + to_string(MAX_GUESSES) + " guesses to guess the secret word.", MESSAGE_WIDTH - 2);
  cout << "|\n";

  cout << "|";
  centerString( " ", MESSAGE_WIDTH - 2);
  cout << "|\n";

  cout << "|";
  centerString( "Good luck!", MESSAGE_WIDTH - 2);
  cout << "|\n";

  cout << "|";
  centerString( " ", MESSAGE_WIDTH - 2);
  cout << "|\n";

  for ( int i = 0; i < MESSAGE_WIDTH; i++ ) {
    cout << "=";
  }
  cout << "\n";

}

void infoMessage(int guessesLeft, string lettersUsed, string guessedSoFar ) {

  cout << endl;

  centerString( " ", MESSAGE_WIDTH);
  cout << endl;
  centerString( "You have " + to_string(guessesLeft) + " guesses left.", MESSAGE_WIDTH );
  cout << endl;
  centerString( " ", MESSAGE_WIDTH );
  cout << endl;
  centerString( "Letters used:", MESSAGE_WIDTH );
  cout << endl;
  centerString( lettersUsed , MESSAGE_WIDTH );
  cout << endl;
  cout << endl;
  centerString( "Your guess so far:", MESSAGE_WIDTH );
  cout << endl;
  centerString( guessedSoFar, MESSAGE_WIDTH );

  cout << endl;

}

void messageBreak( ) {

  for ( int i = 0; i < MESSAGE_BREAK; i++ ){
    cout << endl;
  }
}

char getGuess( string lettersUsed ) {

  char guess;

  cout << endl;
  centerString( "Enter your guess: ", MESSAGE_WIDTH );
  cout << endl;
  cin >> guess;

  guess = toupper( guess );

  while ( lettersUsed.find( guess ) != string::npos ) {

    cout << endl;
    string s = "You already guessed ";
    s += guess;
    centerString( s, MESSAGE_WIDTH );
    cout << endl;

    centerString( "Enter your guess: ", MESSAGE_WIDTH );
    cout << endl;
    cin >> guess;

    guess = toupper( guess );

  }

  return guess;

}

string checkGuess( char guess, string secretWord, string guessedSoFar ) {

  if ( secretWord.find( guess ) != string::npos ) {

    cout << endl;
    string s = "Nice! ";
    s += guess;
    s += " is in the word.";
    centerString( s, MESSAGE_WIDTH );
    cout << endl;

    //  update soFar
    for ( int i = 0; i < secretWord.length(); i++ ){

      if ( secretWord[i] == guess ) {

        guessedSoFar[i] = guess;

      }
    }

  } else {

    cout << endl;
    string s = "Sorry, ";
    s += guess;
    s += " isn't in the word.";
    centerString( s, MESSAGE_WIDTH );
    cout << endl;

  }

  return guessedSoFar;
}

void endGame( int guessesLeft, string secretWord, string guessedSoFar ) {

  if ( guessesLeft == 0 && guessedSoFar != secretWord ) {

    cout << endl;
    centerString( "YOU LOST!", MESSAGE_WIDTH );
    cout << endl;
    cout << endl;
    string s = "You ran out of guesses. The word was ";
    s += secretWord;
    centerString(s, MESSAGE_WIDTH);
    cout << endl;

  } else {

    cout << endl;
    centerString( "YOU GUESSED IT! NICE.", MESSAGE_WIDTH );
    cout << endl;

  }


}

string randomiseSecretWord( vector<string> dictionary ) {

  srand( static_cast<unsigned int>( time(0) ) );
  int i = rand() % dictionary.size() + 1;

  return dictionary[i];
}

int main() {

  vector<string> dictionary = readCSV( "words.csv" );

  const string SECRET_WORD = randomiseSecretWord( dictionary );

  //  initialise variables
  int guessesLeft = MAX_GUESSES;
  string guessedSoFar( SECRET_WORD.size(), '-' );
  string lettersUsed = "";
  char guess;

  welcomeMessage();

  // main loop
  while ( guessesLeft > 0 && guessedSoFar != SECRET_WORD ) {

    infoMessage( guessesLeft, lettersUsed, guessedSoFar );
    guess = getGuess( lettersUsed );
    lettersUsed += guess;

    usleep(500000);
    messageBreak();

    guessedSoFar = checkGuess( guess, SECRET_WORD, guessedSoFar );

    guessesLeft -= 1;
  }

  messageBreak();
  endGame( guessesLeft, SECRET_WORD, guessedSoFar );
  messageBreak();

  return 0;
}
