/**
 * @file Zmogus.cpp
 * @brief Implementation of the `Zmogus` class, representing a basic person entity.
 */
#include <stdio.h>
#include "Zmogus.h"
#include "Header.h"


/**
 * @brief Default constructor for the `Zmogus` class.
 *
 * Initializes the `Zmogus` object with empty strings for the first name (`vardas`)
 * and last name (`pavarde`).
 */
Zmogus::Zmogus() : vardas(""), pavarde("") {}

/**
 * @brief Parameterized constructor for the `Zmogus` class.
 *
 * Initializes the `Zmogus` object with specified first name (`vardas`)
 * and last name (`pavarde`).
 *
 * @param vardas The first name of the person.
 * @param pavarde The last name of the person.
 */
Zmogus::Zmogus(string vardas, string pavarde): vardas(vardas), pavarde(pavarde) {}
