#include "v0_3_header.h"
#include "Studentas.h"
#include "Header.h"
#include "Failas.h"



// Funkcija, kuri nuskaito duomenis is failo.
list<Studentas> skaitymas_is_failo_list(list<Studentas>& studentai, string failo_pav){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + failo_pav + ".txt";
    
    try {
        ifstream failas;
        failas.open(failo_pavadinimas);
        
        if (!failas) {
            throw runtime_error("Problemos su failo atidarymu");
        }
        
        string eilute;
        getline(failas, eilute);
        
        while (getline(failas, eilute)) {
            stringstream stream(eilute);
            Studentas temp;
            string vardas, pavarde;
            int nr;
            
            stream >> vardas >> pavarde;
            temp.setVardas(vardas);
            temp.setPavarde(pavarde);
            
            vector<int> nd;
            while (stream >> nr) {
                nd.push_back(nr);
            }
            
            if (!nd.empty()){
                int egz = nd.back();
                nd.pop_back();
                
                temp.setNamuDarbai(nd);
                temp.setEgzaminas(egz);
                
                temp.vidurkioSkaiciavimas();
                temp.medianosSkaiciavimas();
            }
            
            studentai.push_back(temp);
//            valymas(temp);
                    
        }
        
        failas.close();
        
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    
    return studentai;
}




list<Studentas> vargsiuku_atrinkimas_naudojant_list(list<Studentas>& studentai){
    list<Studentas> vargsiukai;
    for (const auto& studentas : studentai){
        if (studentas.getGalutinisVid() < 5) {
            vargsiukai.push_back(studentas);
        }
    }
    return vargsiukai;
}



list<Studentas> galvociu_atrinkimas_naudojant_list(list<Studentas>& studentai){
    list<Studentas> galvociai;
    for (const auto& studentas : studentai){
        if(studentas.getGalutinisVid() >= 5){
            galvociai.push_back(studentas);
        }
    }
    return galvociai;
}



// Funkcija, kuri paskaiciuoja laika per kuri yra surikiuojamas studentu vektorius pagal vardus didejimo tvarka.
double rikiavimas_pagal_varda_laikas_list(list<Studentas> studentai){
    vector<double> laikai;
    
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai.sort(palyginti_vardus);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        laikai.push_back(answer.count());
    }
    double answer = accumulate(laikai.begin(), laikai.end(), 0.0) / laikai.size() * 0.001;
    return answer;
}



// Funkcija, kuri paskaiciuoja laika per kuri yra surikiuojamas studentu vektorius pagal pavardes didejimo tvarka.
double rikiavimas_pagal_pavarde_laikas_list(list<Studentas> studentai){
    vector<double> laikai;
    
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai.sort(palyginti_pavardes);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        laikai.push_back(answer.count());
    }
    double answer = accumulate(laikai.begin(), laikai.end(), 0.0) / laikai.size() * 0.001;
    return answer;
}



// Funkcija, kuri paskaiciuoja laika per kuri yra surikiuojamas studentu vektorius pagal pazymius didejimo tvarka.
double rikiavimas_pagal_pazymius_laikas_list(list<Studentas> studentai){
    vector<double> laikai;
    
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai.sort(palyginti_pazymius);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        laikai.push_back(answer.count());
    }
    double answer = accumulate(laikai.begin(), laikai.end(), 0.0) / laikai.size() * 0.001;
    return answer;
}



//void irasymas(list<Studentas>& studentai, string failo_pav){
//    
//    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + failo_pav + ".txt";
//    ofstream rez;
//    rez.open(failo_pavadinimas);
//    
//    rez << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
//        rez << "-----------------------------------------------------------------" << endl;
//    for (const auto& student: studentai) {
//        rez << left << setw(20) << student.pavarde << setw(20) << student.vardas
//        << setw(20) << fixed << setprecision(2) << student.galutinis_vid << endl;
//    }
//    
//    rez.close();
//}



void irasymas_naudojant_list(list<Studentas>& studentai, string failo_pav){
    
    string failo_pavadinimas = string("/Users/dovydaskr/Documents/C++/objektinis_pragramavimas_1_uzduotis/objektinis_pragramavimas_1_uzduotis/") + failo_pav + ".txt";
    
    ofstream rez;
    rez.open(failo_pavadinimas);
    
    rez << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
        rez << "-----------------------------------------------------------------" << endl;
    for (const auto& student: studentai) {
        rez << left << setw(20) << student.getPavarde() << setw(20) << student.getVardas()
        << setw(20) << fixed << setprecision(2) << student.getGalutinisVid() << endl;
    }
    
    rez.close();
}



