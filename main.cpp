#include <iostream>
#include <fstream>
using namespace std;

void creaFile(string filename);

bool controlloFileEsistente(string filename);

int main () 
{
    const string fileName = "Database3.zg";
    bool esistente;
    esistente = controlloFileEsistente(fileName);
    if(esistente == false){
        creaFile(fileName);
    }
    string stringa;
    cin >> stringa;
    inserisciDati(fileName, stringa);
    return 0;
}

void creaFile(string filename){
    ofstream file;
    file.open (filename.c_str());
    cout << "Creazione del file " << filename << "..." << endl;
    file.close();
}

bool controlloFileEsistente(string filename){
    bool statoFile;
    fstream file(filename);
    if (file.is_open()){
        statoFile = true;
    }
    else{
        char scelta;
        cout << "Errore: 0001 | il file:\" " << filename <<  "\" non esistente" << endl;
        statoFile = false;
    }
    file.close();
    return statoFile;
}

void inserisciDati(string filename, string linea){
    ifstream file(filename);
    file.write((char *)linea, sizeof(linea));
}
