#include<iomanip>
#include<fstream>
using namespace std;
typedef char str20[21];
typedef char str15[16];

struct tprTurnos{
    str15 obrSoc;
    int nroCred;
};

typedef str20 tvrEspec[20];
typedef tprTurnos ttrTurnos[20][31][24];

bool LeeEspec(ifstream &Especialidades, tvrEspec &vrEspec, short ie);
bool LeeTurnos(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, int cardEspec, tvrEspec vrEspec);
short BusLinF(str20 objetivo, int card, tvrEspec vrEspec, short &i);
void ProcEspecialidades(ifstream &Especialidades, tvrEspec &vrEspec, int &cardEspec);
void ProcTurnosDiaHora(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, tvrEspec vrEspec, int &cardTurnos, int cardEspec);

int main(){
    int cardEspec = 1,
        cardTurnos = 1;
    tvrEspec vrEspec;
    ttrTurnos trTurnos;

    ifstream Especialidades("Especialidades.txt");
    ifstream TurnosDiaHora ("TurnosDiaHora.txt");

    ProcEspecialidades (Especialidades, vrEspec, cardEspec);
    ProcTurnosDiaHora (TurnosDiaHora, trTurnos, vrEspec, cardTurnos, cardEspec);

    Especialidades.close();
    TurnosDiaHora.close();

    cout << cardEspec << endl;
    cout << cardTurnos << endl;
    return 0;
}

void ProcTurnosDiaHora(ifstream &TurnosDiaHora, ttrTurnos &trTurnos, tvrEspec vrEspec, int &cardTurnos, int cardEspec){
    if (!TurnosDiaHora)
        cout << "No se pudo abrir el archivo." << endl;

    while (LeeTurnos(TurnosDiaHora, trTurnos, cardEspec, vrEspec)){
        cardTurnos = cardTurnos + 1;
        }
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
    if (BusLinF(TurnoEspec, cardEspec, vrEspec, i) == 1000) {
        cout << "No se encontro objetivo en funcion LeeTurnos, linea 47-58"<<endl;
        };
    TurnosDiaHora.ignore();
    TurnosDiaHora >> j;
    TurnosDiaHora.ignore();
    TurnosDiaHora >> h >> desc >> m;
    h = h*100;
    k = h+m;
    TurnosDiaHora.ignore();
    TurnosDiaHora.get(trTurnos[i][j][k].obrSoc, 16);
    TurnosDiaHora.ignore();
    TurnosDiaHora >> trTurnos[i][j][k].nroCred;
    TurnosDiaHora.ignore();

    cout << i << endl;

    return TurnosDiaHora.good();
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

bool LeeEspec(ifstream &Especialidades, tvrEspec &vrEspec, short ie) {
    Especialidades>>vrEspec[ie];
    Especialidades.ignore();
    return Especialidades.good();
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
