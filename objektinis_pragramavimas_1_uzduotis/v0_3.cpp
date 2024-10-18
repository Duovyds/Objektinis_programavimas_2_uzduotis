#include "v0_3.hpp"
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"



list<Studentas> vargsiuku_atrinkimas_naudojant_list(list<Studentas>& studentai){
    list<Studentas> vargsiukai;
    
    for (const auto& studentas : studentai){
        if (studentas.galutinis_vid < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    
    return vargsiukai;
}
