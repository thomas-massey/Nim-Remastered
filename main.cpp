// This is a terminal program of the game NIM.
// The game is played between two players or an AI (player can choose who goes first).
// There is one pile of counters which is up to the user to decide how many counters to start with.

#include <iostream>
#include <string>

using namespace std;

int main(){
    // Get parameters from user
    int numCounters;
    cout << "How many counters would you like to start with? ";
    cin >> numCounters;
    cout << endl;

    // Get if they want to play against AI or another player
    string against_AI_input;
    bool against_AI = false;
    cout << "Would you like to play against an AI or another player? (AI/player) ";
    cin >> against_AI_input;
    cout << endl;
    if (against_AI_input == "AI"){
        against_AI = true;
    }

    bool player_first;
    bool smart;
    if (against_AI){
        // Get if they want to go first or second
        string player_first_input;
        cout << "Would you like to go first or second? (first/second) ";
        cin >> player_first_input;
        cout << endl;
        if (player_first_input == "first"){
            player_first = true;
        } else if (player_first_input == "second"){
            player_first = false;
        } else {
            cout << "Invalid input." << endl;
            return 0;
        }


        // Get if the AI is smart or dumb
        string smart_input;
        cout << "Would you like to play against a smart or dumb AI? (smart/dumb) ";
        cin >> smart_input;
        cout << endl;
        if (smart_input == "smart"){
            bool smart = true;
        } else if (smart_input == "dumb"){
            bool smart = false;
        } else {
            cout << "Invalid input." << endl;
            return 0;
        }
    }

    // Turn
    bool player1Turn = true;

    // Game loop
    bool gameOver = false;
    while (!gameOver){
        // Print number of counters
        cout << "There are " << numCounters << " counters left." << endl;

        // If it is a human's turn (not an AI turn)
        if (not against_AI){
            if (player1Turn){
                cout << "Player 1's turn. Please select either 1, 2 or 3 counters." << endl;
            } else {
                cout << "Player 2's turn. Please select either 1, 2 or 3 counters." << endl;
            }
            int numCountersTaken;
            cin >> numCountersTaken;
            if (numCountersTaken > 3 || numCountersTaken < 1){
                cout << "Invalid input." << endl;
                return 0;
            }
            if (player1Turn){
                cout << "Player 1 took " << numCountersTaken << " counters." << endl;
            } else {
                cout << "Player 2 took " << numCountersTaken << " counters." << endl;
            }
            numCounters -= numCountersTaken;
        } else {
            // Determine if it is the AI's turn or the player's turn depending on who goes first
            if ((player_first and player1Turn) || (!player_first and !player1Turn)){
                // If it is the player's turn
                cout << "Humans turn. Please select either 1, 2 or 3 counters." << endl;
                int numCountersTaken;
                cin >> numCountersTaken;
                if (numCountersTaken > 3 || numCountersTaken < 1){
                    cout << "Invalid input." << endl;
                    return 0;
                }
                cout << "You took " << numCountersTaken << " counters." << endl;
                numCounters -= numCountersTaken;
            } else {
                // If it is the AI's turn
                if (smart){
                    // If the AI is smart
                    if (numCounters % 4 == 0){
                        cout << "The AI took 3 counters." << endl;
                        numCounters -= 3;
                    } else if (numCounters % 4 == 1){
                        // Take a random number of counters
                        int numCountersTaken = rand() % 3 + 1;
                        cout << "The AI took " << numCountersTaken << " counters." << endl;
                        numCounters -= numCountersTaken;
                    } else if (numCounters % 4 == 2){
                        cout << "The AI took 1 counters." << endl;
                        numCounters -= 1;
                    } else if (numCounters % 4 == 3){
                        cout << "The AI took 2 counters." << endl;
                        numCounters -= 2;
                    }
                } else {
                    // If the AI is dumb, pick a random number between 1 and 3
                    int numCountersTaken = rand() % 3 + 1;
                    cout << "The AI took " << numCountersTaken << " counters." << endl;
                    numCounters -= numCountersTaken;
                    
                }
                
            }
        }
        if (numCounters <= 0 && !against_AI){
            gameOver = true;
            if (player1Turn){
                cout << "Player 2 wins!" << endl;
            } else {
                cout << "Player 1 wins!" << endl;
            }
        } else if (numCounters <= 0 && against_AI){
            gameOver = true;
            if (player_first && player1Turn){
                cout << "AI win's!" << endl;
            } else if (!player_first && !player1Turn){
                cout << "AI win's!" << endl;
            } else {
                cout << "You win!" << endl;
            }
        }
        player1Turn = !player1Turn;
    }
}