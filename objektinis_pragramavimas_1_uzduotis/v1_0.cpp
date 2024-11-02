#include <stdio.h>
#include "v0_3_header.h"
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"


// Si funkcija reikalinga, kad erase funkcija zinotu pagal ka lyginti studentus bandant juos istrinti.
bool operator==(const Studentas& a, const Studentas& b) {
    return a.vardas == b.vardas && a.pavarde == b.pavarde;
}



// 2 strategija
// vector konteinerio atvejis

void skaidymas_2_strategija_vector(string failo_pavadinimas){
    
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    
    studentai = skaitymas_is_failo(studentai, failo_pavadinimas);
    vargsiukai = vargsiuku_atrinkimas(studentai);
    
    
    for (const auto& vargsiukas : vargsiukai) {
        studentai.erase(
            remove(studentai.begin(), studentai.end(), vargsiukas),
            studentai.end()
        );
    }
    
    
    sort(studentai.begin(), studentai.end(), palyginti_pazymius);
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pazymius);
    
    irasymas_i_faila(studentai, "studentai1000");
    irasymas_i_faila(vargsiukai, "vargsiukai");
}



// list konteinerio atvejis
void skaidymas_2_strategija_list(string failo_pavadinimas){
    
    list<Studentas> studentai;
    list<Studentas> vargsiukai;
    
    studentai = skaitymas_is_failo_list(studentai, failo_pavadinimas);
    vargsiukai = vargsiuku_atrinkimas_naudojant_list(studentai);
    
    for (const auto& vargsiukas : vargsiukai){
        studentai.erase(
            remove(studentai.begin(), studentai.end(), vargsiukas),
            studentai.end());
    }
    
    studentai.sort(palyginti_pazymius);
    vargsiukai.sort(palyginti_pazymius);
    
    irasymas_naudojant_list(studentai, failo_pavadinimas);
    irasymas_naudojant_list(vargsiukai, "vargsiukai");
}



