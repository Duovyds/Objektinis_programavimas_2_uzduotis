#include "v0_3.hpp"
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"



list<Studentas> vargsiuku_atrinkimas_naudojant_list(vector<Studentas>& studentai){
    list<Studentas> vargsiukai;
    
    for (const auto& studentas : studentai){
        if (studentas.galutinis_vid < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    return vargsiukai;
}



list<Studentas> galvociu_atrinkimas_naudojant_list(vector<Studentas>& studentai){
    list<Studentas> galvociai;
    
    for (const auto& studentas : studentai){
        if(studentas.galutinis_vid >= 5){
            galvociai.push_back(studentas);
        }
    }
    return galvociai;
}



void irasymas(list<Studentas>& studentai, string failo_pav, int pasirinkimas){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + failo_pav + ".txt";
    
    ofstream rez;
    rez.open(failo_pavadinimas);
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    if (pasirinkimas == 1) {
        sort(studentai.begin(), studentai.end(), palyginti_vardus);
    } else if (pasirinkimas == 2){
        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    }
    
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
    rez << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
        rez << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        rez << left << setw(20) << student.pavarde << setw(20) << student.vardas
        << setw(20) << fixed << setprecision(2) << student.galutinis_vid << endl;
    }
    
    rez.close();
}
