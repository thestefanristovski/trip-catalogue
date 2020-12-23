/*************************************************************************
                           Simple  -  fichier cpp de class child
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Simple> (fichier Simple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Simple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
const void Simple::Afficher(void)
//Algotithme: aucun
{
    Trajet::Afficher();
    cout<<" avec "<<modeT;
} //----- Fin de M�thode

const char * Simple::getMode()
//Algotithme: aucun
{
    return modeT;
} //----- Fin de M�thode

void Simple::toFile(ofstream &sortie)
//Algo: Affiche les caracteristiques du trajet Simple dans le format defini
{
        sortie<<"S"<<"\n";
        sortie<<cityDept<<"\n";
        sortie<<cityArrl<<"\n";
        sortie<<modeT<<"\n";
}//-- Fin de toFile

bool Simple::isSimple()
//Algo: aucun
{
    return true;
} //--Fin de isSimple

//------------------------------------------------- Surcharge d'op�rateurs



//-------------------------------------------- Constructeurs - destructeur
Simple::Simple ( char * dept, char * arrl, char * m):Trajet(dept,arrl)
    // Algorithme : on allue dynamiquement de memoire pour stocker les noms de villes de depart et arrivee
    // et le mode de transport
{
    #ifdef MAP
        cout << "Appel au constructeur de <Simple>" << endl;
    #endif
    modeT = new char[strlen(m)+1];
    strcpy(modeT,m);

} //----- Fin de Simple

Simple::Simple():Trajet()
    // Algorithme : aucun
{

} //----- Fin de Simple


Simple::~Simple ( )
// Algorithme : aucun
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Simple>" << endl;
#endif
delete[] modeT;

} //----- Fin de ~Simple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

