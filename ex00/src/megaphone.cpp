#include <iostream>

int main(int argc, char const *argv[])
{
    std::string str_toconvert = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::string str_uppercased;

    if (argc > 1) {
        str_toconvert = *++argv;
        while (*++argv)
            str_toconvert.append(*argv);
    }

    for (std::string::iterator it = str_toconvert.begin(); it != str_toconvert.end(); it++)
        str_uppercased.push_back(std::toupper(*it));

    std::cout << str_uppercased << std::endl;
    return 0;
}
