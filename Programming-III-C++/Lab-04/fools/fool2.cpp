#include <iostream>
#include <cstdlib>

using namespace std;

class Gifts // Implementing list in Queue style
{
private:
int currentsize, arraysize, first, last;
string *queueArray;
public:
Gifts(int s = 100); // Constructor
~Gifts(); // Destructor

bool enqueue(string); // Add to end
bool dequeue(); // Remove from front
string front() const; // Get value at front

bool isEmpty() const { return currentsize <= 0; }
bool Fisull() const { return currentsize >= arraysize; }
int Size() const { return currentsize; }
friend ostream & operator << (ostream &, Gifts &);
};

Gifts::Gifts(int s) // Constructor
{
queueArray = new string[s]; // Dynamically allocate array of gifts
arraysize = s;
currentsize = 0;
first = 0;
last = -1;
}

Gifts::~Gifts() // Destructor
{
delete[] queueArray; // Deallocate array
}

bool Gifts::enqueue(string value)
{
if (currentsize >= arraysize) return false;

last = (last + 1) % arraysize;

queueArray[last] = value;

currentsize++;

return true;
}

bool Gifts::dequeue()
{
if (currentsize < 1) return false;

first = (first + 1) % arraysize;

currentsize--;

return true;
}

string Gifts::front() const
{
if (currentsize < 1)
{
cout << "Cannot take front of empty queue!\n";
exit(0);
}
return queueArray[first];
}

ostream & operator << (ostream &of, Gifts &cq)
{
of << "Gifts are: ";
int index = cq.first;
int count = 0;
while (count < cq.Size())
{
of << cq.queueArray[index] << " ";
index = (index + 1) % cq.arraysize;
count ++;
}
cout<<endl;
}
//--------------------------Nice class definition--------------------------------------//
struct NiceChild{
string name;
Gifts giftList;
};
class Nice // Implementing list in Queue style
{
private:
int currentsize, arraysize, first, last;
NiceChild *nc;
public:
Nice(int s = 100); // Constructor
~Nice(); // Destructor

bool enqueue(NiceChild); // Add to end
bool dequeue(); // Remove from front
NiceChild front() const; // Get value at front

bool isEmpty() const { return currentsize <= 0; }
bool Fisull() const { return currentsize >= arraysize; }
int Size() const { return currentsize; }
friend ostream & operator << (ostream &, Nice &);
};

Nice::Nice(int s) // Constructor
{
nc = new NiceChild[s]; // Dynamically allocate array of nice children
arraysize = s;
currentsize = 0;
first = 0;
last = -1;
}

Nice::~Nice() // Destructor
{
delete[] nc; // Deallocate array
}

bool Nice::enqueue(NiceChild value)
{
if (currentsize >= arraysize) return false;

last = (last + 1) % arraysize;

nc[last] = value;

currentsize++;

return true;
}

bool Nice::dequeue()
{
if (currentsize < 1) return false;

first = (first + 1) % arraysize;

currentsize--;

return true;
}

NiceChild Nice::front() const
{
if (currentsize < 1)
{
cout << "Cannot take front of empty queue!\n";
exit(0);
}
return nc[first];
}
ostream & operator << (ostream &of, Nice &cq)
{
of << "Name in nice list: ";
int index = cq.first;
int count = 0;
while (count < cq.Size())
{
of << cq.nc[index].name << " \n";
cout<<cq.nc[index].giftList;
index = (index + 1) % cq.arraysize;
count ++;
}
}
int main(int argc, char ** argv)
{
int iGifts=0, iCounter, iNiceChildCount=100;
string sName, sGift;
Nice niceList(iNiceChildCount);
NiceChild nc;
cout<<"Enter name for nice list: ";
cin>> sName;
while(sName.length() > 0){ // Check if the string is empty
cout<<"\nEnter number of gifts: ";
cin>> iGifts;
Gifts gifts(iGifts);
for(iCounter=0;iCounter<iGifts;iCounter++){
cout<<"Enter gift for "<<sName<<": ";
cin>> sGift;
gifts.enqueue(sGift);
}

nc.name = sName;
nc.giftList = gifts;
niceList.enqueue(nc);
sName = "";
cout<<"Enter name: ";
cin >> sName;
}
cout<< niceList.Size();
for(iCounter=0;iCounter<niceList.Size();iCounter++){
cout<< niceList;
}
}
