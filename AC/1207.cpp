#include <iomanip>
#include <iostream>
using namespace std;

struct item
{
    int type, aT;
    item(int a,int b):type(a), aT(b){}
    item():type(-1),aT(-1){}
};

template<class elemType>
class seqQueue
{
    private:
    elemType *elem;
    int maxsize;
    int head, tail;

    void doubleSpace();

    public:
    seqQueue(int init_size = 10):maxsize(init_size),head(0),tail(0)
    {
        elem = new elemType[maxsize];
    }
    ~seqQueue()
    {
        delete [] elem;
    }
    bool isEmpty(){return head==tail;}
    elemType deQueue();
    elemType getHead()
    {
        return elem[(head+1)%maxsize];
    }
    void enQueue(const elemType &x);
    int length()
    {
        if(tail>=head)
            return tail-head;
        return tail + maxsize - head;
    }
};

template<class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[maxsize<<1];
    for(int i=1;i<maxsize;++i)
    {
        elem[i] = tmp[(head+i)%maxsize];
    }
    head = 0;
    tail = maxsize-1;
    maxsize<<=1;
    delete[] tmp;
}

template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if((tail+1)%maxsize==head)
        doubleSpace();
    tail = (tail+1)%maxsize;
    elem[tail] = x;
}

template<class elemType>
elemType seqQueue<elemType>::deQueue()
{
    head = (head+1)%maxsize;
    return elem[head];
}

int main()
{
    int n, type,time, numOfBus=0, numOfTruck=0;
    int k, tmp, m;
    double busWait = 0, truckWait=0;
    seqQueue<int> bus(100),truck(100);
    item *elem;
    cin>>n;
    elem = new item[n+5];
    for(int i=0;i<n;++i)
    {
        cin>>type>>time;
        elem[i].type = type;
        elem[i].aT = time;
        if(type)
            ++numOfTruck;
        else
            ++numOfBus;
    }
    time=0;
    k =0;
    while(k<n || !bus.isEmpty() || !truck.isEmpty())
    {
        while(k<n && elem[k].aT<=time)
        {
            if(elem[k].type)
                truck.enQueue(elem[k].aT);
            else
                bus.enQueue(elem[k].aT);
            ++k;
        }
        m = 0;
        while(m<2 && (!truck.isEmpty()))
        {
            tmp = truck.deQueue();
            truckWait += (time - tmp);
            ++m;
        }
        while(m<10 && (!bus.isEmpty()))
        {
            tmp = bus.deQueue();
            busWait += (time - tmp);
            ++m;
        }
        while(m<10 && (!truck.isEmpty()))
        {
            tmp = truck.deQueue();
            truckWait += (time - tmp);
            ++m;
        }
        // if(truck.length()> 2)
        // {
        //     while( m<8 && (!bus.isEmpty()))
        //     {
        //         tmp = bus.deQueue();
        //         busWait += (time - tmp);
        //         ++m;
        //     }
        //     while(m<10 && (!truck.isEmpty()))
        //     {
        //         tmp = truck.deQueue();
        //         truckWait += (time - tmp);
        //         ++m;
        //     }
        // }
        // else
        // {
        //     while(!truck.isEmpty())
        //     {
        //         tmp = truck.deQueue();
        //         truckWait += (time - tmp);
        //         ++m;
        //     }
        //     while( m<10 && (!bus.isEmpty()))
        //     {
        //         tmp = bus.deQueue();
        //         busWait += (time - tmp);
        //         ++m;
        //     }
        // }
        time += 10;
    }
    if(busWait == 0)
        cout<<fixed<<setprecision(3)<<busWait<<' ';
    else
        cout<<fixed<<setprecision(3)<<busWait/numOfBus<<' ';
    if(truckWait==0)
        cout<<fixed<<setprecision(3)<<truckWait;
    else
        cout<<fixed<<setprecision(3)<<truckWait/numOfTruck;
    return 0;
}

// int run()
// {
//     int m;
//     seqQueue<int> q(10);
//     for(int i=0;i<23;++i)
//         q.enQueue(i);
//     cout<<q.length()<<endl;
//     for(int i=0;i<18;++i)
//     {
//         m = q.deQueue();
//         cout<<m<<' ';
//     }
//     cout<<endl;
//     cout<<q.length()<<endl;
//     for(int i=100;i<110;++i)
//         q.enQueue(i);
//     cout<<q.length()<<endl;
//     for(int i=0;i<10;++i)
//     {
//         m = q.deQueue();
//         cout<<m<<' ';
//     }
//     cout<<'\n'<<q.length()<<endl;
//     return 0;
// }
