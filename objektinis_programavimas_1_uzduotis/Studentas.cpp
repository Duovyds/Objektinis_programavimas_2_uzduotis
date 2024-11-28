#include <stdio.h>
#include "Studentas.h"
#include "Header.h"
#include "v0_3_header.h"



// Konstructorius
Studentas::Studentas(){
    this->vardas = "";
    this->pavarde = "";
    this->egzaminas = 0;
    this->pazymiu_vidurkis = 0;
    this->mediana = 0;
    this->galutinis_vid = 0;
    this->galutinis_med = 0;
}


Studentas::Studentas(string vardas, string pavarde, vector<int> namu_darbai, int egzaminas){
    this->vardas = vardas;
    this->pavarde = pavarde;
    this->namu_darbai = namu_darbai;
    this->egzaminas = egzaminas;
}


// Copy konstruktorius
Studentas::Studentas(const Studentas& other)
    :  vardas(other.vardas),
       pavarde(other.pavarde),
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


// Copy operatorius
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


// Destruktorius
Studentas::~Studentas() {
    namu_darbai.clear();
}


// Seteriai
void Studentas::setVardas(const string& v) {
    vardas = v;
}

void Studentas::setPavarde(const std::string& p) {
    pavarde = p;
}

void Studentas::setNamuDarbai(const std::vector<int>& nd) {
    namu_darbai = nd;
}

void Studentas::setEgzaminas(int egz) {
    egzaminas = egz;
}


// Geteriai
const std::string& Studentas::getVardas() const {
    return vardas;
}

const std::string& Studentas::getPavarde() const {
    return pavarde;
}

const std::vector<int>& Studentas::getNamuDarbai() const {
    return namu_darbai;
}

int Studentas::getEgzaminas() const {
    return egzaminas;
}

double Studentas::getGalutinisVid() const {
    return galutinis_vid;
}

double Studentas::getGalutinisMed() const {
    return galutinis_med;
}


// Skaiciavimai
void Studentas::vidurkioSkaiciavimas(){
    if(!namu_darbai.empty()){
        pazymiu_vidurkis = accumulate(namu_darbai.begin(), namu_darbai.end(), 0.0) / namu_darbai.size();
    } else {
        pazymiu_vidurkis = 0;
    }
    galutinis_vid = 0.4 * pazymiu_vidurkis + 0.6 * egzaminas;
}

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







// Funkcija, kuri generuoja atstiktinius skaicius, juos iraso i vektoriu, o ta vektoriu grazina
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

int random_egz(){
    
    int pazymys;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10);
    
    pazymys = dis(gen);
    
    return pazymys;
}



// Funkcija, kuri iveda studentu pazymius
void ivedimas(Studentas & Lok){
    
    int ndSk = 0;
    string vardas, pavarde;
    
    cout << "Iveskite studento varda" << endl;
    cin >> vardas;
    Lok.setVardas(vardas);
    
    cout << "Iveskite studento pavarde" << endl;
    cin >> pavarde;
    Lok.setPavarde(pavarde);
    
    cout << "Pazymius norite ivesti rankiniu budu (1), generuoti automatiskai (2)" << endl;
    int ats_1 = 0;
    cin >> ats_1;
    
    vector<int> nd;
    
    if (ats_1 == 1) {
        string input;
        int p;
        cout << "Iveskite pazymius. Norint sustabdyti pazymiu ivedima iveskite zodi stop." << endl;
        cin >> input;
        while (input != "stop") {
            p = stoi(input); // String -> integer
            nd.push_back(p);
            cin >> input;
    }
        Lok.setNamuDarbai(nd);
        int egzaminas;
        
        cout << "Iveskite egzamino pazymi\n";
        cin >> egzaminas;
        Lok.setEgzaminas(egzaminas);
    } else {
        cout << "Iveskite namu darbu pazymiu skaiciu" << endl;
        cin >> ndSk;
        
        // Sugeneruojami random namu darbu pazymiai
        nd = random_pazymiai(ndSk);
        Lok.setNamuDarbai(nd);
        
        // Sugeneruojamas random egzamino pazymys
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 10);
        Lok.setEgzaminas(dis(gen));
        
    }
    
    Lok.vidurkioSkaiciavimas();
    Lok.medianosSkaiciavimas();
    
}



// Funkcija, kuri isvalo tam tikrus objekto elementus, kad nebutu rasoma salia
void valymas(Studentas& Lok) {
    Lok.setVardas("");
    Lok.setPavarde("");
    Lok.setNamuDarbai({});
}



// Funkcija, kuri palygina studentus pagal ju pavardes
bool palyginti_pavardes(const Studentas& a, const Studentas& b){
    return a.getPavarde() < b.getPavarde();
}

// Funkcija, kuri palygina studentus pagal ju vardus
bool palyginti_vardus(const Studentas& a, const Studentas& b){
    return a.getVardas() < b.getVardas();
}


bool palyginti_pazymius(const Studentas& a, const Studentas& b){
    return a.getGalutinisVid() < b.getGalutinisVid();
}



// Funkcija, kuri atspausdina studentu duomenis (galutinis apskaiciuotas ir su vidurkiu ir su mediana)
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


// Funkcija, kuri atspausdina studentu duomenis (galutinis apskaiciuotas tik su vidurkiu)
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


// Funkcija, kuri atspausdina studentu duomenis (galutinis apskaiciuotas tik su mediana)
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


// Funkcija, kuri nuskaito duomenis is failo.
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
        rez << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        rez << left << setw(20) << student.getPavarde() << setw(20) << student.getVardas()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisVid() << endl;
    }
    
    rez.close();
}



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
        rez << left << setw(20) << student.getPavarde() << setw(20) << student.getVardas()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisVid() << endl;
    }
    
    rez.close();
}



void isvedimas_list(list<Studentas> studentai){
        
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    studentai.sort(palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    studentai.sort(palyginti_vardus);
    
    cout << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)"
    << "Objekto adresas" << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(20) << student.getPavarde() << setw(20) << student.getVardas()
        << setw(20) << fixed << setprecision(2)<< student.getGalutinisVid()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisMed()
        << setw(20) << &student << endl;
    }
}
