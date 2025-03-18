#include "Zombie.hpp"

Zombie::Zombie(std::string name) {}

Zombie::~Zombie(std::string name) {}

void Zombie::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

