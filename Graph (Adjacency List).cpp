#include<iostream>
using namespace std;
class AL{
    int v,e,fuel;
    string city;
    AL *next;
    public:
    void create();
    void addedge();
    void display();
}*head[100];
void AL::create(){
    cout<<"Enter the number of cities: ";
    cin>>v;
    for(int i=0;i<v;i++){
        head[i] = new AL;
        cout<<"Enter city name: ";
        cin>>head[i]->city;
        head[i]->next = NULL;
    } 
}
void AL::addedge(){
    string s,d;
    cout<<"Enter the no. of edges:";
    cin>>e;
    for(int i=0;i<e;i++){
        cout<<"Enter source and destination city: ";
        cin>>s>>d;
        int j;
        for(j=0;j<v;j++){
            if(head[j]->city == s){
                break;
            }
        }
        cout<<"Enter fuel required: ";
        AL *n=new AL;
        cin>>n->fuel;
        n->city = d;
        n->next=NULL;
        AL *temp=head[j];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}
void AL::display(){
    for(int i=0;i<v;i++){
        cout<<head[i]->city<<" -> ";
        AL *temp=head[i];
        while(temp->next!=NULL){
            temp=temp->next;
            cout<<temp->city<<"("<<temp->fuel<<")"<<" -> ";
        }
        cout<<"NULL"<<endl;
    }
}
int main(){
    AL g;
    g.create();
    g.addedge();
    cout<<"Adjacency List of the graph: "<<endl;
    g.display();
    return 0;
}
