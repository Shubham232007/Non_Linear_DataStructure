#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class FT{
    string name,edu;
    int age;
    long contact,adhar;
    FT *LC,*RC;
    public:
    void create();
    void insert(FT *root,FT *next);
    void displayIn(FT *root);
    void displayPre(FT *root);
    void displayPost(FT *root);
    void displayleafnode(FT *root);
    void add();
    int height(FT *root);
    int search(FT *root,long key);
    void currentGeneration(FT *root,int ht);
    bool displayansestor(FT *root,int target);
    void siblings(FT *root,long key);
}*root;
void FT::add(){
    char ch;
    do{
        FT *next;
        next = new FT;
        cout<<"Enter next node data: "<<"\n";
        cout<<"Name :";
        cin>>next->name;
        cout<<"Education :";
        cin>>next->edu;
        cout<<"Age :";
        cin>>next->age;
        cout<<"Contact no :";
        cin>>next->contact;
        cout<<"Adhar no :";
        cin>>next->adhar;
        next->LC = next->RC = NULL;
        insert(root, next);
        cout << "Do you want to add more nodes? (y/n): ";
        cin >> ch;
    }while(ch == 'Y' || ch == 'y');
}

void FT::create(){
    root = new FT;
    cout<<"Enter root data: "<<"\n";
    cout<<"Name :";
    cin>>root->name;
    cout<<"Education :";
    cin>>root->edu;
    cout<<"Age :";
    cin>>root->age;
    cout<<"Contact no :";
    cin>>root->contact;
    cout<<"Adhar no :";
    cin>>root->adhar;
    root->LC = root->RC = NULL;
}

void FT::insert(FT *root,FT *next){
    char c;
    cout << "Where to insert " << next->name << " at node " << root->name
         << " (L/R): ";
    cin >> c;
    if(c=='L' || c=='l'){
        if (root->LC == NULL){
            root->LC = next;
        }
        else{
            insert(root->LC, next);
        }
    }
    else{
        if (root->RC == NULL){
            root->RC = next;
        }
        else{
            insert(root->RC, next);
        }
    }
}

void FT::displayIn(FT *root) {
    if (root != NULL) {
        displayIn(root->LC);
        cout <<"\n"<< root->name << "\t\t"<<root->age<<"\t\t"<<root->edu<<"\t\t"<<root->contact<<"\t\t"<<root->adhar;
        displayIn(root->RC);
    }
    else{
        return;
    }
}
void FT::displayPre(FT *root) {
    if (root != NULL) {
        cout <<"\n"<< root->name << "\t"<<root->age<<"\t"<<root->edu<<"\t"<<root->contact<<"\t"<<root->adhar;
        displayPre(root->LC);
        displayPre(root->RC);
    }
    else{
        return;
    }
}
void FT::displayPost(FT *root) {
    if (root != NULL) {
        displayPost(root->LC);
        displayPost(root->RC);
        cout <<"\n"<< root->name << "\t"<<root->age<<"\t"<<root->edu<<"\t"<<root->contact<<"\t"<<root->adhar;
    }
    else{
        return;
    }
}
void FT::displayleafnode(FT *root) {
    if (root != NULL) {
        displayleafnode(root->LC);
        if(root->LC==NULL && root->RC==NULL){
        cout <<"\n"<< root->name << "\t"<<root->age<<"\t"<<root->edu<<"\t"<<root->contact<<"\t"<<root->adhar;
        }
        displayleafnode(root->RC);
    }
    else{
        return;
    }
}
int FT::height(FT *root){
    if(root==NULL){
        return 0;
    }
    else{
        int lh= height(root->LC);
        int rh= height(root->RC);
        return 1+max(lh,rh);
    }
}
int FT::search(FT *root,long key){
    if(root==NULL){
        return 0;
    }
    if(root->adhar==key){
        cout<<"Node found: "<<"\n";
        cout <<"\n"<< root->name << "\t"<<root->age<<"\t"<<root->edu<<"\t"<<root->contact<<"\t"<<root->adhar;
        return 1;
    }
    if(search(root->LC,key)) return 1;
    if(search(root->RC,key)) return 1;
    return 0;
}
void FT::currentGeneration(FT *root,int h){
    if(root==NULL){
        return;
    }
    if(h==0){
        cout <<"\n"<< root->name << "\t"<<root->age<<"\t"<<root->edu<<"\t"<<root->contact<<"\t"<<root->adhar;
    }
    currentGeneration(root->LC,h-1);
    currentGeneration(root->RC,h-1);
}
bool FT::displayansestor(FT *root,int target){
    if(root==NULL){
        return false;
    }
    if(root->adhar==target){
        return true;
    }
    bool left=displayansestor(root->LC,target);
    bool right=displayansestor(root->RC,target);
    if(left || right){
        cout <<"\n"<< root->name << "\t"<<root->age<<"\t"<<root->edu<<"\t"<<root->contact<<"\t"<<root->adhar;
        return true;
    }
    return false;
}
void FT::siblings(FT *root,long key){
    if(root==NULL || (root->LC==NULL && root->RC==NULL)){
        return;
    }
    if((root->LC && root->LC->adhar==key) || (root->RC && root->RC->adhar==key)){
        if(root->LC && root->LC->adhar!=key){
            cout <<"\n"<< root->LC->name << "\t"<<root->LC->age<<"\t"<<root->LC->edu<<"\t"<<root->LC->contact<<"\t"<<root->LC->adhar;
        }
        if(root->RC && root->RC->adhar!=key){
            cout <<"\n"<< root->RC->name << "\t"<<root->RC->age<<"\t"<<root->RC->edu<<"\t"<<root->RC->contact<<"\t"<<root->RC->adhar;
        }
        return;
    }
    siblings(root->LC,key);
    siblings(root->RC,key);
}

