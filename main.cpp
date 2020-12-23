#include <iostream>
#include "Catalog.h"
#include <cstring>

using namespace std;

int main()
{
    Catalog* c = new Catalog();
    int t;
    char type;
    int choix;
    int m, n;
    char *villeDepart = new char[50];
    char *villeArrivee = new char[50];
    bool cont = true;
    while(cont) {
        cout<<"OPTIONS:\n 0-Afficher Catalog\n 1-Ajouter Trajet Simple\n 2-Ajouter Trajet Complexe\n 3-Recherche\n 4-Exporter\n 5-Importer\n 6-Exit\n";
        cin>>t;
        switch(t)
        {
            case 0:
                c->afficherCat();
            break;
            case 1:
                c->addSimple();
            break;
            case 2:
                c->addComplexe();
            break;
            case 3:
                c->chercheTrajet();
            break;
            case 4:
                cout<<"Quel type de trajet voulez-vous exporter? Tapez: S -Simple, C -Complexe, O -Tout Type\n";
                cin>>type;
                cout<<"Pour quelle ville de depart? Tapez le nom ou le mot \"vide\" pour exporter toute ville de depart\n";
                cin>>villeDepart;
                cout<<"Pour quelle ville d'arrivee? Tapez le nom ou le mot \"vide\" pour exporter toute ville d'arrivee\n";
                cin>>villeArrivee;
                cout<<"Sur quelle partie du tableau?\n 1-tout le tableau\n 2-intervalle de M a N\n";
                cin>>choix;
                if (choix==2) {
                    cout<<"Inserer M et N:\n";
                    cin>>m>>n;
                } else {
                    m=0;
                    n=c->getSize();
                }
                c->CatalogToFile(type, villeDepart, villeArrivee, m, n);
            break;
            case 5:
                cout<<"Quel type de trajet voulez-vous importer? Tapez: S -Simple, C -Complexe, O -Tout Type\n";
                cin>>type;
                cout<<"Pour quelle ville de depart? Tapez le nom ou le mot \"vide\" pour importer toute ville de depart\n";
                cin>>villeDepart; //CHECK IF CAN BE EMPTY
                cout<<"Pour quelle ville d'arrivee? Tapez le nom ou le mot \"vide\" pour importer toute ville d'arrivee\n";
                cin>>villeArrivee;
                cout<<"Sur quelle partie du tableau?\n 1-tout le tableau\n 2-intervalle de M a N\n";
                cin>>choix;
                if (choix==2) {
                    cout<<"Inserer M et N:\n";
                    cin>>m>>n;
                } else {
                    m=0;
                    n=1000000;
                }
                c->FileToCatalog(type, villeDepart, villeArrivee, m, n);
            break;
            case 6:
                cont=false;
            break;
            default:
                continue;
        }
    }

    delete c;
    delete[] villeArrivee;
    delete[] villeDepart;

    return 0;
}
