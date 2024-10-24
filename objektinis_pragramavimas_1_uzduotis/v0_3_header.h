#ifndef v0_3_header_h
#define v0_3_header_h

#include "Header.h"
#include <stdio.h>
#include "Studentas.h"
#include "Failas.h"

list<Studentas> vargsiuku_atrinkimas_naudojant_list(vector<Studentas>& studentai);
list<Studentas> galvociu_atrinkimas_naudojant_list(vector<Studentas>& studentai);
void irasymas(list<Studentas>& studentai, string failo_pav, int pasirinkimas);
void laiko_skaiciavimas_list_konteineris(string failo_pavadinimas, int rikiavimo_pasirinkimas);
void irasymas_naudojant_list(list<Studentas>& studentai, string failo_pav, int pasirinkimas);


#endif /* v0_3_header_h */
