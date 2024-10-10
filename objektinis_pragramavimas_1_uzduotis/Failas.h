#ifndef Failas_h
#define Failas_h
#include "Header.h"


void failu_generavimas(int studentu_sk, int namu_darbu_sk);
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai);
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai);
double laiko_nustatymas_failu_generavimas( void (*func)(int, int), int studentu_sk, int nd_sk);
void laiko_skaiciavimas(int studentu_skaicius, int nd_skaicius);


#endif /* Failas_h */
