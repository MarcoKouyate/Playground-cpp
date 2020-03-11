// This is a test project in order to learn how to use Visual Studio 2019 and Git Version Control

#include <iostream>
#include <string>

enum class pokemontype { fire, water, grass, fly, ground };
float multiplier(pokemontype& const type1, pokemontype& const type2);
float immun(pokemontype type1, pokemontype type2);

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

	pokemontype getType() const {
		return m_type;
	}

	//check if pokemon is dead
	bool isDead() {
		return (m_HP <= 0);
	}

	//to inflict damage to pokemon
	void damage(float damage) {
		m_HP = m_HP - int(damage);
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
			other.damage(m_attackPoints * multiplier(m_type, other.m_type) * immun(m_type, other.m_type));
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

bool weakness(pokemontype& const type1, pokemontype& const type2) {
	return (type1 == pokemontype::water && type2 == pokemontype::fire) || (type1 == pokemontype::fire && type2 == pokemontype::grass) || (type1 == pokemontype::grass && type2 == pokemontype::water);
}


float multiplier(pokemontype& const type1, pokemontype& const type2){
	if (weakness(type1, type2)) {
		std::cout << "Cette attaque est super efficace" << std::endl;
		return 2.f;
		}
	else if (weakness(type2, type1)) {
		std::cout << "Cette attaque n'est pas très efficace" << std::endl;
		return 0.5f;
	}
	else  {
		return 1.f;
	} 
}

float immun(pokemontype type1, pokemontype type2) {
	if (type1 == pokemontype::ground && type2 == pokemontype::fly) {
		std::cout << "Cette attaque n'a aucun effet" << std::endl;
		return 0.f;
	}
	else {
		return 1.f;
	}
}

int main() {
	//Pokemons structs
	/*Pokemon pokemon1 ( "Amphinobi", 100, 10, pokemontype::water );
	Pokemon  pokemon2 ("Brasegali", 100, 30, pokemontype::fire );*/
	

	Pokemon pokemon3("Sablette", 100, 10, pokemontype::ground);
	Pokemon pokemon4("Roucool", 100, 10, pokemontype::fly);

	
	
	
	//First duel
	turnperturn(pokemon3, pokemon4);

	return 0;
}