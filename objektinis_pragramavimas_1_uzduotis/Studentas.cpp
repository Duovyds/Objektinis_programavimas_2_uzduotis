#include <stdio.h>
#include "Studentas.h"
#include "Header.h"


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



// Funkcija, kuri iveda studentu pazymius
void ivedimas(Studentas & Lok){
    
    int ndSk = 0;
    
    cout << "Iveskite studento varda" << endl;
    cin >> Lok.vardas;
    cout << "Iveskite studento pavarde" << endl;
    cin >> Lok.pavarde;
    cout << "Pazymius norite ivesti rankiniu budu (1), generuoti automatiskai (2)" << endl;
    int ats_1 = 0;
    cin >> ats_1;
    if (ats_1 == 1) {
        string input;
        int p;
        cout << "Iveskite pazymius. Norint sustabdyti pazymiu ivedima iveskite zodi stop." << endl;
        cin >> input;
        while (input != "stop") {
            p = stoi(input); // String -> integer
            Lok.namu_darbai.push_back(p);
            cin >> input;
    }
        cout << "Iveskite egzamino pazymi\n";
        cin >> Lok.egzaminas;
    } else {
        cout << "Iveskite namu darbu pazymiu skaiciu" << endl;
        cin >> ndSk;
        
        // Sugeneruojami random namu darbu pazymiai
        Lok.namu_darbai = random_pazymiai(ndSk);
        
        // Sugeneruojamas random egzamino pazymys
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 10);
        Lok.egzaminas = dis(gen);
        
    }
    
    Lok.pazymiu_vidurkis = accumulate(Lok.namu_darbai.begin(), Lok.namu_darbai.end(), 0.0) / Lok.namu_darbai.size();
    Lok.galutinis_vid = (0.4 * Lok.pazymiu_vidurkis + 0.6 * Lok.egzaminas);
    
    sort(Lok.namu_darbai.begin(), Lok.namu_darbai.end());
    
    if (ndSk % 2 != 0) {
        Lok.mediana = (float)Lok.namu_darbai[ndSk / 2];
    }else {
        Lok.mediana = (float)(Lok.namu_darbai[(ndSk - 1) / 2] + Lok.namu_darbai[ndSk / 2]) / 2.0;
    }
    
    Lok.galutinis_med = 0.4 * Lok.mediana + 0.6 * Lok.egzaminas;
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



// Funkcija, kuri atspausdina studentu duomenis (galutinis apskaiciuotas ir su vidurkiu ir su mediana)
void isvedimas(vector<Studentas> studentai){
        
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas
        << setw(20) << fixed << setprecision(2)<< student.galutinis_vid
        << setw(20) << fixed << setprecision(2) << student.galutinis_med << endl;
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
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas
        << setw(20) << fixed << setprecision(2) << student.galutinis_vid << endl;
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
        cout << left << setw(14) << student.pavarde << setw(15) << student.vardas
        << setw(20) << fixed << setprecision(2) << student.galutinis_med << endl;
    }
}


// Funkcija, kuri nuskaito duomenis is failo.
vector<Studentas> skaitymas_is_failo(vector<Studentas> studentai){
    
    
    try {
        
        ifstream failas("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/kursiokai.txt");
        
        if (!failas) {
            throw runtime_error("Problemos su failo atidarymu");
        }
        
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
            
            temp.pazymiu_vidurkis = accumulate(temp.namu_darbai.begin(), temp.namu_darbai.end(), 0.0) / temp.namu_darbai.size();
            temp.galutinis_vid = (0.4 * temp.pazymiu_vidurkis + 0.6 * temp.egzaminas);
            
            sort(temp.namu_darbai.begin(), temp.namu_darbai.end());
            
            if (temp.namu_darbai.size() % 2 != 0) {
                temp.mediana = (float)temp.namu_darbai[temp.namu_darbai.size() / 2];
            }else {
                temp.mediana = (float)(temp.namu_darbai[(temp.namu_darbai.size() - 1) / 2] + temp.namu_darbai[temp.namu_darbai.size() / 2]) / 2.0;
            }
            
            temp.galutinis_med = 0.4 * temp.mediana + 0.6 * temp.egzaminas;
            
            studentai.push_back(temp);
            valymas(temp);
                    
        }
        
        failas.close();
        
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    
    return studentai;
}



void irasymas(vector<Studentas> studentai){
    
    ofstream rez("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/rez1.txt");
    
    // Funkcija, kuri rusiuoja studentus pagal ju pavardes didejimo tvarka. (Tvarka galima pakeisti palyginti_pavardes funkcijos viduje).
    sort(studentai.begin(), studentai.end(), palyginti_pavardes);
    // Funkcija, kuri rusiuoja studentus pagal ju vardus didejimo tvarka. (Tvarka galima pakeisti palyginti_vardus funkcijos viduje).
//    sort(studentai.begin(), studentai.end(), palyginti_vardus);
    
    rez << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << endl;
        rez << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        rez << left << setw(14) << student.pavarde << setw(15) << student.vardas
        << setw(20) << fixed << setprecision(2) << student.galutinis_vid
        << setw(20) << fixed << setprecision(2) << student.galutinis_med << endl;
    }
    
    rez.close();
}
