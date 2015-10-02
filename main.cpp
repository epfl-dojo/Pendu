#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void dessinePendu(int);
int jouer();
string donneMot();
int main (){
    std::srand(std::time(0));

    while (true) {
        jouer();

        char partieAgain;
        cout << "Nouvelle partie ?";
        cin >> partieAgain;
        if (partieAgain != 'o') {
            return 0;
        }
    }
}

int jouer()
{
    set<char> lettresSaisies;
    string motRecherche = donneMot();
    char lettreSaisie;
    string input;
    int nombreDeVies = 5;

    cout << "Le Pendu!" << endl;
    string motTente="";
    for(int i=0; i < motRecherche.size(); i++) {
        motTente=motTente+"*";
    }
    while(true) {
        cout<< "Vous devez trouver le mot: " << motTente << endl;
        cout << "Tapez une lettre : ";
        cin >> input;
        lettreSaisie=input[0];
        if (lettresSaisies.find(lettreSaisie) != lettresSaisies.end()) {
            cout << "Vous avez deja essaye la lettre " << lettreSaisie << endl;
        } else {
            lettresSaisies.insert(lettreSaisie);
            bool trouve = false;
            for(int i=0; i < motRecherche.size(); i++) {
                if (lettreSaisie == motRecherche[i]){
                    trouve = true;
                    // TODO : mettre a jour motTente
                    motTente[i]=lettreSaisie;
                }
            }
            if (trouve){
                cout << motTente << endl;
                cout << "BRAVO vous avez trouve la lettre " << lettreSaisie << endl;
                if (motTente==motRecherche){
                    cout << "Vous avez gagne";
                    return 0;
                }
            }else{
                nombreDeVies--;
                dessinePendu(nombreDeVies);
                cout <<"il vous reste "<< nombreDeVies << " vies" << endl;
            }
            if (nombreDeVies==0)
            {
                cout <<"Vous etes mort" <<endl;
                return 0;
            }
        }
    }

    wcout << "Vous avez saisi : " << lettreSaisie << endl;

    return 0;
}

void dessinePendu(int nbVies) {
    if (nbVies == 4) {
        cout << "      _______" << endl
             << "     |/      |" << endl
             << "     |      " << endl
             << "     |      " << endl
             << "     |      " << endl
             << "     |      " << endl
             << "     |" << endl
             << "    _|__        " << endl;
    } else if (nbVies == 3) {
        cout << "      _______" << endl
             << "     |/      |" << endl
             << "     |      (_)" << endl
             << "     |     " << endl
             << "     |       " << endl
             << "     |      " << endl
             << "     |" << endl
             << "    _|__        " << endl;
    } else if (nbVies == 2) {
        cout << "      _______" << endl
             << "     |/      |" << endl
             << "     |      (_)" << endl
             << "     |      \\|/" << endl
             << "     |       " << endl
             << "     |      " << endl
             << "     |" << endl
             << "    _|__        " << endl;
    } else if (nbVies == 1) {
        cout << "      _______" << endl
             << "     |/      |" << endl
             << "     |      (_)" << endl
             << "     |      \\|/" << endl
             << "     |       |" << endl
             << "     |      " << endl
             << "     |" << endl
             << "    _|__        " << endl;
    } else if (nbVies == 0) {
        cout << "      _______" << endl
             << "     |/      |" << endl
             << "     |      (_)" << endl
             << "     |      \\|/" << endl
             << "     |       |" << endl
             << "     |      / \\" << endl
             << "     |" << endl
             << "    _|__        " << endl;
    }
}

string donneMot(){

    std::string line;
    ifstream dict;
    vector<string> mots;
    dict.open("dict.txt");
    while (std::getline(dict, line))
    {
        if(line != ""){
            mots.push_back(line);
        }
    }
    return mots[rand() % mots.size()];
}
