#ifndef v0_3_header_h
#define v0_3_header_h

#include "Header.h"
#include <stdio.h>
#include "Studentas.h"
#include "Failas.h"

list<Studentas> vargsiuku_atrinkimas_naudojant_list(list<Studentas>& studentai);
list<Studentas> galvociu_atrinkimas_naudojant_list(list<Studentas>& studentai);
void irasymas(list<Studentas>& studentai, string failo_pav);
void laiko_skaiciavimas_list_konteineris(string failo_pavadinimas, int rikiavimo_pasirinkimas);
void irasymas_naudojant_list(list<Studentas>& studentai, string failo_pav);

list<Studentas> skaitymas_is_failo_list(list<Studentas>& studentai, string failo_pav);
double rikiavimas_pagal_varda_laikas_list(list<Studentas> studentai);
double rikiavimas_pagal_pavarde_laikas_list(list<Studentas> studentai);
double rikiavimas_pagal_pazymius_laikas_list(list<Studentas> studentai);
void studentu_isskirstymas_list(string failo_pavadinimas);

#endif /* v0_3_header_h */
