/**
 * @file v0_3_header.h
 * @brief Function declarations for processing student data using `std::list`.
 */
#ifndef v0_3_header_h
#define v0_3_header_h
#include "Header.h"
#include <stdio.h>
#include "Studentas.h"
#include "Failas.h"



/**
 * @brief Filters students into a list of "vargsiukai" (students with low grades).
 *
 * @param studentai The list of students to filter.
 * @return A list of "vargsiukai" students.
 */
list<Studentas> vargsiuku_atrinkimas_naudojant_list(list<Studentas>& studentai);

/**
 * @brief Filters students into a list of "galvociai" (students with high grades).
 *
 * @param studentai The list of students to filter.
 * @return A list of "galvociai" students.
 */
list<Studentas> galvociu_atrinkimas_naudojant_list(list<Studentas>& studentai);

/**
 * @brief Writes student data to a file.
 *
 * @param studentai The list of students to write.
 * @param failo_pav The name of the file (excluding the extension).
 */
void irasymas(list<Studentas>& studentai, string failo_pav);

/**
 * @brief Measures execution times for list operations, including sorting and filtering.
 *
 * @param failo_pavadinimas The name of the file containing student data (excluding the extension).
 * @param rikiavimo_pasirinkimas The sorting criteria (1 for name, 2 for surname, 3 for grades).
 */
void laiko_skaiciavimas_list_konteineris(string failo_pavadinimas, int rikiavimo_pasirinkimas);

/**
 * @brief Writes student data to a file using a `std::list`.
 *
 * @param studentai The list of students to write.
 * @param failo_pav The name of the file (excluding the extension).
 */
void irasymas_naudojant_list(list<Studentas>& studentai, string failo_pav);

/**
 * @brief Reads student data from a file into a `std::list`.
 *
 * @param studentai The list to populate with student data.
 * @param failo_pav The name of the file (excluding the extension).
 * @return The populated list of students.
 */
list<Studentas> skaitymas_is_failo_list(list<Studentas>& studentai, string failo_pav);

/**
 * @brief Measures the time required to sort students by name in ascending order.
 *
 * @param studentai The list of students to sort.
 * @return The average sorting time in seconds.
 */
double rikiavimas_pagal_varda_laikas_list(list<Studentas> studentai);

/**
 * @brief Measures the time required to sort students by surname in ascending order.
 *
 * @param studentai The list of students to sort.
 * @return The average sorting time in seconds.
 */
double rikiavimas_pagal_pavarde_laikas_list(list<Studentas> studentai);

/**
 * @brief Measures the time required to sort students by grades in ascending order.
 *
 * @param studentai The list of students to sort.
 * @return The average sorting time in seconds.
 */
double rikiavimas_pagal_pazymius_laikas_list(list<Studentas> studentai);

/**
 * @brief Processes and segregates students into "vargsiukai" and "galvociai" categories,
 *        then writes the results to separate files.
 *
 * @param failo_pavadinimas The name of the file containing student data (excluding the extension).
 */
void studentu_isskirstymas_list(string failo_pavadinimas);

#endif /* v0_3_header_h */
