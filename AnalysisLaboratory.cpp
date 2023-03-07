#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class check {
private:
	string name;
	string id;
public:
	virtual void afisareDateImportante()
	{
		cout << "The person's name is " << this->name << "\n";
		cout << "The person's id is " << this->id << "\n";

	}
	virtual void validity()
	{
		if (this->name == "unknown" || this->id == "000000" || this->id == "unknown")

			cout << "We do not have valid data about the person/ The person is not registered";
		else
			cout << "There are no errors in the person's data.";

	}
};

class binaryFile {
public:
	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;

};

class employee :public check
{
private:
	const string employeeId;
	string name;
	float salary;
	string functionId;
	string phoneNumber;
	int workedDays;
	int* hoursWorkedPerDay;
public:

	employee() :employeeId("000000")
	{

		name = "unknown";
		salary = 0;
		functionId = "000000";
		phoneNumber = "unknown";
		workedDays = 0;
		hoursWorkedPerDay = NULL;


	}
	employee(string employeeId, string name, string functionId) :employeeId(employeeId)
	{

		if (name.length() > 0)
			this->name = name;
		else
			this->name = "unknown";
		if (functionId.length() > 0)
			this->functionId = functionId;
		else
			this->functionId = "000000";

	}
	employee(string employeeId, const string name, float salary, string functionId, string phoneNumber, int workedDays, int* hoursWorkedPerDay) :employeeId(employeeId)
	{

		if (name.length() > 0)
			this->name = name;
		else
			this->name = "unknown";
		if (salary > 0)
			this->salary = salary;
		else
			this->salary = 0;
		this->functionId = functionId;
		if (phoneNumber.length() > 0)
			this->phoneNumber = phoneNumber;
		else
			this->phoneNumber = "unknown";
		if (workedDays > 0)
		{
			this->workedDays = workedDays;
			this->hoursWorkedPerDay = new int[this->workedDays];
			for (int i = 0; i < this->workedDays; i++)
				this->hoursWorkedPerDay[i] = hoursWorkedPerDay[i];
		}
		else {
			this->workedDays = 0;
			this->hoursWorkedPerDay = NULL;
		}
	}

	employee(const employee& a) :employeeId(a.employeeId)
	{

		this->name = a.name;
		this->salary = a.salary;
		this->functionId = a.functionId;
		this->phoneNumber = a.phoneNumber;
		this->workedDays = a.workedDays;
		this->hoursWorkedPerDay = new int[a.workedDays];
		for (int i = 0; i < a.workedDays; i++)
			this->hoursWorkedPerDay[i] = a.hoursWorkedPerDay[i];

	}
	~employee()
	{
		delete[] this->hoursWorkedPerDay;
	}
	employee& operator=(const employee& a)
	{
		if (this != &a)
		{
			delete[]this->hoursWorkedPerDay;
			this->name = a.name;
			this->salary = a.salary;
			this->functionId = a.functionId;
			this->phoneNumber = a.phoneNumber;
			this->workedDays = a.workedDays;
			this->hoursWorkedPerDay = new int[a.workedDays];
			for (int i = 0; i < a.workedDays; i++)
				this->hoursWorkedPerDay[i] = a.hoursWorkedPerDay[i];

		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const employee& a)
	{
		out << endl;
		out << "\nThe employee id is: " << a.employeeId;
		out << "\nThe name of the employee is: " << a.name;
		out << "\nThe employee's salary is: " << a.salary;
		out << "\nThe employee job id is: " << a.functionId;
		out << "\nThe employee's phone number is: " << a.phoneNumber;
		out << "\nThe number of days worked per month is: " << a.workedDays;
		out << "\nThe number of hours worked per month is: ";
		for (int i = 0; i < a.workedDays; i++)
			out << a.hoursWorkedPerDay[i] << " ";
		return out;

	}
	friend istream& operator>>(istream& in, employee& a)
	{
		cout << endl;
		delete[] a.hoursWorkedPerDay;
		cout << "\nThe employee id is: ";
		in >> a.functionId;
		cout << "\nThe name of the employee is: ";
		in >> a.name;
		cout << "\nThe employee's salary is: ";
		in >> a.salary;
		cout << "\nThe employee job id is: ";
		in >> a.functionId;
		cout << "\nThe employee's phone number is: ";
		in >> a.phoneNumber;
		cout << "\nThe number of days worked per month is: ";
		in >> a.workedDays;
		cout << "\nThe number of hours worked per month is: ";
		a.hoursWorkedPerDay = new int[a.workedDays];
		for (int i = 0; i < a.workedDays; i++)
		{
			in >> a.hoursWorkedPerDay[i];
		}
		return in;
	}

	string getidAngajat()
	{
		return this->employeeId;
	}
	string getnume()
	{
		return this->name;
	}
	void setnume(string name)
	{
		if (name.length() > 0)
		{
			this->name = name;
		}

	}
	float getsalariu()
	{
		return this->salary;
	}
	void setsalariu(float salary)
	{
		if (salary > 0)
			this->salary = salary;
	}
	string getidFunctie()
	{
		return this->functionId;
	}
	void setidfunctie(string functionId)
	{
		if (functionId.length() > 1)
			this->functionId = functionId;

	}

	string gettelefon()
	{
		return this->phoneNumber;
	}
	void settelefon(string phoneNumber)
	{
		if (phoneNumber.length() > 1)
			this->phoneNumber = phoneNumber;
	}
	int getzilelucratelunar()
	{
		return this->workedDays;
	}
	void setzilelucrate(int workedDays)
	{
		if (this->workedDays > 0)
			this->workedDays = workedDays;
	}
	int* getorelucrate()
	{
		return this->hoursWorkedPerDay;

	}
	void setOreLucratePeZi(int* hoursWorkedPerDay)
	{
		if (hoursWorkedPerDay != NULL)
		{
			delete[] this->hoursWorkedPerDay;
			this->hoursWorkedPerDay = new int[this->workedDays];
			for (int i = 0; i < this->workedDays; i++)
				this->hoursWorkedPerDay[i] = hoursWorkedPerDay[i];
		}

	}

	employee& operator+(int x) {
		if (x > 0)
		{
			this->salary = this->salary + x;
		}

		return *this;
	}
	int operator[](int i)
	{
		if (i >= 0 && i < this->workedDays)
			return this->hoursWorkedPerDay[i];
	}
	bool operator==(employee& a)
	{
		if (this->employeeId != a.employeeId || this->name != a.name || this->salary != a.salary || this->functionId != a.functionId || this->phoneNumber != a.phoneNumber || this->workedDays != a.workedDays)
			return false;
		for (int i = 0; i < this->workedDays; i++)
			if (this->hoursWorkedPerDay[i] != a.hoursWorkedPerDay[i])
				return false;
		return true;

	}
	/*bool operator<(angajat a)
	{
		return this->numarZileLucrate < a.numarZileLucrate;
	}*/
	friend bool operator<(const employee& a1, const employee& a2) {
		return a1.workedDays < a2.workedDays;
	}
	bool operator!()
	{
		if (this->workedDays <= 0)
			return false;
		return true;

	}
	employee& operator++()
	{
		this->salary++;
		return *this;

	}
	employee& operator++(int)
	{
		employee vn = *this;
		this->salary++;
		return vn;

	}
	operator int()
	{
		int totalHours = 0;
		for (int i = 0; i < this->workedDays; i++)
			totalHours += hoursWorkedPerDay[i];
		return totalHours;

	}
	void afisare()
	{
		cout << endl;
		cout << "\nThe employee id is:  " << this->employeeId;
		cout << "\nThe name of the employee is: " << this->name;
		cout << "\nThe employee's salary is: " << this->salary;
		cout << "\nThe employee job id is: " << this->functionId;
		cout << "\nThe employee's phone number is: " << this->phoneNumber;
		cout << "\nThe number of days worked per month is: " << this->workedDays;
		cout << "\nThe number of hours worked per month is: ";
		for (int i = 0; i < this->workedDays; i++)
			cout << this->hoursWorkedPerDay[i] << " ";

	}

	void writeToFile(fstream& f) {
		size_t lg = this->employeeId.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->employeeId.data(), lg * sizeof(char));

		size_t lg1 = this->name.length() + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->name.data(), lg1 * sizeof(char));

