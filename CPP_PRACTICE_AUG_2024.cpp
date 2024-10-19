#include <iostream>
using namespace std;


/*
command to comment code block in visual studio Ctrl + /
command to uncomment code block in visual studio Ctrl+K+U
command to comment code block in notepad++ Ctrl+k
command to uncomment code block in notepad++ Ctrl+shift+k
*/
/*
QUEST GLOBAL INTERVIEW QUESTION
Q) Write a program in C to compare two strings without using string library functions.
int strcmp(const char *s1, const char *s2)

int main(){}

int strcmp(const char *s1, const char *s2)
{

for(;*s1!='\0';s1++,s2++){
if(*s1!=*s2)
{
return 1;
}

}
if(*s1=='\0'&&s2=='\0')
return 0;
else
}
*/
//Function call by value
void update(int x)
{
	cout << "X is : " << x << endl;
}

int main()
{
	int val=10;
	update(val);
	cout << "VAL is : " << val << endl;
	return 0;
}

//Function call by reference
void update(int& x)
{
	x=x+10;
}

int main()
{
	int val=10;
	cout << "Val before update : " << val << endl;
	update(val);
	cout << "Val after change : " << val << endl;
	
	
}

//SingleTon design in C++
/*
it conatians below things
1.static member
2.private constructor
3.static member function
4.copy constructor = delete
5.assignment operator = delete
*/

class sn
{
	private:
	static sn*i;
	sn(){cout << "SingleTon object created"<< endl;}
	public:
	sn(const Singleton&) = delete;
    sn& operator=(const Singleton&) = delete;
	sn(const sn&)=delete;
	sn& operator =(const sn&)=delete;
	static sn*GetI()
	{
		if(i==0)
			i=new sn();
		return i;
	}
};
sn* sn::i=0;

int main()
{
	sn*s1=sn::GetI();
	sn*s2=sn::GetI();
	if(s1==s2)
		cout<<"Both pointers are pointing to same instance"<<endl;
	else
		cout<<"Both pointers are not pointing to same instance"<<endl;
	return 0;
}

//Static data member and Static functions in C++
class Base
{
	public:
	int x;
	static y;	
	void printX(){cout << x << endl;}
	void printY(){cout << y << endl;}
};
Base::y;
Base::printY();
int main()
{
	Base b1;
	b1.x=10;
	b1.y=30; //Base::y=30;
	Base b2;
	b2.x=20;
	b2.y=40; //Base::y=40;
	cout << b1.x << endl;
	cout << b1.y << endl;
	cout << b2.x << endl;
	cout << b2.y << endl;
	b1.printX();
	b1.printY();// Base::printY();
	b2.printX();
	b2.printY();//Base::printY();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////***Function overloading***/////////////////////
/*
#include <iostream>
using namespace std;
int add(int a, int b)
{
    cout <<"calling integer"<<endl;
    return 0;
}
double add(double x, double y)
{
    cout <<"Calling double"<<endl;
    return 1.2;
    
}

int main()
{
    int c=add(2,6);
    double d=add(1.2,2.3);
    cout <<d<<endl;
    cout<<c<<endl;
    return 0;
}
*/

///////////////////COPY CONSTRUCTOR USING CHAR * POINTER///////////////////////////

#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;

public:
    // Constructor
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    // Display the data
    void display() {
        std::cout << data << std::endl;
    }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2(obj1); // Copy constructor called

    obj1.display();
    obj2.display();

    return 0;
}

///////////////////////////////////////////////////////Copy constructor using char *////////////////////////////////////
#include <iostream>
#include <cstring>

class MyClass {
private:
    char* str;
    int num;

public:
    // Constructor
    MyClass(const char* s, int n) : num(n) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    MyClass(const MyClass& other) : num(other.num) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~MyClass() {
        delete[] str;
    }

    // Display function
    void display() {
        std::cout << "String: " << str << ", Number: " << num << std::endl;
    }
};

int main() {
    MyClass obj1("Hello", 10);
    MyClass obj2(obj1); // Copy constructor called

    obj1.display();
    obj2.display();

    return 0;
}

