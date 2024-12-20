/**
 * @file Studentas.cpp
 * @brief Implementation of the Studentas class and related functions.
 */
#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "v0_3_header.h"
#include "Zmogus.h"


/**
 * @brief Default constructor for Studentas.
 */
Studentas::Studentas() :
Zmogus("", ""), egzaminas(0), namu_darbai() {}

/**
 * @brief Constructor with parameters for initializing a Studentas object.
 * @param vardas Student's first name.
 * @param pavarde Student's last name.
 * @param namu_darbai Vector of homework grades.
 * @param egzaminas Exam grade.
 */
Studentas::Studentas(const string vardas, const string pavarde, vector<int> namu_darbai, int egzaminas)
: Zmogus(vardas, pavarde), namu_darbai(namu_darbai), egzaminas(egzaminas) {}


/**
 * @brief Copy constructor for Studentas.
 * @param other The Studentas object to copy from.
 */
Studentas::Studentas(const Studentas& other)
    :  Zmogus(other),
       namu_darbai(other.namu_darbai),
       egzaminas(other.egzaminas),
       pazymiu_vidurkis(other.pazymiu_vidurkis),
       mediana(other.mediana),
       galutinis_vid(other.galutinis_vid),
       galutinis_med(other.galutinis_med) {
        // Tarkime, kad sukuriu 1 studentu objekta: stud1 su reiksmemis ir tada padarom stud2 = stud1 (sukuriu nauja studento objekta ir ji prilyginu stud1)
        // Be copy konstruktoriaus stud2 objekto reiksmes dalintusi reiksmiu adresais su stud1 reiksmemis. Tai gali sukelti dideliu problemu.
        // Copy konstruktorius padeda isvengti siu problemu. Jis padaro deep copy tarp objektu.
     
 }


/**
 * @brief Copy assignment operator for Studentas.
 * @param other The Studentas object to copy from.
 * @return A reference to the modified Studentas object.
 */
Studentas& Studentas::operator=(const Studentas& other) {
    if (this == &other) {
        return *this;
    }
    vardas = other.vardas;
    pavarde = other.pavarde;
    namu_darbai = other.namu_darbai;
    egzaminas = other.egzaminas;
    pazymiu_vidurkis = other.pazymiu_vidurkis;
    mediana = other.mediana;
    galutinis_vid = other.galutinis_vid;
    galutinis_med = other.galutinis_med;
    return *this;
}


/**
 * @brief Destructor for Studentas.
 */
Studentas::~Studentas() {
    namu_darbai.clear();
}


/**
 * @brief Overloaded output stream operator for Studentas.
 * @param os The output stream.
 * @param s The Studentas object to output.
 * @return A reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << left << setw(19) << s.getPavarde() << setw(20) << s.getVardas() <<
    setw(20)  << fixed << setprecision(2) << s.galutinis_vid;
        return os;
    }


/**
 * @brief Overloaded input stream operator for Studentas.
 * @param is The input stream.
 * @param s The Studentas object to populate.
 * @return A reference to the input stream.
 */
std::istream& operator>>(std::istream& is, Studentas& s) {
    cout << "Iveskite studento varda" << endl;
    is >> s.vardas;
    cout << "Iveskite studento pavarde" << endl;
    is >> s.pavarde;
    cout << "Iveskite namu darbu skaiciu" << endl;
    int x;
    is >> x;
    
    cout << "Pazmymius ivesti rankiniu budu (1), ar generuoti automatiskai (2)?" << endl;
    int pasirinkimas;
    is >> pasirinkimas;
    
    if (pasirinkimas == 1) {
        cout << "Iveskite pazymius" << endl;
        for (int i = 0; i < x; i++){
            int p;
            is >> p;
            s.namu_darbai.push_back(p);
        }
        cout << "Iveskite egzamino pazymi" << endl;
        is >> s.egzaminas;
    } else {
        s.setNamuDarbai(random_pazymiai(x));
        s.setEgzaminas(random_egz());
    }
    
    s.vidurkioSkaiciavimas();
    s.medianosSkaiciavimas();
    
    return is;
}


