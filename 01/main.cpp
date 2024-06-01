#include <iostream>
#include "game.hpp"

using namespace std;

int main() {
    string inputMatches;
    string inputGamers;
    uint32_t matchesInGame;
    uint32_t numGamers;
    MachstickGame* newGame;

    while (true) {
        cout << "Enter the number of players: ";
        getline(cin, inputGamers);

        cout << "Enter the number of matches on the table: ";
        getline(cin, inputMatches);

        try {
            matchesInGame = static_cast<uint32_t>(stoul(inputMatches));
            numGamers = static_cast<uint32_t>(stoul(inputGamers));
        }
        catch (const invalid_argument& err) {
            cerr << "Invalid value. Try again." << endl;
            continue;
        }
        catch (const out_of_range& err) {
            cerr << "Invalid value. Try again." << endl;
            continue;
        }

        if (matchesInGame == 0 || numGamers == 0 ||
            numGamers >= matchesInGame) {
            cerr << "Invalid value. Try again." << endl;
            continue;
        }

        break;
    }

    newGame = new MachstickGame(numGamers, matchesInGame);

    newGame->gameStart();

    delete newGame;

    return 0;
}