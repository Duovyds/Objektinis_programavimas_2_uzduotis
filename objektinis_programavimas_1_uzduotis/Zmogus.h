//
//  Zmogus.h
//  objektinis_programavimas_1_uzduotis
//
//  Created by Dovydas Krištupas on 30/11/2024.
//

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
    const std::string& getVardas() const;
    const std::string& getPavarde() const;
    
    
    
    
};

#endif /* Zmogus_h */
