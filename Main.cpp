// This is a test project in order to learn how to use Visual Studio 2019 and Git Version Control

#include <iostream>
#include <string>

enum pokemontype { fire, water, grass };

class Pokemon {

public:
	Pokemon(std::string name, int HP, int attackPoint, pokemontype type) {
		m_name = name;
		m_HP = HP;
		m_attackPoints = attackPoint;
		m_type = type;
	}

	//Getter
	std::string getName() {
		return m_name;
	}


	//check if pokemon is dead
	bool isDead() {
		return (m_HP <= 0);
	}

	//to inflict damage to pokemon
	void damage(int damage) {
		m_HP = m_HP - damage;
		std::cout << "Le " << m_name << " perd : " << damage << " PV." << std::endl;
	}

	//return informations about the pokemon
	std::string info() {
		return "<" + m_name + " [HP: " + std::to_string(m_HP) + "]>";
	}

	//inflict damage to other pokemon
	void attack(Pokemon& other) {
		if (!isDead()) {
			std::cout << m_name << " attaque " << other.m_name << std::endl;
			other.damage(m_attackPoints);
		}
	}

private:
	std::string m_name;
	int m_HP;
	int m_attackPoints;
	pokemontype m_type;
};

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



int main() {
	//Pokemons structs
	Pokemon pokemon1 ( "Amphinobi", 100, 10, water );
	Pokemon  pokemon2 ("Brasegali", 100, 30, fire );

	
	
	//First duel
	turnperturn(pokemon1, pokemon2);

	

	return 0;
}