/*************************************************************************
                           Simple  -  child class
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Simple> (fichier Simple.h) ----------------
#if ! defined (SIMPLE_H)
#define SIMPLE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Simple>
// Cette classe cree des trajets simples avec une destination depart et d'arrivee (derivees de la classe Trajet)
// et un mode de transport pour le trajet
//------------------------------------------------------------------------

class Simple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    const void Afficher(void);
    // Mode d'emploi : Affiche les destination de depart et arrivee et le mode de transport
    //
    // Contrat : le trajet simple est bien defini
    //

    const char* getMode();
    // Mode d'emploi : Retourne le mode de transport du trajet Simple
    //
    // Contrat :
    //

    void toFile(std::ofstream &sortie);
    // Mode d'emploi : Affiche le trajet dans un fichier selon le format defini
    //
    // Contrat : Trajet est bien defini
    //

    bool isSimple();
    // Mode d'emploi : Retorne vrai si le trajet est Simple
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    Simple & operator = ( const Simple & unSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Simple ( char * dept, char * arrl, char * m);
    // Mode d'emploi : Constructeur qui cree un trajet avec une destination de depart et arrivee
    // et un mode de transport
    // Contrat :
    //

    Simple();
    // Mode d'emploi : Constructeur qui cree un trajet Simple vide (outil pour la creation de trajet complexe
    // Contrat :
    //

    virtual ~Simple( );
    // Mode d'emploi : Destruteur simple
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
char * modeT;

};

//-------------------------------- Autres d�finitions d�pendantes de <Simple>

#endif // Simple_H

