#include<iomanip>
#include<fstream>
using namespace std;
typedef char str19[20];

struct trEspec{
 str19  espec;
};

ifstream Especialidades("C:\\Users\\Usuario\\Documents\\1A UTN\\AyE\\TP 1\\Especialidades.txt");

bool LeeUnReg(ifstream &Especialidades, trEspec &rEspec) {
    Especialidades>>rEspec.espec;
    Especialidades.ignore();
    return Especialidades.good();
}

int main(){
    trEspec rEspec;

    if (!Especialidades) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    while (LeeUnReg (Especialidades, rEspec)){
        cout<< "Especialidad : "<< rEspec.espec<<endl;
    }

    Especialidades.close();

    return 0;
}
