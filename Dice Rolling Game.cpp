#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h>

using namespace std;

enum Color {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    BRIGHT = 8,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_CYAN = 11,
    BRIGHT_RED = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
};

void setColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void resetColor() {
    setColor(WHITE);
}

void clearScreen() {
    system("cls");
}

void displayMenu() {
    clearScreen();

    setColor(BRIGHT_CYAN);
    cout << "========================================\n";
    cout << "          DICE ROLLING SIMULATOR       \n";
    cout << "========================================\n\n";

    setColor(WHITE);
    cout << "           Main Menu\n";
    cout << "           ---------\n\n";

    setColor(BRIGHT_GREEN);
    cout << "   1. Roll Dice\n";
    cout << "   2. View Instructions\n";
    cout << "   3. Exit\n\n";

    setColor(BRIGHT_YELLOW);
    cout << "   Select an option (1-3): ";
    resetColor();
}

void displayDice(int die1, int die2) {
    string diceFaces[6][5] = {
        {"  -------  ", " |       | ", " |   o   | ", " |       | ", "  -------  "},
        {"  -------  ", " | o     | ", " |       | ", " |     o | ", "  -------  "},
        {"  -------  ", " | o     | ", " |   o   | ", " |     o | ", "  -------  "},
        {"  -------  ", " | o   o | ", " |       | ", " | o   o | ", "  -------  "},
        {"  -------  ", " | o   o | ", " |   o   | ", " | o   o | ", "  -------  "},
        {"  -------  ", " | o   o | ", " | o   o | ", " | o   o | ", "  -------  "}
    };

    setColor(BRIGHT_WHITE);
    cout << "\n";

    for(int i = 0; i < 5; i++) {
        cout << "      " << diceFaces[die1-1][i] << "    " << diceFaces[die2-1][i] << "\n";
    }
    cout << "\n";

    setColor(BRIGHT_CYAN);
    cout << "      Die 1: ";
    setColor(BRIGHT_YELLOW);
    cout << die1;
    setColor(BRIGHT_CYAN);
    cout << "          Die 2: ";
    setColor(BRIGHT_YELLOW);
    cout << die2 << "\n\n";
}

void displayInstructions() {
    clearScreen();

    setColor(BRIGHT_CYAN);
    cout << "========================================\n";
    cout << "             INSTRUCTIONS               \n";
    cout << "========================================\n\n";

    setColor(WHITE);
    cout << "How to Play:\n\n";

    setColor(BRIGHT_GREEN);
    cout << "1. ";
    setColor(WHITE);
    cout << "Select 'Roll Dice' from the main menu\n";

    setColor(BRIGHT_GREEN);
    cout << "2. ";
    setColor(WHITE);
    cout << "The program will simulate rolling two dice\n";

    setColor(BRIGHT_GREEN);
    cout << "3. ";
    setColor(WHITE);
    cout << "Watch the dice animation and see your result\n";

    setColor(BRIGHT_GREEN);
    cout << "4. ";
    setColor(WHITE);
    cout << "Special combinations will be highlighted\n";

    setColor(BRIGHT_GREEN);
    cout << "5. ";
    setColor(WHITE);
    cout << "You can roll again or return to the menu\n\n";

    setColor(BRIGHT_CYAN);
    cout << "Special Combinations:\n\n";

    setColor(BRIGHT_RED);
    cout << "  Snake Eyes  ";
    setColor(WHITE);
    cout << ": Two 1s (1 + 1)\n";

    setColor(BRIGHT_MAGENTA);
    cout << "  Boxcars     ";
    setColor(WHITE);
    cout << ": Two 6s (6 + 6)\n";

    setColor(BRIGHT_YELLOW);
    cout << "  Doubles     ";
    setColor(WHITE);
    cout << ": Any matching pair\n";

    setColor(BRIGHT_GREEN);
    cout << "  Lucky 7/11  ";
    setColor(WHITE);
    cout << ": Total of 7 or 11\n\n";

    setColor(BRIGHT_YELLOW);
    cout << "Press Enter to return to menu...";
    resetColor();
    cin.ignore();
    cin.get();
}

