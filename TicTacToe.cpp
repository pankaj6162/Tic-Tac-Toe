#include <iostream> 
#include <limits>
using namespace std; 

// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
} 

// Function to check for a win 
bool checkWin(char board[3][3], char player) 
{ 
    // Check rows, columns, and diagonals 
    for (int i = 0; i < 3; i++) { 
        if (board[i][0] == player && board[i][1] == player 
            && board[i][2] == player) 
            return true; 
        if (board[0][i] == player && board[1][i] == player 
            && board[2][i] == player) 
            return true; 
    } 
    if (board[0][0] == player && board[1][1] == player 
        && board[2][2] == player) 
        return true; 
    if (board[0][2] == player && board[1][1] == player 
        && board[2][0] == player) 
        return true; 
    return false; 
} 

// Function to check for a draw 
bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // If there is an empty cell, game is not draw
        }
    }
    return true; // If no empty cell found, game is draw
}

// Function to clear the board for a new game
void clearBoard(char board[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() 
{ 
    char board[3][3]; 
    char player;
    int row, col; 
    char playAgain;

    cout << "Welcome to Tic-Tac-Toe!\n"; 

    do {
        // Initialize the board and players 
        clearBoard(board);
        player = 'X'; 

        // Game loop 
        for (int turn = 0; turn < 9; turn++) { 
            // Draw the board 
            drawBoard(board); 
            cout << "Player " << player << "'s turn.\n";

            // Prompt for valid input 
            while (true) { 
                cout << "Enter row (0-2) and column (0-2): "; 
                if (!(cin >> row >> col) || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') { 
                    cout << "Invalid move. Try again.\n"; 
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break; // Valid input, exit the loop. 
                } 
            } 

            // Make the move 
            board[row][col] = player; 

            // Check for a win after making a move 
            if (checkWin(board, player)) { 
                drawBoard(board); 
                cout << "Player " << player << " wins!\n"; 
                break; // Exit the loop after a win. 
            } 

            // Check for a draw
            if (checkDraw(board)) {
                drawBoard(board);
                cout << "It's a draw!\n";
                break; // Exit the loop after a draw.
            }

            // Switch to the other player 
            player = (player == 'X') ? 'O' : 'X'; 
        } 

        // Prompt to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0; 
}
