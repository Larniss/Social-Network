#include <iostream>
#include <string>

using namespace std;


// nr de persoane
int nrPersoane;
//matricea adiacenta
bool matrix[100][100];



//Stuctura pentru nod(Persoana)
struct Persoana {
    string nume;
    string prenume;
    int varsta{};
    string adresaEmail;
    string numarTelefon;
};
//vector cu persoane
Persoana persArr[100];

void Initializare() {
    cout << "Introduceti numarul initial de persoane din retea: ";
    cin >> nrPersoane;

    //Se introduce persoana cu datele sale
    for (int i = 0; i < nrPersoane; i++) {
        cout << "Introduceti numele persoanei: ";
        cin >> persArr[i].nume;
        cout << "Introduceti prenumele persoanei: ";
        cin >> persArr[i].prenume;
        cout << "Introduceti varsta: ";
        cin >> persArr[i].varsta;
        cout << "Introduceti adresa de email: ";
        cin >> persArr[i].adresaEmail;
        cout << "Introduceti numarul de telefon: ";
        cin >> persArr[i].numarTelefon;
        cout << "---------------------------------------" <<endl;
        cout <<endl;

    }
    // adauga relatia de prietenie
    cout << endl;
    cout << endl;
    cout << "Introduceti relatia de prietenie dintre persoanele: " << endl;
    cout << "Introduceti 1 daca exista prietenie sau 0 daca nu exista prietenie. " << endl;

    for (int i = 0; i < nrPersoane; i++) {
        for (int j = i + 1; j < nrPersoane; j++) {
            cout << endl << "Prietenia dintre " << persArr[i].nume << " " << persArr[i].prenume << " - " << persArr[j].nume<< " " << persArr[j].prenume  << ":" << endl;
            cin >> matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
    }
    cout << endl;
}


void AfiseazaMatrice() {

    cout << "\n\n Matricea adiacenta este: " << endl;
    for (int i = 0; i < nrPersoane; i++) {
        for (int j = 0; j < nrPersoane; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void AfiseazaRetea() {
    cout << "Reteaua sociala: " << endl;
    for (int i = 0; i < nrPersoane; i++) {
        cout << i << ". " << "\tNume: " << persArr[i].nume << endl << "\tPrenume: " << persArr[i].prenume << endl<< "\tVarsta: " << persArr[i].varsta << endl
             << "\tEmail: " << persArr[i].adresaEmail << endl << "\tTelefon: " << persArr[i].numarTelefon << endl;
        cout << endl;
    }
    cout << endl;
}

void AdaugaPersoana() {
    //Crestem numarul de noduri
    nrPersoane++;
    cout << "Introduceti persoana :" << endl;

    cout << "Introduceti numele persoanei: ";
    cin >> persArr[nrPersoane - 1].nume;
    cout << "Introduceti prenumele persoanei: ";
    cin >> persArr[nrPersoane - 1].prenume;
    cout << "Introduceti varsta: ";
    cin >> persArr[nrPersoane - 1].varsta;
    cout << "Introduceti adresa de email: ";
    cin >> persArr[nrPersoane - 1].adresaEmail;
    cout << "Introduceti numarul de telefon: ";
    cin >> persArr[nrPersoane - 1].numarTelefon;


    //Se adauga relatia de prietenie
    cout << endl;
    cout << endl;
    cout << "Introduceti relatia de prietenie dintre persoanele: " << endl;
    cout << "Introduceti 1 daca exista prietenie sau 0 daca nu exista prietenie. " << endl;

    for (int i = 0; i < nrPersoane - 1; i++) {
        cout << endl << "Prietenia dintre " << persArr[nrPersoane - 1].nume << " " << persArr[nrPersoane - 1].prenume << " - " << persArr[i].nume << " " <<persArr[i].prenume << ":" << endl;
        cin >> matrix[nrPersoane - 1][i];
        matrix[i][nrPersoane - 1] = matrix[nrPersoane - 1][i];
    }
    cout<< endl;
    cout<< endl;
}


void StergePersoana(int x) {
    //Verificam daca avem node
    if (x > nrPersoane) {
        cout << "\n Persoana nu exista";
        return;
    } else {
        for(int i = x; i < nrPersoane - 1; i++ ){
            for(int j = 0; j < nrPersoane; j++ ){
                matrix[i][j] = matrix [i+1][j];
            }
        }
        for(int j = x; j < nrPersoane - 1; j++ ){
            for(int i = 0; i < nrPersoane; i++ ){
                matrix[i][j] = matrix [i][j+1];
            }
        }
        for(int i = x; i < nrPersoane - 1; i++ ){
            persArr[i] = persArr[i+1];
        }
        //Scadem numarul de noduri
        nrPersoane--;
    }
}

void AfisareRelatiePrietenie(int index) {

    int nrPrietenie = 0;
    cout << persArr[index].nume << " " << persArr[index].prenume <<" este prieten/a cu ";
    for (int i = 0; i < nrPersoane; i++) {
        if (matrix[index][i]) {
            cout << persArr[i].nume << " " <<persArr[i].prenume  << ", ";
            nrPrietenie++;
        }
    }
    cout << endl;

    if (nrPrietenie != 0) {
        cout << persArr[index].nume << " " << persArr[index].prenume<<" are " << nrPrietenie << " prieten/i" << endl;
    } else {
        cout << persArr[index].nume << " " << persArr[index].prenume << " nu are prieteni. " << endl;
    }
    cout<< endl;
}

void AfiseazaToateRelatiilePrietenie() {
    for (int j = 0; j < nrPersoane; j++) {
        cout << persArr[j].nume << " " << persArr[j].prenume << " este prieten/a cu ";
        for (int i = 0; i < nrPersoane; i++) {
            if (matrix[j][i]) {
                cout << persArr[i].nume << " " << persArr[i].prenume << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void NumarPersoane() {
    cout << endl << "Numarul de persoane din retea sunt: ";
    cout << nrPersoane << endl;
    cout << endl;
}

void PrieteniCuAceeasiVarsta(int index) {
    int number = 0;
    for (int i = 0; i < nrPersoane; i++) {
        if (persArr[index].varsta == persArr[i].varsta) {
            if (matrix[i][index]) {
                cout << persArr[index].nume<< " " << persArr[index].prenume  << " este prieten/a cu ";
                cout << persArr[i].nume << " " << persArr[i].prenume << endl;
                number++;
            }
        }
        cout << endl;
    }
    if (number == 0) {
        cout << persArr[index].nume<< " " << persArr[index].prenume << " nu are prieteni de aceeasi varsta. " << endl;
    }
    cout<< endl;
    cout<< endl;
}

void ModificaRelatiePrietenie(int index,int index2){

    cout << "Introduceti 1 daca exista prietenie sau 0 daca nu exista prietenie. " << endl;

    cout << endl << "Prietenia dintre " << persArr[index].nume <<" " << persArr[index].prenume << " - " << persArr[index2].nume<< " " << persArr[index2].prenume  << ":" << endl;
    cin >> matrix[index][index2];
    matrix[index2][index] = matrix[index][index2];

    cout<< endl;
    cout<< endl;
}


int main() {

    int optiune = 1;
    int index;
    Initializare();

    do {
        cout << "Meniul de comenzi pentru reteaua sociala." << endl;
        cout << "1. Afiseaza numarul de persoane din retea. " << endl;
        cout << "2. Afiseaza matricea adiacenta a retelei." << endl;
        cout << "3. Adauga o persoana noua in retea. " << endl;
        cout << "4. Sterge o persoana din retea. " << endl;
        cout << "5. Afiseaza relatia de prietenie pentru o persoana anume. " << endl;
        cout << "6. Afiseaza toate relatiile de prietenie din retea." << endl;
        cout << "7. Afiseaza prietenii unei persoane anume de aceeasi varsta." << endl;
        cout << "8. Modifica relatia de prietenie a unei persoane." << endl;
        cout << "9. Afiseaza reteaua sociala." << endl;
        cout << "0. Iesire." << endl;
        cout << endl;

        cout << " Introduceti optiunea dorita: ";
        cin >> optiune;
        cout << endl;

        switch (optiune) {
            case 1: {
                NumarPersoane();
                break;
            }
            case 2: {
                AfiseazaMatrice();
                break;
            }
            case 3: {
                AdaugaPersoana();
                break;
            }
            case 4: {
                cout << "Introduceti indexul persoanei pe care doriti sa o stergeti din retea: ";
                cin >> index;
                StergePersoana(index);
                break;
            }
            case 5: {
                cout << "Introduceti indexul persoanei pentru care doriti sa vedeti relatiile de prietenie: ";
                cin >> index;
                AfisareRelatiePrietenie(index);
                break;
            }
            case 6: {
                AfiseazaToateRelatiilePrietenie();
                break;
            }
            case 7: {
                cout << "Introduceti indexul persoanei pentru care doriti sa vedeti relatiile de prietenie cu persoane de aceeasi varsta: ";
                cin >> index;
                PrieteniCuAceeasiVarsta(index);
                break;

            }

            case 8: {
                int index2;
                cout << "Introduceti primul index al persoanei pentru care doriti sa modificati relatia de prietenie: ";
                cin >> index;
                cout << "Introduceti al doilea index al persoanei pentru care doriti sa modificati relatia de prietenie: ";
                cin >> index2;
                ModificaRelatiePrietenie(index,index2);
                break;
            }
            case 9: {
                AfiseazaRetea();
                break;
            }
            case 0: {
                cout << " Inchidere meniu! " << endl;
                break;
            }
            default:
                cout << "Optiunea aleasa este invalida. Va rog incercati din nou!";
                break;
        }
    } while (optiune);

    return 0;
}
