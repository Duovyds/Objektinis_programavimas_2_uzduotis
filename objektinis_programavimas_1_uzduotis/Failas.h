/**
 * @file Failas.h
 * @brief Header file containing function declarations for managing student data and performing file operations.
 */
#ifndef Failas_h
#define Failas_h
#include "Header.h"

/**
 * @brief Filters students with a final grade less than 5 into a separate vector.
 * @param studentai A vector of students to filter.
 * @return A vector of students with a final grade less than 5.
 */
vector<Studentas> vargsiuku_atrinkimas(vector<Studentas>& studentai);

/**
 * @brief Filters students with a final grade of 5 or higher into a separate vector.
 * @param studentai A vector of students to filter.
 * @return A vector of students with a final grade of 5 or higher.
 */
vector<Studentas> galvociu_atrinkimas(vector<Studentas>& studentai);

/**
 * @brief Calculates and prints the time required for file reading, sorting, and filtering operations.
 * @param failo_pavadinimas The name of the file containing student data.
 * @param rikiavimo_pasirinkimas The criterion for sorting (1: name, 2: surname, 3: grade).
 */
void laiko_skaiciavimas(string failo_pavadinimas, int rikiavimo_pasirinkimas);

/**
 * @brief Writes student data to a file.
 * @param studentai A vector of students to be written to the file.
 * @param failo_pav The base name of the file to be written.
 */
void irasymas_i_faila(vector<Studentas>& studentai, string failo_pav);

/**
 * @brief Measures the time required to sort the student data by name.
 * @param studentai A vector of students to be sorted.
 * @return The time taken to perform the sorting, in seconds.
 */
double rikiavimas_pagal_varda_laikas(vector<Studentas> studentai);

/**
 * @brief Measures the time required to sort the student data by surname.
 * @param studentai A vector of students to be sorted.
 * @return The time taken to perform the sorting, in seconds.
 */
double rikiavimas_pagal_pavarde_laikas(vector<Studentas> studentai);

/**
 * @brief Measures the time required for file generation.
 * @param studentu_skaicius The number of students.
 * @param nd_skaicius The number of assignments.
 */
void laiko_skaiciavimas_failo_generavimas(int studentu_skaicius, int nd_skaicius);

/**
 * @brief Generates the main student data file.
 * @param studentu_skaicius The number of students to include in the file.
 * @param nd_skaicius The number of assignments for each student.
 */
void pagrindinio_failo_generavimas(int studentu_skaicius, int nd_skaicius);

/**
 * @brief Sorts students and divides them into two separate files based on their final grades.
 * @param failo_pavadinimas The name of the file containing the student data to be processed.
 */
void studentu_isskirstymas(string failo_pavadinimas);

/**
 * @brief Measures the time required to sort the student data by grades.
 * @param studentai A vector of students to be sorted.
 * @return The time taken to perform the sorting, in seconds.
 */
double rikiavimas_pagal_pazymius_laikas(vector<Studentas> studentai);


#endif /* Failas_h */
