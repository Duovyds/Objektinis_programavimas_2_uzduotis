#ifndef Failas_h
#define Failas_h
#include "Header.h"


vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai);
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai);
void laiko_skaiciavimas(string failo_pavadinimas, int rikiavimo_pasirinkimas);
void irasymas_i_faila(vector<Studentas>& studentai, string failo_pav);
double rikiavimas_pagal_varda_laikas(vector<Studentas> studentai);
double rikiavimas_pagal_pavarde_laikas(vector<Studentas> studentai);
void laiko_skaiciavimas_failo_generavimas(int studentu_skaicius, int nd_skaicius);

void pagrindinio_failo_generavimas(int studentu_skaicius, int nd_skaicius);
void studentu_isskirstymas(string failo_pavadinimas);
double rikiavimas_pagal_pazymius_laikas(vector<Studentas> studentai);


#endif /* Failas_h */
