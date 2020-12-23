/*************************************************************************
                           Trajet  -  parent class
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TRAJET> (fichier TRAJET.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TRAJET>
// Cette classe est le class Parent de base qui contient la destination de depart et d'arrive finals
// pour tout type de trajet.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const void Afficher(void);
    // Mode d'emploi : Afficher les les desination de depart et arrivee
    //
    // Contrat : le trajet est bien forme
    //

    const char* getDept();
    // Mode d'emploi : Renvoie la destination de Depart
    //
    // Contrat :
    //

    const char* getArrl();
    // Mode d'emploi : Renvoie la destination d'Arrivee
    //
    // Contrat :
    //

    void setDept(char* d);
    // Mode d'emploi : Met en place la destination de Depart
    //
    // Contrat :
    //

    void setArrl(char* a);
    // Mode d'emploi : Met en place la destination de Depart
    //
    // Contrat :
    //

    virtual void toFile(std::ofstream &sortie);
    // Mode d'emploi : affiche un trajet dans un fichier texte selon la structure definie
    //
    // Contrat :
    //

    virtual bool isSimple();
    // Mode d'emploi : retourne faux (redefinie dans les sous-classes)
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( char * destDept, char * destArrl);
    // Mode d'emploi : Constructeur qui cree un trajet avec une destination de depart et arrivee
    //
    // Contrat :
    //

    Trajet ();
    // Mode d'emploi : Constructeur qui cree un trajet vide (outil pour la creation de trajet complexe)
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi : Destructeur simple
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char * cityDept;
char * cityArrl;

};

//-------------------------------- Autres définitions dépendantes de <TRAJET>

#endif // TRAJET_H

