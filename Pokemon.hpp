#pragma once
#include <string>
#include "PokemonTypeEnum.h"

class Pokemon {

public:
	//Constructor
	Pokemon(std::string name, int HP, int attackPoint, pokemontype type);

	//Getter
	std::string getName();

	pokemontype getType() const;

	//check if pokemon is dead
	bool isDead();

	//to inflict damage to pokemon
	void damage(float damage);

	//return informations about the pokemon
	std::string info();

	//inflict damage to other pokemon
	void attack(Pokemon& other);

private:
	std::string m_name;
	int m_HP;
	int m_attackPoints;
	pokemontype m_type;
};