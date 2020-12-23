/*************************************************************************
                           Complexe  -  fichier cpp de la classe
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski, Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Complexe> (fichier Complexe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Complexe.h"
#include "Trajet.h"
#include "Simple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const void Complexe::Afficher(void)
//Algotithme: on affiche tous les trajets simples inclus dans ce trajet
{
    for (int i=0; i<nbTrips; i++)
    {
        tripList[i]->Afficher();
        if(i!=nbTrips-1)
            cout<<" - ";
    }
} //----- Fin de Méthode

void Complexe::toFile(ofstream &sortie)
//Algo: Affiche le type de trajet, le nobre de sous trajets, et affiche les destinations pour chaque sous trajet
{
    sortie<<"C"<<"\n";
    sortie<<nbTrips<<"\n";
    for (int i=0; i<nbTrips; i++) {
        if(i==0) {
            sortie<<tripList[i]->getDept()<<"\n";
        }
        sortie<<tripList[i]->getArrl()<<"\n";
        sortie<<tripList[i]->getMode()<<"\n";
    }
} //--Fin de toFile

bool Complexe::isSimple()
//Algo: aucun
{
    return false;
} //--Fin de isSimple

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Complexe::Complexe (int n, Simple ** liste, char *d, char* a) : Trajet(d, a)
    // Algorithme : on allue dynamiquement de memoire pour stocker les noms de villes de depart et arrivee
    //
{
    #ifdef MAP
        cout << "Appel au constructeur de <Complexe>" << endl;
    #endif
    nbTrips = n;
    tripList = liste;
} //----- Fin de Complexe


Complexe::~Complexe ( )
// Algorithme : aucun
//
{
#ifdef MAPs
    cout << "Appel au destructeur de <Complexe>" << endl;
#endif
    for(int i=0; i<nbTrips; i++) {
        delete tripList[i];
    }
    delete[] tripList;

} //----- Fin de ~Complexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

