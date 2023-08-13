#include<iomanip>
#include<fstream>
using namespace std;
typedef char str20[21];

//para espec bus lin e igualar

struct tprMed{
 str20  nom;
 int  nroMat;
 str20 espec;
 char turno;
};

typedef str20 tvrEspec[20];
typedef tprMed   tvrMed[100];

bool LeeMed(ifstream &Medicos, tvrMed &vrMed, short im);
bool LeeEspec(ifstream &Especialidades, tvrEspec &vrEspec, short ie);
void ProcMedicos(ifstream &Medicos, tvrMed &vrMed, int &cardMed);
void ProcEspecialidades(ifstream &Especialidades, tvrEspec &vrEspec, int &cardEspec);


int main(){
    int cardEspec,
        cardMed;
    tvrEspec vrEspec;
    tvrMed vrMed;

    cardMed = 1;
    cardEspec = 1;

    ifstream Medicos("Medicos.txt");
    ifstream Especialidades("Especialidades.txt");

    ProcMedicos (Medicos, vrMed, cardMed);
    ProcEspecialidades (Especialidades, vrEspec, cardEspec);

    Especialidades.close();
    Medicos.close();


    cout << cardEspec << endl;
    cout << cardMed;

    return 0;
}

bool LeeEspec(ifstream &Especialidades, tvrEspec &vrEspec, short ie) {
    Especialidades>>vrEspec[ie];
    Especialidades.ignore();
    return Especialidades.good();

}

bool LeeMed(ifstream &Medicos, tvrMed &vrMed, short im) {
    Medicos.get(vrMed[im].nom,21);
    Medicos.ignore();
    Medicos>>vrMed[im].nroMat;
    Medicos.ignore();
    Medicos.get(vrMed[im].espec,21);
    Medicos.ignore();
    Medicos>>vrMed[im].turno;
    Medicos.ignore();

    return Medicos.good();
}

void ProcMedicos(ifstream &Medicos, tvrMed &vrMed, int &cardMed){
    short im;

    im = 0;

    if (!Medicos)
        cout << "No se pudo abrir el archivo." << endl;

    while (LeeMed (Medicos, vrMed, im)){
        cardMed = cardMed +1;

        im++;
        }
}

void ProcEspecialidades(ifstream &Especialidades, tvrEspec &vrEspec, int &cardEspec){
        short ie;

        ie = 0;

        if (!Especialidades)
        cout << "No se pudo abrir el archivo." << endl;

        while (LeeEspec (Especialidades, vrEspec, ie)){
        cardEspec = cardEspec + 1;
        ++ie;
        }
}