		size_t lg2 = this->functionId.length() + 1;
		f.write((char*)&lg2, sizeof(int));
		f.write(this->functionId.data(), lg2 * sizeof(char));

		size_t lg3 = this->phoneNumber.length() + 1;
		f.write((char*)&lg3, sizeof(int));
		f.write(this->phoneNumber.data(), lg3 * sizeof(char));

		f.write((char*)&this->salary, sizeof(float));

		f.write((char*)&this->workedDays, sizeof(int));

		for (int i = 0; i < this->workedDays; i++)
		{
			f.write((char*)&this->hoursWorkedPerDay[i], sizeof(int));
		}


	}
	void readFromFile(fstream& f) {


		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->name = buffer;
		delete[] buffer;

		int lg1;
		f.read((char*)&lg1, sizeof(int));
		char* buffer1 = new char[lg1];
		f.read(buffer1, lg1);
		this->functionId = buffer1;
		delete[] buffer1;


		int lg3;
		f.read((char*)&lg3, sizeof(int));
		char* buffer2 = new char[lg3];
		f.read(buffer2, lg3);
		this->phoneNumber = buffer2;
		delete[] buffer2;

		f.read((char*)&this->salary, sizeof(float));

		f.read((char*)&this->workedDays, sizeof(int));

		delete[] this->hoursWorkedPerDay;
		this->hoursWorkedPerDay = new int[this->workedDays];
		for (int i = 0; i < this->workedDays; i++)
		{
			f.read((char*)&this->hoursWorkedPerDay[i], sizeof(int));
		}



	};

	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "name ";
			cin >> this->name;
			fout << this->name << "\n";

			cout << "salary ";
			cin >> this->salary;
			fout << this->salary << "\n";

			fout << this->employeeId << "\n";

			cout << "job id ";
			cin >> this->functionId;
			fout << this->functionId << "\n";

			cout << "phone ";
			cin >> this->phoneNumber;
			fout << this->phoneNumber << "\n";

			cout << "worked days ";
			cin >> this->workedDays;
			fout << this->workedDays << "\n";

			cout << "worked hours ";
			this->hoursWorkedPerDay = new int[this->workedDays];
			for (int i = 0; i < this->workedDays; i++)
			{
				cin >> this->hoursWorkedPerDay[i];
				fout << this->hoursWorkedPerDay[i] << " ";
			}

			fout.close();
		}



	}

	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}


	void scriereCsv(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);

		int i, salary;
		string name, idF, id, phone;
		fout << "Name" << "," << "employeeId" << "," << "functionId" << "," << "Phone number" << "," << "Salary" << "\n";

		for (i = 0; i < 1; i++) {
			cout << "name " << i << " ";
			cin >> name;
			cout << "id " << i << " ";
			cin >> id;
			cout << "functionId  " << i << " ";
			cin >> idF;
			cout << "Phone number " << i << " ";
			cin >> phone;
			cout << "Salary " << i << " ";
			cin >> salary;
			cin.ignore();

			fout << name << ", " << id << ", " << idF << ", " << phone << ", " << salary << ", " << "\n";
		}
		fout.close();
	}
	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	virtual void importantData()
	{
		cout << "The person's name is: " << this->name << "\n";
		cout << "The person's id id: " << this->employeeId << "\n";

	}
	virtual void valid()
	{
		if (this->name == "unknown" || this->employeeId == "000000" || this->employeeId == "unknown")

			cout << "We do not have valid data about the person/ The person is not registered";
		else
			cout << "There are no errors in the person's data.";

	}

	/*void afisareDateImportante() {
		cout << "Id-ul angajatului este: " << this->idAngajat << "\n";
		cout << "Numele angajatului este: " << this->numeAngajat << "\n";
	}
	void valid() {
		if (this->idAngajat == "000000" || this->numeAngajat == "Necunoscut")
			cout << "Nu avem date valide despre angajat/Persoana nu este angajata";
		else
			cout << "Date angajatului nu prezinta erori.";
	}*/



};

class employeeUpdate :public employee {
	int age = 0;
	vector<int> freeDaysPerMonth;
public:
	employeeUpdate()
	{
		this->age = 0;
		for (int i = 0; i < 12; i++)
			this->freeDaysPerMonth.push_back(0);
	}
	employeeUpdate(string employeeId, string name, float salary, string functionId, string phoneNumber,
		int workedDays, int* hoursWorkedPerDay, int age, vector<int> freeDaysPerMonth) :employee(employeeId, name, salary, functionId, phoneNumber, workedDays, hoursWorkedPerDay)
	{
		this->age = age;
		this->freeDaysPerMonth = freeDaysPerMonth;

	}
	employeeUpdate(const employeeUpdate& aa) :employee(aa)
	{
		this->age = aa.age;
		this->freeDaysPerMonth = aa.freeDaysPerMonth;

	}
	friend ostream& operator<<(ostream& out, const employeeUpdate& aa)
	{
		out << (employee)aa;
		out << "The age of the employee is: " << aa.age << "\n";
		out << "The number of free days per month is: ";
		if (aa.freeDaysPerMonth.size() < 12)
		{
			for (int i = 0; i < aa.freeDaysPerMonth.size(); i++)
				cout << "month " << i + 1 << " : " << aa.freeDaysPerMonth[i] << " days" << "\n";

			for (int i = aa.freeDaysPerMonth.size(); i < 12; i++)
				cout << "month " << i + 1 << " : " << "unknown" << "\n";
		}
		else
		{
			for (int i = 0; i < aa.freeDaysPerMonth.size(); i++)
				cout << "month " << i + 1 << " : " << aa.freeDaysPerMonth[i] << " days" << "\n";

		}

		return out;
	}
	~employeeUpdate()
	{

	}

};

