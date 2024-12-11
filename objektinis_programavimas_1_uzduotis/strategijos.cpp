/**
 * @file strategijos.cpp
 * @brief This file contains functions for processing student data with different strategies
 *        for reading, sorting, filtering, and writing to files.
 */
#include <stdio.h>
#include <stdio.h>
#include "v0_3_header.h"
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"
#include "strategijos.h"

/**
 * @brief Compares two Studentas objects for equality.
 *
 * This function is used to compare two Studentas objects to determine if they are equal based on
 * their names and surnames. It is mainly used in the context of erasing students in the container.
 *
 * @param a The first Studentas object.
 * @param b The second Studentas object.
 * @return true if both students have the same name and surname, otherwise false.
 */
bool operator==(const Studentas& a, const Studentas& b) {
    return a.getVardas() == b.getVardas() && a.getPavarde() == b.getPavarde();
}



/**
 * @brief Splits students into two categories using strategy 2 with vector container.
 *
 * This function reads students from a file, divides them into two groups (vargsiukai and others),
 * sorts them based on a chosen criterion (name, surname, or grade), and writes them back to separate files.
 * It also measures and reports the time taken for reading, splitting, sorting, and writing the data.
 *
 * @param failo_pavadinimas The name of the input file.
 * @param rikiavimo_pasirinkimas The sorting criterion (1 for name, 2 for surname, 3 for grades).
 */
void skaidymas_2_strategija_vector(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai = skaitymas_is_failo(studentai, failo_pavadinimas);
        studentai.clear();
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    studentai = skaitymas_is_failo(studentai, failo_pavadinimas);
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() << " irasu skaitymo laikas " << answer2 << endl;
    
    
    auto t1 = high_resolution_clock::now();
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->getGalutinisVid() < 5) {
            // *it reiskia, kad i vektoriu yra pridedamas pats objektas, o ne tik reference.
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
    auto t2 = high_resolution_clock::now();
    auto answer4 = (duration_cast<milliseconds>(t2 - t1)).count() * 0.001;
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu studentu skaidymo laikas " << answer4 << endl;
    
    
    double temp1 = 0, temp2 = 0, temp3 = 0;
    double answer5;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas(studentai);
        temp1 += rikiavimas_pagal_varda_laikas(vargsiukai);
        sort(studentai.begin(), studentai.end(), palyginti_vardus);
        sort(vargsiukai.begin(), vargsiukai.end(), palyginti_vardus);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
        answer5 = temp1;
    } else if(rikiavimo_pasirinkimas == 2){
        temp2 = rikiavimas_pagal_pavarde_laikas(studentai);
        temp2 += rikiavimas_pagal_pavarde_laikas(vargsiukai);
        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
        sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pavardes);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
        answer5 = temp2;
    } else {
        temp3 = rikiavimas_pagal_pazymius_laikas(studentai);
        temp3 += rikiavimas_pagal_pazymius_laikas(vargsiukai);
        sort(studentai.begin(), studentai.end(), palyginti_pazymius);
        sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pazymius);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal pazymius didejimo tvarka " << temp3 << endl;
        answer5 = temp3;
    }
    
    
    vector<double> irasymo_laikas;
    for (int i = 0; i < 5; i ++) {
        auto t1 = high_resolution_clock::now();
        irasymas_i_faila(studentai, failo_pavadinimas);
        irasymas_i_faila(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymo_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymo_laikas.begin(), irasymo_laikas.end(), 0.0) / irasymo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu irasymas i atskira faila laikas " << answer6 << endl;
    
    
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu visas programos veikimo laikas " << answer2 + answer4 + answer5 + answer6 << endl;
}



/**
 * @brief Splits students into two categories using strategy 2 with list container.
 *
 * This function is similar to `skaidymas_2_strategija_vector` but works with the list container.
 * It reads students from a file, splits them into two groups (vargsiukai and others), sorts the groups
 * based on a selected criterion (name, surname, or grades), and writes them to separate files.
 * The function also measures and reports the time taken for reading, splitting, sorting, and writing the data.
 *
 * @param failo_pavadinimas The name of the input file.
 * @param rikiavimo_pasirinkimas The sorting criterion (1 for name, 2 for surname, 3 for grades).
 */
