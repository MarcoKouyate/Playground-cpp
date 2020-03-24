// This is a test project in order to learn how to use Visual Studio 2019 and Git Version Control

#include <iostream>
#include "PokemonTypeEnum.h"
#include "Pokemon.hpp"
#include "Arena.hpp"

int main() {
	//create Pokemons
	Pokemon pokemon3("Sablette", 100, 10, pokemontype::ground);
	Pokemon pokemon4("Roucool", 100, 10, pokemontype::fly);

	
	//First duel
	turnperturn(pokemon3, pokemon4);

	return 0;
}