/**
 * @brief Sets the student's first name.
 * @param v The first name.
 */
void Studentas::setVardas(const string& v) {
    vardas = v;
}

/**
 * @brief Sets the student's last name.
 * @param p The last name.
 */
void Studentas::setPavarde(const std::string& p) {
    pavarde = p;
}

/**
 * @brief Sets the student's homework grades.
 * @param nd A vector of homework grades.
 */
void Studentas::setNamuDarbai(const std::vector<int>& nd) {
    namu_darbai = nd;
}

/**
 * @brief Sets the student's exam grade.
 * @param egz The exam grade.
 */
void Studentas::setEgzaminas(int egz) {
    egzaminas = egz;
}


/**
 * @brief Gets the student's first name.
 * @return The first name.
 */
const std::string& Studentas::getVardas() const {
    return vardas;
}

/**
 * @brief Gets the student's last name.
 * @return The last name.
 */
const std::string& Studentas::getPavarde() const {
    return pavarde;
}

/**
 * @brief Gets the student's homework grades.
 * @return A vector of homework grades.
 */
const std::vector<int>& Studentas::getNamuDarbai() const {
    return namu_darbai;
}

/**
 * @brief Gets the student's exam grade.
 * @return The exam grade.
 */
int Studentas::getEgzaminas() const {
    return egzaminas;
}

/**
 * @brief Gets the student's final grade (average-based).
 * @return The final grade.
 */
double Studentas::getGalutinisVid() const {
    return galutinis_vid;
}

/**
 * @brief Gets the student's final grade (median-based).
 * @return The final grade.
 */
double Studentas::getGalutinisMed() const {
    return galutinis_med;
}


/**
 * @brief Calculates the student's average grade.
 */
void Studentas::vidurkioSkaiciavimas(){
    if(!namu_darbai.empty()){
        pazymiu_vidurkis = accumulate(namu_darbai.begin(), namu_darbai.end(), 0.0) / namu_darbai.size();
    } else {
        pazymiu_vidurkis = 0;
    }
    galutinis_vid = 0.4 * pazymiu_vidurkis + 0.6 * egzaminas;
}

/**
 * @brief Calculates the student's median grade.
 */
void Studentas::medianosSkaiciavimas() {
    if (!namu_darbai.empty()) {
        std::sort(namu_darbai.begin(), namu_darbai.end());
        if (namu_darbai.size() % 2 != 0) {
            mediana = (float)namu_darbai[namu_darbai.size() / 2];
        } else {
            mediana = (float)(namu_darbai[(namu_darbai.size() - 1) / 2] + namu_darbai[namu_darbai.size() / 2]) / 2.0;
        }
    } else {
        mediana = 0.0;
    }
    galutinis_med = 0.4 * mediana + 0.6 * egzaminas;
}


/**
 * @brief Demonstrates the use of rule-of-three methods (constructor, copy, and assignment).
 */
void rule_of_three_metodu_demonstracija(){
    
    // Sukuriame objekta
    Studentas stud1("Jonas", "Jonaitis", {9, 5, 10}, 9);
    stud1.vidurkioSkaiciavimas();
    stud1.medianosSkaiciavimas();
    cout << "Stud1 objektas: " << endl;
    cout << stud1 << endl;
    cout << "-------------------------------------------" << endl;
    
    // Copy konstruktoriaus demonstracija
    Studentas stud2 = stud1;
    cout << "Stud2 objektas: " << endl;
    cout << stud2 << endl;
    cout << "-------------------------------------------" << endl;
    
    // Copy operatoriaus demonstracija
    Studentas stud3;
    stud3 = stud1;
    cout << "Stud3 objektas: " << endl;
    cout << stud3 << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    
    // Pakeiciam stud1 reiksmes, kad patikrinti ar veikia
    stud1 = Studentas("Petras", "Petryla", {4, 4, 6}, 7);
    stud1.vidurkioSkaiciavimas();
    stud1.medianosSkaiciavimas();
    cout << "Objektu reiksmes, kai pakeiciame stud1 reiksmes: " << endl;
    cout << endl;
    
    cout << "Stud1 objektas: " << endl;
    cout << stud1 << endl;
    cout << "-------------------------------------------" << endl;
    
    cout << "Stud2 objektas: " << endl;
    cout << stud2 << endl;
    cout << "-------------------------------------------" << endl;
    
    cout << "Stud3 objektas: " << endl;
    cout << stud3 << endl;
    cout << "-------------------------------------------" << endl;
    
};


