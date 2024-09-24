#include "Header.h"
#include "Studentas.h"


int main(int argc, const char * argv[]) {
    
    vector<Studentas> studentai;
    
    cout << "Pasirinkite:" << endl;
    cout << "Duomenu nuskaitymas is failo (1), duomenu ivedimas ar generavimas (2)" << endl;
    int ats_1 = 0;
    cin >> ats_1;
    if (ats_1 == 1) {
        studentai = skaitymas_is_failo(studentai);
        isvedimas(studentai);
        irasymas(studentai);
    } else {
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
        irasymas(studentai);
    }
    

    return 0;
}
