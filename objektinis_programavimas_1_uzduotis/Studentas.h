#ifndef Studentas_h
#define Studentas_h
#include "Header.h"
#include "Zmogus.h"


class Studentas : public Zmogus {
private:
    vector<int> namu_darbai;
    int egzaminas;
    float pazymiu_vidurkis;
    float mediana;
    float galutinis_vid;
    float galutinis_med;

    
public:
    // Konstruktorius
    Studentas();
    Studentas(string vardas, string pavarde, vector<int> namu_darbai, int egzaminas);
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    
    // Destruktorius
    ~Studentas();
    
    // Seteriai
    void setVardas(const string& v);
    void setPavarde(const std::string& p);
    void setNamuDarbai(const std::vector<int>& nd);
    void setEgzaminas(int egz);
    
    // Geteriai
    const std::string& getVardas() const override;
    const std::string& getPavarde() const override;
    const std::vector<int>& getNamuDarbai() const;
    int getEgzaminas() const;
    double getGalutinisVid() const;
    double getGalutinisMed() const;
    
    // Skaiciavimai
    void vidurkioSkaiciavimas();
    void medianosSkaiciavimas();
    
    // Isvesties operatorius
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    
    // Ivesties operatorius
    friend std::istream& operator>>(std::istream& is, Studentas& s);
    
    
};



vector<int> random_pazymiai(int pazymiu_sk);
void ivedimas(Studentas & Lok);
void valymas(Studentas & Lok);
bool palyginti_pavardes(const Studentas& a, const Studentas& b);
bool palyginti_vardus(const Studentas& a, const Studentas& b);
void isvedimas(vector<Studentas> studentai);
void isvedimas_su_vidurkiu(vector<Studentas> studentai);
void isvedimas_su_mediana(vector<Studentas> studentai);
vector<Studentas> skaitymas_is_failo(vector<Studentas> studentai, string failo_pav);
void irasymas(vector<Studentas>& studentai, string failo_pav, int pasirinkimas);
int random_egz();
void irasymas_list(list<Studentas>& studentai, string failo_pav, int pasirinkimas);
void isvedimas_list(list<Studentas> studentai);
bool palyginti_pazymius(const Studentas& a, const Studentas& b);
void rule_of_three_metodu_demonstracija();
void ivesties_isvesties_metodu_demonstracija();


#endif /* Studentas_h */



