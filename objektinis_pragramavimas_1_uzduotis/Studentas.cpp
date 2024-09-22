#include <stdio.h>
#include "Studentas.h"
#include "Header.h"



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
    
    
    // to be continued!!!!!!!!!!!!!!!
    
//    cout << "Duomenis norite ivesti rankiniu budu (1), ar nuskaityti is failo (2)?" << endl;
//    int ats_1 = 0;
//    if (ats_1 == 1) {
//        cout << "Pasirinktas ivedimas rankiniu budu"
//        cout << "Iveskite studento varda" << endl;
//        cin >> Lok.vardas;
//        cout << "Iveskite studento pavarde" << endl;
//        cin >> Lok.pavarde;
//        cout << "Pazymius norite ivesti rankiniu budu (1), generuoti automatiskai (2)" << endl;
//    } else if (ats_1 == 2){
//        
//    }
    
    

    
    
    
//    cout << "Ar zinote tikslu namu darbu pazymiu skaiciu? taip\ne" << endl;
//    string ats_1;
//    cin >> ats_1;
//    if (ats_1 == "taip") {
//        cout << "Iveskite namu darbu pazymiu skaiciu" << endl;
//        cin >> ndSk;
//        
//        cout << "Ar duomenis ivesite rankiniu budu (1), generuosite atsitiktinai (2) ar skaitysite is failo(2)?" << endl;
//        
//    }
    
    
    
    // Norint ivesti namu darbus nezinant ju skaiciaus, uzkomentuoti sita vieta.

    
    
    // Rankinis namu darbu ir egzamino pazymiu ivedimas:
//    string input;
//    int p;
//    cout << "Iveskite pazymius. Norint sustabdyti pazymiu ivedima iveskite zodi stop" << endl;
//    cin >> input;
//    
//    while (input != "stop") {
//        p = stoi(input);
//        Lok.namu_darbai.push_back(p);
//        cin >> input;
//    }
//    
//    cout << "Iveskite egzamino pazymi\n";
//    cin >> Lok.egzaminas;
    
    
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



// Funkcija, kuri palygina studentus pagal ju pavardes
bool palyginti_pavardes(const Studentas& a, const Studentas& b){
    return a.pavarde < b.pavarde;
}

// Funkcija, kuri palygina studentus pagal ju vardus
bool palyginti_vardus(const Studentas& a, const Studentas& b){
    return a.vardas < b.vardas;
}



// Funkcija, kuri atspausdina studentu duomenis
void isvedimas(vector<Studentas> studentai){
        
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas << setw(20) << student.galutinis_vid << setw(20) << student.galutinis_med << endl;
    }
}



void isvedimas_su_vidurkiu(vector<Studentas> studentai){
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas << setw(20) << student.galutinis_vid << endl;
    }
}



void isvedimas_su_mediana(vector<Studentas> studentai){
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (med.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas << setw(20) << student.galutinis_med << endl;
    }
}



vector<Studentas> skaitymas_is_failo(vector<Studentas> studentai){
    
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
