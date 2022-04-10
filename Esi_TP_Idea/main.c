#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Concurents Concurents;
struct Concurents
{
    char nom_athlete[25]; // 25 caractères au plus concernant les noms d'athlètes
    Concurents *suivant;
};

int t,u;
char tabPays[150][100]; // 150 pays d'au plus 100 caractères, ps: variable Globale.

char tabepreuve[200][100];
 // 200 épreuves d'au plus 100 caractères ps: variable Globale.

// Procedure random chaine de caractere aleatoire pour les athletes
//-------------------------------
char *randstring(size_t length) {

    static char charset[26] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (int n = 0;n < length;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

// proc�dure JO (remplissage des athlètes dans la matrice)
struct Concurents *tabjo[150][200]; // 200 épreuves max et 150 pays max 25 caractères pour les noms des athlètes ps: variable Globale.
struct Concurents *tete[200*150],*ptr[200*150]; // déclaration de la liste chainée; 200x150 :nombre max des listes a créé sur cette matrice de taille max 200x150.
int nbr_cellule[200*150] = {0};

void cree_tabjo(){


    int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }


        printf("Voici les pays qui ont ete remplis: \n");
        for(s = 0; s < 151; s++){
            printf("%d : %s \n", s, tabPays[s]);
        }


    int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };
for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}


        printf("Voici les epreuve qui ont ete remplis: \n");
        for(d = 0; d < 201; d++){
            printf("%d : %s \n", d, tabepreuve[d]);
        }

    int k;
    int i = 0;
    int j = 0;
    int l = 0; // indice cellule dans LLC
    char *nomAthlete;
    struct Concurents *tete_lecture, *ptr_lecture; // pour la lecture de la liste chainée (pour ne pas perdre la tete)


    // maintenant: la crétion de la matrice TABJO.

            printf("\n**************************RECAPITULATIF************************");

            for (j=0; j<t;j++){
                    for(i=0; i<u; i++) {
                            tete[l]=ptr[l]=NULL; // initaisation des pointeurs

            int aleatoire = rand() % 11; // valeur aléatoire comprise entre 0 et 10.
            int k = 0;
            printf("\n-----------------------%s/%s----------------------------------",tabepreuve[i], tabPays[j]);
            printf("\n Le nombre des athletes d'origine < %s > inscrit pour l'epreuve < %s > est: %d ",tabPays[j], tabepreuve[i], aleatoire);
            for(k = 0; k < aleatoire; k++){
                ptr[l]=malloc(sizeof(struct Concurents));
                    if(ptr!=NULL){
                        nomAthlete=randstring(26);
                        strcpy(ptr[l]->nom_athlete,nomAthlete);
                        ptr[l]->suivant=tete[l];
                        tete[l]=ptr[l];
                    }
            } //fin remplissage des athlètes pour chaque pays

            tabjo[i][j] = tete[l]; // affectation de la tete de liste dans la case de la matrice

            // juste un peu d'ordre pour le bon visionnage sur la console
            printf("\n**************************RECAPITULATIF************************");



            printf("\n Information: les athletes inscrit pour l'epreuve <%s>  origine du pays <%s> sont : ",tabepreuve[j], tabPays[i]);

                tete_lecture = tete[l];
                while(tete_lecture){
                    printf("\n -%s ",tete_lecture->nom_athlete);
                    ptr_lecture=tete_lecture;
                    tete_lecture=tete_lecture->suivant;
                }
                nbr_cellule[l] = k; //nombre de cellule créé
                l++; // indice pour la prochaine tete de liste (nouvelle liste pour chaque case de la matrice)

        } // fin j
    } // fin i
}
//--------------------------------
// Procédure inserath (réponse numéro 2)
//--------------------------------

