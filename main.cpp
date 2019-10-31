#include <iostream>
#include <fstream>//Para abrir un fichero para lectura, debe crear un objeto ifstream que se usará como cin.
#include <string>//cadenas de texto
#include <vector>
#include <iomanip>//para manejar formatos, posicionar el texto donde quieras(centrado) setw

using namespace std;

int main() {
  //ESCRIBE EN EL ARCHIVO TXT, CREAR ARCHIVO

  ofstream miarchivo("ejemplo1.txt");//para escribir en el archivo

  if(miarchivo.is_open()){
    miarchivo<<"Primera linea\n";
    miarchivo<<"Segunda Liwefwewnsaea\n";
    miarchivo<<"tercera Linea\n";
  }
  miarchivo.close();

  //LEE LÍNEAS EN EL ARCHIVO TXT
  string line;

  ifstream miarchivo2("ejemplo1.txt");//para leer el archivo
  vector<string> Lineas;
  if(miarchivo2.is_open()){
      while(getline(miarchivo2,line)){//getline lee las lineas del texto
          Lineas.push_back(line);
      }
      miarchivo2.close();
  }
  for(int i=0; i< Lineas.size(); i++){
    cout << Lineas[i] << endl;
  }
  cout << Lineas.size()<<endl;

  for(int i=0; i<10; i++){
    cout << i << setw(5) << endl;
  }
}