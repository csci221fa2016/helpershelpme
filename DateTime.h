#ifndef DATETIME
#define DATETIME
#include <string>

using namespace std;

class DateTime {
	private:
		int year;
		int month;
		int day;
		int hour;
		int minute;
		void parseString();
	public:
		DateTime();
		DateTime(string _str);
		void setYear();
		void setMonth();
		void setDay();
		void setHour();
		void setMinute();
		int getYear();
		int getMonth();
		int getDay();
		int getHour();
		int getMinute();
		string toString();
}

#endif
