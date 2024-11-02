#ifndef v0_3_hpp
#define v0_3_hpp
#include "Header.h"
#include <stdio.h>
#include "Studentas.h"

list<Studentas> vargsiuku_atrinkimas_naudojant_list(vector<Studentas>& studentai);
list<Studentas> galvociu_atrinkimas_naudojant_list(vector<Studentas>& studentai);
void irasymas(list<Studentas>& studentai, string failo_pav, int pasirinkimas);
void laiko_skaiciavimas_list_konteineris(string failo_pavadinimas, int rikiavimo_pasirinkimas);



#endif /* v0_3_hpp */