int main() {
    FT obj;
    int ch;
    do{
        cout<<"\n----Menu----"<<"\n";
        cout<<"1.Create"<<"\n";
        cout<<"2.Add"<<"\n";
        cout<<"3.Display All Nodes"<<"\n";
        cout<<"4.Display Terminal Node"<<"\n";
        cout<<"5.Height of Tree"<<"\n";
        cout<<"6.Search Node by Adhar"<<"\n";
        cout<<"7.Current Generation Nodes"<<"\n";
        cout<<"8.Display Ancestors of a Node"<<"\n";
        cout<<"9.Siblings of a Node"<<"\n";
        cout<<"10.Exit"<<"\n";
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch){
            case 1: obj.create();
            break;
            case 2: obj.add();
            break;
            case 3: int choice;
                    cout<<"1.Inorder Traversal"<<"\n";
                    cout<<"2.Preorder Traversal"<<"\n";
                    cout<<"3.Postorder Traversal"<<"\n";
                    cout<<"Enter your choice for traversal: ";
                    cin>>choice;
                    cout <<"\n"<< "Name" << "\t"<< "Age"<<"\t"<< "Edu"<<"\t"<< "Contact"<<"\t"<< "Adhar";
                    switch(choice){
                        case 1: obj.displayIn(root);
                        break;
                        case 2: obj.displayPre(root);
                        break;
                        case 3: obj.displayPost(root);
                        break;
                        default: cout<<"Wrong choice";
                    }
            break;
            case 4: obj.displayleafnode(root);
            break;
            case 5:{ cout<<"Height of tree is : ";
                    int ht=obj.height(root);
                    cout<<ht-1;
            } break;
            case 6: long key;
                    cout<<"Enter Adhar number to search: ";
                    cin>>key;
                    obj.search(root,key);
            break;
            case 7: {int h=obj.height(root)-1;
                    obj.currentGeneration(root,h);
            } break;
            case 8: long key1;
                    cout<<"Enter Adhar number to find ancestors: ";
                    cin>>key1;
                    cout <<"\n"<< "Name" << "\t"<< "Age"<<"\t"<< "Edu"<<"\t"<< "Contact"<<"\t"<< "Adhar";
                    obj.displayansestor(root,key1);
                    break;
            case 9: long key2;
                    cout<<"Enter Adhar number to find siblings: ";
                    cin>>key2;
                    cout <<"\n"<< "Name" << "\t"<< "Age"<<"\t"<< "Edu"<<"\t"<< "Contact"<<"\t"<< "Adhar";
                    obj.siblings(root,key2);
                    break;
            case 10:cout<<"Exiting program";
            break;
            default:cout<<"Wrong choice";
        }
        }while(ch!=10);
    return 0;
}
