#include "Multiplier.hpp"
#include <iostream>

bool weakness(pokemontype& const type1, pokemontype& const type2) {
	return (type1 == pokemontype::water && type2 == pokemontype::fire) || (type1 == pokemontype::fire && type2 == pokemontype::grass) || (type1 == pokemontype::grass && type2 == pokemontype::water);
}

bool immun(pokemontype type1, pokemontype type2) {
	return (type1 == pokemontype::ground && type2 == pokemontype::fly);
}

float multiplier(pokemontype& const type1, pokemontype& const type2) {
	if (weakness(type1, type2)) {
		std::cout << "Cette attaque est super efficace" << std::endl;
		return 2.f;
	}
	else if (weakness(type2, type1)) {
		std::cout << "Cette attaque n'est pas très efficace" << std::endl;
		return 0.5f;
	}
	else if (immun(type1, type2)) {
		std::cout << "Cette attaque n'a aucun effet" << std::endl;
		return 0.f;
	}
	else {
		return 1.f;
	}
}