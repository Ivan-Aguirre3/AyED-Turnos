/*
    Prototipo 1 de tp
*/

#include <fstream>
using namespace std;

struct{
    string NomAp;
    int NroMatr;
    string NomEsp;
    char Turno;
}Medicos[100];

void ProcMedicos(FILE *Lector);

main(){
    //Declarar las variables utilizadas en el bloque main().


    //Abrir todos los archivos
    FILE *medTxt;
    medTxt = fopen("Medicos.txt","r");


    ProcMedicos(medTxt); // Descarga archivo Medicos.
    /*
    ProcEspecialidad();  // Descarga archivo Especialidades.
    ProcTurnos();  // Descarga archivo TurnosDiaHora.
    LstTurnos(); // Lista ord. x Especialidades, Días y Turnos del vuelco del archivo TurnosDiasHora.
    ProcTurnos(); // Descarga archivo SolicitudesTurnos y lista líneas de las solicitudes.
    LstTurnos(); // Lista ord. x Especialidades, Días y Turnos Actualizado con las SolicitudesTurnos.
    */
    //Cerrar todos los archivos

    return 0;
}

void ProcMedicos(FILE *Lector){

    string Nombre, Apellido;
    char counter = 1;

    while(!feof(Lector)){
        fscanf(Lector,"%s%s%d%s%c",Nombre,Apellido,&Medicos[counter].NroMatr,&Medicos[counter].NomEsp,&Medicos[counter].Turno);

        cout << Medicos[counter].NroMatr;
        /*
        Medicos[counter].NomAp = Apellido + ' ' + Nombre;
        counter++;
        cout << (int)counter <<endl;
        */

    }
}
