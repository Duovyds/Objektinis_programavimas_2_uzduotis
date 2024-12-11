/**
 * @file strategijos.h
 * @brief This header file defines the function prototypes for various strategies related
 *        to processing student data using different containers (vector or list).
 */
#ifndef strategijos_h
#define strategijos_h
#include "Header.h"
#include <stdio.h>
#include "Studentas.h"
#include "Failas.h"
#include "v0_3_header.h"


/**
 * @brief Function for processing student data with a vector using the second strategy.
 * @param failo_pavadinimas The name of the input file containing student data.
 * @param rikiavimo_pasirinkimas An integer representing the sorting criteria.
 */
void skaidymas_2_strategija_vector(string failo_pavadinimas, int rikiavimo_pasirinkimas);

/**
 * @brief Function for processing student data with a list using the second strategy.
 * @param failo_pavadinimas The name of the input file containing student data.
 * @param rikiavimo_pasirinkimas An integer representing the sorting criteria.
 */
void skaidymas_2_strategija_list(string failo_pavadinimas, int rikiavimo_pasirinkimas);

/**
 * @brief Function for processing student data with a vector using the third strategy.
 * @param failo_pavadinimas The name of the input file containing student data.
 * @param rikiavimo_pasirinkimas An integer representing the sorting criteria.
 */
void skaidymas_3_strategija_vector(string failo_pavadinimas, int rikiavimo_pasirinkimas);

/**
 * @brief Function for processing student data with a list using the second strategy.
 * @param failo_pavadinimas The name of the input file containing student data.
 * @param rikiavimo_pasirinkimas An integer representing the sorting criteria.
 */
void skaidymas_3_strategija_list(string failo_pavadinimas, int rikiavimo_pasirinkimas);

/**
 * @brief Compares two `Studentas` objects for equality.
 *
 * This operator is used to compare two `Studentas` objects, likely based on student attributes
 * such as name, surname, or grade.
 *
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return Returns `true` if both students are considered equal, otherwise `false`.
 */
bool operator==(const Studentas& a, const Studentas& b);






#endif /* strategijos_h */
