//Class and Object.

#include <iostream>
#include <string>
using namespace std;
class Volume {
public:
   double length()
	{
		double l;
		cout << "length of box: ";
		cin>> l;
		return l;
	 }
   double width()
   {
	   double w;
	   cout << "width of box: ";
	   cin >> w;
	   return w;
   }
   double height()
   {
	   double h;
	   cout << "height of box: ";
	   cin >> h;
	   return h;
   }
};
int main()
{
	float a,b,c,V;
	Volume l,w,h;
	a = l.length();
	b = w.width();
	c = h.height();
	V = a * b * c;
	cout << "l =" << a << endl;
	cout << "w =" << b << endl;
	cout << "h =" << c << endl;
	cout << "Volume of Box: " << V;
	return 0;
}