void skaidymas_2_strategija_list(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    list<Studentas> studentai;
    list<Studentas> vargsiukai;
    
    
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai = skaitymas_is_failo_list(studentai, failo_pavadinimas);
        studentai.clear();
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    studentai = skaitymas_is_failo_list(studentai, failo_pavadinimas);
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() << " irasu skaitymo laikas " << answer2 << endl;
    
    
    auto t1 = high_resolution_clock::now();
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->getGalutinisVid() < 5) {
            // *it reiskia, kad i vektoriu yra pridedamas pats objektas, o ne tik reference.
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
    auto t2 = high_resolution_clock::now();
    auto answer4 = (duration_cast<milliseconds>(t2 - t1)).count() * 0.001;
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu studentu skaidymo laikas " << answer4 << endl;
    
    
    double temp1 = 0, temp2 = 0, temp3 = 0;
    double answer5;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas_list(studentai);
        temp1 += rikiavimas_pagal_varda_laikas_list(vargsiukai);
        studentai.sort(palyginti_vardus);
        vargsiukai.sort(palyginti_vardus);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
        answer5 = temp1;
    } else if(rikiavimo_pasirinkimas == 2){
        temp2 = rikiavimas_pagal_pavarde_laikas_list(studentai);
        temp2 += rikiavimas_pagal_pavarde_laikas_list(vargsiukai);
        studentai.sort(palyginti_pavardes);
        vargsiukai.sort(palyginti_pavardes);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
        answer5 = temp2;
    } else {
        temp3 = rikiavimas_pagal_pazymius_laikas_list(studentai);
        temp3 += rikiavimas_pagal_pazymius_laikas_list(vargsiukai);
        studentai.sort(palyginti_pazymius);
        vargsiukai.sort(palyginti_pazymius);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal pazymius didejimo tvarka " << temp3 << endl;
        answer5 = temp3;
    }
    
    
    vector<double> irasymo_laikas;
    for (int i = 0; i < 5; i ++) {
        auto t1 = high_resolution_clock::now();
        irasymas_naudojant_list(studentai, failo_pavadinimas);
        irasymas_naudojant_list(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymo_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymo_laikas.begin(), irasymo_laikas.end(), 0.0) / irasymo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu irasymas i atskira faila laikas " << answer6 << endl;
    
    
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu visas programos veikimo laikas " << answer2 + answer4 + answer5 + answer6 << endl;
}


/**
 * @brief Splits students into two categories using strategy 3 with vector container.
 *
 * This function is based on the principles of strategy 1 but works with the vector container.
 * It reads students from a file, compares and separetes them, then sorts the them based on a selected criterion (name, surname, or grades), and writes the groups to separate files.
 * The function also measures and reports the time taken for reading, splitting, sorting, and writing the data.
 *
 * @param failo_pavadinimas The name of the input file.
 * @param rikiavimo_pasirinkimas The sorting criterion (1 for name, 2 for surname, 3 for grades).
 */
void skaidymas_3_strategija_vector(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai = skaitymas_is_failo(studentai, failo_pavadinimas);
        studentai.clear();
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    studentai = skaitymas_is_failo(studentai, failo_pavadinimas);
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() << " irasu skaitymo laikas " << answer2 << endl;
    
    
    auto t1 = high_resolution_clock::now();
    vargsiukai.reserve(studentai.size() / 2);
    // std::back_inserter(vargsiukai) iterpia studento objekta i vargsiuku konteineri, jeigu yra tenkinama salyga.
    std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai),
                 [](const Studentas& studentas) { return studentas.getGalutinisVid() < 5;} );
    
    galvociai.reserve(studentai.size() / 2);
    // std::back_inserter(galvociai) iterpia studento objekta i galvociai konteineri, jeigu yra tenkinama salyga.
    std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(galvociai),
                 [](const Studentas& studentas) { return studentas.getGalutinisVid()>= 5;} );
    auto t2 = high_resolution_clock::now();
    auto answer4 = (duration_cast<milliseconds>(t2 - t1)).count() * 0.001;
    cout << "Failo is " << studentai.size() << " irasu studentu skaidymo laikas " << answer4 << endl;
    
    
    double temp1 = 0, temp2 = 0, temp3 = 0;
    double answer5;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas(galvociai);
        temp1 += rikiavimas_pagal_varda_laikas(vargsiukai);
        sort(galvociai.begin(), galvociai.end(), palyginti_vardus);
        sort(vargsiukai.begin(), vargsiukai.end(), palyginti_vardus);
        cout << studentai.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
        answer5 = temp1;
    } else if(rikiavimo_pasirinkimas == 2){
        temp2 = rikiavimas_pagal_pavarde_laikas(galvociai);
        temp2 += rikiavimas_pagal_pavarde_laikas(vargsiukai);
        sort(galvociai.begin(), galvociai.end(), palyginti_pavardes);
        sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pavardes);
        cout << studentai.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
        answer5 = temp2;
    } else {
        temp3 = rikiavimas_pagal_pazymius_laikas(galvociai);
        temp3 += rikiavimas_pagal_pazymius_laikas(vargsiukai);
        sort(galvociai.begin(), galvociai.end(), palyginti_pazymius);
        sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pazymius);
        cout << studentai.size() << " irasu rikiavimo laikas pagal pazymius didejimo tvarka " << temp3 << endl;
        answer5 = temp3;
    }
    
    
    vector<double> irasymo_laikas;
    for (int i = 0; i < 5; i ++) {
        auto t1 = high_resolution_clock::now();
        irasymas_i_faila(galvociai, "galvociai");
        irasymas_i_faila(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymo_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymo_laikas.begin(), irasymo_laikas.end(), 0.0) / irasymo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() << " irasu irasymas i atskira faila laikas " << answer6 << endl;
    
    
    cout << "Failo is " << studentai.size() << " irasu visas programos veikimo laikas " << answer2 + answer4 + answer6 + answer5 << endl;
}


