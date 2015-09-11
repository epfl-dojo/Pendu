#include <iostream>
#include <set>

using namespace std;

int main()

{
    set<char> lettresSaisies;
    string motRecherche="maison";
    char lettreSaisie;
    int nombreDeVies = 5;

    cout << "Le Pendu!" << endl;
    string motTente="_ _ _ _ _ _";

    while(true) {
            cout<< "Vous devez trouver le mot:" << motTente << endl;
         cout << "Tapez une lettre : ";
        cin >> lettreSaisie;
        if (lettresSaisies.find(lettreSaisie) != lettresSaisies.end()) {
            cout << "Vous avez deja essaye la lettre " << lettreSaisie << endl;
        } else {
            lettresSaisies.insert(lettreSaisie);
            bool trouve = false;
            for(int i=0; i < motRecherche.size(); i++) {
                if (lettreSaisie == motRecherche[i]){
                    trouve = true;
            // TODO : mettre a jour motTente
                    break;
                }
            }
            if (trouve){
                cout << "BRAVO" << endl;
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