void inserath (char nomath[26], int nump, int nume){

    struct Concurents *athlete_list ;
    struct Concurents *ptr_lecture, *tete_lecture, *pointeur = NULL ;
    int indice = 0; // 1: si un athlete existe déja, 0: c'est un nouveau athlete.
    int nombre_athlete_deja_inscrit = 0;
    athlete_list = tabjo[nume][nump]; // liste athlete d'origine du pays numP et d'épreuve numE.
    tete_lecture = athlete_list;
    ptr_lecture = NULL;

    // lecture des données de la liste chainée => spécialement la case tabjo[nume][nump].
    while(tete_lecture != NULL){
        printf("\n -%s ",tete_lecture->nom_athlete);
        nombre_athlete_deja_inscrit++; // calculer le nombre d'athlete déja inscrit
        if(strcmp (nomath, tete_lecture->nom_athlete) == 0){ // athlete existe déja
            indice = 1;
        }
        ptr_lecture=tete_lecture;
        tete_lecture=tete_lecture->suivant;
    }

    if(nombre_athlete_deja_inscrit >= 10){ // si max athlete deja atteint.
        indice = 1;
    }
    if(indice == 0){ // c'est un nouveau athlète + maxathlete pas encore atteint => donc on peut l'ajouter.

        pointeur = NULL;
        pointeur=malloc(sizeof(struct Concurents));
        if(pointeur!=NULL){
            strcpy(pointeur->nom_athlete,nomath); // remplissage du nom du nouveau athlète.
            pointeur->suivant=athlete_list;
            athlete_list=pointeur;
        }
        tabjo[nume][nump] = athlete_list; // affectation de la nouvelle liste dans la case specifie
    }
    else{
        printf("\n ERREUR: On peut pas ajouter un nouveau athlète car les conditions d'ajouts ne sont pas respectées");
    }
}
//-------------------------------
// Proc�dure d'affichage des athlète d'un pays donné.
//---------------------------------

void listathpays (char pays[100]){

     int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }
     int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };


for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}

    int j = 0;
    int i = 0;
    int indice_pays = -1;
    struct Concurents *tete_lecture, *ptr_lecture = NULL; // pour la lecture de la liste chainée (pour ne pas perdre la tete)

    printf("\n\n\n-------------------------------Liste des athletes ----------------------------------");

    for(i = 0; i < t; i++ ){
        if(strcmp(tabPays[i], pays) == 0){
            indice_pays = i;
        }
    }
    if(indice_pays == -1){ // pays est inconnu.
        printf("\n Information: Le pays est inconnu.");
    }
    else{
        for(j = 0 ; j < u; j++){
            printf("\n Les athletes du pays: *%s*: ",tabPays[indice_pays]);
            printf("\n Pour l'epreuve <%s>: ",tabepreuve[j]);
            tete_lecture = tabjo[j][indice_pays];

            // lecture des données de la liste chainée
            if (tete_lecture == NULL){ // dans le cas ou la liste est vide
                exit(EXIT_FAILURE);
            }
            while(tete_lecture != NULL){
                printf("\n -->%s ",tete_lecture->nom_athlete);
                ptr_lecture=tete_lecture;
                tete_lecture=tete_lecture->suivant;
                //free(ptr_lecture);
            }
        } // fin j
    }//else
}
//---------------------------------
// Procedure sansath
//---------------------------------

bool sansath (int ne){ // Réponse a la question 4.
int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }
     int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };

for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}


    int i = 0;

    struct Concurents *tete_lecture = NULL; // pour la lecture de la liste chainée (pour ne pas perdre la tete)

    printf("\n\n\n-------------------------------Reponse a la question 4 ----------------------------------");
    for(i = 0; i < t; i++){
            tete_lecture = tabjo[i][ne];

            // lecture des données de la liste chainee
            if (tete_lecture == NULL){ // dans le cas ou cette épreuve n'a aucun athlète inscrit
                return false;
            }
            else{
            return true;
            }
    } // fin i
return false; // cas particulier: dans le cas ou on a aucun pays ajouté
}

//-----------------------------
// Procedure listjo
//----------------------------

void listjo(){// réponse a la question 5
     int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }
    int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };

for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}
    int i = 0;
    int j = 0;

    struct Concurents *tete_lecture, *ptr_lecture = NULL; // pour la lecture de la liste chainée (pour ne pas perdre la tete)

    printf("\n\n\n-------------------------------LLC ----------------------------------");
    for(i = 0; i < t; i++){
        for(j = 0 ; j < u; j++){
                printf("\n Information: les athletes inscrit pour l'epreuve <%s>  origine du pays <%s> sont : ",tabepreuve[j], tabPays[i]);
                tete_lecture = tabjo[j][i];

                // lecture des données de la liste chainée
                if (tete_lecture == NULL){ // dans le cas ou la liste est vide
                    printf("\n -Aucun athlete n est inscrit pour cette epreuve et pour ce pays. ");
                }
                while(tete_lecture != NULL){
                    printf("\n -%s ",tete_lecture->nom_athlete);
                    ptr_lecture=tete_lecture;
                    tete_lecture=tete_lecture->suivant;
                    //free(ptr_lecture);
                }
        } // fin j
    } // fin i
}
//-------------------
// Procedure suppays
//-----------------