void rollDice() {
    clearScreen();

    setColor(BRIGHT_CYAN);
    cout << "========================================\n";
    cout << "             ROLL THE DICE              \n";
    cout << "========================================\n\n";

    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    int total = die1 + die2;

    displayDice(die1, die2);

    setColor(BRIGHT_CYAN);
    cout << "      Total: ";
    setColor(BRIGHT_YELLOW);
    cout << total << "\n\n";

    if (die1 == 1 && die2 == 1) {
        setColor(BRIGHT_RED);
        cout << "      SNAKE EYES! (Two 1s)\n\n";
    } else if (die1 == 6 && die2 == 6) {
        setColor(BRIGHT_MAGENTA);
        cout << "      BOXCARS! (Two 6s)\n\n";
    } else if (total == 7 || total == 11) {
        setColor(BRIGHT_GREEN);
        cout << "      LUCKY " << total << "!\n\n";
    } else if (die1 == die2) {
        setColor(BRIGHT_YELLOW);
        cout << "      DOUBLES! (" << die1 << " and " << die2 << ")\n\n";
    }

    setColor(BRIGHT_WHITE);
    cout << "========================================\n\n";

    setColor(BRIGHT_GREEN);
    cout << "   Options:\n\n";
    setColor(WHITE);
    cout << "   1. Roll Again\n";
    cout << "   2. Return to Menu\n\n";

    setColor(BRIGHT_YELLOW);
    cout << "   Select an option (1-2): ";
    resetColor();
}

void displayCreatorInfo() {
    clearScreen();

    setColor(BRIGHT_CYAN);
    cout << "========================================\n";
    cout << "           PROGRAM CREATOR             \n";
    cout << "========================================\n\n";

    setColor(BRIGHT_GREEN);
    cout << "   Created by: ";
    setColor(BRIGHT_YELLOW);
    cout << "Shahab Ahmed\n\n";

    setColor(BRIGHT_GREEN);
    cout << "   LinkedIn: ";
    setColor(BRIGHT_CYAN);
    cout << "https://www.linkedin.com/in/shahabahmed01/\n\n";

    setColor(BRIGHT_WHITE);
    cout << "========================================\n\n";

    setColor(BRIGHT_YELLOW);
    cout << "   Press Enter to return to menu...";
    resetColor();
    cin.ignore();
    cin.get();
}

int main() {
    srand(time(0));

    int choice;
    bool exitProgram = false;

    do {
        clearScreen();

        setColor(BRIGHT_CYAN);
        cout << "========================================\n";
        cout << "          DICE ROLLING SIMULATOR       \n";
        cout << "========================================\n\n";

        setColor(WHITE);
        cout << "           Main Menu\n";
        cout << "           ---------\n\n";

        setColor(BRIGHT_GREEN);
        cout << "   1. Roll Dice\n";
        cout << "   2. View Instructions\n";
        cout << "   3. View Creator Info\n";
        cout << "   4. Exit\n\n";

        setColor(BRIGHT_YELLOW);
        cout << "   Select an option (1-4): ";
        resetColor();

        while(!(cin >> choice) || choice < 1 || choice > 4) {
            setColor(BRIGHT_RED);
            cout << "   Invalid input! Please enter 1, 2, 3, or 4: ";
            resetColor();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(choice) {
            case 1: {
                bool rollAgain = true;
                while(rollAgain) {
                    rollDice();

                    int rollChoice;
                    while(!(cin >> rollChoice) || rollChoice < 1 || rollChoice > 2) {
                        setColor(BRIGHT_RED);
                        cout << "   Invalid input! Please enter 1 or 2: ";
                        resetColor();
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if(rollChoice == 2) {
                        rollAgain = false;
                    }
                }
                break;
            }

            case 2:
                displayInstructions();
                break;

            case 3:
                displayCreatorInfo();
                break;

            case 4:
                clearScreen();
                setColor(BRIGHT_CYAN);
                cout << "========================================\n";
                cout << "       THANKS FOR PLAYING!              \n";
                cout << "========================================\n\n";

                setColor(BRIGHT_GREEN);
                cout << "   Created by: ";
                setColor(BRIGHT_YELLOW);
                cout << "Shahab Ahmed\n\n";

                setColor(BRIGHT_GREEN);
                cout << "   LinkedIn: ";
                setColor(BRIGHT_CYAN);
                cout << "https://www.linkedin.com/in/shahabahmed01/\n\n";

                resetColor();
                exitProgram = true;
                break;
        }

    } while(!exitProgram);

    return 0;
}
