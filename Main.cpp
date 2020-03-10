// This is a test project in order to learn how to use Visual Studio 2019 and Git Version Control

#include <iostream>
#include <string>


struct Pokemon {
	std::string name;
	int HP;
	int attackPoints;

	//check if pokemon is dead
	bool isDead() {
		return (HP <= 0);
	}

	//to inflict damage to pokemon
	void damage(int damage) {
		HP = HP - damage;
		std::cout << "Le " << name << " perd : " << damage << " PV." << std::endl;
	}

	//return informations about the pokemon
	std::string info() {
		return "<" +name + " [HP: " + std::to_string(HP) + "]>";
	}

	//inflict damage to other pokemon
	void attack(Pokemon& other) {
		if (!isDead()) {
			std::cout << name << " attaque " << other.name << std::endl;
			other.damage(attackPoints);
		}
	}
};

void turnperturn(Pokemon& pokemon1, Pokemon& pokemon2) {
	while (!pokemon1.isDead() && !pokemon2.isDead()) {
		std::cout << pokemon1.info() << " " << pokemon2.info() << std::endl;
		pokemon1.attack(pokemon2);
		pokemon2.attack(pokemon1);
		std::cout << std::endl;
	}

	if (pokemon1.isDead()) {
		std::cout << pokemon1.name << " est K.O" << std::endl;
	}
	if (pokemon2.isDead()) {
		std::cout << pokemon2.name << " est K.O" << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	//Pokemons structs
	Pokemon pokemon1 = { "Amphinobi", 100, 10 };
	Pokemon pokemon2 = { "Lucario", 100, 30 };

	Pokemon pikachu = { "Pikachu", 100, 10 };
	Pokemon link = { "Link", 85, 15 };
	
	//First duel
	turnperturn(pokemon1, pokemon2);

	//Second duel
	turnperturn(pikachu, link);

	return 0;
}