void suppays(char pays[100]){ // Réponse a la question 6
     int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }
     int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };

for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}

    int j =0;
    int i =0;
    int indice_pays = -1;

    printf("\n\n\n-------------------------------Pays a supprime: %s ----------------------------------\n", pays);

    for(i = 0; i < 151; i++ ){

        if(strcmp(tabPays[i], pays) == 0){
            memset(tabPays[i], '\0', sizeof tabPays[i]); // suppresion du pays de la liste des pays
           for(j=0;j<201;j++){
            tabjo[j][i] = NULL; // suppresion de la case qui correspond au pays qui s'est retiré au JO.
            indice_pays = i;
        }
        }
    }

    if(indice_pays == -1){
        printf("\n -Pays inconnu.");
    }
    else{

        printf("\n -Pays supprime avec succes.");


    }
}
//-----------------------
// Procedure supath
//-----------------------

void supath(char nomath[26], int nump, int nume) // réponse a la question 7: suppresion d'un athlète.
{
     int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }
     int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };

for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}


    struct Concurents *tete_lecture, *tete_temp, *ptr_lecture = NULL; // pour la lecture de la liste chainée (pour ne pas perdre la tete)

    printf("\n\n\n-Suppresion de l'athlete: %s.", nomath);
    printf("\n-Origine: %s.", tabPays[nump]);
    printf("\n-Epreuve: %s.", tabepreuve[nume]);
    tete_lecture = tabjo[nume][nump];

    // lecture des données de la liste chainée

    if (tete_lecture == NULL){ // dans le cas ou la liste est vide
        exit(EXIT_FAILURE);
    }
    if(strcmp(tete_lecture->nom_athlete, nomath) == 0){ // athl�te trouvé en tete de liste.
        tabjo[nume][nump] = tete_lecture->suivant;
    }
    else{ // athl�te trouv� au milieu de en fin de la liste.
        ptr_lecture=tete_lecture;
        while(ptr_lecture!= NULL){
            if(strcmp(ptr_lecture->suivant->nom_athlete, nomath) == 0){// athlète a supprimer trouvé sur la prochaine liste.
                tete_temp = ptr_lecture->suivant;
                ptr_lecture = ptr_lecture->suivant->suivant;
                free(tete_temp);
            }
            ptr_lecture=ptr_lecture->suivant;
        }
        tabjo[nume][nump] = tete_lecture;
    }
}
//-------------------------
// Procedure suplignesvides
//-------------------------

