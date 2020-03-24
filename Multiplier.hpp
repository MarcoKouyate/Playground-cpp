#pragma once
#include "PokemonTypeEnum.h"

bool weakness(pokemontype& const type1, pokemontype& const type2);

bool immun(pokemontype type1, pokemontype type2);

float multiplier(pokemontype& const type1, pokemontype& const type2);
