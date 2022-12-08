#include <iostream>
using namespace std;

int main () {
    string hay, asu, ajgres;
    cout << "Udin: Halo" << endl;
    cout << "Gweh: "; cin >> hay;
    cout << "Udin: Lu asik Bang" << endl;
    cout << "Gweh: "; cin >> asu;
    cout << "Udin: tau Ngk Bang Siapa Yang Paling...." << endl;
    _sleep(3000);
    system("cfonts \"Anjing\" -a center -g red,blue");
    cout << "Gweh: "; cin >> ajgres;
    _sleep(1000);
    system("cfonts \"Yang Nonton Video Ini\" -f shade -c cyanBright -a center");
    _sleep(1000);
    for (int i = 0; i < 99; i++)
    {   
        string asu[rand() % 3] = {"red,blue", "blue,red", "green, yellow"};
        _sleep(50);
        system("cfonts \"Anjing\" -a center -g ");
    }
    
}