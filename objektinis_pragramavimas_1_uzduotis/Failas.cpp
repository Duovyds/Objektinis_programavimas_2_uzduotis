#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"



void failu_generavimas(){
    
    int studentu_sk;
    int namu_darbu_sk;
    
    
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> studentu_sk;
    cout << "Iveskite namu darbu pazymiu skaiciu: " << endl;
    cin >> namu_darbu_sk;
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + "Studentai" + to_string(studentu_sk) + ".txt";
    
    ofstream failas;
    failas.open(failo_pavadinimas);
    
    vector<int> pazymiai;
    
    failas << left << setw(17) << "Pavardė" << setw(17) << "Vardas";
    
    for (int i = 1; i <= namu_darbu_sk; i++) {
        failas << left << setw(17) << "ND" + to_string(i);
    }
    failas << left << setw(17) << "EGZ" << endl;
    failas << endl;
    
    
    for (int i = 1; i <= studentu_sk; i++){
        
        failas << left << setw(16) << "Pavarde" + to_string(i) << setw(17) << "Vardas" + to_string(i);
        
        for (int j = 1; j <= namu_darbu_sk; j++) {
            pazymiai = random_pazymiai(namu_darbu_sk);
            failas << left << setw(17) << pazymiai.at(j - 1);
        }
        int egz = random_egz();
        failas << left << setw(17) << egz << endl;
        
    }
    
    failas.close();
}
