#include<iomanip>
#include<fstream>
using namespace std;
typedef char str20[21];

struct trEspec{
 str20  espec;
};

struct trMed{
 str20  nom;
 int  nroMat;
 str20 espec;
 char turno;
};

bool LeeMed(ifstream &Medicos, trMed &rMed);
bool LeeEspec(ifstream &Especialidades, trEspec &rEspec);
void ProcMedicos(ifstream &Medicos, trMed &rMed, int &cardMed);
void ProcEspecialidades(ifstream &Especialidades, trEspec &rEspec, int &cardEspec);


int main(){
    trEspec rEspec;
    trMed rMed;
    int cardEspec,
        cardMed;

    cardMed = 1;
    cardEspec = 1;

    ifstream Medicos("Medicos.txt");
    ifstream Especialidades("Especialidades.txt");

    ProcMedicos (Medicos, rMed, cardMed);
    ProcEspecialidades (Especialidades, rEspec, cardEspec);

    Especialidades.close();
    Medicos.close();


    cout << cardEspec << endl;
    cout << cardMed;

    return 0;
}

bool LeeEspec(ifstream &Especialidades, trEspec &rEspec) {
    Especialidades>>rEspec.espec;
    Especialidades.ignore();
    return Especialidades.good();
}

bool LeeMed(ifstream &Medicos, trMed &rMed) {
    Medicos.get(rMed.nom,21);
    Medicos.ignore();
    Medicos>>rMed.nroMat;
    Medicos.ignore();
    Medicos.get(rMed.espec,21);
    Medicos.ignore();
    Medicos>>rMed.turno;
    Medicos.ignore();
    return Medicos.good();
}

void ProcMedicos(ifstream &Medicos, trMed &rMed, int &cardMed){
    if (!Medicos)
        cout << "No se pudo abrir el archivo." << endl;

        while (LeeMed (Medicos, rMed)){
        cardMed = cardMed +1;
        }
}

void ProcEspecialidades(ifstream &Especialidades, trEspec &rEspec, int &cardEspec){
        if (!Especialidades)
        cout << "No se pudo abrir el archivo." << endl;

        while (LeeEspec (Especialidades, rEspec))
        cardEspec = cardEspec + 1;
}
