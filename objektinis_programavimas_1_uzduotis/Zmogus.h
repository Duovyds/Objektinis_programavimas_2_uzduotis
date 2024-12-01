#ifndef Zmogus_h
#define Zmogus_h
#include "Header.h"


class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    Zmogus();
    Zmogus(string vardas, string pavarde);
    virtual ~Zmogus() = default;
    
    
    // Geteriai
    virtual const std::string& getVardas() const = 0;
    virtual const std::string& getPavarde() const = 0;
    
    
    
    
};

#endif /* Zmogus_h */
