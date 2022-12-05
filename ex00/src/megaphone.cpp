#include <iostream>

int main(int argc, char const *argv[])
{
    std::string str_toconvert = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::string str_uppercased;

    if (argc == 2)
        str_toconvert = argv[1];
    else if (argc != 1)
        return 1;

    std::cout << "Length -> " << str_toconvert.length() << std::endl;
    for (size_t i = 0; i < str_toconvert.length(); i++)
        std::cout << "caractere : " << str_toconvert[i] << std::endl;

    std::cout << std::endl;
    for (std::string::iterator it = str_toconvert.begin(); it != str_toconvert.end(); it++)
        std::cout << "kara : " << *it << std::endl;

    std::cout << str_toconvert << std::endl;
    return 0;
}
