#include "Arena.hpp"
#include <iostream>

void turnperturn(Pokemon& pokemon1, Pokemon& pokemon2) {
	while (!pokemon1.isDead() && !pokemon2.isDead()) {
		std::cout << pokemon1.info() << " " << pokemon2.info() << std::endl;
		pokemon1.attack(pokemon2);
		pokemon2.attack(pokemon1);
		std::cout << std::endl;
	}

		if (pokemon1.isDead()) {
			std::cout << pokemon1.getName() << " est K.O" << std::endl;
		}
		if (pokemon2.isDead()) {
			std::cout << pokemon2.getName() << " est K.O" << std::endl;
		}

	std::cout << std::endl;
}