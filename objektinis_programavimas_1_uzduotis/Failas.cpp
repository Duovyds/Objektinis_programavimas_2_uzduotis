#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"
#include "v0_3_header.h"



void pagrindinio_failo_generavimas(int studentu_skaicius, int nd_skaicius){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_2_uzduotis/objektinis_programavimas_1_uzduotis/") +
    "studentai" + to_string(studentu_skaicius) + ".txt";
    vector<int> nd_pazymiai;
    ofstream rez;
    rez.open(failo_pavadinimas);
    
    rez << left << setw(20) << "Vardas" << setw(20) << "Pavardė";
    for (int i = 0; i < nd_skaicius; i++) {
        rez << left << setw(8) << "ND" + to_string(i + 1);
    }
    rez << left << setw(8) << "EGZ" << endl;
    
    for (int i = 0; i < studentu_skaicius; i++) {
        nd_pazymiai = random_pazymiai(nd_skaicius);
        rez << left << setw(20) << "Vardas" + to_string(i + 1)
        << setw(20) << "Pavardė" + to_string(i + 1);
        for (int j = 0; j < nd_skaicius; j++) {
            rez << left << setw(8) << nd_pazymiai.at(j);
        }
        rez << left << setw(8) << random_egz() << endl;
    }
    rez.close();
}



// Funkcija, kuri duomenis is vektoriaus perraso i faila, pries tai surikiavus duomenis pagal pasirinkta parametra.
void irasymas_i_faila(vector<Studentas>& studentai, string failo_pav){
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_2_uzduotis/objektinis_programavimas_1_uzduotis/") +
    failo_pav + ".txt";
    
    ofstream failas;
    failas.open(failo_pavadinimas);
    
    failas << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
        failas << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        failas << left << setw(20) << student.getPavarde() << setw(20) << student.getVardas()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisVid() << endl;
    }
    
    failas.close();
}



// Funkcija, kuri paskaiciuoja laika per kuri yra surikiuojamas studentu vektorius pagal vardus didejimo tvarka.
double rikiavimas_pagal_varda_laikas(vector<Studentas> studentai){
    vector<double> laikai;
    
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        sort(studentai.begin(), studentai.end(), palyginti_vardus);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        laikai.push_back(answer.count());
    }
    double answer = accumulate(laikai.begin(), laikai.end(), 0.0) / laikai.size() * 0.001;
    return answer;
}



// Funkcija, kuri paskaiciuoja laika per kuri yra surikiuojamas studentu vektorius pagal pavardes didejimo tvarka.
double rikiavimas_pagal_pavarde_laikas(vector<Studentas> studentai){
    vector<double> laikai;
    
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        laikai.push_back(answer.count());
    }
    double answer = accumulate(laikai.begin(), laikai.end(), 0.0) / laikai.size() * 0.001;
    return answer;
}



// Funkcija, kuri paskaiciuoja laika per kuri yra surikiuojamas studentu vektorius pagal pavardes didejimo tvarka.
double rikiavimas_pagal_pazymius_laikas(vector<Studentas> studentai){
    vector<double> laikai;
    
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        sort(studentai.begin(), studentai.end(), palyginti_pazymius);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        laikai.push_back(answer.count());
    }
    double answer = accumulate(laikai.begin(), laikai.end(), 0.0) / laikai.size() * 0.001;
    return answer;
}



