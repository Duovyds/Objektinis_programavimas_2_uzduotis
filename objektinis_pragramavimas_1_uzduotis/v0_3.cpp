#include "v0_3_header.h"
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
        studentai.sort(palyginti_vardus);
//        sort(studentai.begin(), studentai.end(), palyginti_vardus);
    } else if (pasirinkimas == 2){
        studentai.sort(palyginti_pavardes);
//        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
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



void laiko_skaiciavimas_list_konteineris(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    vector<Studentas> studentai2;
    list<Studentas> vargsiukai;
    list<Studentas> galvociai;
    
    
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
            vargsiukai = vargsiuku_atrinkimas_naudojant_list(studentai2);
            auto t2 = high_resolution_clock::now();
            auto answer = duration_cast<milliseconds>(t2 - t1);
            vargsiuku_atrinkimas_laikas.push_back(answer.count());
        }
    double answer3 = accumulate(vargsiuku_atrinkimas_laikas.begin(), vargsiuku_atrinkimas_laikas.end(), 0.0) / vargsiuku_atrinkimas_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu vargsiuku atrinkimo laikas naudojant list konteineri " << answer3 << endl;

    
    vector<double> galvociu_atrinkimo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        galvociai = galvociu_atrinkimas_naudojant_list(studentai2);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        galvociu_atrinkimo_laikas.push_back(answer.count());
    }
    double answer4 = accumulate(galvociu_atrinkimo_laikas.begin(), galvociu_atrinkimo_laikas.end(), 0.0) / galvociu_atrinkimo_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu galvociu atrinkimo laikas naudojant list konteineri " << answer4 << endl;
    
    
}
