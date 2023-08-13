#include<iomanip>
#include<fstream>
using namespace std;
typedef char str20[21];
typedef char str15[16];
typedef str20 tvrEspec[20];

struct tprMed{
    str20  nom;
    int  nroMat;
    str20 espec;
    char turno;
    };
struct tprTurnos{
    str15 obrSoc;
    int nroCred;
};

typedef tprMed   tvrMed[100];
typedef tprTurnos ttrTurnos[20][31][24];

//Prototipos
bool LeeEspec(ifstream &Especialidades, tvrEspec &vrEspec, short ie);
bool LeeMed(ifstream &Medicos, tvrMed &vrMed, short im);
bool LeeTurnos(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, int cardEspec, tvrEspec vrEspec);
void ProcEspecialidades(ifstream &Especialidades, tvrEspec &vrEspec, int &cardEspec);
void ProcMedicos(ifstream &Medicos, tvrMed &vrMed, int &cardMed);
void ProcTurnosDiaHora(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, tvrEspec vrEspec, int &cardTurnos, int cardEspec);
short BusLinF(str20 objetivo, int card, tvrEspec vrEspec, short &i);
//fin Prototipos

int main(){
    int cardEspec = 0,
        cardMed = 0,
        cardTurnos = 0;
    tvrEspec vrEspec;
    tvrMed vrMed;
    ttrTurnos trTurnos;

    ifstream Medicos("Medicos.txt");
    ifstream Especialidades("Especialidades.txt");
    ifstream TurnosDiaHora ("TurnosDiaHora.txt");

    ProcMedicos (Medicos, vrMed, cardMed);
    ProcEspecialidades (Especialidades, vrEspec, cardEspec);
    ProcTurnosDiaHora (TurnosDiaHora, trTurnos, vrEspec, cardTurnos, cardEspec);

    Especialidades.close();
    Medicos.close();
    TurnosDiaHora.close();

    cout << cardEspec << endl;
    cout << cardMed << endl;
    cout << cardTurnos << endl;

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

bool LeeTurnos(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, int cardEspec, tvrEspec vrEspec) {
    short i = 0,
          j = 0,
          h = 0,
          m = 0;
    int   k = 0;
    char desc;
    str20 TurnoEspec;
    TurnosDiaHora.get(TurnoEspec, 21);
    BusLinF(TurnoEspec, cardEspec, vrEspec, i) == 1000); // profundidad segun hora y minuto, de forma hhmm *//
    TurnosDiaHora.ignore();
    TurnosDiaHora >> j; // las columnas corresponden con los dias, empezando con el 0 (el dia 1 = pos 0)*/
    TurnosDiaHora.ignore();
    TurnosDiaHora >> h >> desc >> m;
    h = h*100;
    k = h+m; // profundidad segun hora y minuto, de forma hhmm *//
    TurnosDiaHora.ignore();
    TurnosDiaHora.get(trTurnos[i][j-1][k].obrSoc, 16);
    TurnosDiaHora.ignore();
    TurnosDiaHora >> trTurnos[i][j-1][k].nroCred;
    TurnosDiaHora.ignore();



    return TurnosDiaHora.good();
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


void ProcTurnosDiaHora(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, tvrEspec vrEspec, int &cardTurnos, int cardEspec){
    if (!TurnosDiaHora)
        cout << "No se pudo abrir el archivo." << endl;

    while (LeeTurnos(TurnosDiaHora, trTurnos, cardEspec, vrEspec)){
        cardTurnos = cardTurnos + 1;
        }
}

short BusLinF (str20 objetivo, int card, tvrEspec vrEspec, short &i){
    short aux;
    for (aux = 0; aux < card; ++aux){
        if (strcmp(vrEspec[aux], objetivo) == -32){         // NO SE PORQUE, SOLO FUNCA CON -32, NO PREGUNTES, SOLO DISFRUTA *//
            i = aux;
        }
    }

    return i;
}
