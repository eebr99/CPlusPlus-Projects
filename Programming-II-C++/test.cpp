#include <iostream>
using namespace std;



class Point {
   private:
      int x, y;
   public:
      void set(int, int);
};

void Point::set(int x, int y) {
   x = x; 
   y = y; 
}





int main(){
	
cout << sizeof(int) << endl;
cout << sizeof(short) << endl;
cout << sizeof(double) << endl;
cout << sizeof(char) << endl;
cout << sizeof(long double) << endl;

		
void show(int n){
  if (n>1) {
    show(n-1);
  }
  cout<<n<<" ";
}

show(5);







}
