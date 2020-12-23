/*************************************************************************
                           TRAJET  -  cpp file for class
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const void Trajet::Afficher(void)
//Algotithme: aucun
{
    cout<<cityDept<<" -> "<<cityArrl;
} //----- Fin de Méthode

const char* Trajet::getDept()
//Algotithme: aucun
{
    return cityDept;
} //----- Fin de Méthode

const char* Trajet::getArrl()
//Algotithme: aucun
{
    return cityArrl;
} //----- Fin de Méthode

void Trajet::setDept(char*d)
//Algotithme: aucun
{
    strcpy(cityDept,d);
} //----- Fin de Méthode

void Trajet::setArrl(char*a)
//Algotithme: aucun
{
    strcpy(cityArrl,a);
} //----- Fin de Méthode

void Trajet::toFile(ofstream &sortie)
//Algo: aucun
{
}//-- Fin de toFile

bool Trajet::isSimple()
//Algo: aucun
{
    return false;
}//--Fin de isSimple

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme : aucun
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet ( char * destDept, char * destArrl )
    // Algorithme : on allue dynamiquement de memoire pour stocker les noms de villes de depart et arrivee
    //
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
    cityDept = new char[strlen(destDept)+1];
    cityArrl = new char[strlen(destArrl)+1];
    strcpy(cityDept,destDept);
    strcpy(cityArrl,destArrl);

} //----- Fin de Trajet

Trajet::Trajet()
    // Algorithme : aucun
    //
{

} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme : Destructeur
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete[] cityArrl;
    delete[] cityDept;


} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

