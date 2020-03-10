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
	};

	void damage(int damage) {
		HP = HP - damage;
		std::cout << "Le " << name << " perd : " << damage << " PV." << std::endl;
	};

	void attack(Pokemon& other) {
		std::cout << name << " attaque " << other.name << std::endl;
	};
};

int main() {
	Pokemon pokemon1 = { "Amphinobi", 100, 10 };
	Pokemon pokemon2 = { "Lucario", 100, 10 };

	pokemon1.attack(pokemon2);
	
	pokemon1.damage(20);

	if (pokemon1.isDead()) {
		std::cout << "Le " << pokemon1.name << " est K.O" << std::endl;
	}

	return 0;
}