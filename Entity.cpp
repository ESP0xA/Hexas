#include <iostream>
#include "Entity.h"

void Entity::Print()
{

	std::cout << "cPedHealth: " << cPedHealth << "\n";
	std::cout << "cPedPosition: {" << cPedCoords.x << ", " << cPedCoords.y << ", " << cPedCoords.z << "}\n";

	std::cout << "\n\n";
}