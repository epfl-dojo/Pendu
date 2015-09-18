#include <iostream>
#include <set>

using namespace std;

int main()

{
    set<char> lettresSaisies;
    string motRecherche="fromage";
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
                cout <<"il vous reste "<< nombreDeVies << " vies" << endl;
            }
            if (nombreDeVies==0)
            {
                cout <<"Vous etes mort" <<endl;
                return 0;
            }
        }
    }

    wcout << "Vous avez saisie : " << lettreSaisie << endl;

    return 0;
}

