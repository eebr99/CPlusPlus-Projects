#include <string>
#include <iostream>
using namespace std;
template <class T>
class ArrayList
{
private:
T* data;
int size;
int capacity;
void expand(); //used for expanding the list when its full
void shiftRight(int index); //shift all elements starting from index , by 1 position to right
void shiftLeft(int index); //shift all elements starting from index , by 1 position to left
  
static const int DEFAULT_CAPACITY = 10;
public:
ArrayList(int capacity = DEFAULT_CAPACITY);
void add(T item); //add to end of list
bool remove(int index);// removes an item from specified index
bool add(int index, T item); //add at specified index, index should be with in the current size
int getSize();
T& get(int index); //get item at specified index
~ArrayList();//destructor
};


template <class T>
ArrayList<T>::ArrayList(int capacity )
{
this->capacity = capacity;
this->size = 0;
this->data = new T[capacity];
}

template <class T>
void ArrayList<T>::add(T item) //add to end of list
{
if(size == capacity)
expand();
data[size++] = item;
}

template <class T>
bool ArrayList<T>::remove(int index)// removes an item from specified index
{
if(index < 0 || index >= size)
return false;
shiftLeft(index+1);
size--;
return true;
}

template <class T>
bool ArrayList<T>::add(int index, T item) //add at specified index, index should be with in the current size
{
if(index < 0 || index > size)
return false;
if(size == capacity)
expand();
if(index == size)
data[size] = item;
else
{
shiftRight(index);
data[index] = item;
}
size++;
return true;
  
}
template <class T>
int ArrayList<T>::getSize()
{
return size;
}
template <class T>
T& ArrayList<T>::get(int index) //get item at specified index
{
return data[index];
}
template <class T>
void ArrayList<T>::expand() //used for expanding the list when its full
{
capacity *= 2; //double the capacity
T* temp = new T[capacity]; //allocate bigger array
for(int i = 0; i < size; i++) //copy all exisiting data
temp[i] = data[i];
  
//deallocate old array and assign new array
delete[] data;
data =temp;
}

template <class T>
void ArrayList<T>::shiftRight(int index) //shift all elements starting from index , by 1 position to right
{
for(int i = size-1; i >= index; i--)
data[i+1] = data[i];
}

template <class T>
void ArrayList<T>::shiftLeft(int index) //shift all elements starting from index , by 1 position to left
{
for(int i = index; i < size; i++)
data[i-1] = data[i];
}

template <class T>
ArrayList<T>::~ArrayList()
{
delete []data;
}

//main:
int main()
{
ArrayList<string> names;
ArrayList< ArrayList<string> > gifts; //each element in the list is itself a list of strings
  
string name, gift;
int count = 0;
while(true)
{
cout << "name for nice list: ";
getline(cin, name);
if(name.empty()) //no name specified, means no more data
break;
names.add(name);
cout << "add gifts for " << name << endl;
while(true)
{
cout << "gift: ";
getline(cin, gift);
if(gift.empty())
break;
gifts.get(count).add(gift);
}
count++;
}
  
cout << endl << endl;
for(int i = 0; i < names.getSize(); i++)
{
cout << names.get(i) << ": " ;
ArrayList<string>& g = gifts.get(i);
for(int j = 0; j < g.getSize(); j++)
cout << g.get(j) << ", " ;
cout << endl;
}
}