// Funkcija, kuri is pagrindinio studentu vektoriaus atrenka studentus, kuriu galutinis pazymys yra mazesnis nei 5 ir iraso i atskira vektoriu.
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai){
    vector<Studentas> vargsiukai;
    
    for (const auto& studentas : studentai){
        if (studentas.getGalutinisVid() < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    return vargsiukai;
}



// Funkcija, kuri is pagrindinio studentu vektoriaus atrenka studentus, kuriu galutinis pazymys yra didesnis arba lygus 5 ir iraso juos i atskira vektoriu.
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai){
    
    vector<Studentas> galvociai;
    
    for (const auto& studentas : studentai){
        if (studentas.getGalutinisVid() >= 5) {
            galvociai.push_back(studentas);
        }
    }
    return galvociai;
}



void studentu_isskirstymas(string failo_pavadinimas){
    
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    int rikiavimo_pasirinkimas;
    
    studentai = skaitymas_is_failo(studentai, failo_pavadinimas);
    
    cout << "Studentus rikiuoti pagal: varda (1), pavarde (2), galutini pazymi (3)" << endl;
    cin >> rikiavimo_pasirinkimas;
    cout << "Vykdoma programa..." << endl;
    
    if (rikiavimo_pasirinkimas == 1) {
        sort(studentai.begin(), studentai.end(), palyginti_vardus);
    } else if (rikiavimo_pasirinkimas == 2){
        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    } else {
        sort(studentai.begin(), studentai.end(), palyginti_pazymius);
    }
    
    vargsiukai = vargsiuku_atrinkimas(studentai);
    galvociai = galvociu_atrinkimas(studentai);
    
    irasymas_i_faila(vargsiukai, "vargsiukai");
    irasymas_i_faila(galvociai, "galvociai");
}



// Funkcija, kuri apskaiciuoja laika per kuri yra sugeneruojamas duomenu vektorius ir tie duomenys yra irasomi i faila
void laiko_skaiciavimas_failo_generavimas(int studentu_skaicius, int nd_skaicius){

    vector<double> failu_generavimo_laikai;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        pagrindinio_failo_generavimas(studentu_skaicius, nd_skaicius);
        auto t2 = high_resolution_clock::now();
        auto answer1 = duration_cast<milliseconds>(t2 - t1);
        failu_generavimo_laikai.push_back(answer1.count());
    }
    double answer1 = accumulate(failu_generavimo_laikai.begin(), failu_generavimo_laikai.end(), 0.0) / failu_generavimo_laikai.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu generavimo laikas " << answer1 << endl;
}



// Funkcija, kuri apskaiciuoja vidutini laika per kuri duomenys yra nuskaitomi, surusiuojami ir isskaidomi i atskirus failus pagal parinktus kriterijus
void laiko_skaiciavimas(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    vector<Studentas> studentai2;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai2 = skaitymas_is_failo(studentai2, failo_pavadinimas);
        studentai2.clear();
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    studentai2 = skaitymas_is_failo(studentai2, failo_pavadinimas);
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu skaitymo laikas " << answer2 << endl;
    
    
    
    double temp1 = 0, temp2 = 0, temp3 = 0;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas(studentai2);
//        sort(studentai2.begin(), studentai2.end(), palyginti_vardus);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
    } else if(rikiavimo_pasirinkimas == 2){
        temp2 = rikiavimas_pagal_pavarde_laikas(studentai2);
//        sort(studentai2.begin(), studentai2.end(), palyginti_pavardes);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
    } else {
        temp3 = rikiavimas_pagal_pazymius_laikas(studentai2);
//        sort(studentai2.begin(), studentai2.end(), palyginti_pazymius);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal pazymius didejimo tvarka " << temp3 << endl;
    }
    
    
    
    vector<double> vargsiuku_atrinkimas_laikas;
        for (int i = 0; i < 5; i++) {
            auto t1 = high_resolution_clock::now();
            vargsiukai = vargsiuku_atrinkimas(studentai2);
            auto t2 = high_resolution_clock::now();
            auto answer = duration_cast<milliseconds>(t2 - t1);
            vargsiuku_atrinkimas_laikas.push_back(answer.count());
        }
    double answer3 = accumulate(vargsiuku_atrinkimas_laikas.begin(), vargsiuku_atrinkimas_laikas.end(), 0.0) / vargsiuku_atrinkimas_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu vargsiuku atrinkimo laikas " << answer3 << endl;
    
    
    
    vector<double> galvociu_atrinkimo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        galvociai = galvociu_atrinkimas(studentai2);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        galvociu_atrinkimo_laikas.push_back(answer.count());
    }
    double answer4 = accumulate(galvociu_atrinkimo_laikas.begin(), galvociu_atrinkimo_laikas.end(), 0.0) / galvociu_atrinkimo_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu galvociu atrinkimo laikas " << answer4 << endl;
    
    
    
    vector<double> irasymas_vargsiukai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas_i_faila(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_vargsiukai_laikas.push_back(answer.count());
    }
    double answer5 = accumulate(irasymas_vargsiukai_laikas.begin(), irasymas_vargsiukai_laikas.end(), 0.0) / irasymas_vargsiukai_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu vargsiuku irasymas i atskira faila laikas " << answer5 << endl;
    
    
    
    vector<double> irasymas_galvociai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas_i_faila(galvociai, "galvociai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_galvociai_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymas_galvociai_laikas.begin(), irasymas_galvociai_laikas.end(), 0.0) / irasymas_galvociai_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu galvociu irasymas i atskira faila laikas " << answer6 << endl;
    
    cout << "Visas programos veikimo laikas " << answer2 + temp1 + temp2 + temp3 + answer3 + answer4 + answer5 + answer6 << endl;
}
