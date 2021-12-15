//Eric Blanco
#include <string>
#include <iostream>

template <class T>
class ArrayList{
    private:
        T* data;
        int size;
        int capacity;
        void expand(); //expands the list when its full
        void shiftRight(int index); //shift all elements from index, by 1 to the right
        void shiftLeft(int index); //shift all elements  from index, by 1 to the left
  
static const int DEFAULT_CAPACITY = 10;

    public:
        ArrayList(int capacity = DEFAULT_CAPACITY);
        void add(T item); //add to end of list
        bool remove(int index);// removes an item from specified index
        bool add(int index, T item); //add at specified index, index should be within current size
        int getSize();
        T& get(int index); //get item @ specified index
        ~ArrayList();
};

template <class T>
ArrayList<T>::ArrayList(int capacity ){
    this->capacity = capacity;
    this->size = 0;
    this->data = new T[capacity];
}

template <class T>
void ArrayList<T>::add(T item){ //add to end of list
    if(size == capacity)
    expand();
    data[size++] = item;
}

template <class T>
bool ArrayList<T>::remove(int index){ //remove item
    if(index < 0 || index >= size)
    return false;
    shiftLeft(index+1);
    size--;
    return true;
}

template <class T>
bool ArrayList<T>::add(int index, T item){ //add at specific place
    if(index < 0 || index > size)
    return false;
    if(size == capacity)
    expand();
    if(index == size)
    data[size] = item;
    else{
        shiftRight(index);
        data[index] = item;
    }
    size++;
    return true;  
}

template <class T>
int ArrayList<T>::getSize(){return size;}

template <class T>
T& ArrayList<T>::get(int index) {return data[index];} //get item at specific place

template <class T>
void ArrayList<T>::expand(){ //expand the list
    capacity *= 2; //dbl the capacity
    T* temp = new T[capacity]; //allocate larger array
    for(int i = 0; i < size; i++) //copy data
    temp[i] = data[i];  
    //deallocate old array and assign new array
    delete[] data;
    data =temp;
}

template <class T>
void ArrayList<T>::shiftRight(int index){
    for(int i = size-1; i >= index; i--)
    data[i+1] = data[i];
}

template <class T>
void ArrayList<T>::shiftLeft(int index){
    for(int i = index; i < size; i++)
    data[i-1] = data[i];
}

template <class T>
ArrayList<T>::~ArrayList(){delete []data;} //prevent memory leak

//main:
int main(){
    ArrayList<std::string> names;
    ArrayList< ArrayList<std::string> > gifts; //each element in the list is a list of strings
  
    std::string name, gift;
    int count = 0;
    while(true){
        std::cout << "name for nice list: ";
        std::getline(std::cin, name);
        if(name.empty()) //no name specified, means no more data
        break;
        names.add(name);
        std::cout << "add gifts for " << name << std::endl;
        while(true){
            std::cout << "gift: ";
            std::getline(std::cin, gift);
            if(gift.empty())
            break;
            gifts.get(count).add(gift);
        }
        count++;
    }  
    std::cout << std::endl << std::endl;
    std::cout << "The list contains" << std::endl;
    for(int i = 0; i < names.getSize(); i++){
        std::cout << names.get(i) << ": " ;
        ArrayList<std::string>& g = gifts.get(i);
        for(int j = 0; j < g.getSize(); j++)
        std::cout << g.get(j) << ", " ;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}