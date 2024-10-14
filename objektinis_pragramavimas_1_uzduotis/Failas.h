#ifndef Failas_h
#define Failas_h
#include "Header.h"


//void failu_generavimas(int studentu_sk, int namu_darbu_sk);
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai);
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai);
//double laiko_nustatymas_failu_generavimas( void (*func)(int, int), int studentu_sk, int nd_sk);
void laiko_skaiciavimas(string failo_pavadinimas, int rikiavimo_pasirinkimas);
vector<Studentas> studentu_generavimas(int studentu_skaicius, int namu_darbu_skaicius);
void irasymas_i_faila(vector<Studentas>& studentai, int rikiavimo_pasirinkimas);
double rikiavimas_pagal_varda_laikas(vector<Studentas> studentai);
double rikiavimas_pagal_pavarde_laikas(vector<Studentas> studentai);
void generavimas_ir_isskirstymas(int studentu_skaicius, int nd_skaicius, int rikiavimo_pasirinkimas);
void laiko_skaiciavimas_failo_generavimas(int studentu_skaicius, int nd_skaicius, int rikiavimo_pasirinkimas);


#endif /* Failas_h */
