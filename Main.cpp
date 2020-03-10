// This is a test project in order to learn how to use Visual Studio 2019 and Git Version Control

//CONSIGNES POUR NASSIM
/*I- Récupérer ce repo  - FAIT
a) Installer Github extension pour visual studio - FAIT
b) Se connecter à Github - FAIT
c) Récupérer ce repo - FAIT
*/

#include <iostream>
#include <string>


struct Pokemon {
	std::string name;
	int HP;
	int attackPoints;

	bool isDead() {
		return (HP <= 0);
	}

	void damage(int damage) {
		HP = HP - damage;
		std::cout << "Le " << name << " perd : " << damage << " PV." << std::endl;
	}

	std::string info() {
		return "<" +name + " [HP: " + std::to_string(HP) + "]>";
	}

	void attack(Pokemon& other) {
		if (!isDead()) {
			std::cout << name << " attaque " << other.name << std::endl;
			other.damage(attackPoints);
		}
	}
};

void turnperturn(Pokemon& pokemon1, Pokemon& pokemon2) {
	while (!pokemon1.isDead() && !pokemon2.isDead()) {
		pokemon1.attack(pokemon2);
		pokemon2.attack(pokemon1);
	}

	if (pokemon1.isDead()) {
		std::cout << "Le " << pokemon1.name << " est K.O" << std::endl;
	}
	if (pokemon2.isDead()) {
		std::cout << "Le " << pokemon2.name << " est K.O" << std::endl;
	}
}

int main() {
	Pokemon pokemon1 = { "Amphinobi", 100, 10 };
	Pokemon pokemon2 = { "Lucario", 100, 30 };
	

	turnperturn(pokemon1, pokemon2);


	std::cout << pokemon1.info() << std::endl;
	std::cout << pokemon2.info() << std::endl;



	return 0;
}