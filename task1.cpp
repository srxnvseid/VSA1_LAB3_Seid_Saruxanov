#include <bits/stdc++.h>
using namespace std;

struct CustomerNode {
    string name;
    string medicine;
    CustomerNode* next;   // musteri nodu hansiki onu linkedlist kimi node da saxlayir
};

struct Queue{               //  novbe simulyasiyasi ucun struct 
    CustomerNode* front;
    CustomerNode* rear;
};

void initQueue(Queue* q)            // novbe pointerlerinin yaradilmasi
{
    q->front=nullptr;
    q->rear=nullptr;
}

bool isEmpty(Queue* q)
{
    return q->front == nullptr;
}

void enqueue(Queue* q, string name,string medicine) // (novbeye element elave etmek qisaca linked list sonuna)
{
    CustomerNode* customer1=new CustomerNode();
    customer1->name=name;
    customer1->medicine=medicine;
    customer1->next=nullptr;

    if(q->rear==nullptr)
    {
        q->front=q->rear=customer1;
        return;
    }
    q->rear->next=customer1;
    q->rear=customer1;
}

void dequeue(Queue* q)  // en ondeki insani silmek lazimdir cunki o artiq novbeden cixir 
{
    if(isEmpty(q))
    {
        cout<<"Novbe bosdur silmeye bir sey yoxdur" << endl;
        return;
    }
    CustomerNode* current=q->front;
    cout<<"Xidmet gosterildi: "<<current->name << endl;

    q->front=q->front->next;            // en ondeki pointer ondan sonraki pointere dogru yonelir ve cari front silinir
    if(q->front == nullptr)
    {
        q->rear=nullptr;
    }

    delete current;
}

void printQueue(Queue* q)
{
    if(isEmpty(q))
    {
        cout<<"Novbe bosdur!" << endl;
        return;
    }

    CustomerNode* current=q->front;

    while(current!=nullptr)
    {
        cout<<current->name<<" - "<<current->medicine<<endl;
        current=current->next;
    }
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, "Eli", "Parasetamol");
    enqueue(&q, "Aysel", "Aspirin");
    enqueue(&q, "Murad", "Analgin");

    printQueue(&q);

    dequeue(&q);

    printQueue(&q);

    return 0;
}