#include<iomanip>
#include<fstream>
using namespace std;
typedef char str20[21];


bool LeeEspec(ifstream &Especialidades, int &vEspec);;
void ProcEspecialidades(ifstream &Especialidades, int &vEspec, int &cardEspec);


int main(){
    int vEspec[20];
    int cardEspec,

    cardEspec = 1;

    ifstream Especialidades("Especialidades.txt");

    ProcEspecialidades (Especialidades, vEspec, cardEspec);

    Especialidades.close();


    cout << cardEspec;

    return 0;
}

bool LeeEspec(ifstream &Especialidades, int &vEspec, int i) {
    Especialidades>>vEspec[i];
    Especialidades.ignore();
    return Especialidades.good();
}

void ProcEspecialidades(ifstream &Especialidades, int &vEspec, int &cardEspec){
        int i;

        i=1;
        if (!Especialidades)
        cout << "No se pudo abrir el archivo." << endl;

        while (LeeEspec (Especialidades, vEspec))
        1++
        cardEspec = cardEspec + 1;
        cout<< vEspec[i];
}
