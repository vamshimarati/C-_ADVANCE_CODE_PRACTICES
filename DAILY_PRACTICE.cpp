#include <iostream>
using namespace std;

//fucntion call by value 
// void update(int x)
// {
// cout << "X :" << x << endl;
// x++;
// cout << "X :" << x << endl;
// }

// int main()
// {
// int p=10;
// cout << "Val :" << p << endl;
// update(p);
// cout << "Val :" << p << endl;
// return 0;
// }

//===================================================================
//function call by refernce
// #include <iostream>
// using namespace std;
// void update(int &x)
// {
// cout << "X :" << x << endl;
// x++;
// cout << "X :" << x << endl;
// }

// int main()
// {
// int p =10;
// cout << "Val :" << p << endl;
// update(p);
// cout << "Val :" << p << endl;
// return 0;
// }

//===================================================================
//call by pointer
// #include <iostream>
// using namespace std;

// void update(int *x)
// {
// cout << "X :" << *x << endl;
// (*x)++;
// cout << "X :" << *x << endl;
// }

// int main()
// {
// int p =10;
// cout << "Val :" << p << endl;
// update(&p);
// cout << "Val :" << p << endl;
// return 0;
// }

//===================================================================
//class and object
// #include <iostream>
// using namespace std;
// class Base{
// Private:
// int x;
// int y;
// public:
// void set(int a, int b){x=a; y=b;}
// void disp(){cout << x << endl; cout << y << endl;}
// };
// int main()
// {
// Base b1;
// b1.set(10, 20);
// Base b2;
// b2.set(10, 20);
// b1.disp();
// b2.disp();
// return 0;
// }

//===================================================================
//constructor, default constructor, parameterized constructor, copy constructor
// #include <iostream>
// using namespace std;
// class Base{
// private:
// int x;
// int y;
// public:
// Base(){int x=0; int y=0; cout << "default constructor is called" << endl;}
// Base(int a, int b){x=a; y=b; cout << "Parameterized called.." << endl;}
// Base(Base &rhs){x=rhs.x; y=rhs.y; cout << "copy constructor is called" << endl;}
// void disp(){cout << "X :" << x << endl; cout << "Y :" << y << endl;}
// };
// int main()
// {
// Base b1;
// b1.disp();
// Base b2(20, 30);
// b2.disp();
// Base b3 = b2;
// b3.disp();
// cout << "copying existing objects" << endl;
// b1=b2;
// b1.disp();
// return 0;
// }

//===================================================================
// constructor initializer list
// #include <iostream>
// using namespace std;

// class counter
// {
// private:
// int count;
// int a;
// int b;
// public:
// //counter():count(0){}
// counter () : count(1), a(17), b(35){}
// void disp(){cout << count << endl; cout << a << endl; cout << b << endl;}	
// };
// int main()
// {
	// counter c1;
	// c1.disp();
	// return 0;
// }

//===================================================================
// operator overloading returning temporary object
// #include <iostream>
// using namespace std;
// class counter
// {
	// private:
	// int count;
	// public:
	// counter():count(0){}
	// int get_count(){return count;}
	// counter operator ++()
	// {
		// ++count;
		// counter temp;
		// temp.count=count;
		// return temp;
	// }
// };
// int main(){
	// counter c1, c2;
	// cout << "\n c1 =" << c1.get_count(); // did a mistake keeping "<< endl;"
	// cout << "\n c2 =" << c2.get_count(); 
	// ++c1;
	// c2=++c1;
	// cout << "\n c1 =" << c1.get_count(); 
	// cout << "\n c2 =" << c2.get_count(); 
	// return 0;
// }

//===================================================================
//operator overloading by returning nameless temporary object
#include <iostream>
using namespace std;

class counter{
private:
int count;
public:
counter():count(0){}
counter(int c):count(c) {}
int get_count(){return count;}
counter operator ++(){
++count;
return counter(count);
}
};

int main(){
counter c1, c2;
cout << "\n c1 = " << c1.get_count();// did a mistake, without giving member access operator like "c1.get_count();"
cout << "\n c2 = " << c2.get_count();
++c1;
c2=++c1;
cout << "\n c1 = " << c1.get_count();
cout << "\n c2 = " << c2.get_count();
return 0;
}





































































