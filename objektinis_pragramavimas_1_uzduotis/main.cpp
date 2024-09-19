#include <iostream>
#include <vector> // vektoriaus<> sukurimui
#include <numeric>
#include <cmath> // round() funkcijos naudojimui
#include <algorithm>
#include <iomanip>
#include <random> // Atsitiktiniu skaiciu generavimui

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
    cout << "Iveskite namu darbu skaiciu" << endl;
    cin >> ndSk;
    
    // Rankinis duomenu ivedimas:
    //        cout << "Iveskite pazymius\n";
    //        for (int j = 0; j < ndSk; j++) {
    //            int pazymys;
    //            cin >> pazymys;
    //            temp.namu_darbai.push_back(pazymys);
    //        }
    //
    //        cout << "Iveskite egzamino pazymi\n";
    //        cin >> temp.egzaminas;
    
    
    // Atsitiktiniu pazymiu generavimas
    Lok.namu_darbai = random_pazymiai(ndSk);
    
    // Atsitiktinio egzamino pazymio generavimas
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10);
    
    Lok.egzaminas = dis(gen);
    
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
        cout << "Pavardė" << "       " << "Vardas" << "       " << "Galutinis (vid.)" << "      " << "Galutinis (med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        for (const auto& student: studentai) {
            cout << student.pavarde << "       " << student.vardas << "       " << student.galutinis_vid << "      " <<
                student.galutinis_med << endl;
        }
}


int main(int argc, const char * argv[]) {
    
    
    int studSk;
    cout << "Iveskite studentu skaiciu\n";
    cin >> studSk;
    Studentas temp;
    
    for (int i = 0; i < studSk; i++) {
        ivedimas(temp);
        studentai.push_back(temp);
        valymas(temp);
    }
    
    isvedimas(studentai);
    
    
    return 0;
}
