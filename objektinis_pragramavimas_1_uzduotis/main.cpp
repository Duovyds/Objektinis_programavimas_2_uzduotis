#include "Header.h"
#include "Studentas.h"
#include "Failas.h"


int main(int argc, const char * argv[]) {
    
    vector<Studentas> studentai;
    
    try {
        cout << "Pasirinkite:" << endl;
        cout << "Duomenu nuskaitymas is failo (1), duomenu ivedimas ar generavimas (2), bandomojo failo generavimas bei operaciju laiko apskaiciavimas (3)" << endl;
        int ats_1 = 0;
        cin >> ats_1;
        
        if (cin.fail()) {
            throw invalid_argument("Ivestas simbolis nera skaicius");
        }
        
        if (ats_1 == 1) {
                studentai = skaitymas_is_failo(studentai, "kursiokai");
//                isvedimas(studentai);
                irasymas(studentai, "rez1");
        } else if (ats_1 == 2){
            try {
                int studSk;
                cout << "Iveskite studentu skaiciu\n";
                cin >> studSk;
                Studentas temp;
                
                if (cin.fail() or studSk <= 0) {
                    throw invalid_argument("Ivestas simbolis nera skaicius arba skaicius yra mazesnis arba lygus 0");
                }
                
                for (int i = 0; i < studSk; i++) {
                    ivedimas(temp);
                    studentai.push_back(temp);
                    valymas(temp);
                    }
                isvedimas(studentai);
                irasymas(studentai, "rez1");
                } catch (const invalid_argument& e) {
                    cerr << e.what() << endl;
            }
        } else if (ats_1 == 3){
            laiko_skaiciavimas(1000, 15);
        }
        else {
            throw out_of_range("Netinkamas ivestas skaicius. Pasirinktas skaicius turi buti tarp 1 ir 3 imtinai");
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    } catch (const out_of_range& e){
        cerr << e.what() << endl;
    }
    

    return 0;
}
