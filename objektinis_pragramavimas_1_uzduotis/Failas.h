#ifndef Failas_h
#define Failas_h
#include "Header.h"


void failu_generavimas(int studentu_sk, int namu_darbu_sk);
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas> studentai);
vector<Studentas> galvociu_atrinkimas(vector<Studentas> studentai);
double laiko_nustatymas_failu_generavimas( void (*func)(int, int));


#endif /* Failas_h */
