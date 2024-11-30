#include <stdio.h>
#include "Zmogus.h"
#include "Header.h"


class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    Zmogus(string vardas, string pavarde){
        this->vardas = vardas;
        this->pavarde = pavarde;
    }
    
    virtual ~Zmogus() = default;
    
    
    
    
};

