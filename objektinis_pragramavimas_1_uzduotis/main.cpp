#include "Header.h"
#include "Studentas.h"
#include "Failas.h"


int main(int argc, const char * argv[]) {
    
    vector<Studentas> studentai2;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    double answer1 = laiko_nustatymas_failu_generavimas(failu_generavimas);
    cout << "Failas sukuriamas per " << answer1 << " sec." << endl;
    
    
    studentai2 = skaitymas_is_failo(studentai2, "studentai1000");
    vargsiukai = vargsiuku_atrinkimas(studentai2);
    galvociai = galvociu_atrinkimas(studentai2);
    irasymas(vargsiukai, "vargsiukai");
    irasymas(galvociai, "galvociai");
    
    
    
    
    
    
    
    
//    vector<Studentas> studentai;
//    
//    try {
//        cout << "Pasirinkite:" << endl;
//        cout << "Duomenu nuskaitymas is failo (1), duomenu ivedimas ar generavimas (2)" << endl;
//        int ats_1 = 0;
//        cin >> ats_1;
//        
//        if (cin.fail()) {
//            throw invalid_argument("Ivestas simbolis nera skaicius");
//        }
//        
//        if (ats_1 == 1) {
//                studentai = skaitymas_is_failo(studentai);
////                isvedimas(studentai);
//                irasymas(studentai);
//        } else if (ats_1 == 2){
//            try {
//                int studSk;
//                cout << "Iveskite studentu skaiciu\n";
//                cin >> studSk;
//                Studentas temp;
//                
//                if (cin.fail() or studSk <= 0) {
//                    throw invalid_argument("Ivestas simbolis nera skaicius arba skaicius yra mazesnis arba lygus 0");
//                }
//                
//                for (int i = 0; i < studSk; i++) {
//                    ivedimas(temp);
//                    studentai.push_back(temp);
//                    valymas(temp);
//                    }
//                isvedimas(studentai);
//                irasymas(studentai);
//                } catch (const invalid_argument& e) {
//                    cerr << e.what() << endl;
//            }
//        } else {
//            throw out_of_range("Netinkamas ivestas skaicius. Pasirinktas skaicius turi buti 1 arba 2");
//        }
//    } catch (const invalid_argument& e) {
//        cerr << e.what() << endl;
//    } catch (const out_of_range& e){
//        cerr << e.what() << endl;
//    }
    

    return 0;
}
