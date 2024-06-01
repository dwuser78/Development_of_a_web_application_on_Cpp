#include "game.hpp"

MachstickGame::MachstickGame(uint32_t numGamers, uint32_t numMatchsticks) {
    std::string name;
    Gamer *gamer;

    this->loser = nullptr;
    this->matchsticks = numMatchsticks;

    for (size_t i = 0; i < numGamers; i++) {

        std::cout << "Enter the name of player " << i + 1 << " : ";
        std::getline(std::cin, name);

        gamer = new Gamer(name);

        this->gamers.push_back(gamer);
    }
}

MachstickGame::~MachstickGame() {
    for (Gamer *gamer : this->gamers)
        delete gamer;
}

void MachstickGame::gameStart() {
    while (true) {
        for (Gamer *gamer : this->gamers) {
            std::cout << "Matches on the table: " << this->matchsticks
                << std::endl;
            makeMove(gamer);

            if (this->matchsticks == 0) {
                this->loser = gamer;

                gameEnd();

                return;
            }
        }
    }
}

void MachstickGame::gameEnd() {
    std::cout << "Game over." << std::endl;

    std::cout << "Winners:" << std::endl;
    for (Gamer *gamer : this->gamers) {
        if (gamer != this->loser)
            std::cout << *(gamer->getName()) << std::endl;
    }

    std::cout << std::endl << "Loser:" << std::endl;
        std::cout << *(this->loser->getName()) << std::endl;
}

void MachstickGame::makeMove(Gamer *gamer) {
    std::string inputMathces;
    uint32_t matchesOnMove;
    std::string userName;

    while (true) {
        userName = *(gamer->getName());

        std::cout << "Player " << userName << " takes a match (1 - "
            << MAX_MATCHSTICK << "): ";
        std::getline(std::cin, inputMathces);

        try {
            matchesOnMove = static_cast<uint32_t>(std::stoul(inputMathces));
        }
        catch (const std::invalid_argument& err){
            std::cerr << "Invalid value. Try again." << std::endl;
            continue;
        }
        catch (const std::out_of_range& err) {
            std::cerr << "Invalid value. Try again." << std::endl;
            continue;
        }

        if (matchesOnMove > this->matchsticks || matchesOnMove == 0 ||
            matchesOnMove > MAX_MATCHSTICK) {
            std::cerr << "Invalid value. Try again." << std::endl;
            continue;
        }

        break;
    }

    this->matchsticks -= matchesOnMove;
    gamer->addMatchsticks(matchesOnMove);
}