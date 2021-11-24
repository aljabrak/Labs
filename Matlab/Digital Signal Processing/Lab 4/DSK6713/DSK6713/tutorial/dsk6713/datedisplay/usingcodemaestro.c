
// A C structure 
typedef struct date {
	int day;
	int month;
	int year;
	char monthName[3];
} DATE, *DATEPTR

// Some variable declarations
const int COUNTER = 1;
int dspConfig = 0;
DATEPTR currDate;
DATE futureDate;

// A typical function
int addNumber(int num1, int num2)
{
	return num1 + num2;
}