class doctor : public employee
{
private:
	string specialization;
	string degree;
public:
	doctor()
	{
		this->specialization = "unknown";
		this->degree = "unknown";
	}
	doctor(string employeeId, string name, float salary, string functionId, string phoneNumber,
		int workedDays, int* hoursWorkedPerDay, string specialization, string degree) :employee(employeeId, name, salary, functionId, phoneNumber, workedDays, hoursWorkedPerDay)
	{
		this->specialization = specialization;
		this->degree = degree;
	}
	doctor(const doctor& m) :employee(m)
	{
		this->specialization = m.specialization;
		this->degree = m.degree;
	}
	friend ostream& operator<<(ostream& out, const doctor& m)
	{
		out << (employee)m;
		out << "The doctor's specialization is: " << m.specialization << "\n";
		out << "The doctor's degree is: " << m.degree << "\n";
		return out;
	}
	~doctor()
	{

	}
};

class nurse : public employee
{
private:
	string* responsabilitiesList;
	int numberOfResponsabilities;

public:
	nurse()
	{
		this->responsabilitiesList = NULL;
		this->numberOfResponsabilities = 0;
	}
	nurse(string employeeId, string name, float salary, string functionId, string phoneNumber,
		int numarZileLucrate, int* oreLucratePeZi, string* listaAtributii, int nrAtributii) :employee(employeeId, name, salary, functionId, phoneNumber, numarZileLucrate, oreLucratePeZi)
	{
		this->numberOfResponsabilities = nrAtributii;
		this->responsabilitiesList = new string[this->numberOfResponsabilities];
		for (int i = 0; i < this->numberOfResponsabilities; i++)
			this->responsabilitiesList[i] = listaAtributii[i];
	}
	nurse(const nurse& as) :employee(as)
	{
		this->numberOfResponsabilities = as.numberOfResponsabilities;
		this->responsabilitiesList = new string[as.numberOfResponsabilities];
		for (int i = 0; i < as.numberOfResponsabilities; i++)
			this->responsabilitiesList[i] = as.responsabilitiesList[i];

	}
	friend ostream& operator<<(ostream& out, const nurse& as)
	{
		out << (employee)as;
		out << "The number of duties of the assistant is: " << as.numberOfResponsabilities << "\n";
		out << "The duties of the assistant are " << "\n";
		for (int i = 0; i < as.numberOfResponsabilities; i++)
			out << i + 1 << " " << as.responsabilitiesList[i] << "\n";
		return out;
	}
	~nurse()
	{
		delete[] this->responsabilitiesList;
	}
};

class colection {
private:
	int employeeNumber = 0;
	employee** employeem{};
public:
	colection()
	{

	}
	colection(int employeeNumber, employee** employeem)
	{
		this->employeeNumber = employeeNumber;
		this->employeem = new employee * [this->employeeNumber];
		for (int i = 0; i < this->employeeNumber; i++)
			this->employeem[i] = employeem[i];
	}
	~colection()
	{
		delete[] this->employeem;
	}
};

class Contact {
private:
	string phone;
	string address;
	string email;
public:
	Contact() {
		phone = "unknown";
		address = "unknown";
		email = "unknown";
	}
	Contact(string phone, string address, string email)
	{
		this->phone = phone;
		this->address = address;
		this->email = email;
	}

	friend ostream& operator<<(ostream& out, const Contact& c)
	{
		out << "\nphone " << c.phone;
		out << "\naddress: " << c.address;
		out << "\nemail: " << c.email;
		return out;
	}
	friend istream& operator>>(istream& in, Contact& c)
	{
		cout << "\nphone:";
		in >> c.phone;
		cout << "\naddress: ";
		in >> c.address;
		cout << "\nemail:";
		in >> c.email;
		return in;
	}
	bool operator==(Contact& c)
	{
		if (this->phone == c.phone && this->address == c.address && this->email == c.email)
			return true;
		return false;

	}
};

class patient :public check {
private:
	char* name;
	const string cnp;
	int age;
	Contact contactData{};
	int currentMonth;
	int ConsultationsDuringTheYear[12];
public:

	patient() :cnp("unknown")
	{
		name = new char[strlen("unknown") + 1];
		strcpy(name, "unknown");
		for (int i = 0; i < currentMonth; i++)
			ConsultationsDuringTheYear[i] = 0;

		age = 0;
		currentMonth = 0;

	}
	patient(string cnp, const char* name, Contact contactData, int currentMonth) :cnp(cnp)
	{
		if (strlen(name) > 1)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
		this->contactData = contactData;
		if (currentMonth > 0 && currentMonth <= 12)
			this->currentMonth = currentMonth;
	}
	patient(string cnp, const char* name, int ConsultationsDuringTheYear[12], Contact contactData, int age, int currentMonth) :cnp(cnp)
	{
		if (strlen(name) > 1)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
		if (currentMonth > 0 && currentMonth <= 12)
		{
			this->currentMonth = currentMonth;
		}
		for (int i = 0; i < this->currentMonth; i++)
		{
			if (ConsultationsDuringTheYear[i] > 0)
				this->ConsultationsDuringTheYear[i] = ConsultationsDuringTheYear[i];
			else
				this->ConsultationsDuringTheYear[i] = 0;
		}
		this->contactData = contactData;
		this->age = age;

	}
	patient(const patient& p) :cnp(p.cnp)
	{
		this->name = new char[strlen(p.name) + 1];
		strcpy(this->name, p.name);
		for (int i = 0; i < p.currentMonth; i++)
			this->ConsultationsDuringTheYear[i] = p.ConsultationsDuringTheYear[i];
		this->contactData = p.contactData;
		this->age = p.age;
		this->currentMonth = p.currentMonth;
	}
	patient& operator=(const patient& p)
	{
		if (this != &p)
		{
			this->name = new char[strlen(p.name) + 1];
			strcpy(this->name, p.name);
			for (int i = 0; i < p.currentMonth; i++)
				this->ConsultationsDuringTheYear[i] = p.ConsultationsDuringTheYear[i];
			this->contactData = p.contactData;
			this->age = p.age;
			this->currentMonth = p.currentMonth;
		}
		return *this;

	}
	~patient()
	{
		delete[] this->name;
	}
	friend ostream& operator<<(ostream& out, const patient& p)
	{
		out << endl;
		out << "\nname: " << p.name;
		out << "\ncnp: " << p.cnp;
		out << "\nage: " << p.age;
		out << "\ncontact data: " << p.contactData;
		out << "\ncurrent moth: " << p.currentMonth;
		out << "\nConsultations During The Year: ";
		for (int i = 0; i < p.currentMonth; i++)
			out << "\nmonth " << i + 1 << " " << p.ConsultationsDuringTheYear[i];
		return out;
	}
	friend istream& operator>>(istream& in, patient& p)
	{
		cout << "\nname: ";
		in >> p.name;
		cout << "\nage: ";
		in >> p.age;
		cout << "\ncontact data: ";
		in >> p.contactData;
		cout << "\ncurrent month";
		in >> p.currentMonth;
		cout << "\nConsultations During The Year: ";
		for (int i = 0; i < p.currentMonth; i++)
			in >> p.ConsultationsDuringTheYear[i];

		return in;
	}
	char* getnume() {
		return this->name;
	}
	string getcnp() {
		return this->cnp;
	}
	int getlunacurenta()
	{
		return this->currentMonth;
	}
	int getnrconsultatii(int index) {

		return this->ConsultationsDuringTheYear[index];
	}
	Contact getcontact()
	{
		return this->contactData;
	}
	int getvarsta()
	{
		return this->age;
	}
	void setnume(const char* name)
	{
		if (strlen(name) > 0)
		{
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
	}
	void setlunacurenta(int currentMonth)
	{
		if (currentMonth > 0 && currentMonth <= 12)
			this->currentMonth = currentMonth;
	}
	void setcontact(Contact c)
	{
		this->contactData = c;
	}
	void setnrconsultatii(int ConsultationsDuringTheYear[], int nr)
	{
		for (int i = 0; i < nr; i++)
			this->ConsultationsDuringTheYear[i] = ConsultationsDuringTheYear[i];
		for (int j = nr; j < 12; j++)
			this->ConsultationsDuringTheYear[j] = 0;

	}
	void setvarsta(int age)
	{
		if (age >= 0)
			this->age = age;
	}

	int operator[](int i)
	{
		if (i > 0 && i < this->currentMonth)
			return this->ConsultationsDuringTheYear[i];
	}
	bool operator==(patient& p)
	{
		for (int i = 0; i < this->currentMonth; i++)
			if (this->ConsultationsDuringTheYear[i] != p.ConsultationsDuringTheYear[i])
				return false;
		if (*this->name == *p.name && this->cnp == p.cnp && this->contactData == p.contactData && this->age != p.age)
			return true;

		return true;

	}
	bool operator>(patient p)
	{
		return this->age > p.age;
	}
	operator int& ()
	{
		int totalConsultatii = 0;
		for (int i = 0; i < this->currentMonth; i++)
			totalConsultatii += ConsultationsDuringTheYear[i];
		return totalConsultatii;

	}
	bool operator!()
	{
		for (int i = 0; i < this->currentMonth; i++)
			if (ConsultationsDuringTheYear[i] = 0)
				return false;
		return true;
	}
	patient& operator++() {

		this->age++;
		return *this;
	}
	patient operator++(int)
	{
		patient aux = *this;
		this->age++;
		return aux;

	}

	int operator+ (int x) {
		this->age = this->age + x;

		return this->age;
	}


	void afisare() {
		cout << endl;
		cout << "\nname: " << this->name;
		cout << "\ncnp: " << this->cnp;
		cout << "\nage: " << this->age;
		cout << "\ncontact data: " << this->contactData;
		cout << "\ncurrent month: " << this->currentMonth;
		cout << "\nConsultations During The Year: ";
		for (int i = 0; i < this->currentMonth; i++)
			cout << "\nluna " << i + 1 << " " << this->ConsultationsDuringTheYear[i];

	}
	void writeToFile(fstream& f) {
		size_t lg = this->cnp.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->cnp.data(), lg * sizeof(char));

		size_t lg1 = strlen(this->name) + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->name, lg1 * sizeof(char));

