#include <stdio.h>
#include "Zmogus.h"
#include "Header.h"


// Default konstruktorius
Zmogus::Zmogus() : vardas(""), pavarde("") {}

// Konstruktorius
Zmogus::Zmogus(string vardas, string pavarde): vardas(vardas), pavarde(pavarde) {}

    
    
// Geteriai
const std::string& Zmogus::getVardas() const {
    return vardas;
}
const std::string& Zmogus::getPavarde() const {
    return pavarde;
}
    
    
    
    