//////////////////////////////example program for assignmet operator overloading and copy constructor////////////////
#include <iostream>
using namespace std;
class BMA
{
    int *x;
    public:
    BMA(int val=0):x{new int(val)} {}
    void setX(int val){*x=val;}
    void print(){cout<<"OUTPUT : "<<*x<<endl;}
    ~BMA() { delete x; cout<<"Destructor called"<<endl;}
    BMA& operator = (const BMA& obj)
    {
        if(this!=&obj)
        {
        *x = *obj.x;
        cout<<"Assignment operator called"<<endl;
        }
        return *this;

    }
    BMA(const BMA& rhs)
    {
        x = new int;
        *x = *rhs.x;
        cout<<"Copy constructor called"<<endl;
    }
};
int main()
{
    BMA b1(10);
    cout<<"Printing b1 value"<<endl;
    b1.print();
    cout<<"Trying to call assignmet operator"<<endl;
    BMA b2;
    b2=b1;
    b2.print();
    cout<<"trying to call copy constructor"<<endl;
    BMA b3(b1);//we can also use BMA b3=b1 
    b3.print();
    b1.setX(20);
    cout<<"b1 value after change"<<endl;
    b1.print();
    cout<<"b2 and b3 value after changing b1 value"<<endl;
    b2.print();
    b3.print();
    return 0;
}

//all c++ topics comparsion vs rust toipcs comparsion with definition summary

//////////////////copy constructor and assignment operator with char* int* pointers with default constructor////////////////
#include <iostream>
#include <cstring>
using namespace std;
class BMA
{
    char* name;
    int *sno;
    public:
    BMA(const char* str="",int val=0):sno{new int(val)}
    {
        name = new char[strlen(str)+1];
        strcpy(name,str);
    }
    void setName(const char* str)
    {
        name = new char[strlen(str)+1];
        strcpy(name,str);
    }
    BMA(const BMA& obj)
    {
        name = new char[strlen(obj.name)+1];
        strcpy(name,obj.name);
        sno = new int;
        *sno = *obj.sno;
        cout<<"Copy constructor called"<<endl;
    }
    BMA& operator = (const BMA& rhs)
    {
        if(this!=&rhs)
        {
            strcpy(name,rhs.name);
            *sno = *rhs.sno;
            cout<<"Assignment operator called"<<endl;
        }
        return *this;
    }
    void print()
    {
        cout<<"Name : "<<name<<"\t"<<"URN : "<<*sno<<endl;
    }
    ~BMA() { delete[] name; delete sno; cout<<"Destructor called"<<endl; }
};
int main()
{
    BMA HSBC;
    HSBC.print();
    HSBC.setName("VAMSHI");
    HSBC.print();
    BMA AMEX;
    AMEX = HSBC;
    AMEX.print();
    BMA BOA(HSBC);
    BOA.print();
    return 0;
}

//////////////////copy constructor and assignment operator with char* int with default constructor////////////////
#include <iostream>
#include <cstring>
using namespace std;
class BMA
{
    char* name;
    int sno;
    public:
    BMA(const char* str="",int val=0):sno(val)
    {
        name = new char[strlen(str)+1];
        strcpy(name,str);
    }
    void setName(const char* str)
    {
        delete name;
        cout<<"deleted the name pointer"<<endl;
        name = new char[strlen(str)+1];
        strcpy(name,str);
    }
    BMA(const BMA& obj)
    {
        name = new char[strlen(obj.name)+1];
        strcpy(name,obj.name);
        //sno = new int;
        sno = obj.sno;
        cout<<"Copy constructor called"<<endl;
    }
    BMA& operator = (const BMA& rhs)
    {
        if(this!=&rhs)
        {
            strcpy(name,rhs.name);
            sno = rhs.sno;
            cout<<"Assignment operator called"<<endl;
        }
        return *this;
    }
    void print()
    {
        cout<<"Name : "<<name<<"\t"<<"URN : "<<sno<<endl;
    }
    ~BMA() { delete[] name; cout<<"Destructor called"<<endl; }
};
int main()
{
    BMA HSBC("VAMSHI_KUMAR",10);
    HSBC.print();
    HSBC.setName("VAMSHI");
    HSBC.print();
    BMA AMEX;
    AMEX = HSBC;
    AMEX.print();
    BMA BOA(HSBC);
    BOA.print();
    return 0;
}
