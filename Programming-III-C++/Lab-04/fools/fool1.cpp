#include<iostream>
#include<string>

using namespace std;

//GiftsList ADT
class GiftsList
{
   private:
       struct Gifts
       {
           string name;//Name of gift item
           Gifts *next;//Point to next gift
          
           Gifts(string n) : name(n), next(nullptr){}
       };
       Gifts *head;//Head of gifts list
  
   public:
       GiftsList() : head(nullptr){}
          
       /*
       *   Function to insert gifts in list of gifts
       */
       void insert(string n)
       {
          
           Gifts *newGift = new Gifts(n);
           if(head == nullptr)
           {
               head = newGift;
           }
           else
           {
               Gifts *ptr = head;
               while(ptr->next != nullptr)
                   ptr = ptr->next;
               ptr->next = newGift;
           }
       }
      
       /*
       *   Function to print Content of gifts list
       */
       void print()
       {
           Gifts *ptr = head;
           while(ptr != nullptr)
           {
               if(ptr->next == nullptr)
                   cout<<ptr->name<<endl;
               else
                   cout<<ptr->name<<", ";
               ptr = ptr->next;  
           }
       }
};

//Class definition of NiceList
class NiceList
{
   private:
       struct List
       {
           string name;
           GiftsList gifts;//Instance of GiftsList ADT
           List *next;
          
           List(string n, GiftsList g) : name(n), gifts(g), next(nullptr){}
       };
      
       List *head;
      
   public:
       NiceList() : head(nullptr){}//To create an empty list
      
       /*
       *   Purpose: To insert a new person's name and a list of gifts received by him/her
       *   Parameters: Name of the person and An instance of GiftsList which is having list of gifts
       *   Pre-condition: A NiceList object is created
       *   Post-condition: A person's name and list of gifts is added at the end of the NiceList ADT
       *   Pseudocode: newNode = List(name, gifts)
       *               IF head == NULL
       *                   head = newNode
       *               ELSE
       *                   ptr = head
       *                   while ptr.next != NULL
       *                       ptr = ptr.next
       *                   ptr.next = newNode
       */
       void insert(string name, GiftsList gifts)
       {
           List *newNode = new List(name, gifts);
           if(head == nullptr)//If NiceList is empty
           {
               head = newNode;
           }
           else
           {
               List *ptr = head;
               while(ptr->next != nullptr)
                   ptr = ptr->next;
               ptr->next = newNode;
           }
       }
      
       /*
       *   Purpose: Add one more gift to the list of gifts for a given kid’s name
       *   Parameters: Name of the kid and name of gift
       *   Pre-condition: A NiceList object is created and name of the kid already exist in the NiceList
       *   Post-condition: A new gift has been added in the last of the list of gifts for the kid
       *   Pseudocode: ptr = head
       *               WHILE ptr.name != kidName && ptr != NULL
       *                   ptr = ptr.next
       *               ptr.gifts.INSERT(giftName)
       */
       void addGift(string n, string giftName)
       {
           List *ptr = head;
           while(ptr->name != n && ptr != nullptr)
           {
               ptr = ptr->next;
           }
           ptr->gifts.insert(giftName);//Insert new gift
       }
      
       /*
       *   Function to print NiceList content
       */
       void print()
       {
           List *ptr = head;
           while(ptr != nullptr)
           {
               cout<<"Name: "<<ptr->name<<", Gifts: ";
               ptr->gifts.print();
               ptr = ptr->next;  
           }
       }
};

//Sample driver function
int main()
{
   NiceList NL1;
  
   GiftsList GL1, GL2, GL3;
  
   GL1.insert("Candy");
   GL1.insert("Gaming console");
   GL1.insert("Laptop");
  
   GL2.insert("Computer");
   GL2.insert("Mobile");
   GL2.insert("Ear phones");
  
   GL3.insert("Chocolates");
   GL3.insert("Toffee");
  
   NL1.insert("Jack", GL1);
   NL1.insert("Bill", GL2);
   NL1.insert("Alice", GL3);
  
   cout<<"Content of Nice List: ";
   NL1.print();//Print Nice List
  
   cout<<" Adding a new gift for Alice... ";
   NL1.addGift("Alice", "Cotton Candy");
  
   cout<<"Content of Nice List: ";
   NL1.print();//Print Nice List
  
   return 0;
}
