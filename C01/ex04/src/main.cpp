#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main(int argc, char const *argv[])
{
	if (argc != 4)
		return (std::cout << "Not the good amount of arguments", 1);

	char const *ifname = argv[1];
	std::string ofname_str = std::string(ifname).append(".replace");
	char const *ofname = ofname_str.c_str();

	char const *s1 = argv[2];
	char const *s2 = argv[3];

	std::ifstream ifs(ifname);
	std::string buf;
	std::string buf_replaced;
	size_t pos;
	size_t stop;
	size_t const s1_len = strlen(s1);

	if (!ifs)
	{
		perror("Failed");
		return 1;
	}

	std::ofstream ofs(ofname);
	while (std::getline(ifs, buf))
	{
		std::cout << "ENTER\n";
		buf_replaced = "";
		pos = 0;
		while (pos < buf.length())
		{
			stop = buf.find(s1, pos);
			if (stop == std::string::npos)
			{
				buf_replaced += buf.substr(pos, std::string::npos);
				break;
			}
			buf_replaced += buf.substr(pos, stop - pos);
			buf_replaced += s2;
			pos = stop + s1_len;
		}
		ofs << buf_replaced;
		if (!ifs.eof())
			ofs << "\n";
	}

	if (ifs.fail() && !ifs.eof())
		std::cout << "An error has occured" << std::endl;

	std::cout << std::endl;
	return 0;
}