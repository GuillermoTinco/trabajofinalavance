#include "Editor.h"
#include "FuncionesFin.h"
EditorTexto::EditorTexto() {
    // asignarle valor 0 para que la interface trabaje con ese
    this->opcion=0;
    this->ubicac="";
}
EditorTexto::EditorTexto(entero opcion, cadena ubicac){
    this->opcion=opcion;
    this->ubicac=ubicac;
}
//funciones"main"de los metodos... en FUNCIONESFIN estan
// las funciones de las funciones main de estos metodos de la clase
nada EditorTexto::Runcasouno(cadena ubicac) {
    string line;
    ifstream miarchivo(getUbicac()); //para leer el archivo
    vector<string> Lineas;
    if(miarchivo.is_open()){
        while(getline(miarchivo,line)){//getline lee las lineas del texto
            Lineas.push_back(line);
        }
        miarchivo.close();
    }
    for(int i=0; i< Lineas.size(); i++){
        cout << Lineas[i] << endl;
    }

} //Listo!!!!!
nada EditorTexto::Runcasodos(cadena ubicac) {
    ofstream miarchivo(ubicac);//para escribir en el archivo
    string texto;
    cout <<"Ingrese el texto, cuando finalice ingrese 'XX': "<<endl;
    if(miarchivo.is_open())
    {
        do{
            cin.ignore();
            getline(cin, texto);
            if(texto == "X"){
                break;
            }
            else{
                miarchivo << texto <<endl;
            }
        }
        while(texto!="X");
    }
    cout << "Texto grabado" << endl;
    miarchivo.close();
}//Listo!!!!!!
nada EditorTexto::Runcasotres(cadena ubicac) {} //
nada EditorTexto::Runcasocuatro(cadena ubicac) {} //
nada EditorTexto::Runcasocinco(cadena ubicac) {} //
nada EditorTexto::Runcasoseis(cadena ubicac) {} //
nada EditorTexto::Runcasosiete(cadena ubicac) {
    cadena palabra7, texto7,txt7;
    ifstream archivo(getUbicac());
    ifstream inutil(ubicac);
    entero numLines=numlineas(inutil);
    //cout << numLines; === 8
    //cout << archivo.eof(); === no vale
    cout<<"Ingrese la palabra que desea buscar: ";
    cin>>palabra7;
    palabra7=palabra7 +" ";
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    entero i=0;
    while(i < numLines){
        //necesito encontrar la cantidad de lineas, listo
        getline(archivo,txt7);
        texto7+=txt7;
        i++;
    }
    if(palabra_en_texto(texto7,palabra7))
        cout<<"La palabra se encuentra en el texto.";
    else
        cout<<"La palabra no se encuentra en el texto.";

    archivo.close();

} //Listo!!!!!//verComynFbn
nada EditorTexto::Runcasoocho(cadena ubicac) {
    cadena palabra8, texto8,txt8,reemplazo;
    ifstream archivo(getUbicac());
    ifstream inutil(ubicac); //otro archivo para poder sacar el num de lineas sin afectar al archivo
    entero numLines=numlineas(inutil); //numero de lineas del documento
    cout<<"Ingrese la palabra que desea reemplazar: ";
    cin>>palabra8;
    cout<<"Ingrese el reemplazo: ";
    cin>>reemplazo;
    palabra8=palabra8 +" ";
    //apertura del archivo
    //verificación de que el archivo se abrió con éxito
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    //llenado de la variable texto con el archivo
    entero i=0;
    while(i < numLines){
        if(i<numLines-1){
            getline(archivo,txt8);
            texto8+=txt8+"\n";}
        //while else creado para que no añada una linea en blanco al final
        else{
            getline(archivo,txt8);
            texto8+=txt8;
        }
        i++;
    }//cerrado del archivo
    reemplazar_palabra(texto8,palabra8,reemplazo);
    cout<<texto8;//la variable texto contiene el archivo modificado
    ofstream archivoescribir(ubicac); //para escribir en el archivo
    if(archivoescribir.is_open()){
    archivoescribir << texto8;}
    archivo.close();
    archivoescribir.close();
} //Listo!!!!//VErConFn
nada EditorTexto::Runcasonueve(cadena ubicac) {
    cadena palabra9, texto9,txt9;
    ifstream archivo(getUbicac());
    ifstream inutil(ubicac); //otro archivo para poder sacar el num de lineas sin afectar al archivo
    entero numLines=numlineas(inutil); //numero de lineas del documento
    cout<<"Ingrese la palabra que desea buscar: ";
    cin>>palabra9;
    palabra9=palabra9 +" ";
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    entero i=0;
    while(i<numLines){
        getline(archivo,txt9);
        texto9+=txt9;
        i++;
    }
    cout<<"La palabra se encuentra "<< palabras_en_texto(texto9,palabra9)<<" veces en el texto "<<endl;

    archivo.close();

} //Listo!!!/VErConFn
nada EditorTexto::Runcasodiez(cadena ubicac) {} //
//la aparte de dibujar despues se podría hacer con un for y vaya acomodando tdo
nada EditorTexto::Dibujar(){
    //  hacer td el trabajo de la interface
    //está en elarchivo frame de poo
    cout <<
             "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "|                     "<< getNombrePrograma() << "                          |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasouno() <<"                                           |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasodos() <<"                                     |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasotres() <<"                           |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasocuatro() <<"                 |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasocinco() <<"               |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasoseis() <<"                              |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasosiete() <<"                          |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasoocho() <<"                        |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasonueve() <<"   |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         "|                                                              |" << endl <<
         "| "<< getCasodiez() <<"                              |" << endl <<
         "|                                                              |" << endl <<
         "*--------------------------------------------------------------*" << endl <<
         " 0. Salir" << endl;
} //Listo