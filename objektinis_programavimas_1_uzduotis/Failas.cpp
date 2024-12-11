/**
 * @file Failas.cpp
 * @brief This file contains the implementation of a program for managing and processing student data.
 */
#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"
#include "v0_3_header.h"



/**
 * @brief Generates the main file with student data including names, grades, and exam scores.
 *
 * This function generates a file that contains a list of students with their respective names,
 * grades for multiple assignments (ND), and final exam grades (EGZ). The file is saved with a
 * name based on the number of students.
 *
 * @param studentu_skaicius The number of students to generate.
 * @param nd_skaicius The number of assignments (ND) each student has.
 */
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



/**
 * @brief Writes student data to a file.
 *
 * This function writes the data to a specified file.
 *
 * @param studentai A vector of student objects to write to the file.
 * @param failo_pav The name of the file to save the student data.
 */
void irasymas_i_faila(vector<Studentas>& studentai, string failo_pav){
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_2_uzduotis/objektinis_programavimas_1_uzduotis/") +
    failo_pav + ".txt";
    
    ofstream failas;
    failas.open(failo_pavadinimas);
    
    failas << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
        failas << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        failas << student << endl;
    }
    
    failas.close();
}



/**
 * @brief Measures the time taken to sort a vector of students by first name in ascending order.
 *
 * This function calculates the average time taken to sort the students vector by their first names
 * in ascending order over multiple iterations.
 *
 * @param studentai A vector of student objects to sort.
 * @return The average time in seconds taken to sort the vector.
 */
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



/**
 * @brief Measures the time taken to sort a vector of students by last name in ascending order.
 *
 * This function calculates the average time taken to sort the students vector by their last names
 * in ascending order over multiple iterations.
 *
 * @param studentai A vector of student objects to sort.
 * @return The average time in seconds taken to sort the vector.
 */
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



/**
 * @brief Measures the time taken to sort a vector of students by their grades in ascending order.
 *
 * This function calculates the average time taken to sort the students vector by their grades
 * in ascending order over multiple iterations.
 *
 * @param studentai A vector of student objects to sort.
 * @return The average time in seconds taken to sort the vector.
 */
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



/**
 * @brief Selects students whose final grade is less than 5 and returns them in a new vector.
 *
 * This function filters out the students whose final grade is below 5 and returns them in a new vector.
 *
 * @param studentai A vector of student objects to filter.
 * @return A vector of students with final grades less than 5.
 */
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai){
    vector<Studentas> vargsiukai;
    
    for (const auto& studentas : studentai){
        if (studentas.getGalutinisVid() < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    return vargsiukai;
}



/**
 * @brief Selects students whose final grade is greater than or equal to 5 and returns them in a new vector.
 *
 * This function filters out the students whose final grade is greater than or equal to 5 and returns them in a new vector.
 *
 * @param studentai A vector of student objects to filter.
 * @return A vector of students with final grades greater than or equal to 5.
 */
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai){
    
    vector<Studentas> galvociai;
    
    for (const auto& studentas : studentai){
        if (studentas.getGalutinisVid() >= 5) {
            galvociai.push_back(studentas);
        }
    }
    return galvociai;
}


/**
 * @brief Sorts students by a selected criterion and splits them into two groups based on their final grades.
 *
 * This function allows the user to select a sorting criterion (name, last name, or grade),
 * sorts the students accordingly, then separates them into two groups based on their final grades.
 * The two groups are saved to separate files: "vargsiukai" for students with final grades below 5,
 * and "galvociai" for students with final grades 5 or higher.
 *
 * @param failo_pavadinimas The name of the file to read the students from.
 */
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



/**
 * @brief Measures the time required to generate the student data file.
 *
 * This function calculates the average time taken to generate the student data file over multiple iterations.
 *
 * @param studentu_skaicius The number of students to generate.
 * @param nd_skaicius The number of assignments (ND) each student has.
 */
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



/**
 * @brief Measures the total time taken to read, sort, and separate student data into different files.
 *
 * This function calculates the time taken to read the student data from a file, sort the students
 * by the selected criterion, separate them into two groups based on their final grades, and then
 * write the groups to separate files. It provides a detailed breakdown of each step.
 *
 * @param failo_pavadinimas The name of the file to read the students from.
 * @param rikiavimo_pasirinkimas The sorting criterion (1: by name, 2: by last name, 3: by grade).
 */
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