/**
 * @brief Demonstrates input and output operators for the Studentas class.
 */
void ivesties_isvesties_metodu_demonstracija(){
    Studentas temp;
    cin >> temp;
    cout << temp;
    cout << endl;
}



/**
 * @brief Generates a vector of random grades.
 * @param pazymiu_sk Number of grades to generate.
 * @return A vector containing random grades.
 */
vector<int> random_pazymiai(int pazymiu_sk) {
    
    vector<int> random_pazymiai;
    
    random_device rd; // Remiantis sistemos laiku sugeneruoja atsitiktini skaiciu (seed). Skaicius, paleidus programa, skiriasi kiekviena karta.
    mt19937 gen(rd()); // Sugeneruoja atsitiktinius skaicius. Parametras rd() uztikrina, kad tie skaiciai kiekviena karta butu skirtingi.
    uniform_int_distribution<> dis(0, 10); // Sugeneruotus skaicius paskirsto pagal duota intervala.
    
    for (int i = 0; i < pazymiu_sk ; i++) {
        random_pazymiai.push_back(dis(gen));
    }
    return random_pazymiai;
}

/**
 * @brief Generates a random exam grade.
 * @return A random grade between 1 and 10.
 */
int random_egz(){
    
    int pazymys;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10);
    
    pazymys = dis(gen);
    
    return pazymys;
}



/**
 * @brief Function to input new students;
 * @param Lok Reference to a Studentas object.
 */
void ivedimas(Studentas & Lok){
    cin >> Lok;
    Lok.vidurkioSkaiciavimas();
    Lok.medianosSkaiciavimas();
}



/**
 * @brief Function to clear certain elements of a Studentas object.
 * Ensures no residual data is printed alongside.
 * @param Lok Reference to a Studentas object.
 */
void valymas(Studentas& Lok) {
    Lok.setVardas("");
    Lok.setPavarde("");
    Lok.setNamuDarbai({});
}



/**
 * @brief Comparator function to compare students by last names.
 * @param a First Studentas object to compare.
 * @param b Second Studentas object to compare.
 * @return True if the last name of a comes before b lexicographically.
 */
bool palyginti_pavardes(const Studentas& a, const Studentas& b){
    return a.getPavarde() < b.getPavarde();
}

/**
 * @brief Comparator function to compare students by first names.
 * @param a First Studentas object to compare.
 * @param b Second Studentas object to compare.
 * @return True if the first name of a comes before b lexicographically.
 */
bool palyginti_vardus(const Studentas& a, const Studentas& b){
    return a.getVardas() < b.getVardas();
}

/**
 * @brief Comparator function to compare students by their final grade.
 * @param a First Studentas object to compare.
 * @param b Second Studentas object to compare.
 * @return True if the final average grade of a is less than b.
 */
bool palyginti_pazymius(const Studentas& a, const Studentas& b){
    return a.getGalutinisVid() < b.getGalutinisVid();
}



/**
 * @brief Function to print student data (final grade calculated with average).
 * @param studentai Vector of Studentas objects.
 */
void isvedimas(vector<Studentas> studentai){
        
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Objekto adresas" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << student << setw(20) << &student << endl;
    }
}


/**
 * @brief Function to print student data (final grade calculated with average).
 * @param studentai Vector of Studentas objects.
 */