		f.write((char*)&this->age, sizeof(int));

		f.write((char*)&this->currentMonth, sizeof(int));

		for (int i = 0; i < this->currentMonth; i++)
		{
			f.write((char*)&this->ConsultationsDuringTheYear[i], sizeof(int));
		}

		f.write((char*)&this->contactData, sizeof(Contact));

	}
	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->name = buffer;
		delete[] buffer;

		f.read((char*)&this->age, sizeof(int));

		f.read((char*)&this->currentMonth, sizeof(int));

		for (int i = 0; i < this->currentMonth; i++) {
			f.read((char*)&this->ConsultationsDuringTheYear[i], sizeof(int));
		}
		f.read((char*)&this->contactData, sizeof(Contact));
	}
	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "name ";
			cin >> this->name;
			fout << this->name << "\n";

			fout << this->cnp << "\n";

			cout << "age ";
			cin >> this->age;
			fout << this->age << "\n";

			cout << "contact data ";
			cin >> this->contactData;
			fout << this->contactData << "\n";

			cout << "current month ";
			cin >> this->currentMonth;
			fout << this->currentMonth << "\n";

			cout << "Consultations During The Year ";

			for (int i = 0; i < this->currentMonth; i++)
			{
				cin >> this->ConsultationsDuringTheYear[i];
				fout << this->ConsultationsDuringTheYear[i] << " ";
			}

			fout.close();
		}

	}
	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}

	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	void patientReport(string fisier)
	{
		fstream fout;
		fout.open(fisier, ios::out);
		cout << "The patient's name is" << this->name << " and his age is " << this->age << " years.He can be contacted at the following address : " << this->contactData << "\n";
		cout << "At the current date we are in the month " << this->currentMonth << " and the patient's medical visits are: " << "\n";
		for (int i = 0; i < this->currentMonth; i++)
			cout << "month " << i + 1 << " " << this->ConsultationsDuringTheYear[i] << " consultations" << "\n";


		fout << "The patient's name is " << this->name << " iar varsta acestuia este de " << this->age << " years. He can be contacted at the following address : "
			<< this->contactData << "\n";
		fout << "At the current date we are in the month " << this->currentMonth << " and the patient's medical visits are: " << "\n";
		for (int i = 0; i < this->currentMonth; i++)
			fout << "month " << i + 1 << " " << this->ConsultationsDuringTheYear[i] << " consultations" << "\n";



		fout.close();
	}
	void afisareDateImportante()
	{
		cout << "The person's name is " << this->name << "\n";
		/*cout << "The person's id is " << this->id << "\n";*/


	}
	virtual void valid()
	{
		if (this->name == "unknown"  /*|| this->id == "000000" || this->id == "unknown"*/)

			cout << "We do not have valid data about the person/ The person is not registered";
		else
			cout << "There are no errors in the person's data.";

	}
	/*void afisareDateImportante() {
		cout << "Numele pacientului este: " << this->numePacient << "\n";
		cout << "Cnp-ul pacientului este: " << this->cnp << "\n";
		cout << "Varsta pacientului este: " << this->varsta << "\n";
	}*/
	/*void valid() {
		if (this->numePacient == "Necunoscut" || this->cnp == "necunoscut" || this->varsta == 0)
			cout << "Nu avem date valide despre pacient/ Pacientul nu este inregistrat";
		else
			cout << "Date pacientului nu prezinta erori.";
	}*/
};

class product {
private:
	string name;
	float price;
public:
	product()
	{
		name = "necunoscuta";
		price = 0;
	}
	product(string name, float price)
	{
		this->name = name;
		this->price = price;
	}
	product(const product& p)
	{
		this->name = p.name;
		this->price = p.price;
	}
	product& operator=(const product& p)
	{
		this->name = p.name;
		this->price = p.price;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const product& p)
	{
		out << "\nname: " << p.name;
		out << "\nprice: " << p.price;
		return out;

	}
	friend istream& operator>>(istream& in, product& p)
	{
		cout << "name: ";
		in >> p.name;
		cout << "price: ";
		in >> p.price;
		return in;
	}
	bool operator==(product& p)
	{
		if (this->name == p.name && this->price == p.price)
			return true;
		return false;
	}

};

