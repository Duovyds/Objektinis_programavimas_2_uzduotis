# Objektinis programavimas
# 1 užduotis.


## Programos aprašymas:
Programa skirta darbui su studentų duomenimis.
Programa suteikia naudotojui galimybę duomenis nuskaityti iš failo, juos įvesti rankiniu būdu arba sugeneruoti atsitiktiniu būdu, duomenis išskirstyti į atskirus failus remiantis studentų galutiniais pažymiais. Taip pat yra galimybė įvertinti kiekvienos funkcijos veikimo greitį.


## v0.1
### Funkcijos:
- Duomenų skaitymas iš failo;
- Rankinis duomenų įvedimas;
- Duomenų rūšiavimas;
- Išimčių tvarkymas.

 Ši programos versija suteikia naudotojui keletą primityvių įrankių darbui su studentų duomenimis.


## v0.2
### Funkcijos:
- Visos v0.1 funkcijos;
- Duomenų failo generavimas;
- Didesnis kriterijų pasirinkimas duomenų rūšiavimui;
- Duomenų skaidymas į atskirus failus remiantis studentų galutinių pažymių rezultatais;
- Programos spartos analizė (naudojant vector konteinerį darbui su duomenimis).

Ši programos versija suteikia naudotojui platesnį diapozoną įrankių darbui su duomenimis.

### Veikimo spartos analizė:

<img width="577" alt="Screenshot 2024-11-03 at 00 10 59" src="https://github.com/user-attachments/assets/f810c8cb-1e4d-45c5-9085-d26620a9c207">

<img width="577" alt="Screenshot 2024-11-03 at 00 17 08" src="https://github.com/user-attachments/assets/ee5207da-12fa-4de6-97e8-3698bebb1d2f">

<img width="577" alt="Screenshot 2024-11-03 at 00 17 55" src="https://github.com/user-attachments/assets/b67e45a7-85d2-47a1-bba7-f3c4daf2a366">

<img width="577" alt="Screenshot 2024-11-03 at 00 18 41" src="https://github.com/user-attachments/assets/ded15c7e-0311-41aa-831f-835cb8de06c1">

<img width="577" alt="Screenshot 2024-11-03 at 00 30 34" src="https://github.com/user-attachments/assets/658d45f8-6949-4063-bcec-65c7f1fc7278">


## v0.3
### Funkcijos:
- Visos v0.2 funkcijos;
- Rankinio duomenų įvedimo metu, į ekraną papildomai išvedamas ir objekto adresas;
- Programos spartos analizė su pasirinktu konteineriu darbui su duomenimis (vector arba list).

Ši programos versija suteikia galimybę platesnei spartos analizei. T.y., galimybę įvertinti programos spartą priklausomai nuo pasirinkto konteinerio darbui su duomenimis.

### Veikimo spartos analizė:

<img width="577" alt="Screenshot 2024-11-03 at 14 00 33" src="https://github.com/user-attachments/assets/6e19801e-406c-4621-9feb-9814a28aca24">

<img width="577" alt="Screenshot 2024-11-03 at 14 00 53" src="https://github.com/user-attachments/assets/754ae28e-0c4f-440c-8ba8-35e8b1459feb">

<img width="630" alt="Screenshot 2024-11-03 at 14 15 42" src="https://github.com/user-attachments/assets/1ad9f7ff-cbb7-4463-a61b-7a9c499236c0">

<img width="630" alt="Screenshot 2024-11-03 at 14 03 19" src="https://github.com/user-attachments/assets/420c59e4-d8cb-47dd-adad-23f87e14fe26">

<img width="630" alt="Screenshot 2024-11-03 at 14 08 52" src="https://github.com/user-attachments/assets/0fa6a9d3-a9d4-43ef-a882-c72951250079">


## v1.0
### Funkcijos:
- Visos v0.3 funkcijos;
- Galimybė studentų atrinkimą atlikti pagal pasirinktą strategiją.

Ši programos versija suteikia galimybę naudotojui pačiam pasirinkti studentų atrinkimo strategiją, konteinerį duomenims saugoti.





## Strategijų spartos analizės rezultatai
### Strategija nr.1:

Strategijos idėja: bendro studentų konteinerio skaidymas į du atskirus: "vargšiukų" ir "galvočių". Tokiu būdu tas pats studentas yra ir pradiniame konteineryje ir savo kategorijos konteineryje. Toks algoritmas yra neefektyvus užimamos atminties atžvilgiu.

Žemiau pateikta lentelė vaizduoja programos spartą, priklausomai nuo pasirinkto konteinerio tipo (vector arba list) ir studentų skaičiaus.

<img width="1367" alt="Screenshot 2024-11-03 at 15 22 03" src="https://github.com/user-attachments/assets/e70b68cc-203c-469a-9295-29e2b3c0c3fa">

Išvados: beveik visais atvejais operacijos su vector konteineriu įvykdomos greičiau, todėl galima teigti, kad strategijai nr. 1 palankiau yra naudoti vector konteinerį.


### Strategija nr.2:

