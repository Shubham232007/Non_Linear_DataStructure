#include<iostream>
using namespace std;
class ST{
    int ID;
    float CET;
    string name,Admissionstatus;
    ST *LC,*RC;
    public:
    void create();
    void add();
    void insert(ST *root,ST* next);
    void displayAll(ST *root);
    int search(ST *root, int id);
    int countNodes(ST *root);
    int FirstTopper(ST *root);
    int LastTopper(ST *root);
    void first3Toppers(ST *root, int &k);
    void displayIIT(ST *root);
    void displayNonIIT(ST *root);
    int height(ST *root);
}*root;
void ST::create(){
    root = new ST;
    cout<<"Enter root data: "<<"\n";
    cout<<"ID :";
    cin>>root->ID;
    cout<<"Name :";
    cin>>root->name;
    cout<<"CET :";
    cin>>root->CET;
    cout<<"Admissionstatus :";
    cin>>root->Admissionstatus;
    root->LC = root->RC = NULL;
}
void ST::add(){
    char ch;
    do{
        ST *next;
        next = new ST;
        cout<<"Enter next node data: "<<"\n";
        cout<<"ID :";
        cin>>next->ID;
        cout<<"Name :";
        cin>>next->name;
        cout<<"CET score :";
        cin>>next->CET;
        cout<<"Admission status :";
        cin>>next->Admissionstatus;
        next->LC = next->RC = NULL;
        insert(root, next);
        cout << "Do you want to add more nodes? (y/n): ";
        cin >> ch;
    }while(ch == 'Y' || ch == 'y');
}
void ST::insert(ST *root,ST *next){
    if(next->CET<=root->CET){
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
void ST::displayAll(ST *root) {
    if (root != NULL) {
        displayAll(root->LC);
        cout <<"\n"<< root->ID << "\t\t"<<root->name<<"\t\t"<<root->CET<<"\t\t"<<root->Admissionstatus;
        displayAll(root->RC);
    }
    else{
        return;
    }
}
int ST::search(ST *root, int id){
    if(root == NULL){
        return 0;
    }

    if(root->ID == id){
        cout<<"Student found:\n";
        cout <<"\n"<< root->ID << "\t\t"
             << root->name << "\t\t"
             << root->CET << "\t\t"
             << root->Admissionstatus;
        return 1;
    }

    if(search(root->LC, id))
        return 1;

    return search(root->RC, id);
}
int ST::countNodes(ST *root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->LC)+countNodes(root->RC);
}
int ST::FirstTopper(ST *root){
    if(root==NULL){
        cout<<"Tree is empty"<<"\n";
        return -1;
    }
    ST *current=root;
    while(current->RC!=NULL){
        current=current->RC;
    }
    cout<<"Student with maximum CET score: "<<"\n";
    cout <<"\n"<< current->ID << "\t\t"<<current->name<<"\t\t"<<current->CET<<"\t\t"<<current->Admissionstatus;
    return current->CET;
}
int ST::LastTopper(ST *root){
    if(root==NULL){
        cout<<"Tree is empty"<<"\n";
        return -1;
    }
    ST *current=root;
    while(current->LC!=NULL){
        current=current->LC;
    }
    cout<<"Student with minimum CET score: "<<"\n";
    cout <<"\n"<< current->ID << "\t\t"<<current->name<<"\t\t"<<current->CET<<"\t\t"<<current->Admissionstatus;
    return current->CET;
}
void ST::first3Toppers(ST *root, int &k){
    if(root==NULL || k>=3){
        return;
    }
    first3Toppers(root->RC,k);
    if(k<3){
        cout <<"\n"<< root->ID << "\t\t"<<root->name<<"\t\t"<<root->CET<<"\t\t"<<root->Admissionstatus;
        k++;
    }
    first3Toppers(root->LC,k);
}
void ST::displayIIT(ST *root){
    if(root==NULL){
        return;
    }
    displayIIT(root->LC);
    if(root->Admissionstatus=="IIT" || root->Admissionstatus=="iit"){
        cout <<"\n"<< root->ID << "\t\t"<<root->name<<"\t\t"<<root->CET<<"\t\t"<<root->Admissionstatus;
    }
    displayIIT(root->RC);
}
void ST::displayNonIIT(ST *root){
    if(root==NULL){
        return;
    }
    displayNonIIT(root->LC);
    if(root->Admissionstatus!="IIT" && root->Admissionstatus!="iit"){
        cout <<"\n"<< root->ID << "\t\t"<<root->name<<"\t\t"<<root->CET<<"\t\t"<<root->Admissionstatus;
    }
    displayNonIIT(root->RC);
}
int ST::height(ST *root){
    if(root==NULL){
        return 0;
    }
    else{
        int lh= height(root->LC);
        int rh= height(root->RC);
        return 1+max(lh,rh);
    }
}

int main(){
    ST obj;
    int ch;
    do{
        cout<<"\n----Menu----"<<"\n";
        cout<<"1.Create"<<"\n";
        cout<<"2.Add"<<"\n";
        cout<<"3.Display All Student Records"<<"\n";
        cout<<"4.Count of Students"<<"\n";
        cout<<"5.Search Student by ID"<<"\n";
        cout<<"6.Student with Highest CET Score"<<"\n";
        cout<<"7.Student with Lowest CET Score"<<"\n";
        cout<<"8.Top 3 Toppers"<<"\n";
        cout<<"9.Display IIT Admitted Students"<<"\n";
        cout<<"10.Display Non-IIT Admitted Students"<<"\n";
        cout<<"11.Height of Tree"<<"\n";
        cout<<"12.Exit"<<"\n";
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch){
            case 1: obj.create();
            break;
            case 2: obj.add();
            break;
            case 3: cout <<"\n"<< "ID" << "\t\t"<<"Name"<<"\t\t"<<"CET"<<"\t\t"<<"Admissionstatus";
                    obj.displayAll(root);
            break;
            case 4: cout<<"Total number of students: "<<obj.countNodes(root)<<"\n";
            break;
            case 5: {int id;
                    cout<<"Enter Student ID to search: ";
                    cin>>id;
                    if(!obj.search(root,id)){
                        cout<<"Student with ID "<<id<<" not found."<<"\n";
                    }
                  }
            break;
            case 6: obj.FirstTopper(root);
            break;
            case 7: obj.LastTopper(root);
            break;
            case 8: {int k=0;
                    cout<<"Top 3 Toppers are: "<<"\n";
                    cout <<"\n"<< "ID" << "\t\t"<<"Name"<<"\t\t"<<"CET"<<"\t\t"<<"Admissionstatus";
                    obj.first3Toppers(root,k);
                    }
            break;
            case 9: cout<<"IIT Admitted Students: "<<"\n";
                    cout <<"\n"<< "ID" << "\t\t"<<"Name"<<"\t\t"<<"CET"<<"\t\t"<<"Admissionstatus";
                    obj.displayIIT(root);
            break;
            case 10: cout<<"Non-IIT Admitted Students: "<<"\n";
                        cout <<"\n"<< "ID" << "\t\t"<<"Name"<<"\t\t"<<"CET"<<"\t\t"<<"Admissionstatus";
                        obj.displayNonIIT(root);
            break;
            case 11:{ cout<<"Height of tree is : ";
                    int ht=obj.height(root);
                    cout<<ht-1;
            } break;
            case 12: cout<<"Exiting program."<<"\n";
            break;
            default: cout<<"Invalid choice! Please try again."<<"\n";
        }
    }while(ch!=12);
    return 0;                            

}