void suplignesvides() // réponse a la question 8
{
     int C,s;
char* tabPays[151];

char* tabqlq[151]= {"Afghanistan",	"Afrique Du Sud", "Albanie","Algérie","Allemagne","Andorre","Angola	","Antigua-et-barbuda",
"Arabie Saoudite","Argentine","Arménie	","Aruba","Australie","Azerbaïdjan","Bahamas","Bahreïn","Bangladesh","Barbade","Belgique","Belize",
"Bénin","Bermudes","Bhoutan	","Biélorussie","Birmanie","Bolivie","Bosnie-herzégovine","Botswana","Brésil","Brunei","Bulgarie","Burkina Faso","Burundi","Cambodge",
"Cameroun","Canada","Chili","Chine","Colombie","Corée Du Sud","Costa Rica","Côte D'ivoire","Croatie","Cuba","Danemark","Djibouti","Dominique","Égypte","Émirats Arabes Unis",
"Érythrée","Espagne","États-unis","Éthiopie","Fidji","Finlande","France","Gabon","Gambie","Géorgie","Ghana","Grèce","Grenade","Guam","Guatemala","Guinée","Guinée-Bissau","Guyana",
"Haïti","Honduras","Hong Kong","Hongrie","Inde","Indonésie","Irak","Iran","Irlande","Islande","Italie","Jamaïque","Japon","Kazakhstan","Kenya","Kirghizistan",
"Lesotho","Lettonie","Liban","Liberia","Libye","Luxembourg","Madagascar","Malaisie","Maldives","Mali","Malte","Maroc","Marshall","Mauritanie","Mexique","Micronésie",
"Moldavie","Monaco","Mongolie","Mozambique","Namibie","Nauru","Népal","Nicaragua","Niger","Nigeria","Norvège","Nouvelle-Zélande","Oman","Pakistan","Panama",
"Pays-Bas","Pérou","Philippines","Pologne","Porto Rico","Portugal","Qatar","Roumanie","Salomon","Salvador","Sénégal","Serbie","Seychelles","Sierra Leone",
"Singapour","Slovaquie","Slovénie","Somalie","Soudan","Soudan du Sud","Sri Lanka","Suède","Suisse","Suriname","Syrie","Tadjikistan","Taipei Chinois","Tanzanie",
"Tchad","Thaïlande","Uruguay","Vanuatu","Venezuela","Viêt Nam","Yémen","Zambie","Zimbabwe"	};

 for(C=0;C<151;C++)
 {
  tabPays[C]=tabqlq[C];
 }
    int d= 0;
    int r;
    char* tabepreuve[201];

char* tabqlqq[201]={"Athétisme	Homme 100 m","Athétisme	Homme 200 m","Athétisme	Homme 400 m","Athétisme	Homme 800 m","Athétisme	Homme 1 500 m","Athétisme	Homme 5 000 m","Athétisme	Homme 10 000 m",
"Athétisme	Homme Marathon","Athétisme	Homme 110 m haies","Athétisme	Homme 400 m haies","Athétisme	Homme 3 000 m steeple","Athétisme	Homme 4 × 100 m",
"Athétisme	Homme 4 × 400 m","Athétisme	Homme 20 km marche","Athétisme	Homme 50 km marche","Athétisme	Homme Saut en hauteur","Athétisme	Homme Saut à la perche",
"Athétisme	Homme Saut en longueur","Athétisme	Homme Triple saut","Athétisme	Homme Lancer du poids","Athétisme	Femme 100 m","Athétisme	Femme 200 m",
"Athétisme	Femme 400 m","Athétisme	Femme 800 m","Athétisme	Femme 1 500 m","Athétisme	Femme 5 000 m","Athétisme	Femme 10 000 m","Athétisme	Femme Marathon",
"Athétisme	Femme 110 m haies","Athétisme	Femme 400 m haies","Athétisme	Femme 3 000 m steeple","Athétisme	Femme 4 × 100 m","Athétisme	Femme 4 × 400 m",
"Athétisme	Femme 20 km marche","Athétisme	Femme 50 km marche","Athétisme	Femme Saut en hauteur","Athétisme	Femme Saut à la perche","Athétisme	Femme Saut en longueur",
"Athétisme	Femme Triple saut","Athétisme	Femme Lancer du poids","Athétisme	Décathlon","Aviron	Skiff","Aviron	Deux de couple","Aviron	Deux de couple poids légers",
"Aviron	Quatre de couple","Aviron	Deux sans barreur","Aviron	Quatre sans barreur","Aviron	Huit","Badminton Simple","Badminton Double","Baseball	Finale""Basketball	Finale 5 x 5",
"Basketball	Finale 3 x 3","Boxe Poids mouches (-52 kg)","Boxe Poids coqs (-57 kg)","Boxe Poids légers (-63 kg)","Boxe Poids welters (-69 kg)","Boxe Poids moyens (-75 kg)",
"Boxe Poids mi-lourds (-81 kg)","Boxe Poids lourds (-91 kg)","Boxe Poids super-lourds (+91 kg)","Canoë-kayak	Slalom C1","Canoë-kayak	Slalom K1","Canoë-kayak	C1 - 1 000 m",
"Canoë-kayak	C2 - 1 000 m","Canoë-kayak	K1 - 200 m","Canoë-kayak	K1 - 1 000 m","Canoë-kayak	K2 - 1 000 m",
"Canoë-kayak	K4 - 500 m","Cyclisme Course en ligne (route)","Cyclisme Contre-la-montre (route)","Cyclisme  Keirin (piste)","Cyclisme  Vitesse individuelle (piste)",
"Cyclisme  Vitesse par équipes (piste)",
"Cyclisme  Poursuite par équipes (piste)","Cyclisme  Course à l'américaine (piste)","Cyclisme Omnium (piste)","Cyclisme VTT cross-country","Cyclisme BMX freestyle",
"Cyclisme BMX racing","Equitation	Dressage individuel","Equitation	Dressage par équipes","Equitation	Saut d'obstacles individuel","Equitation	Saut d'obstacles par équipes",
"Equitation	Concours complet individuel","Equitation	Concours complet par équipes","Escalade	Finale","Escrime	Épée individuelle","Escrime	Épée par équipes",
"Escrime	Fleuret individuel","Escrime	Fleuret par équipes","Escrime	Sabre individuel","Escrime	Sabre par équipes","Football	Finale","Golf	Finale",
"Gymnastique	Artistique - Concours gén, par équipe","Gymnastique	Artistique - Concours général","Gymnastique	Artistique - Sol","Gymnastique	Artistique - Cheval d'arçons",
"Gymnastique	Artistique - Anneaux","Gymnastique	Artistique - Saut de cheval","Gymnastique	Artistique - Barres parallèles","Gymnastique	Artistique - Barre fixe",
"Gymnastique	Trampoline","Haltérophilie	61 kg","Haltérophilie	67 kg ","Haltérophilie	73 kg ","Haltérophilie	81 kg ","Haltérophilie	96 kg ","Haltérophilie	109 kg",
"Haltérophilie	+109 kg ","Handball	Finale","Hockey sur gazon	Finale","Judo	Moins de 60 kg","Judo	Moins de 66 kg","Judo	Moins de 73 kg","Judo	Moins de 81 kg",
"Judo	Moins de 90 kg","Judo	Moins de 100 kg","Judo	Plus de 100 kg","Judo	Par équipes","Karaté	Kumite - Poids légers","Karaté	Kumite - Poids moyens",
"Karaté	Kumite - Poids lourds","Karaté	Kata","Lutte	Gréco-romaine - Moins de 60 kg","Lutte	Gréco-romaine - Moins de 67 kg","Lutte	Gréco-romaine - Moins de 77 kg",
"Lutte	Gréco-romaine - Moins de 87 kg","Lutte	Gréco-romaine - Moins de 97 kg","Lutte	Gréco-romaine - Moins de 130 kg","Lutte	Lutte libre - Moins de 57 kg",
"Lutte	Lutte libre - Moins de 65 kg","Lutte	Lutte libre - Moins de 74 kg","Lutte	Lutte libre - Moins de 86 kg","Lutte	Lutte libre - Moins de 97 kg",
"Lutte	Lutte libre - Moins de 125 kg","Natation	50 m nage libre","Natation	100 m nage libre","Natation	200 m nage libre","Natation	400 m nage libre",
"Natation	800 m nage libre","Natation	1 500 m nage libre","Natation	100 m dos","Natation	200 m dos","Natation	100 m brasse","Natation	200 m brasse",
"Natation	100 m papillon","Natation	200 m papillon","Natation	200 m 4 nages","Natation	400 m 4 nages","Natation	Relais 4 × 100 m nage libre","Natation	Relais 4 × 200 m nage libre",
"Natation	Relais 4 × 100 m 4 nages","Natation	Eau vive 10 km","Plongeon	Tremplin à 3 m","Plongeon	Haut-vol à 10 m","Plongeon	Tremplin à 3 m synchronisé",
"Plongeon	Haut-vol à 10 m synchronisé","Natation sync.	Duo","Natation sync.	Ballet","Water-polo	Finale","Pentathlon moderne	Finale","Rugby à sept	Finale",
"Rugby à sept	Finale","Skateboard	Park","Skateboard	Street","Softball	Finale","Surf	Finale","Taekwondo	Poids mouches","Taekwondo	Poids légers",
"Taekwondo	Poids welters","Taekwondo	Poids lourds","Tennis	Simple","Tennis	Double","Tennis	Mixte	Finale mixte","Tennis de table	Simple",
"Tennis de table	Double","Tennis de table	Finale mixte","Tir	Pistolet à 10 m air comprimé","Tir	Pistolet à 25 m tir rapide","Tir	Carabine à 10 m air comprimé",
"Tir	Carabine à 50 m trois positions","Tir	Trap","Tir	Skeet","Tir	Mixte	Pistolet à 10 m air comprimé","Tir	Mixte	Carabine à 10 m air comprimé",
"Tir	Mixte	Trap","Tir à l'arc	Individuel","Tir à l'arc	Par équipes","Tir à l'arc	Mixte par équipes","Triathlon	Triathlon","Triathlon	Relais mixte",
"Voile	Laser","Voile	Finn","Voile	RS:X","Voile	470","Voile	49er","Voile	Mixte	Nacra 17","Volley-ball salle	Homme	Finale",
"Volley-ball salle	Femme	Finale" };

for(r=0;r<201;r++)
{
 tabepreuve[r]=tabqlqq[r];
}
    int i = 0;
    int j = 0;
    int k = 0;
    int nbepreuve=u;

    struct Concurents *tete_lecture = NULL; // pour la lecture de la liste chainée (pour ne pas perdre la tete)

    printf("\n\n\n-------------------------------Suppression des epreuves qui n ont aucun inscription ----------------------------------");
    for(j = 0 ; j < u; j++){
            for(i = 0; i < t; i++){

            tete_lecture = tabjo[j][i];

            // lecture des données de la liste chainée
            if (tete_lecture == NULL){ // Aucune inscription.
                printf("\n -Aucun athlete n est inscrit pour cette epreuve. Donc on la supprime ");
                for(k = j ; k < u; k++){
                    strcpy(tabepreuve[k], tabepreuve[k+1]);// suppresion de l'épreuve.(ecraser l'epreuve par une autre pour plus d'optimisation.
                }
                nbepreuve--;
            }
            else{
                printf("ereur il n'y a pas d'epreuves vides");
            }
        } // fin j
    } // fin i
}
//------------------------------
// procedure qui affiche le menu principal
//------------------------------
void menu()
{
system("cls");
printf("MENU PRINCIPAL\n");
printf("1: Procedure creer_tabjo \n");
printf("2: Procedure inserath \n");
printf("3: Procedure listathpays \n");
printf("4: Procedure sansath \n");
printf("5: Procedure listjo \n");
printf("6: Procedure suppays \n");
printf("7: Procedure supath \n");
printf("8: Procedure suplignesvides \n");
printf("\n donnez votre choix :");
}