void studentu_isskirstymas_list(string failo_pavadinimas){
    
    list<Studentas> studentai;
    list<Studentas> vargsiukai;
    list<Studentas> galvociai;
    int rikiavimo_pasirinkimas;
    
    studentai = skaitymas_is_failo_list(studentai, failo_pavadinimas);
    
    cout << "Studentus rikiuoti pagal: varda (1), pavarde (2), galutini pazymi (3)" << endl;
    cin >> rikiavimo_pasirinkimas;
    cout << "Vykdoma programa..." << endl;
    
    if (rikiavimo_pasirinkimas == 1) {
        studentai.sort(palyginti_vardus);
    } else if (rikiavimo_pasirinkimas == 2){
        studentai.sort(palyginti_pavardes);
    } else {
        studentai.sort(palyginti_pazymius);
    }
    
    vargsiukai = vargsiuku_atrinkimas_naudojant_list(studentai);
    galvociai = galvociu_atrinkimas_naudojant_list(studentai);
    
    irasymas_naudojant_list(vargsiukai, "vargsiukai");
    irasymas_naudojant_list(galvociai, "galvociai");
}



void laiko_skaiciavimas_list_konteineris(string failo_pavadinimas, int rikiavimo_pasirinkimas){
    
    list<Studentas> studentai2;
    list<Studentas> vargsiukai;
    list<Studentas> galvociai;
    
    
    vector<double> skaitymas_is_failo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        studentai2 = skaitymas_is_failo_list(studentai2, failo_pavadinimas);
        studentai2.clear();
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        skaitymas_is_failo_laikas.push_back(answer.count());
    }
    studentai2 = skaitymas_is_failo_list(studentai2, failo_pavadinimas);
    double answer2 = accumulate(skaitymas_is_failo_laikas.begin(), skaitymas_is_failo_laikas.end(), 0.0) / skaitymas_is_failo_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu skaitymo laikas " << answer2 << endl;
    
    
    double temp1 = 0, temp2 = 0, temp3 = 0;
    if (rikiavimo_pasirinkimas == 1) {
        temp1 = rikiavimas_pagal_varda_laikas_list(studentai2);
        studentai2.sort(palyginti_vardus);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal varda didejimo tvarka " << temp1 << endl;
    } else if (rikiavimo_pasirinkimas == 2){
        temp2 = rikiavimas_pagal_pavarde_laikas_list(studentai2);
        studentai2.sort(palyginti_pavardes);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal pavarde didejimo tvarka " << temp2 << endl;
    } else {
        temp3 = rikiavimas_pagal_pazymius_laikas_list(studentai2);
        studentai2.sort(palyginti_pazymius);
        cout << studentai2.size() << " irasu rikiavimo laikas pagal pazymius didejimo tvarka " << temp3 << endl;
    }
    
    
    vector<double> vargsiuku_atrinkimas_laikas;
        for (int i = 0; i < 5; i++) {
            auto t1 = high_resolution_clock::now();
            vargsiukai = vargsiuku_atrinkimas_naudojant_list(studentai2);
            auto t2 = high_resolution_clock::now();
            auto answer = duration_cast<milliseconds>(t2 - t1);
            vargsiuku_atrinkimas_laikas.push_back(answer.count());
        }
    double answer3 = accumulate(vargsiuku_atrinkimas_laikas.begin(), vargsiuku_atrinkimas_laikas.end(), 0.0) / vargsiuku_atrinkimas_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu vargsiuku atrinkimo laikas naudojant list konteineri " << answer3 << endl;

    
    vector<double> galvociu_atrinkimo_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        galvociai = galvociu_atrinkimas_naudojant_list(studentai2);
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        galvociu_atrinkimo_laikas.push_back(answer.count());
    }
    double answer4 = accumulate(galvociu_atrinkimo_laikas.begin(), galvociu_atrinkimo_laikas.end(), 0.0) / galvociu_atrinkimo_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu galvociu atrinkimo laikas naudojant list konteineri " << answer4 << endl;
    
    
    vector<double> irasymas_vargsiukai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas_naudojant_list(vargsiukai, "vargsiukai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_vargsiukai_laikas.push_back(answer.count());
    }
    double answer5 = accumulate(irasymas_vargsiukai_laikas.begin(), irasymas_vargsiukai_laikas.end(), 0.0) / irasymas_vargsiukai_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu vargsiuku irasymas i atskira faila laikas " << answer5 << endl;
    
    
    vector<double> irasymas_galvociai_laikas;
    for (int i = 0; i < 5; i++) {
        auto t1 = high_resolution_clock::now();
        irasymas_naudojant_list(galvociai, "galvociai");
        auto t2 = high_resolution_clock::now();
        auto answer = duration_cast<milliseconds>(t2 - t1);
        irasymas_galvociai_laikas.push_back(answer.count());
    }
    double answer6 = accumulate(irasymas_galvociai_laikas.begin(), irasymas_galvociai_laikas.end(), 0.0) / irasymas_galvociai_laikas.size() * 0.001;
    cout << "Failo is " << studentai2.size() << " irasu galvociu irasymas i atskira faila laikas " << answer6 << endl;
    
    cout << "Visas programos veikimo laikas " << answer2 + temp1 + temp2 + temp3 + answer3 + answer4 + answer5 + answer6 << endl;
}
