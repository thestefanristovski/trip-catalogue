/*************************************************************************
                           Complexe  -  child class
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Complexe> (fichier Complexe.h) ----------------
#if ! defined (COMPLEXE_H)
#define COMPLEXE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"
#include "Simple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Complexe>
// Cette classe est derivee de la classe Trajet. Elle contient plusieurs trajets Simples
// qui sont enchainees ( les destinations entre la dest. de depart et arrivee sont liees)
//------------------------------------------------------------------------

class Complexe : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    const void Afficher(void);
    // Mode d'emploi : On affiche tous les trajets inclus dans ce trajet complexe
    //
    // Contrat : le trajet est bien defini
    //

    void toFile(std::ofstream &sortie);
    // Mode d'emploi : On affiche le trajet dans un fichier texte selon le format defini
    //
    // Contrat : le trajet est bien defini
    //

    bool isSimple();
    // Mode d'emploi : on appelle cette fonction pour verifier si le trajet est simple ou pas
    //
    // Contrat : le trajet est bien defini
    //


//------------------------------------------------- Surcharge d'op�rateurs
    Complexe & operator = ( const Complexe & unComplexe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Complexe (int n, Simple ** liste, char *d, char* a);
    // Mode d'emploi : Constructeur qui cree un trajet complexe a partir d'une liste de trajets simples
    //
    // Contrat : destinations entre la destination de depart et la dest finale sont liees (verifie dans la fonction main)
    //

    virtual ~Complexe( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
int nbTrips;
Simple ** tripList;

};

//-------------------------------- Autres d�finitions d�pendantes de <Complexe>

#endif // Complexe_H

