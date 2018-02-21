//
//  main.cpp
//  Proyecto1
//  Created by Alejandro on 30/01/18.
//  Copyright © 2018 Alejandro. All rights reserved.
// Alejandro Hernández Lopez
// A00822926
// 30 de enero de 2018
// Crea un html con los bloques de comentarios de un archivo cpp que ingrese el usuario
// Proyecto 1
//Version 1.1
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string sNombreArchivo;
    string sString;
    //Declaro dos archivos, uno de entrada y uno de salida. El de entrada servira para leer los datos del archivo cpp que contiene los comentarios y el de salida sera un archivo html
    ifstream fArchEntrada;
    ofstream fArchSalida;
    //La varibale bEstaDentro dirá si entró dentro del bloque de comentarios.
    bool bEstaDentro{false};
    ofstream fArchivoParaElimianrLineas;
    cout << "¿Cuál es nombre del archivo? (sin extensión)" << endl;
    //Ingresa el usuario el nombre del archivo
    cin >> sNombreArchivo;
    
    //Abre el archivo que se acaba de crear donde solo estan los comentarios y tambien abre uno nuevo pero ahora el de salida es un html
    fArchEntrada.open(sNombreArchivo + ".cpp");
    fArchSalida.open(sNombreArchivo + ".html");
    
    //En el archivo nuevo de salida de html pone lo que debe llevar al principio para que se haga bien un html
    fArchSalida << "<!DOCTYPE html>" << endl;
    fArchSalida << "<html>" << endl;
    fArchSalida << "<head>" << endl;
    fArchSalida << "<title>" << endl;
    fArchSalida << "Documentación del archivo " << sNombreArchivo << endl;
    fArchSalida << "</title>" << endl;
    fArchSalida << "</head>" << endl;
    fArchSalida << "<body>" << endl;
    //Mientras el archivo no termine de leerse, cada vez que encuentra el @ y la secuencia lo que hace es un substring que lo agrega al html además de que le da el formato.
    while(!fArchEntrada.eof())
    {
        getline(fArchEntrada, sString);
        for(int i = 0; i < sString.length(); i++)
        {
            if(sString[i] == '/' && sString[i+ 1] == '*')
            {
                bEstaDentro = true;
            }
            else if (sString[i] == '*' && sString[i+ 1] == '/')
            {
                
                bEstaDentro = false;
            }
        }
        if (bEstaDentro == true)
        {
            for(int i = 0; i < sString.length(); i++)
            {
                string restoDeOracion {""};
                if(sString[i] == '@' && sString[i+ 1] == 'p' && sString[i+ 2] == 'r' && sString[i+ 3] == 'o' && sString[i+ 4] == 'g' && sString[i+ 5] == 'N' && sString[i+ 6] == 'a' && sString[i+ 7] == 'm' && sString[i+ 8] == 'e')
                {
                    fArchSalida << "<h2>" << endl;
                    restoDeOracion = sString.substr(i + 9);
                    fArchSalida << "<font color=\"#737CA1\">" << endl;
                    fArchSalida << "Programa: " << restoDeOracion << endl;
                    fArchSalida << "</font>" << endl;
                    fArchSalida << "<br>" << endl;
                    fArchSalida << "</h2>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'a' && sString[i+ 2] == 'u' && sString[i+ 3] == 't' && sString[i+ 4] == 'h' && sString[i+ 5] == 'o' && sString[i+ 6] == 'r')
                {
                    fArchSalida << "<strong>" << endl;
                    restoDeOracion = sString.substr(i + 7);
                    fArchSalida << "Descripcion: " << endl << "</strong>" << endl  << "<font color=\"#4863A0\">"  << restoDeOracion << endl;
                    fArchSalida << "</font>" << endl;
                    fArchSalida << "<br>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'a' && sString[i+ 2] == 'u' && sString[i+ 3] == 't' && sString[i+ 4] == 'h' && sString[i+ 5] == 'o' && sString[i+ 6] == 'r')
                {
                    fArchSalida << "<strong>" << endl;
                    restoDeOracion = sString.substr(i + 7);
                    fArchSalida << "Nombre del autor: "<< endl  <<"</strong>" << endl <<  restoDeOracion << endl;
                    fArchSalida << "</font>" << endl;
                    fArchSalida << "<br>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'd' && sString[i+ 2] == 'a' && sString[i+ 3] == 't' && sString[i+ 4] == 'e')
                {
                    fArchSalida << "<strong>" << endl;
                    restoDeOracion = sString.substr(i + 5);
                    fArchSalida <<"Fecha de creacion"<< endl << "</strong>" << "<font color=\"#4863A0\">"  << restoDeOracion << endl;
                    fArchSalida << "</font>" << endl;
                    fArchSalida << "<br>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'f' && sString[i+ 2] == 'u' && sString[i+ 3] == 'n' && sString[i+ 4] == 'c' && sString[i+ 5] == 'N' && sString[i+ 6] == 'a' && sString[i+ 7] == 'm' && sString[i+ 8] == 'e')
                {
                    fArchSalida << "<h3>" << endl;
                    fArchSalida << "<hr>" << endl;
                    fArchSalida << "<br>" << endl;
                    restoDeOracion = sString.substr(i + 9);
                    fArchSalida << "Funcion: " << "<font color=\"#4863A0\">"  << restoDeOracion << endl;
                    fArchSalida << "</font>" << endl;
                    fArchSalida << "<br>" << endl;
                    fArchSalida << "</h3>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'd' && sString[i+ 2] == 'e' && sString[i+ 3] == 's' && sString[i+ 4] == 'c' )
                {
                    
                    fArchSalida << "<strong>" << endl;
                    restoDeOracion = sString.substr(i + 5);
                    fArchSalida << "Descripcion" << endl;
                    fArchSalida << "</strong>" << endl;
                    fArchSalida << restoDeOracion << endl;
                    fArchSalida << "<br>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'p' && sString[i+ 2] == 'a' && sString[i+ 3] == 'r' && sString[i+ 4] == 'a' && sString[i+ 5] == 'm'  )
                {
                    fArchSalida << "<strong>" << endl;
                    restoDeOracion = sString.substr(i + 6);
                    fArchSalida << "Parametros: " << endl;
                    fArchSalida << "</strong>" << endl;
                    fArchSalida << restoDeOracion << endl;
                    fArchSalida << "<br>" << endl;
                    break;
                }
                else if(sString[i] == '@' && sString[i+ 1] == 'r' && sString[i+ 2] == 'e' && sString[i+ 3] == 't' && sString[i+ 4] == 'u' && sString[i+ 5] == 'r'  && sString[i+ 6] == 'n')
                {
                    fArchSalida << "<strong>" << endl;
                    restoDeOracion = sString.substr(i + 7);
                    fArchSalida << "Valor de retorno: " << endl;
                    fArchSalida << "</strong>" << endl;
                    fArchSalida << restoDeOracion << endl;
                    fArchSalida << "<br>" << endl;
                    break;
                }
                
            }
        }
        
    }
    //Cierra las etiquetas de html body y html
    fArchSalida << "</body>" << endl;
    fArchSalida << "</html>" << endl;
    //Cierra los dos archivos el de salida y el de entrada
    fArchEntrada.close();
    fArchSalida.close();
    return 0;
}