class Supplier :public binaryFile {
private:
	string id = "unknown";
	product** productsList = NULL;
	int productsNumber = 0;
	float* quantitySuppliedOfEachProduct = NULL;
public:
	Supplier()
	{
		id = "unkown";
		productsNumber = 0;
		productsList = NULL;
		quantitySuppliedOfEachProduct = NULL;

	}
	Supplier(string id, product** productsList, int productsNumber, float* quantitySuppliedOfEachProduct)
	{
		if (id.length() > 1)
			this->id = id;
		else
			this->id = "unknown";
		if (productsNumber > 0 && productsList != NULL)
		{
			this->productsNumber = productsNumber;
			this->productsList = new product * [this->productsNumber];
			for (int i = 0; i < this->productsNumber; i++)
			{
				this->productsList[i] = new product(*productsList[i]);
			}
		}

		if (quantitySuppliedOfEachProduct != NULL)
		{
			this->quantitySuppliedOfEachProduct = new float[this->productsNumber];
			for (int i = 0; i < this->productsNumber; i++)
				this->quantitySuppliedOfEachProduct[i] = quantitySuppliedOfEachProduct[i];
		}

	}
	Supplier(string id, int productsNumber)
	{
		if (id.length() > 1)
			this->id = id;
		if (productsNumber > 0)
		{
			this->productsNumber = productsNumber;

		}
	}

	Supplier(const Supplier& f)
	{
		this->id = f.id;
		this->productsNumber = f.productsNumber;

		this->productsList = new product * [f.productsNumber];
		for (int i = 0; i < f.productsNumber; i++)
		{
			this->productsList[i] = new product(*f.productsList[i]);
		}
		this->quantitySuppliedOfEachProduct = new float[f.productsNumber];
		for (int i = 0; i < f.productsNumber; i++)
			this->quantitySuppliedOfEachProduct[i] = f.quantitySuppliedOfEachProduct[i];
	}
	Supplier& operator=(const Supplier& f)
	{
		if (this != &f)
		{

			for (int i = 0; i < this->productsNumber; i++)
				delete this->productsList[i];
			delete[] this->productsList;
			delete[] quantitySuppliedOfEachProduct;

			this->id = f.id;
			if (f.productsList != NULL && f.productsNumber > 0)
			{
				this->productsNumber = f.productsNumber;
				this->productsList = new product * [this->productsNumber];
				for (int i = 0; i < this->productsNumber; i++)
				{
					this->productsList[i] = new product(*f.productsList[i]);

				}
			}
			else
			{
				this->productsList = NULL;
				this->productsNumber = 0;
			}
			this->quantitySuppliedOfEachProduct = new float[f.productsNumber];
			for (int i = 0; i < f.productsNumber; i++)
				for (int i = 0; i < f.productsNumber; i++)
				this->quantitySuppliedOfEachProduct[i] = f.quantitySuppliedOfEachProduct[i];

		}

		return *this;
	}
	string getid()
	{
		return this->id;
	}
	void setid(string id)
	{
		if (id.length() > 0)
			this->id = id;
	}
	int getnrprodusefurnizate()
	{
		return this->productsNumber;
	}
	void setnrprodusefurnizate(int productsNumber)
	{
		if (productsNumber > 0)
			this->productsNumber = productsNumber;
	}

	product** getlistaproduse() {
		return this->productsList;
	}
	void setlistaproduse(product** productsList)
	{
		for (int i = 0; i < this->productsNumber; i++)
			delete this->productsList[i];
		delete[] this->productsList;


		this->productsList = new product * [this->productsNumber];
		for (int i = 0; i < this->productsNumber; i++)
		{
			this->productsList[i] = new product();
			this->productsList[i] = productsList[i];

		}

	}
	float* getcantitateaFurnizata()
	{
		return this->quantitySuppliedOfEachProduct;
	}
	void setcantitateaFurnizata(float* quantitySuppliedOfEachProduct)
	{
		delete[] this->quantitySuppliedOfEachProduct;
		this->quantitySuppliedOfEachProduct = new float[this->productsNumber];
		for (int i = 0; i < this->productsNumber; i++)
			this->quantitySuppliedOfEachProduct[i] = quantitySuppliedOfEachProduct[i];
	}
	~Supplier()
	{
		delete[] this->productsList;
		delete[] this->quantitySuppliedOfEachProduct;
	}
	friend ostream& operator<<(ostream& out, const Supplier& f)
	{
		out << "\nId: " << f.id;
		out << "\nProducts number: " << f.productsNumber;
		out << "\nList of products: ";
		for (int i = 0; i < f.productsNumber; i++)
			out << *f.productsList[i] << " " << endl;
		out << "\nQuantity Supplied Of Each Product: " << endl;
		for (int i = 0; i < f.productsNumber; i++)
			out << "\nproduct " << i + 1 << ": " << f.quantitySuppliedOfEachProduct[i];
		return out;

	}

	friend istream& operator>>(istream& in, Supplier& f) {
		for (int i = 0; i < f.productsNumber; i++)
			delete f.productsList[i];
		delete[] f.productsList;
		cout << "\nid: ";
		in >> f.id;
		cout << "\nproducts number";
		in >> f.productsNumber;

		if (f.productsNumber > 0)
		{
			f.productsList = new product * [f.productsNumber];
			for (int i = 0; i < f.productsNumber; i++)
			{
				f.productsList[i] = new product();
				in >> *f.productsList[i];
			}

		}
		cout << "\nQuantity Supplied Of Each Product: ";
		delete[] f.quantitySuppliedOfEachProduct;
		f.quantitySuppliedOfEachProduct = new float[f.productsNumber];
		for (int i = 0; i < f.productsNumber; i++)
			in >> f.quantitySuppliedOfEachProduct[i];
		return in;
	}

	float operator[](int i)
	{
		if (i >= 0 && i < this->productsNumber)
			return this->quantitySuppliedOfEachProduct[i];
	}
	bool operator==(const Supplier& f)
	{
		if (this->id != f.id || this->productsNumber != f.productsNumber)
			return false;
		for (int i = 0; i < this->productsNumber; i++)
		{
			if (this->productsList[i] != f.productsList[i] || this->quantitySuppliedOfEachProduct[i] != f.quantitySuppliedOfEachProduct[i])
				return false;
		}

		return true;

	}
	Supplier& operator++() {

		float* vn = new float[this->productsNumber + 1];
		for (int i = 0; i < this->productsNumber; i++)
		{
			vn[i] = this->quantitySuppliedOfEachProduct[i];
		}
		vn[this->productsNumber] = 1;
		delete[] this->quantitySuppliedOfEachProduct;

		this->quantitySuppliedOfEachProduct = vn;
		this->productsNumber++;

		return *this;
	}
	Supplier operator++(int)
	{
		Supplier copie = *this;
		float* vn = new float[this->productsNumber + 1];
		for (int i = 0; i < this->productsNumber; i++) {
			vn[i] = this->quantitySuppliedOfEachProduct[i];
		}
		vn[this->productsNumber] = 0;
		delete[] this->quantitySuppliedOfEachProduct;

		this->quantitySuppliedOfEachProduct = vn;
		this->productsNumber++;

		return copie;
	}

