#include<iostream>
using namespace std;
class Adjecent {
    int v,e;
    string city[20];
    int fuel;
    int adj[20][20];
public:
    void create();
    void display();
};
void Adjecent::create() {
    cout << "Enter the number of cities: ";
    cin >> v;
    cout << "Enter the city names:\n";
    for (int i = 0; i < v; i++) {
        cout << "City " << i + 1 << ": ";
        cin >> city[i];
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (j > i) {
                cout << "Enter the fuel required to travel from " << city[i] << " to " << city[j] << ": ";
                cin >> fuel;
                adj[i][j] = adj[j][i] = fuel;
            }
            else if (i == j){
                adj[i][j] = 0;
            }
        }
}
}
void Adjecent::display() {
    cout << "Adjacency Matrix (Fuel Required):\n";
    cout << "\t";
    for (int i = 0; i < v; i++) {
        cout << city[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < v; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < v; j++) {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    Adjecent a;
    a.create();
    a.display();
    return 0;
}