void isvedimas_su_vidurkiu(vector<Studentas> studentai){
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.getPavarde() << setw(15) << student.getVardas()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisVid() << endl;
    }
}


/**
 * @brief Function to print student data (final grade calculated with median).
 * @param studentai Vector of Studentas objects.
 */
void isvedimas_su_mediana(vector<Studentas> studentai){
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (med.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.getPavarde() << setw(15) << student.getVardas()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisMed() << endl;
    }
}


/**
 * @brief Reads students' data from a file.
 * @param studentai Vector of Studentas objects.
 * @param failo_pav File name to read data from.
 * @return Updated vector of Studentas objects.
 */
vector<Studentas> skaitymas_is_failo(vector<Studentas> studentai, string failo_pav){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_2_uzduotis/objektinis_programavimas_1_uzduotis/") + failo_pav + ".txt";
    
    try {
        
//        ifstream failas("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/kursiokai.txt");
        ifstream failas;
        failas.open(failo_pavadinimas);
        
        if (!failas) {
            throw runtime_error("Problemos su failo atidarymu");
        }
        
        string eilute;
        
        getline(failas, eilute);
        
        while (getline(failas, eilute)) {
            
            stringstream stream(eilute);
            Studentas temp;
            string vardas, pavarde;
            int nr;

            stream >> vardas >> pavarde;
            temp.setVardas(vardas);
            temp.setPavarde(pavarde);
            
            vector<int> nd;
            while (stream >> nr) {
                nd.push_back(nr);
            }
            
            if (!nd.empty()){
                int egz = nd.back();
                nd.pop_back();
                
                temp.setNamuDarbai(nd);
                temp.setEgzaminas(egz);
                temp.vidurkioSkaiciavimas();
                temp.medianosSkaiciavimas();
            }
            
            studentai.push_back(temp);
                    
        }
        
        failas.close();
        
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    
    return studentai;
}


/**
 * @brief Sorts and writes student data to a file.
 * @param studentai Vector of Studentas objects.
 * @param failo_pav File name to write data to.
 * @param pasirinkimas Sorting option.
 */
void irasymas(vector<Studentas>& studentai, string failo_pav, int pasirinkimas){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_2_uzduotis/objektinis_programavimas_1_uzduotis/") + failo_pav + ".txt";
    
    ofstream rez;
    rez.open(failo_pavadinimas);
    
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    if (pasirinkimas == 1) {
        sort(studentai.begin(), studentai.end(), palyginti_vardus);
    } else if (pasirinkimas == 2){
        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    }
    
    
    rez << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
        rez << "-------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        rez << student << endl;
    }
    
    rez.close();
}


/**
 * @brief Sorts and writes student data to a file.
 * @param studentai Vector of Studentas objects.
 * @param failo_pav File name to write data to.
 * @param pasirinkimas Sorting option.
 */
void irasymas_list(list<Studentas>& studentai, string failo_pav, int pasirinkimas){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_2_uzduotis/objektinis_programavimas_1_uzduotis/") + failo_pav + ".txt";
    
    ofstream rez;
    rez.open(failo_pavadinimas);
    
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    if (pasirinkimas == 1) {
//        sort(studentai.begin(), studentai.end(), palyginti_vardus);
        studentai.sort(palyginti_vardus);
    } else if (pasirinkimas == 2){
//        sort(studentai.begin(), studentai.end(), palyginti_pavardes);
        studentai.sort(palyginti_pavardes);
    }
    
    
    rez << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
        rez << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        rez << student << endl;
    }
    
    rez.close();
}


/**
 * @brief Function to print student data (final grade calculated with average).
 * @param studentai Vector of Studentas objects.
 */
void isvedimas_list(list<Studentas> studentai){
        
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    studentai.sort(palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    studentai.sort(palyginti_vardus);
    
    cout << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Objekto adresas" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << student << setw(20) << &student << endl;
    }
}