	bool operator>(Supplier& f)
	{
		return this->productsNumber > f.productsNumber;
	}
	bool operator!()
	{
		if (this->productsList == NULL)
			return false;
		return true;
	}
	int operator+(int x)
	{
		if (x > 0)
		{
			this->productsNumber = this->productsNumber + x;
		}
		return this->productsNumber;
	}
	operator float()
	{
		float cantitateTotala = 0;
		for (int i = 0; i < this->productsNumber; i++)
			cantitateTotala += quantitySuppliedOfEachProduct[i];
		return cantitateTotala;

	}
	void afisare()
	{
		cout << "\nId: " << this->id;
		cout << "\nproducts number: " << this->productsNumber;
		cout << "\nList of products: ";
		for (int i = 0; i < this->productsNumber; i++)
			cout << *this->productsList[i] << " " << endl;
		cout << "\nquantity Supplied Of Each Product: " << endl;
		for (int i = 0; i < this->productsNumber; i++)
			cout << "\nproduct " << i + 1 << ": " << this->quantitySuppliedOfEachProduct[i];



	}
	void writeToFile(fstream& f) {
		size_t lg = this->id.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->id.data(), lg * sizeof(char));

		f.write((char*)&this->productsNumber, sizeof(int));

		for (int i = 0; i < this->productsNumber; i++)
		{
			f.write((char*)&this->quantitySuppliedOfEachProduct[i], sizeof(float));
		}

		f.write((char*)&this->productsList, sizeof(product));

	}
	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->id = buffer;
		delete[] buffer;

		f.read((char*)&this->productsList, sizeof(product));

		f.read((char*)&this->productsNumber, sizeof(int));

		delete[]this->quantitySuppliedOfEachProduct;
		f.read((char*)&this->quantitySuppliedOfEachProduct, sizeof(float));
		this->quantitySuppliedOfEachProduct = new float[this->productsNumber];
		for (int i = 0; i < this->productsNumber; i++) {
			f.read((char*)&quantitySuppliedOfEachProduct[i], sizeof(float));

		}
	}
	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "id ";
			cin >> this->id;
			fout << this->id << "\n";

			cout << "products number ";
			cin >> this->productsNumber;
			fout << this->productsNumber << "\n";

			cout << "list of products: ";


			this->productsList = new product * [this->productsNumber];
			for (int i = 0; i < this->productsNumber; i++)
			{
				this->productsList[i] = new product();
				cin >> *this->productsList[i];
				fout << *this->productsList[i];
			}

			cout << " quantity Supplied Of Each Product: ";
			delete[] this->quantitySuppliedOfEachProduct;
			this->quantitySuppliedOfEachProduct = new float[this->productsNumber];
			for (int i = 0; i < this->productsNumber; i++)
			{
				cin >> this->quantitySuppliedOfEachProduct[i];
				fout << this->quantitySuppliedOfEachProduct[i];
			}

			fout.close();
		}

	}
	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}
	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}

};

class Consultation {
private:
	string* listOfServices{};
	int numberOfServices = 0;
	float listOfPrices[40]{};
	float time = 0;
public:
	Consultation()
	{
		listOfServices = NULL;
		numberOfServices = 0;
		for (int i = 0; i < this->numberOfServices; i++)
			listOfPrices[i] = 0;
		time = 0;
	}
	Consultation(string* listOfServices, int numberOfServices)
	{
		if (numberOfServices > 0 && listOfServices != NULL)
		{
			this->numberOfServices = numberOfServices;
			this->listOfServices = new string[this->numberOfServices];
			for (int i = 0; i < this->numberOfServices; i++)
			{
				this->listOfServices[i] = listOfServices[i];

			}
		}
	}
	Consultation(string* listOfServices, int numberOfServices, float listOfPrices[40], float time)
	{
		if (numberOfServices > 0 && listOfServices != NULL)
		{
			this->numberOfServices = numberOfServices;
			this->listOfServices = new string[this->numberOfServices];
			for (int i = 0; i < this->numberOfServices; i++)

				this->listOfServices[i] = listOfServices[i];
		}
		for (int i = 0; i < this->numberOfServices; i++)
			this->listOfPrices[i] = listOfPrices[i];
		if (time > 0)
			this->time = time;


	}
	Consultation(const Consultation& c)
	{
		if (c.numberOfServices > 0 && c.listOfServices != NULL)
		{
			this->numberOfServices = c.numberOfServices;
			this->listOfServices = new string[c.numberOfServices];
			for (int i = 0; i < c.numberOfServices; i++)
			{
				this->listOfServices[i] = c.listOfServices[i];
			}
		}
		for (int i = 0; i < c.numberOfServices; i++)
			this->listOfPrices[i] = c.listOfPrices[i];
		if (time > 0)
			this->time = c.time;

	}
	Consultation& operator=(const Consultation& c)
	{
		if (this != &c)
		{
			delete[] this->listOfServices;
			this->numberOfServices = c.numberOfServices;
			this->listOfServices = new string[c.numberOfServices];
			for (int i = 0; i < c.numberOfServices; i++)
			{
				this->listOfServices[i] = c.listOfServices[i];
			}

			for (int i = 0; i < c.numberOfServices; i++)
				this->listOfPrices[i] = c.listOfPrices[i];
			this->time = c.time;
		}
		return *this;
	}
	int getnrservicii()
	{
		return this->numberOfServices;
	}
	string* getlistaservicii()
	{
		return this->listOfServices;
	}
	float getlistapreturi(int i)
	{
		return this->listOfPrices[i];
	}
	float getdurata()
	{
		return this->time;
	}
	void setnrservicii(int numberOfServices)
	{
		if (numberOfServices > 0)
			this->numberOfServices = numberOfServices;
	}
	void setlistaservicii(string* listOfServices)
	{
		if (listOfServices != NULL)
		{
			delete[] this->listOfServices;
			this->listOfServices = new string[this->numberOfServices];
			for (int i = 0; i < this->numberOfServices; i++)
				this->listOfServices[i] = listOfServices[i];
		}
	}
	void setlistapreturi(float listOfPrices[])
	{

		for (int i = 0; i < this->numberOfServices; i++)
			this->listOfPrices[i] = listOfPrices[i];
	}
	void setdurata(float time)
	{
		if (time > 0 && time < 120)
			this->time = time;
	}
	friend ostream& operator<<(ostream& out, const Consultation& c)
	{
		out << endl;
		out << "\nnumber Of Services " << c.numberOfServices;
		out << "\nlist Of Services " << endl;
		for (int i = 0; i < c.numberOfServices; i++)
		{
			out << i + 1 << ": " << c.listOfServices[i] << endl;

		}
		out << "\nlist Of Prices: ";
		for (int i = 0; i < c.numberOfServices; i++)
			out << c.listOfServices[i] << " price: " << c.listOfPrices[i] << endl;
		out << "\ntime: " << c.time;
		return out;

	}
	friend istream& operator>>(istream& in, Consultation& c)
	{

		cout << "\number Of Services: ";
		in >> c.numberOfServices;
		delete[] c.listOfServices;
		c.listOfServices = new string[c.numberOfServices];
		cout << "\nlist Of Services: ";
		for (int i = 0; i < c.numberOfServices; i++)
		{
			cout << i + 1 << ": ";
			in >> c.listOfServices[i];
		}
		cout << "\nlist Of Prices: ";
		for (int i = 0; i < c.numberOfServices; i++)
		{

			cout << c.listOfServices[i] << ": ";
			in >> c.listOfPrices[i];
		}
		cout << "\ntime: ";
		in >> c.time;
		return in;


	}
	float operator[](int index)
	{
		if (index >= 0 && index < this->numberOfServices)
			return this->listOfPrices[index];
	}
	/*bool operator<(Consultatie c)
	{
		return this->durata < c.durata;
	}*/
	friend bool operator<(const Consultation& c1, const Consultation& c2) {
		return c1.time < c2.time;
	}
	bool operator!()
	{
		if (this->numberOfServices <= 0)
			return false;
		return true;

	}
	bool operator==(Consultation& c)
	{

		if (this->numberOfServices != c.numberOfServices || this->time != c.time)
			return false;
		for (int i = 0; i < this->numberOfServices; i++)
		{
			if (this->listOfServices[i] != c.listOfServices[i] || this->listOfPrices[i] != c.listOfPrices[i])
				return false;
		}
		return true;
	}
	float operator+(float x) {
		if (x > 0)
			this->time = this->time + x;

		return this->time;
	}
	Consultation& operator++()
	{
		this->numberOfServices++;
		return*this;
	}
	Consultation operator++(int)
	{
		Consultation rez = *this;
		this->numberOfServices++;
		return rez;

	}

