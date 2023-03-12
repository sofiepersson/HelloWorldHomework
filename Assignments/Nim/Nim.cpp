#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int matches = 24;

int GetPlayerChoice() {
    cout << "How many matches do you want to draw? (1-3): ";
    bool validChoice = false;
    int playerChoice;
    while (!validChoice) {
        cin >> playerChoice;
        if (playerChoice >= 1 && playerChoice <= 3)
            validChoice = true;
        else
            cout << "Invalid input." << endl;
    }
    return playerChoice;
}

int GetUnbeatableAi() {
    int aiChoice = -1 + (matches % 4);
    if (aiChoice == 0)
    {
        aiChoice = rand() % 3 + 1;
    }
    else if (aiChoice == -1)
    {
        aiChoice = 3;
    }
    return aiChoice;
}

int GetNormalAi()
{
    int aiChoice;
    if (matches >= 3)
    {
        aiChoice = rand() % 3 + 1;
    }
    else if (matches == 2)
    {
        aiChoice = rand() % 3 + 1;
    }
    else
    {
        aiChoice = 1;

    }
    return aiChoice;
}

void PrintMatches()
{
    int i = 0;
    while (i < matches)
    {
        cout << "|";
        i++;
    }
    cout << " (" << matches << ")" << endl;
}

void main() {
    srand(time(0));
    cout << "Welcome to Nim!" << endl;
    AskDifficulty:
    cout << "Please choose the difficulty, [N]ormal or [U]nbeatable: ";
    char difficulty;
    cin >> difficulty;

    if (difficulty == 'N')
    {
        while (matches > 0)
        {
            PrintMatches();
            int playerChoice = GetPlayerChoice();
            matches -= playerChoice;
            if (matches <= 0)
            {
                cout << "You lose..." << endl;
                return;
            }
            PrintMatches();
            int aiChoice = GetNormalAi();
            cout << "The AI draws " << aiChoice << " matches." << endl;
            matches -= aiChoice;
            if (matches <= 0)
            {
                cout << "You win!" << endl;
            }
        }
    }
    else if (difficulty == 'U')
    {
        while (matches > 0)
        {
            PrintMatches();
            int playerChoice = GetPlayerChoice();
            matches -= playerChoice;
            if (matches <= 0)
            {
                cout << "You lose..." << endl;
                return;
            }
            PrintMatches();
            int aiChoice = GetUnbeatableAi();
            cout << "The AI draws " << aiChoice << " matches." << endl;
            matches -= aiChoice;
            if (matches <= 0)
            {
                cout << "You win!" << endl;
            }
        }
    }
    else
    {
        goto AskDifficulty;
    }
}