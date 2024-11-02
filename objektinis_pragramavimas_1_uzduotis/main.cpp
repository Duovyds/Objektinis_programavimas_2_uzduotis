#include "Header.h"
#include "Studentas.h"
#include "Failas.h"
#include "v0_3_header.h"


int main(int argc, const char * argv[]) {
    
    vector<Studentas> studentai;
    list<Studentas> studentai_list;
    int pasirinkimas1 = 0;
    int studentu_skaicius = 0;
    int namu_darbu_skaicius =0;
    
    try {
        cout << "Pasirinkite:" << endl;
        cout << "Duomenu nuskaitymas is failo (1), duomenu ivedimas ar generavimas (2), failo generavimas (3), studentu isskirstymas (4), operaciju laiko apskaiciavimas (5)" << endl;
        int ats_1 = 0;
        cin >> ats_1;
        
        if (cin.fail()) {
            throw invalid_argument("Ivestas simbolis nera skaicius");
        }
        
        if (ats_1 == 1) {
                studentai = skaitymas_is_failo(studentai, "kursiokai");
//                isvedimas(studentai);
                irasymas(studentai, "rez1", 2);
        } else if (ats_1 == 2){
            try {
                int konteinerio_tipas;
                cout << "Duomenis saugoti i vector konteineri (1), duomenis saugoti i list konteineri (2)" << endl;
                cin >> konteinerio_tipas;
                
                if (konteinerio_tipas == 1) {
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
                    irasymas(studentai, "rez1", 2);
                } else if (konteinerio_tipas == 2){
                    int studSk;
                    cout << "Iveskite studentu skaiciu\n";
                    cin >> studSk;
                    Studentas temp;
                                    
                    if (cin.fail() or studSk <= 0) {
                        throw invalid_argument("Ivestas simbolis nera skaicius arba skaicius yra mazesnis arba lygus 0");
                    }
                    
                    for (int i = 0; i < studSk; i++) {
                        ivedimas(temp);
                        studentai_list.push_back(temp);
                        valymas(temp);
                    }
                    isvedimas_list(studentai_list);
                    irasymas_list(studentai_list, "rez1", 2);
                }
            } catch (const invalid_argument& e) {
                    cerr << e.what() << endl;
            }
        } else if (ats_1 == 3){
            cout << "Iveskite studentu skaiciu" << endl;
            cin >> studentu_skaicius;
            cout << "Iveskite namu darbu skaiciu" << endl;
            cin >> namu_darbu_skaicius;
            cout << "Vykdomas failo generavimo algoritmas" << endl;
            pagrindinio_failo_generavimas(studentu_skaicius, namu_darbu_skaicius);
            laiko_skaiciavimas_failo_generavimas(studentu_skaicius, namu_darbu_skaicius);
            cout << "Algoritmas baigtas." << endl;
        } else if (ats_1 == 4){
            string pasirinkimas;
            string directory = "/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis";
            string command = "ls " + directory + "/*.txt | xargs -n 1 basename";
            system(command.c_str());
            cout << endl;
            cout << "Pasirinkite kuri faila norite isskirstyti. Ivesti failo pavadinima be .txt dalies" << endl;
            cin >> pasirinkimas;
            studentu_isskirstymas(pasirinkimas);
            cout << "Algoritmas baigtas" << endl;
        } else if (ats_1 == 5){
            int konteinerio_pasirinkimas;
            cout << "Pasirinkite konteinerio tipa. (1) vector, (2) list" << endl;
            cin >> konteinerio_pasirinkimas;
            if (konteinerio_pasirinkimas == 1) {
                string pasirinkimas;
                string directory = "/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis";
                string command = "ls " + directory + "/*.txt | xargs -n 1 basename";
                system(command.c_str());
                cout << endl;
                cout << "Pasirinkite kuri faila norite testuoti. Ivesti failo pavadinima be .txt dalies" << endl;
                cin >> pasirinkimas;
                cout << "Pagal kokius parametrus norite rusiuoti studentus? (1) varda, (2) pavarde, (3) pazymius" << endl;
                cin >> pasirinkimas1;
                cout << endl;
                cout << "Paleidziamas algoritmas laiko skaiciavimui naudojant vector konteineri" << endl;
                cout << endl;
                laiko_skaiciavimas(pasirinkimas, pasirinkimas1);
                cout << "Algoritmas baigtas" << endl;
            } else {
                string pasirinkimas;
                string directory = "/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis";
                string command = "ls " + directory + "/*.txt | xargs -n 1 basename";
                system(command.c_str());
                cout << endl;
                cout << "Pasirinkite kuri faila norite testuoti. Ivesti failo pavadinima be .txt dalies" << endl;
                cin >> pasirinkimas;
                cout << "Pagal kokius parametrus norite rusiuoti studentus? (1) varda, (2) pavarde, (3) pazymius" << endl;
                cin >> pasirinkimas1;
                cout << endl;
                cout << "Paleidziamas algoritmas laiko skaiciavimui naudojant list konteineri" << endl;
                cout << endl;
                laiko_skaiciavimas_list_konteineris(pasirinkimas, pasirinkimas1);
                cout << "Algoritmas baigtas" << endl;
                
            }
        }
        else {
            throw out_of_range("Netinkamas ivestas skaicius. Pasirinktas skaicius turi buti tarp 1 ir 5 imtinai");
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    } catch (const out_of_range& e){
        cerr << e.what() << endl;
    }
    

    return 0;
}
