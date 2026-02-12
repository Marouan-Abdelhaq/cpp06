#include <iostream>
#include <cstdlib>

#include <iostream>

struct Animal {
    virtual ~Animal() {} // IMPORTANT pour dynamic_cast
};

struct Chien : Animal {
    public:
    std::string namee;
    void aboyer() {
        std::cout << "Wouf !" << std::endl;
    }
    void name()
    {
        std::cout << namee << std::endl;
    }
};

struct Chat : Animal {
    void miauler() {
        std::cout << "Miaou !" << std::endl;
    }
};

int main() {
    Animal* a = new Chat();   // C'est un Chat en réalité

    Chien* c = dynamic_cast<Chien*>(a); // ❌ On ment au compilateur

    c->name(); // 💥 DANGER

    delete a;
}
