// Micah Pennington
// April 12 2022 ©
// Chapter 14 Program
#include <iostream>

using namespace std;

/***************************** NumDays Class *****************************/

class NumDays {
private:
	double hours;
	double days;
public:
	NumDays(double h = 0) {
		hours = h;
		days = h / 8;
	}
	void setHours(double h) {
		hours = h;
		days = h / 8;
	}
	void setDays(double d) {
		days = d;
		hours = d * 8;
	}
	double getHours()const { return hours;}
	double getDays()const { return days; }
	//overloaded + operator
	NumDays operator+(NumDays& right) {
		NumDays temp;
		temp.setHours(hours + right.getHours());
		return temp;
	}
	//overloaded - operator
	NumDays operator -(NumDays& right) {
		NumDays temp;
		temp.setHours(hours - right.getHours());
		return temp;
	}
	//overloaded prefix ++
	NumDays operator ++() {
		++hours;
		days = hours / 8;
		return *this;
	}
	//overloaded operator postfix ++
	NumDays operator ++(int) {
		hours++;
		NumDays temp(hours);
		days = hours / 8;
		return temp;
	}
	//overloaded operator prefix --
	NumDays operator --() {
		--hours;
		days = hours / 8;
		return *this;
	}
	//overloaded operator postfix--
	NumDays operator --(int) {
		hours--;
		NumDays temp(hours);
		days = hours / 8;
		return temp;
	}
};

/***************************** TimeOff Class *****************************/

class TimeOff {
private:
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays vacTaken;
	NumDays maxUnpaid;
	NumDays unpaidTaken;
	string employeeName;
	int employeeID;
public:
	TimeOff(NumDays maxSickDaysIN = NumDays(0), NumDays maxVacationIN = NumDays(0), NumDays maxUnpaidIN = NumDays(0), string employeeNameIN = "No Name", int employeeIDIN = -1) {
		maxSickDays = maxSickDaysIN;
		// I wasn't sure how to do this input validation, so tell me if I did it wrong and I'll fix it
		// Also, if the instructions didn't explicily specify what members this class should have I would add a static const or something to hold the 240
		// Hard coding it feels wrong lol
		if (maxVacationIN.getHours() > 240) {
			maxVacation.setHours(240);
			cout << "Max Vacation entered exceeds max limit of 240 hours. Set to max of 240\n";
		}
		else { maxVacation = maxVacationIN; }
		maxUnpaid = maxUnpaidIN;
		employeeName = employeeNameIN;
		employeeID = employeeIDIN;
	}
	void setMaxSickDays(NumDays maxSickDaysIN) { maxSickDays = maxSickDaysIN; }
	void setSickTaken(NumDays sickTakenIN) { sickTaken = sickTakenIN; }
	void setMaxVacation(NumDays maxVacationIN) {
		if (maxVacationIN.getHours() > 240) {
			maxVacation.setHours(240);
			cout << "Max Vacation entered exceeds max limit of 240 hours. Set to max of 240\n";
		}
		else { maxVacation = maxVacationIN; }
	}
	void setVacTaken(NumDays vacTakenIN) { vacTaken = vacTakenIN; }
	void setMaxUnpaid(NumDays maxUnpaidIN) { maxUnpaid = maxUnpaidIN; }
	void setUnpaidTaken(NumDays unpaidTakenIN) { unpaidTaken = unpaidTakenIN; }
	void setEmployeeName(string employeeNameIN) { employeeName = employeeNameIN; }
	void setEmployeeID(int employeeIDIN) { employeeID = employeeIDIN; }
	/* In case "Taken" variables are not supposed to exceed the max
	void setMaxSickDays(NumDays maxSickDaysIN) { maxSickDays = maxSickDaysIN; }
	void setSickTaken(NumDays sickTakenIN) {
		if (sickTakenIN.getHours() > maxSickDays.getHours()) {
			sickTaken = maxSickDays;
			cout << "Sick Taken entered exceeds max limit of " << maxSickDays.getHours() << " hours. Set to max of " << maxSickDays.getHours() << '\n';
		}
		else { sickTaken = sickTakenIN; }
	}
	void setMaxVacation(NumDays maxVacationIN) {
		if (maxVacationIN.getHours() > 240) {
			maxVacation.setHours(240);
			cout << "Max Vacation entered exceeds max limit of 240 hours. Set to max of 240\n";
		}
		else { maxVacation = maxVacationIN; }
	}
	void setVacTaken(NumDays vacTakenIN) {
		if (vacTakenIN.getHours() > maxVacation.getHours()) {
			vacTaken = maxVacation;
			cout << "Vacation Taken entered exceeds max limit of " << maxVacation.getHours() << " hours. Set to max of " << maxVacation.getHours() << '\n';
		}
		else { vacTaken = vacTakenIN; }
	}
	void setMaxUnpaid(NumDays maxUnpaidIN) { maxUnpaid = maxUnpaidIN; }
	void setUnpaidTaken(NumDays unpaidTakenIN) {
		if (unpaidTakenIN.getHours() > maxUnpaid.getHours()) {
			unpaidTaken = maxUnpaid;
			cout << "Sick Taken entered exceeds max limit of " << maxUnpaid.getHours() << " hours. Set to max of " << maxUnpaid.getHours() << '\n';
		}
		else { unpaidTaken = unpaidTakenIN; }
	}
	void setEmployeeName(string employeeNameIN) { employeeName = employeeNameIN; }
	void setEmployeeID(int employeeIDIN) { employeeID = employeeIDIN; }*/
	NumDays getMaxSickDays() { return  maxSickDays; }
	NumDays getSickTaken() { return  sickTaken; }
	NumDays getMaxVacation() { return  maxVacation; }
	NumDays getVacTaken() { return  vacTaken; }
	NumDays getMaxUnpaid() { return  maxUnpaid; }
	NumDays getUnpaidTaken() { return  unpaidTaken; }
	string getEmployeeName() { return employeeName; }
	int getEmployeeID() { return employeeID; }

};

/***************************** Main Program *****************************/

int main() {
	/*
	NumDays one(25), two(15), three, four;
	//display one and two
	cout << "One: " << one.getDays() << endl;
	cout << "Two: " << two.getDays() << endl;
	//Add one and two assign the result to three
	three = one + two;
	//display three
	cout << "Three: " << three.getDays() << endl;
	//postfix increment operator
	four = three++;
	cout << "Four = three++: " << four.getDays() << endl;
	//prefix increment operator
	four = ++three;
	cout << "Four = ++three: " << four.getDays() << endl;
	//post fix decrement operator
	four = three--;
	cout << "Four = three--: " << four.getDays() << endl;
	//pre fix decrement operator
	four = --three;
	cout << "Four = --three: " << four.getDays() << endl;
	*/

	// Declare variables
	TimeOff timeOff;
	int months;
	const int SICK_HOURS_PER_MONTH = 8;
	const int VACATION_HOURS_PER_MONTH = 12;

	// Get input
	cout << "Please enter the number of months the employee has worked at the company for: ";
	cin >> months;
	cin.ignore();

	// Calculate time off
	timeOff.setMaxSickDays(NumDays(SICK_HOURS_PER_MONTH * months));
	timeOff.setMaxVacation(NumDays(VACATION_HOURS_PER_MONTH * months));

	// Display employee sick and vacation days
	cout << "Max sick days = " << timeOff.getMaxSickDays().getDays() << "\nMax vacation days = " << timeOff.getMaxVacation().getDays();

	return EXIT_SUCCESS;
}