//---------------------
// PROGRAMME PRINCIPAL
//----------------------
int main()

{
    int choix;
    char rep;
    char nom_athlete[26], nom_pays[100];
    int num_epreuve, num_pays;
    printf("-----------------------------------------Projet TP1, Bonjour ! ---------------------------------\n");
    printf("Choisir Pays \n"); //****************************************************************
            scanf("%d", &t);
            printf("Choisir Epreuve \n"); //***************************************************************
            scanf("%d",&u);


    do {
            menu();
        scanf("%d",&choix);
    switch(choix){

    case 1: cree_tabjo();
    break;

   case 2:  printf("\n\n Entrer le nom de l'athlete a ajouter:");
    scanf("%s",&nom_athlete);
    printf("Donner le numero du pays: ");
    scanf("%d",&num_pays);
    printf("Donner le numero d'epreuve: ");
    scanf("%d",&num_epreuve);


    inserath(nom_athlete, num_pays, num_epreuve);

    break;

    case 3: printf("\n\n Entrer le pays pour afficher la liste des athletes:");
    scanf("%s", &nom_pays);
    listathpays (nom_pays);
    break;

    case 4: printf("\n\n Entrer le numero de l'epreuve: (reponse a la question 4): ");
    scanf("%d", &num_epreuve);
    bool reponse = sansath(num_epreuve);
    printf("\n REPONSE RETOURNEE PAR LA FONCTION sansath: %d", reponse);
    break;

    case 5: listjo();
    break;

    case 6: { printf("\n\n Entrer le nom du pays a supprime: (reponse a la question 6) \n");
    scanf("%s", &nom_pays);
    suppays(nom_pays);}
    break;

    case 7: printf("\n\n Entrer le nom de althlete a supprime: (r�ponse a la question 7)");
    scanf("%s", &nom_athlete);
    printf("\n\n Entrer le num�ro de l'epreuve: (de l'athlete a supprime)");
    scanf("%d", &num_epreuve);
    printf("\n\n Entrer le num�ro du pays: (de l'athlete a supprime)");
    scanf("%d", &num_pays);
    supath(nom_athlete, num_pays, num_epreuve);
    break;
    case 8: suplignesvides();
    default: printf("choix incorrect\n");
    }
printf("\n voulez vous rester dans l'execution O/N: ");

fflush(stdin);scanf("%c",&rep);
  }

while(rep=='o' || rep=='O');

return 0;



    printf("\n-----------------------------------------------------FIN------------------------------------------");
    return 0;
}
