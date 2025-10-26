/*
    kode ini dibuat untuk menambahkan suatu nilai di suatu posisi (berbasis index start di 0)
*/
#include <iostream>
using namespace std;

//deklarasi node, punya elemen dan punya pointer yang menuju ke node selanjutnya
struct node{
    double data;
    node* next;
};
//fungsi yang akan meng insert nilai node tsb di suatu posisi (sekalian untuk return head)
node* insertnodeatpos(node* head, double dat, int pos){
    node* newnode= new node();
    newnode->data=dat;
    newnode->next=nullptr;

    if(pos==0){
        newnode->next=head;
        return newnode;
    }

    node* current= head;
    for(int i=0; i<pos-1; i++){
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;

    return head;
}

//fungsi untuk memprint nilai nilai tsb
void print(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main(){
    int n;
    cout << "Masukkan berapa banyak elemen: ";
    cin >>n;

    node* head=nullptr;
    node* tail=nullptr;
    cout << "Masukkan elemen elemen tsb: " << endl;
    for(int i=0; i<n; i++){
        int value;
        cin >> value;

        node* newnode= new node();
        newnode->data=value;
        newnode->next=nullptr;

        if(head==nullptr){
            head=newnode;
            tail=newnode;
        } else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    double dat;
    int pos;
    cout << "Masukkan nilai apa yang ingin dimasukkan: ";
    cin >> dat;
    cout << "Masukkan ingin memasukkan nilai tsb di posisi keberapa: ";
    cin >> pos;

    //panggil fungsi untuk menaruh nilai tsb di suatu posisi
    head=insertnodeatpos(head,dat,pos);
    
    //panggil fungsi untuk memprint
    cout << "List nilai nilai tsb yang terbaru: " << endl;
    print(head);
    return 0;
}