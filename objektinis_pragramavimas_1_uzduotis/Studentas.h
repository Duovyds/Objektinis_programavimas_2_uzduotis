#ifndef Studentas_h
#define Studentas_h
#include "Header.h"

// Sukuriame studento objekta
struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
    float pazymiu_vidurkis;
    float mediana;
    float galutinis_vid;
    float galutinis_med;
};



vector<int> random_pazymiai(int pazymiu_sk);
void ivedimas(Studentas & Lok);
void valymas(Studentas & Lok);
bool palyginti_pavardes(const Studentas& a, const Studentas& b);
bool palyginti_vardus(const Studentas& a, const Studentas& b);
void isvedimas(vector<Studentas> studentai);
void isvedimas_su_vidurkiu(vector<Studentas> studentai);
void isvedimas_su_mediana(vector<Studentas> studentai);
vector<Studentas> skaitymas_is_failo(vector<Studentas> studentai, string failo_pav);
void irasymas(vector<Studentas> studentai, string failo_pav);
int random_egz();



#endif /* Studentas_h */
