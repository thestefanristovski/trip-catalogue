/*************************************************************************
                           Catalog  -  cpp file for class
                             -------------------
    d�but                : 11/2019
    copyright            : (C) Stefan Ristovski Andrieu Girard
    e-mail               : stefan.ristovski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalog> (fichier Catalog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "Trajet.h"
//#include "Simple.h"
//#include "Complexe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Catalog::getSize() {
    //Algorithme: aucun
    int ntemp = *nb;
    return ntemp;
} //----- Fin de M�thode

void Catalog::addSimple() {
    //Algorithme: Input of destinations and mode, creating new catalog with more allocated memory,
    //creating the instance of class Simple, adding to catalog, deleting temporary strings and old catalog from memory
    cout<<"---AJOUT DE TRAJET SIMPLE---\n";
    char* d = new char[50];
    char* a= new char[50];
    char* m= new char[50];
    cout<<"Depart: \n";
    cin>>d;
    cout<<"Arrivee: \n";
    cin>>a;
    cout<<"Mode de transport: \n";
    cin>>m;
    addSimpleDirect(d,a,m);
    delete[] d;
    delete[] a;
    delete[] m;
} //----- Fin de M�thode

void Catalog::addSimpleDirect(char* d, char* a, char* m) {
    //Algorithme: Input of destinations and mode, creating new catalog with more allocated memory,
    //creating the instance of class Simple, adding to catalog, deleting temporary strings and old catalog from memory
    int ntemp = *nb;
    Trajet ** temp = new Trajet*[ntemp+1];
    for (int i=0; i<ntemp; i++) {
        temp[i] = cat[i];
    }
    temp[ntemp] = new Simple(d,a,m);
    *nb = ntemp+1;
    delete[] cat;
    cat = temp;
} //----- Fin de M�thode

void Catalog::addComplexe() {
    //Algo: input of number of trips, creating a list of Trajets Simples, adding all trips with constraint of matching destinations for
    //transfers (a->x; x->c) creating new catalog with more allocated memory,
    //creating the instance of class Complexe, adding to catalog, deleting temporary strings and old catalog from memory
    cout<<"---AJOUT DE TRAJET COMPLEXE---\n";
    int x;
    cout<<"Combien de trajets sont inclus? \n";
    cin>>x;
    Simple** listeS = new Simple*[x];
    char* dfinal = new char[50];
    char* afinal= new char[50];

    for(int i=0; i<x; i++) {
        char* a;
        char* d;
        char* m;
        if(i==0) {
            d = new char[50];
            cout<<"Destination de depart:\n";
            cin>>d;
            strcpy(dfinal,d);
            a= new char[50];
            cout<<"Premier arret:\n";
            cin>>a;
            m= new char[50];
            cout<<"Mode de Transport pour 1er trajet:\n";
            cin>>m;
            listeS[i] = new Simple(d,a,m);
            delete[] d;
            d= new char[50];
            strcpy(d,a);
        } else if (i==x-1) {
            delete[] a;
            a= new char[50];
            cout<<"Destination finale:\n";
            cin>>a;
            strcpy(afinal,a);
            delete[] m;
            m= new char[50];
            cout<<"Mode de Transport pour "<<i+1<<"eme trajet:\n";
            cin>>m;
            listeS[i] = new Simple(d,a,m);
            delete[] d;
            delete[] a;
            delete[] m;
        } else {
            a= new char[50];
            cout<<"Destination suivante:\n";
            cin>>a;
            m= new char[50];
            cout<<"Mode de Transport pour "<<i+1<<"eme trajet:\n";
            cin>>m;
            listeS[i] = new Simple(d,a,m);
            d= new char[50];
            strcpy(d,a);
        }
    }
    addComplexeDirect(x,listeS,dfinal,afinal);
    delete[] dfinal;
    delete[] afinal;
} //----- Fin de M�thode

void Catalog::addComplexeDirect(int x, Simple** listeS, char* dfinal, char* afinal) {
    //Algo: input of number of trips, creating a list of Trajets Simples, adding all trips with constraint of matching destinations for
    //transfers (a->x; x->c) creating new catalog with more allocated memory,
    //creating the instance of class Complexe, adding to catalog, deleting temporary strings and old catalog from memory
    int ntemp = *nb;
    Trajet ** temp = new Trajet*[ntemp+1];
    for (int i=0; i<ntemp; i++) {
        temp[i] = cat[i];
    }
    temp[ntemp] = new Complexe(x,listeS,dfinal,afinal);
    *nb = ntemp+1;
    delete[] cat;
    cat=temp;
} //----- Fin de M�thode

const void Catalog::afficherCat() {
    //Algo: boucle for qui affiche chaque element du catalogue
    cout<<"---NOTRE CATALOG DE TRAJETS---\n";
    int ntemp = *nb;
    for (int i=0; i<ntemp; i++) {
        cat[i]->Afficher();
        //cout<<endl<<cat[i]->getDept();
        cout<<endl;
    }
} //----- Fin de M�thode


bool Catalog::searchComplexe(const char* d, const char*a, int t, Trajet** resultats, int* maxi) {
    //Algo: Fontion recursive qui cherche tous les trajets possibles a partir d'un element du catalogue
    //d,a = destinations; cat, nb = catalogue et sa taille; t = index du trahet pour lequel on cherche solutions
    //nbSol = garde le nombre des solutions trouves, resultats, maxi = garde les resultats et son taille
    bool res = false;
    int ntemp = *nb;
    int nbSolTemp = *nbSol;
    if(t==-1){              //PART THAT IS CALLED BY RECURSION, APPLIES ALGO TO ALL ELEMENTS
        for(int i=0; i<ntemp; i++) {
            if(strcmp(cat[i]->getArrl(), a) == 0) { //IF ARRIVAL MATCHES
                if(strcmp(cat[i]->getDept(), d)==0) { //IF DEPARTURE MATCHES
                    resultats[nbSolTemp] = cat[i];
                    if(nbSolTemp>*maxi)
                        *maxi = nbSolTemp;
                    res = true;
                    nbSolTemp ++;
                    *nbSol = nbSolTemp;
                } else {
                    *nbSol = nbSolTemp + 1;
                    if(searchComplexe(d,cat[i]->getDept(), -1, resultats, maxi)) {
                        resultats[nbSolTemp] = cat[i];
                        if(nbSolTemp>*maxi)
                        *maxi = nbSolTemp;
                        res = true;
                        nbSolTemp ++;
                        *nbSol = nbSolTemp;

                    } else {
                    }
                }

            } else {
            }
        }
    } else {                //PART CALLED BY MAIN, APPLIES ALGO TO ONLY ONE TRAJET
        if(strcmp(cat[t]->getArrl(), a) == 0) { //IF ARRIVAL MATCHES
            if(strcmp(cat[t]->getDept(), d)==0) { //IF DEPARTURE MATCHES
                resultats[nbSolTemp] = cat[t];
                res = true;
            } else {
                *nbSol = nbSolTemp + 1;
                if(searchComplexe(d,cat[t]->getDept(), -1, resultats, maxi)) {
                    resultats[nbSolTemp] = cat[t];
                    if(nbSolTemp>*maxi)
                        *maxi = nbSolTemp;
                    res = true;
                    nbSolTemp ++;
                    *nbSol = nbSolTemp;
                } else {
                }
            }
        } else {
        }
    }
    return res;
} //----- Fin de M�thode

void Catalog::CatalogToFile(char condType, char* depart, char* arrivee, int m, int n) {
    //Algo: Prend en compte toutes les conditions pour exporter les trajets necessaired du catalogue dans un fichier texte
    char* fileDest = new char[100];
    cout<<"Nom de Fichier: (n'oubliez pas l'extension .txt)\n";
    cin>>fileDest;
    //cout<<"M, N"<<m<<n<<endl;
    ofstream sortie(fileDest);
    for (int i=m; i<n; i++) {
        if(cat[i]->isSimple() && (condType=='S' || condType=='O') && (strcmp(cat[i]->getDept(), depart)==0 || strcmp(depart, "vide")==0) && (strcmp(cat[i]->getArrl(), arrivee)==0 || strcmp(arrivee,"vide")==0)) { //CHECK IF FUNCTION EXISTS TO VERIFY STRING EMPTY
            //cout<<"A"<<endl;
            cat[i]->toFile(sortie);
        }
        if (!(cat[i]->isSimple()) && (condType=='C' || condType=='O') && (strcmp(cat[i]->getDept(), depart)==0 || strcmp(depart, "vide")==0) && (strcmp(cat[i]->getArrl(), arrivee)==0 || strcmp(arrivee,"vide")==0)) {
            //cout<<"A"<<endl;
            cat[i]->toFile(sortie);
        }
    }
    delete[] fileDest;
} //--Fin de CatalogToFile

void Catalog::FileToCatalog(char condType, char* depart, char* arrivee, int mi, int n) {
    //Algo: Lit le fichier texte ligne par ligne, cree les trajets et les ajoute dans le catalogue
    //2 algos differents pour chaque type de trajet vu la structure differente
    int nbTrajet =0;
    char* fileDest = new char[100];
    cout<<"Ecrivez le nom de Fichier: (n'oubliez pas l'extension .txt) \n";
    cin>>fileDest;
    ifstream input(fileDest);
    char* line = new char[100];
    while(input.getline(line, 100, '\n'))
    {
        if(strlen(line)==1) {
            if(line[0]=='S') {
                char* d = new char[50];
                char* a = new char[50];
                char* m = new char[50];
                input.getline(d, 100, '\n');
                input.getline(a, 100, '\n');
                input.getline(m, 100, '\n');
                if((condType=='S' || condType=='O') && (strcmp(d, depart)==0 || strcmp(depart, "vide")==0) && (strcmp(a, arrivee)==0 || strcmp(arrivee,"vide")==0) && nbTrajet>=mi && nbTrajet<=n ) {
                    addSimpleDirect(d,a,m);
                }
                nbTrajet++;
                delete[] d;
                delete[] a;
                delete[] m;
            } else if (line[0]=='C') {
                int x;
                input>>x;
                Simple** listeS = new Simple*[x];
                char* destFinal = new char[50];
                char* arrlFinal = new char[50];
                char* d = new char[50];
                input.getline(d, 100, '\n');
                input.getline(d, 100, '\n');
                strcpy(destFinal, d);
                for (int i=0; i<x; i++) {
                        char* a = new char[50];
                        char* m = new char[50];
                        input.getline(a, 100, '\n');
                        input.getline(m, 100, '\n');
                        listeS[i] = new Simple(d,a,m);
                        strcpy(d,a);
                        if(i==x-1) {
                            strcpy(arrlFinal, a);
                        }
                        delete[] a;
                        delete[] m;
                }
                if((condType=='C' || condType=='O') && (strcmp(destFinal, depart)==0 || strcmp(depart, "vide")==0) && (strcmp(arrlFinal, arrivee)==0 || strcmp(arrivee,"vide")==0) && nbTrajet>=mi && nbTrajet<=n ) {
                    addComplexeDirect(x, listeS, destFinal, arrlFinal);
                }
                delete[] d;
                delete[] destFinal;
                delete[] arrlFinal;
                nbTrajet++;
            }
        }
    }
    delete[] fileDest;
    delete[] line;
} //--Fin de FileToCatalog

void Catalog::chercheTrajet() {
    //Algo: Fonction qui trouve les trajets possibles et les affiche, elle applique la fonction precedente
    //a chaque element du catalogue
    int ntemp = *nb;
    Trajet ** resultats = new Trajet*[ntemp];

    cout<<"---RECHERCHE DE TRAJETS---\n";
    char*d = new char[50];
    char*a = new char[50];
    cout<<"Depart :\n";
    cin>>d;
    cout<<"Arrivee:\n";
    cin>>a;
    cout<<"\nTrajets Possibles:\n";
    int i=0;
    int* maxi = new int;
    *maxi = 0;
    while(i<ntemp) {
        *nbSol = 0;
        *maxi = 0;
        if(searchComplexe(d,a,i, resultats, maxi)) { //AFFICHAGE DES SOLUTIONS
            int n = *maxi;
            //cout<<"n "<<n<<endl;
            for (int k=n; k>=0; k--) {
                if(k==n) {
                    cout<<"\t";
                    resultats[k]->Afficher();
                } else if (strcmp(resultats[k]->getDept(),resultats[k+1]->getDept()) == 0) {
                    cout<<"\tOU ";
                    resultats[k]->Afficher();
                } else if(k==0){
                    cout<<"\t+ ";
                    resultats[k]->Afficher();
                } else {
                    cout<<"\t+ ";
                    resultats[k]->Afficher();
                }
            }
            cout<<endl;
        }
        i++;
    }
    delete[] d;
    delete[] a;
    delete[] resultats;
    delete maxi;
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Catalog::Catalog ( const Catalog & unCatalog )
// Algorithme : aucun
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Catalog>" << endl;
    #endif
} //----- Fin de Catalog (constructeur de copie)


Catalog::Catalog ()
    // Algorithme : on allue dynamiquement de memoire pour stocker les noms de villes de depart et arrivee
    //
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalog>" << endl;
    #endif
    cat = new Trajet*();
    nb = new int;
    *nb = 0;
    nbSol = new int;
    *nbSol = 0;

} //----- Fin de Catalog


Catalog::~Catalog ( )
// Algorithme : Destructeur
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
    for(int i=0; i<*nb; i++) {
        delete cat[i];
    }
    delete[] cat;
    delete nb;
    delete nbSol;


} //----- Fin de ~Catalog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


