#pragma once

#include <string>

class Gamer {
public:
    Gamer(std::string name) {
        this->name = new std::string();
        *(this->name) = name;
    }
    ~Gamer() {
        delete this->name;
    }

    std::string *getName() {
        return this->name;
    }

    void setName(std::string *name) {
        *this->name = *name;
    }

    void addMatchsticks(uint32_t matchsticks) {
        this->matchsticks += matchsticks;
    }

private:
    std::string *name;
    uint32_t matchsticks;
};