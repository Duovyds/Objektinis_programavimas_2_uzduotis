/**
 * @file Studentas.h
 * @brief Declaration of the `Studentas` class.
 */
#ifndef Studentas_h
#define Studentas_h

#include "Header.h"
#include "Zmogus.h"

/**
 * @class Studentas
 * @brief Represents a student, inheriting from the Zmogus class.
 */
class Studentas : public Zmogus {
private:
    /**
     * @brief Stores homework grades of the student.
     */
    vector<int> namu_darbai;

    /**
     * @brief Exam grade of the student.
     */
    int egzaminas;

    /**
     * @brief Average grade of the student.
     */
    float pazymiu_vidurkis;

    /**
     * @brief Median grade of the student.
     */
    float mediana;

    /**
     * @brief Final grade based on average calculation.
     */
    float galutinis_vid;

    /**
     * @brief Final grade based on median calculation.
     */
    float galutinis_med;

public:
    /**
     * @brief Default constructor.
     */
    Studentas();

    /**
     * @brief Parameterized constructor.
     * @param vardas Student's first name.
     * @param pavarde Student's last name.
     * @param namu_darbai Homework grades.
     * @param egzaminas Exam grade.
     */
    Studentas(string vardas, string pavarde, vector<int> namu_darbai, int egzaminas);

    /**
     * @brief Copy constructor.
     * @param other Another Studentas object to copy from.
     */
    Studentas(const Studentas& other);

    /**
     * @brief Copy assignment operator.
     * @param other Another Studentas object to assign from.
     * @return Reference to the assigned Studentas object.
     */
    Studentas& operator=(const Studentas& other);

    /**
     * @brief Destructor.
     */
    ~Studentas();

    /**
     * @brief Sets the student's first name.
     * @param v First name.
     */
    void setVardas(const string& v);

    /**
     * @brief Sets the student's last name.
     * @param p Last name.
     */
    void setPavarde(const std::string& p);

    /**
     * @brief Sets the student's homework grades.
     * @param nd Vector of homework grades.
     */
    void setNamuDarbai(const std::vector<int>& nd);

    /**
     * @brief Sets the student's exam grade.
     * @param egz Exam grade.
     */
    void setEgzaminas(int egz);

    /**
     * @brief Gets the student's first name.
     * @return First name.
     */
    const std::string& getVardas() const override;

    /**
     * @brief Gets the student's last name.
     * @return Last name.
     */
    const std::string& getPavarde() const override;

    /**
     * @brief Gets the student's homework grades.
     * @return Vector of homework grades.
     */
    const std::vector<int>& getNamuDarbai() const;

    /**
     * @brief Gets the student's exam grade.
     * @return Exam grade.
     */
    int getEgzaminas() const;

    /**
     * @brief Gets the student's final grade based on average calculation.
     * @return Final grade based on average.
     */
    double getGalutinisVid() const;

    /**
     * @brief Gets the student's final grade based on median calculation.
     * @return Final grade based on median.
     */
    double getGalutinisMed() const;

    /**
     * @brief Calculates the average grade of the student.
     */
    void vidurkioSkaiciavimas();

    /**
     * @brief Calculates the median grade of the student.
     */
    void medianosSkaiciavimas();

    /**
     * @brief Output stream operator for Studentas.
     * @param os Output stream.
     * @param s Studentas object.
     * @return Output stream with student information.
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    /**
     * @brief Input stream operator for Studentas.
     * @param is Input stream.
     * @param s Studentas object.
     * @return Input stream with student information.
     */
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

/**
 * @brief Generates random grades for a student.
 * @param pazymiu_sk Number of grades to generate.
 * @return Vector of random grades.
 */
vector<int> random_pazymiai(int pazymiu_sk);

/**
 * @brief Inputs student information.
 * @param Lok Studentas object to populate.
 */
void ivedimas(Studentas & Lok);

/**
 * @brief Cleans up the student data.
 * @param Lok Studentas object to clear.
 */
void valymas(Studentas & Lok);

/**
 * @brief Compares two students by last name.
 * @param a First student.
 * @param b Second student.
 * @return True if a's last name is less than b's.
 */
bool palyginti_pavardes(const Studentas& a, const Studentas& b);

/**
 * @brief Compares two students by first name.
 * @param a First student.
 * @param b Second student.
 * @return True if a's first name is less than b's.
 */
bool palyginti_vardus(const Studentas& a, const Studentas& b);

/**
 * @brief Outputs a list of students.
 * @param studentai Vector of students to output.
 */
void isvedimas(vector<Studentas> studentai);

/**
 * @brief Outputs students with their final grade based on average.
 * @param studentai Vector of students to output.
 */
void isvedimas_su_vidurkiu(vector<Studentas> studentai);

/**
 * @brief Outputs students with their final grade based on median.
 * @param studentai Vector of students to output.
 */
void isvedimas_su_mediana(vector<Studentas> studentai);

/**
 * @brief Reads students from a file.
 * @param studentai Vector to store read students.
 * @param failo_pav File name to read from.
 * @return Vector of students.
 */
vector<Studentas> skaitymas_is_failo(vector<Studentas> studentai, string failo_pav);

/**
 * @brief Writes student data to a file.
 * @param studentai Vector of students to write.
 * @param failo_pav File name to write to.
 * @param pasirinkimas Option for file writing.
 */
void irasymas(vector<Studentas>& studentai, string failo_pav, int pasirinkimas);

/**
 * @brief Generates a random exam grade.
 * @return Random exam grade.
 */
int random_egz();

/**
 * @brief Writes student data to a file using a list.
 * @param studentai List of students to write.
 * @param failo_pav File name to write to.
 * @param pasirinkimas Option for file writing.
 */
void irasymas_list(list<Studentas>& studentai, string failo_pav, int pasirinkimas);

/**
 * @brief Outputs a list of students.
 * @param studentai List of students to output.
 */
void isvedimas_list(list<Studentas> studentai);

/**
 * @brief Compares two students by their grades.
 * @param a First student.
 * @param b Second student.
 * @return True if a's grades are less than b's.
 */
bool palyginti_pazymius(const Studentas& a, const Studentas& b);

/**
 * @brief Demonstrates the rule of three methods.
 */
void rule_of_three_metodu_demonstracija();

/**
 * @brief Demonstrates input and output methods.
 */
void ivesties_isvesties_metodu_demonstracija();

#endif /* Studentas_h */

