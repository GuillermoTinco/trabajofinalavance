#ifndef TRABAJOFINAL_FUNCIONESFIN_H
#define TRABAJOFINAL_FUNCIONESFIN_H

#include "Variablesnat.h"
#include <fstream>
#include <vector>
tof palabra_en_texto(cadena& texto7, cadena& palabra7){
    entero auxPal=0,contador=0;
    for(entero i=0;i<texto7.size();i++){
        if(toupper(texto7[i])==toupper(palabra7[auxPal])){
            auxPal++;
            if (auxPal==palabra7.size()-1){
                if(texto7[i+1]=='.' or texto7[i+1]==',' or texto7[i+1]==' ' or texto7[i+1]==';' or texto7[i+1]==':'){
                    auxPal=0;contador++;
                }
            }
        }
        else auxPal=0;
    }
    return contador;
}
nada reemplazar(entero& desde, entero& hasta,cadena& texto,cadena& reemplazo){
    //creación del vector que contendrá el texto
    vector<caracter> txt;
    //llenado del vector con el texto
    for (char i : texto) {
        txt.push_back(i);
    }
    //eliminado de la palabra en al posición dada
    for(entero i=hasta;i>=desde;i--){
        txt.erase(txt.begin()+i);
    }
    //inserción del reemplazo donde se borró la palabra
    for (entero i=reemplazo.size()-1;i>=0;i--){
        txt.insert(txt.begin()+desde,reemplazo[i]);
    }
    //creación de una variable auxiliar de texto
    cadena newtxt;
    //llenado de la variable con el texto modificado que contiene el vector
    for(char i : txt){
        newtxt+=i;
    }
    //paso del texto de la variable auxiliar a la variable texto del main
    texto=newtxt;

}
nada reemplazar_palabra(cadena& texto8, cadena& palabra8, cadena& reemplazo8){
    entero auxPal=0,auxw=0,desde,hasta;entero_positivo i;
    //verifica que el texto sea analizado hasta por completo
    while(auxw==0) {
        for (i = 0; i < texto8.size() - 1; i++) {
            //compara que cada una de las letras coincida con la palabra que se quiere reemplazar.
            if (toupper(texto8[i])==toupper(palabra8[auxPal])) {
                auxPal++;
                //verificar que ya coincidieron todas las letras de la palabra.
                if (auxPal == palabra8.size()-1) {
                    //verifica que después de la palabra no siga una letra.
                    if (texto8[i + 1] == '.' or texto8[i + 1] == ',' or texto8[i + 1] == ' ' or texto8[i + 1] == ';' or texto8[i + 1] == ':') {
                        //verifica que antes de la palabra no haya una letra.
                        if (texto8[i-auxPal] == ' ') {
                            hasta = i;
                            desde = i - auxPal +1;
                            auxPal = 0;
                            //llamado a la subfunción encargada del reemplazo de la palabra
                            //y envío de los datos de posición de la palabra en el texto,
                            //texto y el reemplazo.
                            reemplazar(desde, hasta, texto8, reemplazo8);
                            break;
                        }
                    }
                }
            }
            else
                auxPal = 0;
        }
        //verifica que el texto haya sido leído completamente para poder salir del bucle
        if (i==texto8.size()-1) auxw++;
    }

}
entero palabras_en_texto(cadena& texto9, cadena& palabra9){
    entero auxPal=0,contador=0;
    for(entero i=0;i<texto9.size();i++){
        if(toupper(texto9[i])==toupper(palabra9[auxPal])){
            auxPal++;
            if (auxPal==palabra9.size()-1){
                if(texto9[i+1]=='.' or texto9[i+1]==',' or texto9[i+1]==' ' or texto9[i+1]==';' or texto9[i+1]==':'){
                    auxPal=0;contador++;
                }
            }
        }
        else
            auxPal=0;
    }
    return contador;
}
entero numlineas(ifstream &archivo){
    letras unused;
    entero numLines=0;
    while(getline(archivo, unused)){
        numLines++;
    }
    return numLines;
}
#endif //TRABAJOFINAL_FUNCIONESFIN_H