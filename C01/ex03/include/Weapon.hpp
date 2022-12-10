#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {

public:

	Weapon(std::string type);

	void		setType(std::string type);
	std::string const &getType();


private:
	std::string type;

};

#endif