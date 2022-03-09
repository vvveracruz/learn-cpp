// Tic Tac Toe
// Mar 22

#include <iostream>
// #include <typeinfo>

using namespace std;

// vars
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';

char choose_piece() {
    char choice = '\0';
    while (choice == '\0') {
        try {
            cout << "\tWill you play as X or O? ";
            cin >> choice;
            cout << "\n";

            choice = toupper(choice);
            if (choice != 'X' && choice != 'O') {
                choice = '\0';
                throw(choice);
            }
        } catch (char choice) {
            cout << "\tThat is not a valid choice: choose one either X or O.\n";
        }
    }
    return choice;
}

void display_board() {
    cout << "\n";
    cout << "\t    "
         << "     |     |     \n";
    cout << "\t    "
         << "  " << board[0][0] << "  |  " << board[0][1] << "  |  "
         << board[0][2] << " \n";
    cout << "\t    "
         << "     |     |     \n";
    cout << "\t    "
         << "-----|-----|-----\n";
    cout << "\t    "
         << "     |     |     \n";
    cout << "\t    "
         << "  " << board[1][0] << "  |  " << board[1][1] << "  |  "
         << board[1][2] << " \n";
    cout << "\t    "
         << "     |     |     \n";
    cout << "\t    "
         << "-----|-----|-----\n";
    cout << "\t    "
         << "     |     |     \n";
    cout << "\t    "
         << "  " << board[2][0] << "  |  " << board[2][1] << "  |  "
         << board[2][2] << " \n";
    cout << "\t    "
         << "     |     |     \n";
}

// void human turn

// void computer turn

// bool game status - if gameover then stop

int main() {
    cout << "\n";
    cout << "\tT I C K -- T A C -- T O E\n\n";
    char piece = choose_piece();

    if (piece == turn) {
        cout << "\tGood choice, you start.\n";
    } else {
        cout << "\tComputer starts.\n";
    }

    display_board();

    cout << "\n";
    return 0;
}