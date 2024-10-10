#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"



void failu_generavimas(int studentu_sk, int namu_darbu_sk){

    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + "studentai" + to_string(studentu_sk) + ".txt";
    
    ofstream failas;
    failas.open(failo_pavadinimas);
    
    vector<int> pazymiai;
    
    failas << left << setw(17) << "Vardas" << setw(17) << "Pavardė";
    
    for (int i = 1; i <= namu_darbu_sk; i++) {
        failas << left << setw(17) << "ND" + to_string(i);
    }
    failas << left << setw(17) << "EGZ" << endl;
    
    
    for (int i = 1; i <= studentu_sk; i++){

        failas << left << setw(17) << ("Vardas" + to_string(i)) << setw(17) << ("Pavardė" + to_string(i));
        
        for (int j = 1; j <= namu_darbu_sk; j++) {
            pazymiai = random_pazymiai(namu_darbu_sk);
            failas << left << setw(17) << pazymiai.at(j - 1);
        }
        int egz = random_egz();
        failas << left << setw(17) << egz << endl;
    }
    
    
    
    failas.close();
}



vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai){
    
    vector<Studentas> vargsiukai;
    
    for (const auto& studentas : studentai){
        if (studentas.galutinis_vid < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    return vargsiukai;
}



vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai){
    
    vector<Studentas> galvociai;
    
    for (const auto& studentas : studentai){
        if (studentas.galutinis_vid >= 5) {
            galvociai.push_back(studentas);
        }
    }
    return galvociai;
}



double laiko_nustatymas_failu_generavimas(void(*func)(int, int), int studentu_sk, int nd_sk){
    
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    
    vector<Studentas> studentai2;
    vector<double> failu_generavimo_laikai;
    // Pirmas parametras nurodo studentu skaiciu, antras - pazymiu skaiciu.
//    int studentu_sk = 1000;
//    int nd_sk = 5;

        for (int i = 0; i < 5; i++) {
            auto t1 = high_resolution_clock::now();
            failu_generavimas(studentu_sk, nd_sk);
            auto t2 = high_resolution_clock::now();
            auto answer1 = duration_cast<milliseconds>(t2 - t1);
            failu_generavimo_laikai.push_back(answer1.count());
        }
    
//    for (const auto& laikas : failu_generavimo_laikai){
//        cout << laikas << endl;
//    }
    
    double answer = accumulate(failu_generavimo_laikai.begin(), failu_generavimo_laikai.end(), 0.0) / failu_generavimo_laikai.size() * 0.001;
//    cout << "Studentu skaicius: " << studentu_sk << endl;
    
    return answer;
}



void laiko_skaiciavimas(int studentu_skaicius, int nd_skaicius){
    
    vector<Studentas> studentai2;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    
    
    double answer1 = laiko_nustatymas_failu_generavimas(failu_generavimas, studentu_skaicius, nd_skaicius);
    cout << "Failo is " << studentu_skaicius << " irasu generavimo laikas " << answer1 << endl;
    
    
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai2 = skaitymas_is_failo(studentai2, "studentai1000");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu skaitymo laikas " << answer2 << endl;
    
    
    
    vector<double> vargsiuku_atrinkimas_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        vargsiukai = vargsiuku_atrinkimas(studentai2);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        vargsiuku_atrinkimas_laikas.push_back(answer.count());
    }
    double answer3 = accumulate(vargsiuku_atrinkimas_laikas.begin(), vargsiuku_atrinkimas_laikas.end(), 0.0) / vargsiuku_atrinkimas_laikas.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu vargsiuku atrinkimo laikas " << answer3 << endl;
    
    
    
    vector<double> galvociu_atrinkimo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        galvociai = galvociu_atrinkimas(studentai2);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        galvociu_atrinkimo_laikas.push_back(answer.count());
    }
    double answer4 = accumulate(galvociu_atrinkimo_laikas.begin(), galvociu_atrinkimo_laikas.end(), 0.0) / galvociu_atrinkimo_laikas.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu galvociu atrinkimo laikas " << answer4 << endl;
    
    
    
    vector<double> irasymas_vargsiukai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_vargsiukai_laikas.push_back(answer.count());
    }
    double answer5 = accumulate(irasymas_vargsiukai_laikas.begin(), irasymas_vargsiukai_laikas.end(), 0.0) / irasymas_vargsiukai_laikas.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu vargsiuku irasymas i atskira faila laikas " << answer5 << endl;
    
    
    
    vector<double> irasymas_galvociai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas(galvociai, "galvociai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_galvociai_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymas_galvociai_laikas.begin(), irasymas_galvociai_laikas.end(), 0.0) / irasymas_galvociai_laikas.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu galvociu irasymas i atskira faila laikas " << answer6 << endl;
    
    
    
}