	operator float()
	{
		float totalPrice = 0;
		for (int i = 0; i < this->numberOfServices; i++)
			totalPrice += listOfPrices[i];
		return totalPrice;

	}
	~Consultation()
	{
		delete[] this->listOfServices;
	}
	void afisare() {
		cout << endl;
		cout << "\nnumber Of Services: " << this->numberOfServices;
		cout << "\nlist Of Services: ";
		for (int i = 0; i < this->numberOfServices; i++)
		{
			cout << i + 1 << ": " << this->listOfServices[i];

		}
		cout << "\nlist Of Prices: ";
		for (int i = 0; i < this->numberOfServices; i++)
			cout << this->listOfServices[i] << " price: " << this->listOfPrices[i];
		cout << "\ntime: " << this->time;

	}
	void writeToFile(fstream& f) {

		for (int i = 0; i < this->numberOfServices; i++)
		{
			f.write((char*)&this->listOfServices[i], sizeof(char));
		}

		f.write((char*)&this->numberOfServices, sizeof(int));

		f.write((char*)&this->time, sizeof(float));

		for (int i = 0; i < this->numberOfServices; i++)
		{
			f.write((char*)&this->listOfPrices[i], sizeof(float));
		}



	}
	void readFromFile(fstream& f) {

		f.read((char*)&this->numberOfServices, sizeof(int));

		int lg;
		delete[]this->listOfServices;
		f.read((char*)&this->listOfServices, sizeof(int));
		this->listOfServices = new string[this->numberOfServices];
		for (int i = 0; i < this->numberOfServices; i++) {
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->listOfServices[i] = buffer;
			delete[] buffer;
		}


		for (int i = 0; i < this->numberOfServices; i++) {
			f.read((char*)&listOfPrices[i], sizeof(float));

		}
		f.read((char*)&this->time, sizeof(float));
	}


	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "number Of Services ";
			cin >> this->numberOfServices;
			fout << this->numberOfServices << "\n";

			cout << "list Of Services ";
			this->listOfServices = new string[this->numberOfServices];
			for (int i = 0; i < this->numberOfServices; i++)
			{
				cout << i + 1 << ": ";
				cin >> this->listOfServices[i];
				fout << this->listOfServices[i];
			}

			cout << "list Of Prices: ";
			for (int i = 0; i < this->numberOfServices; i++)
			{
				fout << this->listOfServices[i] << ": ";
				cin >> this->listOfPrices[i];
				fout << this->listOfPrices[i];
			}

			cout << "time ";
			cin >> this->time;
			fout << this->time << "\n";



			fout.close();
		}



	}
	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}
	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	
};

class consultationUpdate :public Consultation
{
	int daysOfWaitingForResults = 0;

public:
	consultationUpdate()
	{
		this->daysOfWaitingForResults = 0;

	}
	consultationUpdate(string* listOfServices, int numberOfServices, float listOfPrices[40], float time, int daysOfWaitingForResults)
		:Consultation(listOfServices, numberOfServices, listOfPrices, time)
	{
		this->daysOfWaitingForResults = daysOfWaitingForResults;

	}
	consultationUpdate(const consultationUpdate& ca) : Consultation(ca)
	{
		this->daysOfWaitingForResults = ca.daysOfWaitingForResults;

	}
	friend ostream& operator<<(ostream& out, const consultationUpdate& ca)
	{
		out << (Consultation)ca;
		out << "days Of Waiting For Results : " << ca.daysOfWaitingForResults << "\n";

		return out;
	}
	~consultationUpdate()
	{

	}

};

class Laboratory :public binaryFile {
	string name{};
	string location{};
	static int number;
	int numberOfEmployees{};
	employee* employeem{};


public:
	Laboratory()
	{
		number++;
		name = "unknown";
		location = "N/A";
		numberOfEmployees = 0;
		employeem = NULL;


	}
	Laboratory(string name, string location)
	{
		number++;
		if (name.length() > 1)
			this->name = name;
		if (location.length() > 1)
			this->location = location;
	}

	Laboratory(string name, string location, int numberOfEmployees, employee* employeem)
	{
		number++;
		if (name.length() > 1)
			this->name = name;
		if (location.length() > 1)
			this->location = location;
		if (numberOfEmployees > 0 && employeem != NULL)
		{
			this->numberOfEmployees = numberOfEmployees;
			this->employeem = new employee[this->numberOfEmployees];
			for (int i = 0; i < this->numberOfEmployees; i++)
				this->employeem[i] = employeem[i];
		}

	}
	Laboratory(const Laboratory& l)
	{
		number++;
		this->name = l.name;
		this->location = l.location;
		this->numberOfEmployees = l.numberOfEmployees;
		this->employeem = new employee[l.numberOfEmployees];
		for (int i = 0; i < l.numberOfEmployees; i++)
			this->employeem[i] = l.employeem[i];
	}
	Laboratory& operator=(const Laboratory& l)
	{
		if (this != &l)
		{
			this->number++;
			delete[] this->employeem;
			this->name = l.name;
			this->location = l.location;
			this->numberOfEmployees = l.numberOfEmployees;
			this->employeem = new employee[l.numberOfEmployees];
			for (int i = 0; i < l.numberOfEmployees; i++)
				this->employeem[i] = l.employeem[i];
		}
		return *this;
	}
	~Laboratory()
	{

		number--;
		delete[] this->employeem;

	}
	friend ostream& operator<<(ostream& out, const Laboratory& l)
	{
		out << endl;
		out << "\nname:" << l.name;
		out << "\nlocation: " << l.location;
		out << "\nnumber of laboratories: " << l.number;
		out << "\nnumber Of Employees: " << l.numberOfEmployees;
		out << "\nlist of employees: ";
		for (int i = 0; i < l.numberOfEmployees; i++)
			out << l.employeem[i];
		return out;

	}
	friend istream& operator>>(istream& in, Laboratory& l)
	{
		delete[] l.employeem;
		cout << "\nnname: ";
		in >> l.name;
		cout << "\nlocation: ";
		in >> l.location;
		cout << "\nnumber Of Employees: ";
		in >> l.numberOfEmployees;
		cout << "\nlist of employees: ";
		if (l.numberOfEmployees > 0)
		{
			l.employeem = new employee[l.numberOfEmployees + 1];

			for (int i = 0; i < l.numberOfEmployees; i++)
			{

				in >> l.employeem[i];
			}

		}
		else
		{
			l.numberOfEmployees = 0;
			l.employeem = NULL;
		}
		return in;

	}
	string getnume()
	{
		return this->name;
	}
	void setnume(string name)
	{
		if (name.length() > 1)
			this->name = name;
	}
	string getlocatie()
	{
		return this->location;
	}
	void setlocatie(string location)
	{
		if (location.length() > 1)
			this->location = location;
	}
	int getnrlaboratoare()
	{
		return this->number;
	}
	int getnrangajati()
	{
		return this->numberOfEmployees;
	}
	void setnrangajati(int numberOfEmployees)
	{
		if (numberOfEmployees > 0)
			this->numberOfEmployees = numberOfEmployees;
	}
	employee* getlistaangajati()
	{
		return this->employeem;
	}
	void setangajat(employee* employeem)
	{
		if (employeem != NULL)
		{
			delete[] this->employeem;
			this->employeem = new employee[this->numberOfEmployees];
			for (int i = 0; i < this->numberOfEmployees; i++)
				this->employeem[i] = employeem[i];
		}
	}

