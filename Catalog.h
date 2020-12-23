/*************************************************************************
                           Catalog  - class
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalog> (fichier Catalog.h) ----------------
#if ! defined ( Catalog_H )
#define Catalog_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Simple.h"
#include "Complexe.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
// Cette classe est le class qui gere le catalogue et toutes ses fonctions
//------------------------------------------------------------------------

class Catalog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int getSize();
    // Mode d'emploi : retourne la taille du catalogue
    //
    // Contrat :
    //

    void addSimple();
    // Mode d'emploi : Ajouter un trajet simple au catalogue
    //
    // Contrat :
    //

    void addSimpleDirect(char* d, char* a, char* m);
    // Mode d'emploi : Ajouter un trajet simple au catalogue
    //
    // Contrat :
    //

    void addComplexe();
    // Mode d'emploi : Ajouter un trajet complexe au catalogue
    //
    // Contrat :
    //

    void addComplexeDirect(int x, Simple** listeS, char* dfinal, char* afinal);
    // Mode d'emploi : Ajouter un trajet complexe au catalogue
    //
    // Contrat :
    //

    const void afficherCat();
    // Mode d'emploi : Afficher les trajets dans le catalogue
    //
    // Contrat : le Catalog est bien forme
    //

    bool searchComplexe(const char* d, const char*a, int t, Trajet** resultats, int* maxi);
    // Mode d'emploi : Trouver options possibles pour element t - appele automatiquement par la methode chercheTrajet
    //
    // Contrat : le Catalog est bien forme
    //

    void chercheTrajet();
    // Mode d'emploi : Chercher trajets possibles
    //
    // Contrat : le Catalog est bien forme
    //

    void CatalogToFile(char condType, char* depart, char* arrivee, int m, int n);
    // Mode d'emploi : Exporter le catalogue dans un fichier texte avec le format defini
    //
    // Contrat : le Catalog est bien forme
    //

    void FileToCatalog(char condType, char* depart, char* arrivee, int m, int n);
    // Mode d'emploi : Importer des trajets dans le catalogue a partir d'un fichier texte dans le format defini
    //
    // Contrat : la structure du fichier est bien definie
    //

//------------------------------------------------- Surcharge d'opérateurs
    Catalog & operator = ( const Catalog & unCatalog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Catalog ( const Catalog & unCatalog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalog ();
    // Mode d'emploi : Constructeur qui cree un Catalog vide
    //
    // Contrat :
    //

    virtual ~Catalog ( );
    // Mode d'emploi : Destructeur simple
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet** cat;
int* nb;
int* nbSol;

};

//-------------------------------- Autres définitions dépendantes de <Catalog>

#endif // Catalog_H


