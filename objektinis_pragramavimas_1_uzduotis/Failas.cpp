#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"
#include "v0_3_header.h"



// Funkcija, kuri priskiria duomenis studento strukturai ir prideda ja prie studentu vektoriaus.
vector<Studentas> studentu_generavimas(int studentu_skaicius, int namu_darbu_skaicius){
    vector<Studentas> studentai;
    Studentas temp;
    
    for (int i = 0; i < studentu_skaicius; i++) {
        temp.vardas = "Vardas" + to_string(i + 1);
        temp.pavarde = "Pavardė" + to_string(i + 1);
        temp.namu_darbai = random_pazymiai(namu_darbu_skaicius);
        temp.egzaminas = random_egz();
        temp.pazymiu_vidurkis = accumulate(temp.namu_darbai.begin(), temp.namu_darbai.end(), 0.0) / temp.namu_darbai.size();
        temp.galutinis_vid = (0.4 * temp.pazymiu_vidurkis + 0.6 * temp.egzaminas);
        studentai.push_back(temp);

        valymas(temp);
    }
    return studentai;
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



// Funkcija, kuri duomenis is vektoriaus perraso i faila, pries tai surikiavus duomenis pagal pasirinkta parametra.
void irasymas_i_faila(vector<Studentas>& studentai, int rikiavimo_pasirinkimas){
    Studentas temp = studentai.at(0);
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + "studentai" + to_string(studentai.size()) + ".txt";
    
    if (rikiavimo_pasirinkimas == 1) {
           sort(studentai.begin(), studentai.end(), palyginti_vardus);
       } else {
           sort(studentai.begin(), studentai.end(), palyginti_pavardes);
       }

    ofstream failas;
    failas.open(failo_pavadinimas);
    
    failas << left << setw(20) << "Vardas" << setw(20) << "Pavardė";
    for (int i = 1; i <= temp.namu_darbai.size(); i++) {
        failas << left << setw(17) << "ND" + to_string(i);
    }
    failas << left << setw(17) << "EGZ" << endl;
    
    for (const auto& studentas : studentai){
        failas << left << setw(20) << studentas.vardas << setw(20) << studentas.pavarde;
        for (int i = 0; i < studentas.namu_darbai.size(); i++) {
            failas << left << setw(17) << studentas.namu_darbai.at(i);
        }
        failas << left << setw(17) << studentas.egzaminas;
        failas << endl;
    }
}



// Funkcija, kuri is pagrindinio studentu vektoriaus atrenka studentus, kuriu galutinis pazymys yra mazesnis nei 5 ir iraso i atskira vektoriu.
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai){
    vector<Studentas> vargsiukai;
    
    for (const auto& studentas : studentai){
        if (studentas.galutinis_vid < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    return vargsiukai;
}



// Funkcija, kuri is pagrindinio studentu vektoriaus atrenka studentus, kuriu galutinis pazymys yra didesnis arba lygus 5 ir iraso juos i atskira vektoriu.
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai){
    
    vector<Studentas> galvociai;
    
    for (const auto& studentas : studentai){
        if (studentas.galutinis_vid >= 5) {
            galvociai.push_back(studentas);
        }
    }
    return galvociai;
}



// Funkcija, kuri sugeneruoja studentu vektoriu, iraso duomenis i pagrindini faila, tada duomenis surusiuoja ir isskaido i du atskirus failus
void generavimas_ir_isskirstymas(int studentu_skaicius, int nd_skaicius, int rikiavimo_pasirinkimas){
    vector<Studentas> stud = studentu_generavimas(studentu_skaicius, nd_skaicius);
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    irasymas_i_faila(stud, rikiavimo_pasirinkimas);
    vargsiukai = vargsiuku_atrinkimas(stud);

    galvociai = galvociu_atrinkimas(stud);
    irasymas(vargsiukai, "vargsiukai", rikiavimo_pasirinkimas);
    irasymas(galvociai, "galvociai", rikiavimo_pasirinkimas);
}



// Funkcija, kuri apskaiciuoja laika per kuri yra sugeneruojamas duomenu vektorius ir tie duomenys yra irasomi i faila
void laiko_skaiciavimas_failo_generavimas(int studentu_skaicius, int nd_skaicius, int rikiavimo_pasirinkimas){
    
    vector<Studentas> stud;
    
    vector<double> studentu_generavimas_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        stud = studentu_generavimas(studentu_skaicius, nd_skaicius);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        studentu_generavimas_laikas.push_back(answer.count());
    }
    double answer2 = accumulate(studentu_generavimas_laikas.begin(), studentu_generavimas_laikas.end(), 0.0) / studentu_generavimas_laikas.size() * 0.001;
    cout << "Failo is " << studentu_skaicius << " irasu studentu vektoriaus generavimo laikas " << answer2 << endl;

    
    
    vector<double> failu_generavimo_laikai;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas_i_faila(stud, rikiavimo_pasirinkimas);
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
    
    
    
    double temp1 = 0, temp2 = 0;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas(studentai2);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
    } else {
        temp2 = rikiavimas_pagal_pavarde_laikas(studentai2);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
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
        irasymas(vargsiukai, "vargsiukai", rikiavimo_pasirinkimas);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_vargsiukai_laikas.push_back(answer.count());
    }
    double answer5 = accumulate(irasymas_vargsiukai_laikas.begin(), irasymas_vargsiukai_laikas.end(), 0.0) / irasymas_vargsiukai_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu vargsiuku irasymas i atskira faila laikas " << answer5 << endl;
    
    
    
    vector<double> irasymas_galvociai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas(galvociai, "galvociai", rikiavimo_pasirinkimas);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_galvociai_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymas_galvociai_laikas.begin(), irasymas_galvociai_laikas.end(), 0.0) / irasymas_galvociai_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu galvociu irasymas i atskira faila laikas " << answer6 << endl;
    
    cout << "Visas programos veikimo laikas " << answer2 + temp1 + temp2 + answer3 + answer4 + answer5 + answer6 << endl;
}