	int operator[](int i)
	{
		if (i >= 0 && i < this->numberOfEmployees)
			return this->employeem[i];
	}
	bool operator==(const Laboratory& l)
	{
		if (this->name != l.name || this->location != l.location || this->numberOfEmployees != l.numberOfEmployees)
			return false;
		for (int i = 0; i < this->numberOfEmployees; i++)
		{
			if (this->employeem[i] != l.employeem[i])
				return false;
		}

		return true;

	}
	bool operator>(Laboratory& l)
	{
		return this->numberOfEmployees > l.numberOfEmployees;
	}
	bool operator!()
	{
		if (this->employeem == NULL)
			return false;
		return true;
	}
	string operator+(string add)
	{
		if (add.length() > 0)
		{
			this->location = this->location + add;
		}
		return this->location;
	}
	int operator++()
	{
		this->numberOfEmployees++;
		return this->numberOfEmployees;

	}
	int operator++(int)
	{
		int nrVechi = this->numberOfEmployees;
		this->numberOfEmployees++;
		return nrVechi;

	}
	void afisare()
	{
		cout << endl;
		cout << "\nName:" << this->name;
		cout << "\nLocation: " << this->location;
		cout << "\nnumber of laboratories: " << this->number;
		cout << "\nnumber Of Employees: " << this->numberOfEmployees;
		cout << "\nlist of employees: ";
		for (int i = 0; i < this->numberOfEmployees; i++)
			cout << this->employeem[i];
	}
	void writeToFile(fstream& f) {
		size_t lg = this->name.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->name.data(), lg * sizeof(char));

		size_t lg1 = this->location.length() + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->location.data(), lg1 * sizeof(char));

		f.write((char*)&this->number, sizeof(int));

		f.write((char*)&this->numberOfEmployees, sizeof(int));


		f.write((char*)&this->employeem, sizeof(employee));
	}
	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->name = buffer;
		delete[] buffer;

		f.read((char*)&lg, sizeof(int));
		char* buffer1 = new char[lg];
		f.read(buffer1, lg);
		this->location = buffer1;
		delete[] buffer1;

		f.read((char*)&this->employeem, sizeof(employee));

		f.read((char*)&this->numberOfEmployees, sizeof(int));

		f.read((char*)&this->number, sizeof(int));


	}

	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "name ";
			cin >> this->name;
			fout << this->name << "\n";

			cout << "location ";
			cin >> this->location;
			fout << this->location << "\n";

			fout << this->number << "\n";

			cout << "number Of Employees ";
			cin >> this->numberOfEmployees;
			fout << this->numberOfEmployees << "\n";

			cout << "list of employees ";
			this->employeem = new employee[this->numberOfEmployees];
			for (int i = 0; i < this->numberOfEmployees; i++)
			{
				cin >> this->employeem[i];
				fout << this->employeem[i];
			}

			fout.close();
		}
	}


	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}


	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	



};
int Laboratory::number = 0;


	/*===========================MENU=======================
	string st[20];
	int itemcount = 0;
	showMenu();
	int answer;
	string next;
	do
	{
		cout << "Introduceti raspunsul(1-5):";
		cin >> answer;
		switch (answer)
		{
		case 1: addEmployee(); break;
		case 2: addPatient(); break;
		case 3: addSupplier(); break;
		case 4: addConsultation(); break;
		case 5: addLaboratory(); break;
		default: cout << "invalid"; break;
		}
		cout << "Press n or N to continue:";
		cin >> next;
	} while (next == "n" || next == "N");
	*/

int main()
{

	employee** v = new employee * [2];
	v[0] = new doctor;
	v[1] = new nurse;
	colection c(2, v);


	check* ch;
	employee a5;
	employee a7("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 });
	ch = &a7;
	ch->afisareDateImportante();
	ch->validity();




	cout << "\n============VECTOR============\n";
	vector<int> vec;
	for (int i = 0; i < 11; i++)
		vec.push_back(i);
	employeeUpdate a("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 }, 25, vec);
	cout << a;

	cout << "\n==============MAP=================";
	employee a1;
	employee a2("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 });
	employee a3;

	map<int, employee>mapev;
	mapev[0] = a1;
	mapev[1] = a2;
	mapev[2] = a3;

	map<int, employee>::iterator i;
	for (i = mapev.begin(); i != mapev.end(); i++)
		cout << "\n" << i->first << " " << i->second << "\n";

	cout << "\n===============SET=================";

	Consultation co;
	string listaServicii[2] = { "test covid","test alergii" };
	Consultation co2(listaServicii, 2, new float[2]{ 12,50 }, 30);


	set<Consultation>setev;
	setev.insert(co);
	setev.insert(co2);


	set<Consultation>::iterator it;
	for (it = setev.begin(); it != setev.end(); it++)
		cout << *it;

	cout << "\n=============LIST==============\n";

	list<int> lint;
	Laboratory l;

	employee ang2("123456", "Mihnea", 1400, "000005", "076888888", 4, new int[4]{ 7,7,4,5 });
	employee ang3("9999", "Alin", 1400, "000005", "0765000000", 2, new int[2]{ 2,3 });

	employee lista[2] = { ang2,ang3 };
	Laboratory l1("Clinmed", "BD.Iuliu Maniu", 2, lista);
	Laboratory l2("Medica", "str.nordului");


	lint.push_back(l.getnrangajati());
	lint.push_back(l1.getnrangajati());


	list<int>::iterator itList;
	for (itList = lint.begin(); itList != lint.end(); itList++)
		cout << *itList << " ";
	cout << "\n";
	list<int>::reverse_iterator rItList;
	for (rItList = lint.rbegin(); rItList != lint.rend(); rItList++)
		cout << *rItList << " ";





}