/**
 * @brief Splits students into two categories using strategy 3 with list container.
 * @param failo_pavadinimas The name of the input file.
 * @param rikiavimo_pasirinkimas The sorting criterion (1 for name, 2 for surname, 3 for grades).
 */
void skaidymas_3_strategija_list(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    list<Studentas> studentai;
    list<Studentas> vargsiukai;
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai = skaitymas_is_failo_list(studentai, failo_pavadinimas);
        studentai.clear();
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    studentai = skaitymas_is_failo_list(studentai, failo_pavadinimas);
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() << " irasu skaitymo laikas " << answer2 << endl;
    
    
    auto t1 = high_resolution_clock::now();
    // Studentus, kurie tenkina salyga, perkeliame  vargsiukai konteineri.
    std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai),
                        [](const Studentas& student) { return student.getGalutinisVid() >= 5; });
    
    // Is studentu konteinerio istriname vargsiukus
    studentai.remove_if([](const Studentas& student) { return student.getGalutinisVid() < 5; });
    auto t2 = high_resolution_clock::now();
    auto answer4 = (duration_cast<milliseconds>(t2 - t1)).count() * 0.001;
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu studentu skaidymo laikas " << answer4 << endl;
    
    
    double temp1 = 0, temp2 = 0, temp3 = 0;
    double answer5;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas_list(studentai);
        temp1 += rikiavimas_pagal_varda_laikas_list(vargsiukai);
        studentai.sort(palyginti_vardus);
        vargsiukai.sort(palyginti_vardus);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
        answer5 = temp1;
    } else if(rikiavimo_pasirinkimas == 2){
        temp2 = rikiavimas_pagal_pavarde_laikas_list(studentai);
        temp2 += rikiavimas_pagal_pavarde_laikas_list(vargsiukai);
        studentai.sort(palyginti_pavardes);
        vargsiukai.sort(palyginti_pavardes);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
        answer5 = temp2;
    } else {
        temp3 = rikiavimas_pagal_pazymius_laikas_list(studentai);
        temp3 += rikiavimas_pagal_pazymius_laikas_list(vargsiukai);
        studentai.sort(palyginti_pazymius);
        vargsiukai.sort(palyginti_pazymius);
        cout << studentai.size() + vargsiukai.size() << " irasu rikiavimo laikas pagal pazymius didejimo tvarka " << temp3 << endl;
        answer5 = temp3;
    }
    
    
    vector<double> irasymo_laikas;
    for (int i = 0; i < 5; i ++) {
        auto t1 = high_resolution_clock::now();
        irasymas_naudojant_list(studentai, failo_pavadinimas);
        irasymas_naudojant_list(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymo_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymo_laikas.begin(), irasymo_laikas.end(), 0.0) / irasymo_laikas.size() * 0.001;
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu irasymas i atskira faila laikas " << answer6 << endl;
    
    
    cout << "Failo is " << studentai.size() + vargsiukai.size() << " irasu visas programos veikimo laikas " << answer2 + answer4 + answer5 + answer6 << endl;
    
}

