//      (_||_/
//      (    )       Preferences data
//     ( o  0 )
//-OOO°--(_)---°OOO---------------------------------------
//                   Copyright (C) 2006 By Dominique Roux-Serret
// .OOOo      oOOO.  roux-serret@ifrance.com
//-(   )------(   )---------------------------------------
//  ( (        ) /   Copyright (C) 2023 By Johnny Jazeix
//   (_)      (_/    jazeix@gmail.com

//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 or version 3 of the License.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#ifndef PREFERENCE_DOM_
#define PREFERENCE_DOM_

#include <SDL2/SDL_audio.h> // for SDL_MIX_MAXVOLUME

#define VITESSE_MAX 180.0
#define VITESSE_MOY 120.0
#define VITESSE_MIN 80.0
#define DUREE_VITESSE (10 * 1000)

#define DUREE_PAUSE (3 * 1000)

#define DUREE_REDUIT (10 * 1000)
#define DUREE_ALONGE (10 * 1000)
#define ECARTWAGON_MAX 27.0
#define ECARTWAGON_MOY 13.0
#define ECARTWAGON_MIN 4.0

#define N_VIES_DEP 3

#define RAYON_TOUCHE (32 * 32)

#define LT 17
#define HT 15
#define MAX_N_LEVEL_IN_MEMORY 256

#define D_Left 0
#define D_Right 1
#define D_Top 2
#define D_Bottom 3

#define D_Case 40
#define D_CaseR 31.416

/*** Possible pieces on the level ***/
#define C_None 0
#define C_Rail 1
#define C_Wagon 2
#define C_Allonge 3
#define C_Reduit 4
#define C_Speed 5
#define C_Live 6
#define C_Fin 7

enum e_Difficulte {
    Easy,
    Normal,
    Hard
};

/*** Mémorise un score ***/
#define LSCOREMAX 460

struct sScore
{
    int Score;
    char Name[80];
};

/*** Structure des preferences Générales ***/
struct sOldPreference
{
    e_Difficulte Difficulte; // Difficulté de la partie (Vitesse)
    int Niveau; // Niveau du joueur
    int NVie; // Nombre de vie du joueur
    int Score; // Score du joueur
    double Vitesse; // Vitesse suivant le niveau
    double VitesseMoy; // Vitesse en cours de la loco
    float EcartWagon; // ecart en pixels entre 2 wagons
    int NiveauMax;
    int FullScreen;
    int Langue; // Langue à afficher
    int NLangues; // Nombre de langues disponible
    float Volume; // Volumes audio
    float VolumeM; // Volume de la music
    struct sScore Sco[8]; // Mémorise les scores
};

struct sNewPreference
{
    e_Difficulte Difficulte { Normal }; // current game difficulty
    int Niveau; // current level
    int NVie { N_VIES_DEP }; // current number of life
    int Score; // current score
    double Vitesse { VITESSE_MOY }; // Vitesse suivant le niveau
    double VitesseMoy { VITESSE_MOY }; // Vitesse en cours de la loco
    float EcartWagon { ECARTWAGON_MOY }; // ecart en pixels entre 2 wagons
    int NLangues; // Nombre de langues disponible
    int NiveauMax[3] { 0, 0, 0 }; // One per difficulty
    int FullScreen { true };
    int Langue { -1 }; // locale index
    float Volume { (float)SDL_MIX_MAXVOLUME }; // audio volume
    float VolumeM { (float)SDL_MIX_MAXVOLUME }; // music volume
    struct sScore Sco[8]; // store scores
    int HumanRightsQuiz { 1 }; // enable the human rights questions at the end of a level
};

enum eMenu {
    mMenu,
    mMenuJeux,
    mMenuSpeed,
    mMenuNiveau,
    mLangue,
    mGame,
    mScore,
    mScoreEdit,
    mOption,
    mQuit,
    mEdit,
};

#endif
