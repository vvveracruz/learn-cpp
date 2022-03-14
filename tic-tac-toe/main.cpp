// Tic Tac Toe
// Mar 22

#include <iostream>
// #include <typeinfo>

using namespace std;

// // vars
// char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// char turn = 'X';

// char choose_piece() {
//     char choice = '\0';
//     while (choice == '\0') {
//         try {
//             cout << "\tWill you play as X or O? ";
//             cin >> choice;
//             cout << "\n";

//             choice = toupper(choice);
//             if (choice != 'X' && choice != 'O') {
//                 choice = '\0';
//                 throw(choice);
//             }
//         } catch (char choice) {
//             cout << "\tThat is not a valid choice: choose one either X or
//             O.\n";
//         }
//     }
//     return choice;
// }

char human_turn(char piece) {
    char c = '\0';
    cout << "Enter a number to play or q to quit: ";
    cin >> c;
    while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' &&
           c != '6' && c != '7' && c != '8' && c != '9' && c != 'q' &&
           c != 'Q') {
        cout << "Enter a number to play or q to quit: ";
        cin >> c;
    }
    return c;
}

void display_board(char board[3][3]) {
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
    cout << "\n";
}

// // void human turn
// char human_turn(char piece) {
//     char c = '\0';
//     cout << "Enter a number to play or q to quit: ";
//     cin >> c;
//     while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' &&
//            c != '6' && c != '7' && c != '8' && c != '9' && c != 'q' &&
//            c != 'Q') {
//         cout << "Enter a number to play or q to quit: ";
//         cin >> c;
//     }
//     if (c != 'q' && c != 'Q') {
//          int i = c - '0'; // this is some stackoverflow magic
//           board[static_cast<int>(i/3)][i%3]=piece;
//     }
//     return c;
// }

// // void computer turn

// // bool game status - if gameover then stop
// bool is_gameover(char exitCode) {
//     // exit code
//     if (exitCode == 'q' or exitCode == 'Q') {
//         return true;
//     }

//     // simple rows & simple column wins
//     for (int i; i < 3; i++) {
//         if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
//             board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
//             return true;
//         }
//     }

//     // diagonal wins
//     if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
//         board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
//         return true;
//     }

//     // all spaces filled
//     for (int i; i < 3; i++) {
//         for (int j; j < 3; j++) {
//             if (board[i][j] != 'X' && board[j][i] != 'O') {
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// int main() {
//     cout << "\n";
//     cout << "\tT I C K -- T A C -- T O E\n\n";
//     char human_piece = choose_piece();

//     if (human_piece == turn) {
//         cout << "\tGood choice, you start.\n";
//     } else {
//         cout << "\tComputer starts.\n";
//     }
//     char exitCode = '\0';
//     while (not is_gameover(exitCode)) {
//         display_board();
//      //    exitCode = human_turn(human_piece);
//      exitCode='q';
//     }

//     return 0;
// }

int main() {
    char human_piece = 'X';
    char board[3][3] = {
        {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    display_board(board);
    char turn = human_turn(human_piece);
    cout << "You chose " << turn;
    return 0;
}