#include "Header.h"
#include "Studentas.h"


// Sukuriame studentu objekto vektoriu
vector<Studentas> studentai;

int main(int argc, const char * argv[]) {
    
    // Jei duomenis norime nuskaityti is failo:
//    skaitymas_is_failo(studentai);
    
    // Jei duomenis norime ivesti rankiniu budu:
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
//    isvedimas_su_vidurkiu(studentai);
//    isvedimas_su_mediana(studentai);
    
    return 0;
}
