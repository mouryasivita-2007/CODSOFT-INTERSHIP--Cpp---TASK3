THIS IS THE TIC -TAC -TOE MADE BY ME WHICH TAKE ASSIGN TWO PLAYER X AND O AND ALSO TELLS WHOS THE WINNER WITH HAVING A 3*3 BOARD AND ALSO AT THE LAST PROPMT DO WANNA PLAY AGAIN IS GIVEN 

#include <iostream>
using namespace std;

char board[3][3];
int currentPlayer;
char currentMarker;

void resetBoard() {
    char c = '1';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = c++;
}

void drawBoard() {
    cout << "\n   TIC TAC TOE - BY Sivita Mourya \n";
    cout << "   " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "  ---|---|---\n";
    cout << "   " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "  ---|---|---\n";
    cout << "   " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWinner() {
    // Rows
    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;

    // Columns
    for(int i=0; i<3; i++)
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void game() {
playAgain:
    resetBoard();
    drawBoard();

    cout << "Player 1 choose your marker (X/O): ";
    cin >> currentMarker;

    currentPlayer = 1;

    int turns = 0;
    int winnerPlayer = 0;

    while(turns < 9 && winnerPlayer == 0) {
        int slot;
        cout << "Player " << currentPlayer << " enter position (1-9): ";
        cin >> slot;

        if(slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            continue;
        }

        if(!placeMarker(slot)) {
            cout << "Slot already occupied. Choose another.\n";
            continue;
        }

        drawBoard();
        winnerPlayer = checkWinner();
        if(winnerPlayer != 0) break;

        switchPlayer();
        turns++;
    }

    if(winnerPlayer != 0)
        cout << "Player " << winnerPlayer << " wins!\n";
    else
        cout << "Game Draw!\n";

    char again;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> again;

    if(again == 'y' || again == 'Y')
        goto playAgain;
}
//main function starts from here
int main() {
    game();
    return 0;
}

