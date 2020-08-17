#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../vgg.cpp"

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char NO_ONE = 'N';
const char TIE = 'T';
const int SCREEN_WIDTH = 60;
const int NUM_SQUARES = 9;

void displayInstructions( int screenWidth ) {

  cout << vgg::titleTop( '=', screenWidth) << endl;
  screenWidth -= 2;

  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( "---------------", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "| TIC TAC TOE |", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "---------------", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( "INSTRUCTIONS", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( "Make your move known by entering a number", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "0-8. The number corresponds to the desired", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "board position, as illustrated:", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( "0 | 1 | 2", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "---------", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "3 | 4 | 5", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "---------", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( "6 | 7 | 8", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( "FYI: X always starts.", screenWidth ) << "|" << endl;

  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;
  cout << "|" << vgg::centerString( " ", screenWidth ) << "|" << endl;

  screenWidth += 2;
  cout << vgg::titleTop( '=', screenWidth) << endl;
}

void displayBoard( vector<char> board, int roundNumber, int screenWidth ) {

  string row1 = string(1, board[0]) + " | " + string(1, board[1]) + " | " + string(1, board[2]);
  string row2 = string(1, board[3]) + " | " + string(1, board[4]) + " | " + string(1, board[5]);
  string row3 = string(1, board[6]) + " | " + string(1, board[7]) + " | " + string(1, board[8]);
  string divider = "---------";

  string boardDisplay[5] = { row1, divider, row2, divider, row3 };

  cout << endl;
  cout << vgg::titleTop( '-' , screenWidth ) << endl;
  cout << "Round " << roundNumber << endl;

  for ( int i = 0; i < 5; i ++ ) {

    cout << vgg::centerString( boardDisplay[i], screenWidth ) << endl;

  }
  cout << endl;

}

char choosePiece( int screenWidth ) {

  char piece = EMPTY;

  cout << endl;

  while ( (piece != X) && (piece != O) ) {

    string question = "Choose your piece: X or O? ";
    cout << question;
    cin >> piece;

  }

  return piece;
}

char checkWinner( const vector<char>& board ) {

  const int WINNING_ROWS[8][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,6},
    {0,4,8},
    {2,4,6}
  };
  const int TOTAL_ROWS = 8;

  //  if any winning row has three values that are the same and not empty then we have a winner

  for (int row = 0; row < TOTAL_ROWS; row++ ){

    if ( ( board[ WINNING_ROWS[row][0] ] != EMPTY ) &&
      ( board[ WINNING_ROWS[row][0] ] ==  board[ WINNING_ROWS[row][1] ] ) &&
      ( board[ WINNING_ROWS[row][1] ] ==  board[ WINNING_ROWS[row][2] ] ) ) {

      return board[ WINNING_ROWS[row][0] ];

    } else if ( count( board.begin(), board.end(), EMPTY ) == 0 ) {

      return TIE;

    } else {

      return NO_ONE;

    }
  }
}

int main() {

  int move;
  int roundNumber = 1;
  char human;
  char computer;
  char turn = X;
  vector<char> board( NUM_SQUARES, EMPTY );


  displayInstructions( SCREEN_WIDTH );

  human = choosePiece( SCREEN_WIDTH );
  if (human == X) {
    computer = O;
  } else {
    computer = X;
  }

  displayBoard( board, roundNumber, SCREEN_WIDTH );

  while ( checkWinner( board ) == NO_ONE ) {

    roundNumber += 1;
    displayBoard( board, roundNumber, SCREEN_WIDTH );

    if ( roundNumber == 3 ) {
      break;
    }
  }

  return 0;
}
