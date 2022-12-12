#include "Harl.hpp"

std::string Harl::levels[]= {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};


void    Harl::debug(void) const {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void    Harl::info(void) const {
    std::cout <<  "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void    Harl::warning(void) const {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void    Harl::error(void) const {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*f[4])(void) const = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    size_t i;
    for (i = 0; i < 4; i++)
        if (Harl::levels[i] == level)
            break;
    if (i == 4)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    while (i < 4)
        (this->*f[i++])();
}

