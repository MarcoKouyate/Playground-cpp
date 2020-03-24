#include "Pokemon.hpp"
#include <iostream>
#include "Multiplier.hpp"


//Constructor
Pokemon::Pokemon(std::string name, int HP, int attackPoint, pokemontype type) {
	m_name = name;
	m_HP = HP;
	m_attackPoints = attackPoint;
	m_type = type;
};

//Getter
std::string Pokemon::getName() {
	return m_name;
};

pokemontype Pokemon::getType() const {
	return m_type;
};

//check if pokemon is dead
bool Pokemon::isDead() {
	return (m_HP <= 0);
}

//to inflict damage to pokemon
void Pokemon::damage(float damage) {
	m_HP = m_HP - int(damage);
	std::cout << "Le " << m_name << " perd : " << damage << " PV." << std::endl;
}

//return informations about the pokemon
std::string Pokemon::info() {
	return "<" + m_name + " [HP: " + std::to_string(m_HP) + "]>";
}

//inflict damage to other pokemon
void Pokemon::attack(Pokemon& other) {
	if (!isDead()) {
		std::cout << m_name << " attaque " << other.m_name << std::endl;
		other.damage(m_attackPoints * multiplier(m_type, other.m_type));
	}
}