Strategijos idėja: bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį "vargšiukai". Tokiu būdu, jeigu studentas yra "vargšiukas", jį įkeliame į naująjį konteinerį, bei ištriname iš senojo. Ko pasekoje, pagrindiniame konteineryje liks tik "galvočiai". Užimamos atminties atžvilgiu tai yra efektyviau, nei pirmos strategijos atveju, tačiau tam tikro tipo konteineriams ši strategija gali būti "skausminga" dėl dažno duomenų trynimo.

Žemiau pateikta lentelė vaizduoja programos spartą, priklausomai nuo pasirinkto konteinerio tipo (vector arba list) ir studentų skaičiaus.

<img width="702" alt="Screenshot 2024-11-06 at 10 10 07" src="https://github.com/user-attachments/assets/efb66041-7752-45fe-9641-b22a327a30e1">

Išvados: vector konteinerio atveju, programa veikia labai ilgai, todėl lentelėje atitinkamose vietose nėra įvesti rezultatai. List konteinerio atveju, programa visada veikė greičiau. Tai ypač pasijaučia su didesniu duomenų skaičiumi.


### Strategijų nr.1 ir nr.2 apibendrinimas:

<img width="351" alt="Screenshot 2024-11-06 at 13 31 49" src="https://github.com/user-attachments/assets/f00c2bd8-d2f8-4c9c-847d-fcba00569222">

Išvados: strategiją nr.1 yra naudingiau naudoti, kai yra dirbama su vector konteineriu, o strategiją nr.2 yra naudingiau naudoti, kai yra dirbama su list konteineriu. Tačiau bendru atveju, pirmoji strategija yra efektyvesnė.


### Strategija nr.3

Strategijos idėja: bendro studentų konteinerio skaidymas panaudojant greičiausiai veikiančią strategiją (nr.1 arba nr.2). Kadangi strategija nr.1 buvo efektyvesnė su vector konteineriu, o strategija nr.2 su list konteineriu, strategija nr.3 realizuota remiantis tiek pirma tiek antra strategija.

Žemiau pateikta lentelė vaizduoja programos spartą, priklausomai nuo pasirinkto konteinerio tipo (vector arba list) ir studentų skaičiaus.

<img width="703" alt="Screenshot 2024-11-07 at 21 22 21" src="https://github.com/user-attachments/assets/1c857698-1026-42dd-8782-9634696afa21">

Išvados: strategija nr.3 veikia efektyviau, kai yra naudojamas vector konteineris.


### Strategijų nr.2 ir nr.3 apibendrinimas:

<img width="311" alt="Screenshot 2024-11-07 at 22 50 57" src="https://github.com/user-attachments/assets/a27db0fb-9273-46c7-9670-f5389c1ff1d1">

Išvados: vector konteinerio atveju, 3 strategija yra efektyvesnė, list konteinerio atveju, priešingai, programa veikia efektyviau, kai yra naudojama 2 strategija. Tačiau bendru atveju, trečia strategija veikia efektyviau.


### Strategijų nr.1, nr.2 ir nr.3 apibendrinimas:

<img width="282" alt="Screenshot 2024-11-07 at 23 22 58" src="https://github.com/user-attachments/assets/735fa7ce-ef9f-4043-99ca-ed7bb23d37b6">

Išvados: tiek vector, tiek list konteinerių atveju, trečioji strategija veikia efektyviausiai.


## Naudojimosi instrukcija:

1. Pasirinkite: Duomenų nuskaitymas iš failo (1), duomenų įvedimas ar generavimas (2), failo generavimas (3), studentų išskirstymas (4), operacijų laiko apskaičiavimas (5):

Duomenų nuskaitymas iš failo: duomenų nuskaitymas iš pasirinkto failo.
Duomenų įvedimas ar generavimas: galimybė įvesti duomenis rankiniu būdu, bei pasirinkti ar pažymius įvesti rankiniu būdu, ar generuoti automatiškai.
Failo generavimas: galimybė įvesti studentų skaičių, pažymių skaičių ir tada sugeneruoti failą pagal pasirinktus parametrus.
Studentų išskirstymas: duomenų nuskaitymas iš failo, jų surūšiavimas, atrinkimas pagal kategoriją, bei įrašymas į failą.
Operacijų laiko apskaičiavimas: studentų išskirstymo algoritmo efektyvumo apskaičiavimas.


# 2 Užduotis
## v1.1

### Struct ir class tipų palyginimas:

<img width="851" alt="Screenshot 2024-11-18 at 20 17 10" src="https://github.com/user-attachments/assets/b6accb84-8e3b-427b-b8b1-896fb4ecd092">

Išvados: struct tipas veikia šiek tiek greičiau, nei class tipas.


### Eksperimentinės analizės rezultatai, priklausomai nuo optimizavimo lygio:

<img width="852" alt="Screenshot 2024-11-21 at 00 01 58" src="https://github.com/user-attachments/assets/fd3924a8-0a1e-438c-9088-f88ff5e3f2d5">


Išvados: kai studentų sk. siekia 1 mil., efektyviausiai veikia flag 1, kai studentų sk. siekia 10 mil., efektyviausiai veikia flag flag 2. Tačiau vertinant bendrai, rezultatai skiriasi minimaliai.













