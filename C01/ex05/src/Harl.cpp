#include "Harl.hpp"

std::string Harl::levels[]= {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};


void    Harl::debug(void) const {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) const {
    std::cout <<  "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) const {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) const {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*f[4])(void) const = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (size_t i = 0; i < 4; i++)
    {
        if (Harl::levels[i] == level)
            (this->*f[i])();
    }
}

