#include <iostream>
#include <cstdlib>

int main()
{
    int    a = 42;
int* ptr = &a;

struct Chien { int age; };
struct Avion { float vitesse; };

Chien monChien;
monChien.age = 5;


Avion* monFauxAvion = reinterpret_cast<Avion*>(&monChien);


std::cout << "Vitesse de l'avion-chien : " << monFauxAvion->vitesse << std::endl;
}