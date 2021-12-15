//Muhammad Saud Zahir.

#include <iostream>
#include <string>
#include <Windows.h>
#include<iomanip>
#include<stdlib.h>
#include <conio.h>
using namespace std;
class Lights {
protected:
	string light_color;
	int time;
public:
	Lights() { light_color = "no color"; time = 0; }
	string getLightColor() { return light_color; }
	void setTime(int a) { time = a; }
	int getTime() { return time; }
	virtual void signalTime() = 0;
};
class sides {
	string sideName;
public:
	sides(string a) { //constructor
		sideName = a;
	}
	string getSideName() { return sideName; };
	void sideMoving() {
		cout << "The Side Moving is : " << getSideName() << endl;
	};
	void sideWaiting() {
		cout << "The Side Waiting is : " << getSideName() << endl;
	};
	void sideReady() {
		cout << "The Side Ready to Move is : " << getSideName() << endl;
	};
};
class red :public Lights {
public:
	red() { light_color = "RED"; }
	void signalTime() {
		setTime(10 * 1000); //red light is on for 10 seconds.Value here may be incresed/decreased
	}
};
class yellow :public Lights {
public:
	yellow() { light_color = "YELLOW"; }
	void signalTime() {
		setTime(6 * 1000); //yellow light is on for 6 seconds.Value here may be incresed/decreased
	}
};
class green :public Lights {
public:
	green() { light_color = "GREEN"; }
	void signalTime() {
		setTime(20 * 1000); //green light is on for 20 seconds.Value here may be incresed/decreased
	}
};
Lights* turnSignal(Lights *lt) {
	red *r = new red;
	green *g = new green;
	yellow *y = new yellow;
	if (lt->getLightColor() == "RED")
	{
		lt = dynamic_cast<Lights *>(y);
		return lt;
	}
	else if (lt->getLightColor() == "YELLOW")
	{
		lt = dynamic_cast<Lights*>(g);
		return lt;
	}
	else if (lt->getLightColor() == "GREEN")
	{
		lt = dynamic_cast<Lights*>(r);
		return lt;
	}
}
void timer(int a)
{
	Sleep(a);

};
///////////////////////////////
int main() {
	sides north("North"), south("South"), east("East"), west("West");
	green *g = new green;
	// set signal time and north side starts moving.
	g->signalTime();
	cout << "The ==> " << g->getLightColor() << " <== signal is ON" << endl;
	north.sideMoving();
	timer(g->getTime());
	////
	Lights *lt = turnSignal(g);
	cout << endl;
	cout << endl;
	//turn color to red and north starts waiting.
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	north.sideWaiting();
	lt->signalTime();
	timer(lt->getTime());
	////
	cout << endl;
	cout << endl;
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	east.sideReady();
	lt->signalTime();
	timer(lt->getTime());
	cout << endl;
	cout << endl;
	//turn color to green and east side start moving
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	east.sideMoving();
	lt->signalTime();
	timer(lt->getTime());
	cout << endl;
	cout << endl;
	//turn signal to red and east side start waiting
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	east.sideWaiting();
	lt->signalTime();
	timer(lt->getTime());
	//

	//turn signal to yellow and south is ready to move
	cout << endl;
	cout << endl;
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	south.sideReady();
	lt->signalTime();
	timer(lt->getTime());
	//
	//turn signal to green and south is ready to move
	cout << endl;
	cout << endl;
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	south.sideMoving();
	lt->signalTime();
	timer(lt->getTime());
	//turn signal to red and south is waiting
	cout << endl;
	cout << endl;
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	south.sideWaiting();
	lt->signalTime();
	timer(lt->getTime());
	/////
	//turn signal to yellow and west is ready to move
	cout << endl;
	cout << endl;
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	west.sideWaiting();
	lt->signalTime();
	timer(lt->getTime());
	///
	//turn signal to green and west is moving
	cout << endl;
	cout << endl;
	lt = turnSignal(lt);
	cout << "The ==> " << lt->getLightColor() << " <== signal is ON" << endl;
	west.sideMoving();
	lt->signalTime();
	timer(lt->getTime());
	system("pause");
	return 0;
}
