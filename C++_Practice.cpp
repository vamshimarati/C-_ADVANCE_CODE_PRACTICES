
codedamn courses in google and search for cpp

/*===========================================================================*/
/*Function Call by Value*/

// #include <iostream>
// using namespace std;

// void update(int* x)
// {
// cout << "X :" << *x << endl;
// }

// int main(){
// int p=10;
// void update(int& p);
// cout << "Val :" << p << endl;
// return 0;
// }

/*===========================================================================*/

/*Const data member*/

// #include <iostream>
// using namespace std;

// class Circle{
	// const int pi=3.14;
	// int r;
	// public:
	// Circle(float a) {r=a;}
	// void getArea(){cout << r*r*pi << endl;}
// };

// int main(){
	// Circle c1(5.4), c2(10);
	// c1.getArea();
	// c2.getArea();
	// return 0;
// }

/*===========================================================================*/

#include <iostream>
using namespace std;

class point
{
	private:
	int x, y;
	public:
	point(int x1, inty1)
	{
		x=x1;
		y=y1;
	}
	
	point (const point& obj)//copy constructor
	{
		x=obj.x;
		y=obj.y;
	}
	void display()
	{
		cout << x << endl;
		cout << y << endl;
	}
};

int main()
{
	point p1(10, 20);
	point p1(p2);
	p1.display();
	p2.display();
	return 0;
}