#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

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


vector<Studentas> studentai;

int main(int argc, const char * argv[]) {
    
    int studSk;
    
    cout << "Iveskite studentu skaiciu\n";
    cin >> studSk;
    
    for (int i = 0; i < studSk; i++) {
        Studentas temp;
        int ndSk = 0;
        cout << "Iveskite studento varda\n";
        cin >> temp.vardas;
        cout << "Iveskite studento pavarde\n";
        cin >> temp.pavarde;
        cout << "Iveskite namu darbu pazymiu skaiciu\n";
        cin >> ndSk;
        cout << "Iveskite pazymius\n";
        
        for (int j = 0; j < ndSk; j++) {
            int pazymys;
            cin >> pazymys;
            temp.namu_darbai.push_back(pazymys);
        }
        
        cout << "Iveskite egzamino pazymi\n";
        cin >> temp.egzaminas;
        
        temp.pazymiu_vidurkis = round((accumulate(temp.namu_darbai.begin(), temp.namu_darbai.end(), 0.0) / temp.namu_darbai.size()) * 100) / 100;
        
        temp.galutinis_vid = round((0.4 * temp.pazymiu_vidurkis + 0.6 * temp.egzaminas) * 100) / 100;
        
        
        sort(temp.namu_darbai.begin(), temp.namu_darbai.end());
        
        if (ndSk % 2 != 0) {
            temp.mediana = (float)temp.namu_darbai[ndSk / 2];
        }else {
            temp.mediana = (float)(temp.namu_darbai[(ndSk - 1) / 2] + temp.namu_darbai[ndSk / 2]) / 2.0;
        }
        
        temp.galutinis_med = round((0.4 * temp.mediana + 0.6 * temp.egzaminas) * 100) / 100;
        
        studentai.push_back(temp);
    }
    
    
    
    
    
    
    
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
        
        
        
    //  Sutvarkyti formatavima.
        cout << "Pavardė" << "       " << "Vardas" << "       " << "Galutinis (vid.)" << "      " << "Galutinis (med.)" << endl;
        cout << "------------------------------------------------------" << endl;
        for (const auto& student: studentai) {
            cout << student.pavarde << "       " << student.vardas << "       " << student.galutinis_vid << "      " <<
                student.galutinis_med << endl;
        }
    
    
    return 0;
}


