#pragma once

#include <string>

class Gamer {
public:
    Gamer(std::string name);
    ~Gamer();

    std::string *getName();
    void setName(std::string *name);
    void addMatchsticks(uint32_t matchsticks);

private:
    std::string *name;
    uint32_t matchsticks;
};