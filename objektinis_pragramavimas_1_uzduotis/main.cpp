#include <iostream>
#include <vector> // vektoriaus<> sukurimui
#include <numeric>
#include <cmath> // round() funkcijos naudojimui
#include <algorithm>
#include <iomanip> // setw() funkcijos naudojimui
#include <random> // Atsitiktiniu skaiciu generavimui
#include <fstream> // Skaitymui is failo
#include <sstream>
#include <string>
#include <cstdlib> // stoi() funkcijos naudojimui

using namespace std;

// Sukuriame studento objekta
struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
    float pazymiu_vidurkis;
    float mediana;
    float galutinis_vid;
    float galutinis_med;
};

// Sukuriame studentu objekto vektoriu
vector<Studentas> studentai;


// Funkcija, kuri generuoja atstiktinius skaicius, juos iraso i vektoriu, o ta vektoriu grazina
vector<int> random_pazymiai(int pazymiu_sk) {
    
    vector<int> random_pazymiai;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10);
    
    for (int i = 0; i < pazymiu_sk ; i++) {
        random_pazymiai.push_back(dis(gen));
    }
    return random_pazymiai;
}



// Funkcija, kuri iveda studentu pazymius
void ivedimas(Studentas & Lok){
    int ndSk = 0;
    
    cout << "Iveskite studento varda" << endl;
    cin >> Lok.vardas;
    cout << "Iveskite studento pavarde" << endl;
    cin >> Lok.pavarde;
    
    
    // Rankinis namu darbu ir egzamino pazymiu ivedimas:
    string input;
    int p;
    cout << "Iveskite pazymius. Norint sustabdyti pazymiu ivedima iveskite zodi stop" << endl;
    cin >> input;
    
    while (input != "stop") {
        p = stoi(input);
        Lok.namu_darbai.push_back(p);
        cin >> input;
    }
    
    cout << "Iveskite egzamino pazymi\n";
    cin >> Lok.egzaminas;
    
    
    // Atsitiktiniu namu darbu ir egzamino pazymiu generavimas
//    Lok.namu_darbai = random_pazymiai(ndSk);
    
    // Atsitiktinio egzamino pazymio generavimas
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dis(0, 10);
//    Lok.egzaminas = dis(gen);
    
    Lok.pazymiu_vidurkis = round((accumulate(Lok.namu_darbai.begin(), Lok.namu_darbai.end(), 0.0) / Lok.namu_darbai.size()) * 100) / 100;
    Lok.galutinis_vid = round((0.4 * Lok.pazymiu_vidurkis + 0.6 * Lok.egzaminas) * 100) / 100;
    
    sort(Lok.namu_darbai.begin(), Lok.namu_darbai.end());
    
    if (ndSk % 2 != 0) {
        Lok.mediana = (float)Lok.namu_darbai[ndSk / 2];
    }else {
        Lok.mediana = (float)(Lok.namu_darbai[(ndSk - 1) / 2] + Lok.namu_darbai[ndSk / 2]) / 2.0;
    }
    
    Lok.galutinis_med = round((0.4 * Lok.mediana + 0.6 * Lok.egzaminas) * 100) / 100;
}

// Funkcija, kuri isvalo tam tikrus objekto elementus, kad nebutu rasoma salia
void valymas(Studentas & Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.namu_darbai.clear();
}


// Funkcija, kuri atspausdina studentu duomenis
void isvedimas(vector<Studentas> studentai){
    
    for (const auto& student : studentai) {
            cout << "\nStudento vardas: " << student.vardas;
            cout << "\nStudento pavarde: " << student.pavarde;
            cout << "\nNamu darbu pazymiai: ";
                for (int grade : student.namu_darbai) {
                    cout << grade << " ";
                }
            cout << "\nPazymiu vidurkis: " << student.pazymiu_vidurkis;
            cout << "\nEgzamino pazymys: " << student.egzaminas;
            cout << "\nGalutinis (vid.): " << student.galutinis_vid;
            cout << "\nGalutinis (med.): " << student.galutinis_med << endl;
        }
        
        cout << endl;
        
        
    //  Sutvarkyti formatavima
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas << setw(20) << student.galutinis_vid << setw(20) << student.galutinis_med << endl;
    }
}


void isvedimas_su_vidurkiu(vector<Studentas> studentai){
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas << setw(20) << student.galutinis_vid << endl;
    }
}


void isvedimas_su_mediana(vector<Studentas> studentai){
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (med.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas << setw(20) << student.galutinis_med << endl;
    }
}



vector<Studentas> skaitymas_is_failo(){
    
    ifstream failas("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/kursiokai.txt");
    string eilute;
    int nr;
    Studentas temp;
    
    getline(failas, eilute);
    
    while (getline(failas, eilute)) {
        
        stringstream stream(eilute);

        stream >> temp.vardas >> temp.pavarde;
        
        while (stream >> nr) {
            temp.namu_darbai.push_back(nr);
        }
        
        temp.egzaminas = temp.namu_darbai.back();
        temp.namu_darbai.pop_back();
        
        temp.pazymiu_vidurkis = round((accumulate(temp.namu_darbai.begin(), temp.namu_darbai.end(), 0.0) / temp.namu_darbai.size()) * 100) / 100;
        temp.galutinis_vid = round((0.4 * temp.pazymiu_vidurkis + 0.6 * temp.egzaminas) * 100) / 100;
        
        sort(temp.namu_darbai.begin(), temp.namu_darbai.end());
        
        if (temp.namu_darbai.size() % 2 != 0) {
            temp.mediana = (float)temp.namu_darbai[temp.namu_darbai.size() / 2];
        }else {
            temp.mediana = (float)(temp.namu_darbai[(temp.namu_darbai.size() - 1) / 2] + temp.namu_darbai[temp.namu_darbai.size() / 2]) / 2.0;
        }
        
        temp.galutinis_med = round((0.4 * temp.mediana + 0.6 * temp.egzaminas) * 100) / 100;
        
        studentai.push_back(temp);
        valymas(temp);
        
    }
    
    failas.close();
    
    return studentai;
}


int main(int argc, const char * argv[]) {
    
    
    
    // Jei duomenis norime nuskaityti is failu:
    skaitymas_is_failo();
//    isvedimas(studentai);
    
    
    // Jei duomenis norime ivesti rankiniu budu:
//    int studSk;
//    cout << "Iveskite studentu skaiciu\n";
//    cin >> studSk;
//    Studentas temp;
//    for (int i = 0; i < studSk; i++) {
//        ivedimas(temp);
//        studentai.push_back(temp);
//        valymas(temp);
//    }
    
    isvedimas(studentai);
//    isvedimas_su_vidurkiu(studentai);
//    isvedimas_su_mediana(studentai);
    
    return 0;
}
