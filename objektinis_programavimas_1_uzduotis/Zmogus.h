/**
 * @file Zmogus.h
 * @brief Declaration of the `Zmogus` class, a base class for representing a person entity.
 */
#ifndef Zmogus_h
#define Zmogus_h
#include "Header.h"


/**
 * @class Zmogus
 * @brief Represents a basic person entity with a name and surname.
 *
 * The `Zmogus` class provides protected attributes for a person's first name (`vardas`)
 * and last name (`pavarde`). It is designed as a base class with pure virtual methods
 * for accessing these attributes, making it abstract.
 */
class Zmogus {
protected:
    /**
     * @brief The first name of the person.
     */
    string vardas;
    
    /**
     * @brief The last name of the person.
     */
    string pavarde;

public:
    /**
     * @brief Default constructor.
     */
    Zmogus();
    
    /**
     * @brief Parameterized constructor.
     * @param vardas The first name of the person.
     * @param pavarde The last name of the person.
     */
    Zmogus(string vardas, string pavarde);
    
    /**
     * @brief Virtual destructor.
     */
    virtual ~Zmogus() = default;
    
    
    /**
     * @brief Pure virtual getter for the first name.
     * @return A constant reference to the `vardas` string.
     */
    virtual const std::string& getVardas() const = 0;
    
    /**
     * @brief Pure virtual getter for the last name.
     * @return A constant reference to the `pavarde` string.
     */
    virtual const std::string& getPavarde() const = 0;
    
};

#endif /* Zmogus_h */
