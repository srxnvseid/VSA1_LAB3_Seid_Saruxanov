#include <bits/stdc++.h>
using namespace std;


// ilk olaraq sade queue funksiyasini stl olmadan yaratmaq ucun ozumuz yaza

struct PassengerNode{
    string name;
    int age;
    PassengerNode* next;
};
struct Queue{
    PassengerNode* front;
    PassengerNode* rear;
};
void initQueue(Queue* q)
{
    q->front=nullptr;
    q->rear=nullptr;
}
bool isEmpty(Queue* q)
{
    return q->front==nullptr;
}
void Enqueue(Queue* q, string name,int age)
{
    PassengerNode* passenger1=new PassengerNode();
    passenger1->name=name;
    passenger1->age=age;
    passenger1->next=nullptr;

    if(q->rear==nullptr)
    {
        q->front=q->rear=passenger1;
        return;
    }
    q->rear->next=passenger1;
    q->rear=passenger1;
}
void Dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        cout<<"Novbe bosdur" << endl;
        return;
    }

    PassengerNode* current=q->front;
    cout << "Avtobusa mindi: " << current->name << " (" << current->age << " yas)" << endl;
    q->front=q->front->next;

    if(q->front==nullptr)
    {
        q->rear=nullptr;
    }
    delete current;
}
void printQueue(Queue* q)
{
    if(isEmpty(q))
    {
        cout<<"Novbe bosdur cap ugursuz" << endl;
        return;
    }
    PassengerNode* current=q->front;
    while(current!=nullptr){
        cout<<"Novbe: "<<current->name << " (" << current->age << " yas)" << endl;
        current=current->next;
    }
}

// avtobus ucun iki queue yaradaq biri yaslari coxlari saxlasin digeri ise az olanlari

struct BusStop
{
    Queue Pq; // priority queue (yasi cox olanlari saxlamaq ucun novbe)
    Queue Rq;  // regular queue (yasi az olanlari saxlamaq ucun novbe)
};
void initBusStop(BusStop* stop)
{
    initQueue(&(stop->Pq));  // iki ferqli novbe nodelari menimsedilir
    initQueue(&(stop->Rq));

}

void AddPassenger(BusStop* stop,string name,int age)
{
    if(age>45)
    {
        Enqueue(&(stop->Pq), name, age); // oz funksiyamizi cagiririq 
    }
    else
    {
        Enqueue(&(stop->Rq), name, age); // oz funksiyamizda elave edirik regular queue ya 
    }
}

// bu tamamaile priority queue, tree ve heap olmadan novbe yaradilmasidir, novbenin eger herhansi elementini de silmek istesek
// pointerlerle ve adressle dequeue ederek sile bilerik 

int main()
{
    BusStop stop;
    initBusStop(&stop);
    AddPassenger(&stop, "Kamran", 24);
    AddPassenger(&stop, "Tofiq", 72);
    AddPassenger(&stop, "Nigar", 31);
    AddPassenger(&stop, "Zehra", 68);

    cout << "--- Prioritetli Novbe (45+) ---" << endl;
    printQueue(&(stop.Pq));

    cout << "\n--- Normal Novbe ---" << endl;
    printQueue(&(stop.Rq));

    return 0;
}