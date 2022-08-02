#include "Student.h"
#include "LearningStudent.h"
#include "AvgGrade.h"
#include "Association.h"
#include "Base.h"
#include "Derived.h"



void CheckRecord(ifstream& Record) {

	cout <<"\n\n\n\n"<< "\tHello everyone, three students worked on this program, with your permission I will list them:" << "\n" << "\n" << "\tMendelev Danila." << "\n" << "\tMisha Buter." << "\n" << "\tDubkov Ilya.\n\n";


	system("pause");
	system("cls");

	cout << "Now we are going to check Record File..." << "\n\n";
	system("pause");
	system("cls");

	if (Record.is_open()) {
		cout << "File is open " << "\n";
	}
	else
	{
		throw "File is not open";
	}
	if (Record.peek() != EOF) {
		cout << "File is not empty" << "\n";
	}
	else
	{
		throw "File is empty";
	}
	if (Record.bad() == false) {
		cout << "File exist" << "\n";
	}
	else
	{
		throw "File is not exist";
	}

	system("pause");
	system("cls");

	cout << "As you can see with Record file Everything is fine..." << "\n";
	system("pause");
	system("cls");
}

void CheckStudentsInfo(ifstream& StudentsInfo) {
	cout << "Now we are going to check Students info file" << "\n";
	system("pause");
	system("cls");
	if (StudentsInfo.is_open()) {
		cout << "File is open " << "\n";
	}
	else
	{
		throw "File is not open";
	}
	if (StudentsInfo.peek() != EOF) {
		cout << "File is not empty" << "\n";
	}
	else
	{
		throw "File is empty";
	}
	if (StudentsInfo.bad() == false) {
		cout << "File exist" << "\n";
	}
	else
	{
		throw "File is not exist";
	}

	system("pause");
	system("cls");

	cout << "As you can see with Students info file everything is fine..." << "\n";
	system("pause");
	system("cls");

	cout << "If everything is fine we can continiue to work" << "\n";
	system("pause");
	system("cls");
}

void BinRecord(fstream& BinRec, const string& BinRecPath, ifstream& Record) {

	BinRec.open(BinRecPath, ios::out | ios::binary);

	Student a;

	vector<Student> st;

	st.push_back(a);

	for (size_t i = 0; i < st.size(); ++i) {
		while (Record >> st[i]) {
			BinRec.write(reinterpret_cast<char*>(&st[i]), sizeof(Student));
		}
	}

	BinRec.close();

}

void BinStudentsInfo(ifstream& StudentsInfo, fstream& BinStInfo, const string& BinStPath) {

	BinStInfo.open(BinStPath, ios::out | ios::binary);

	LearningStudent a;

	vector<LearningStudent> Lst;

	Lst.push_back(a);

	for (size_t i = 0; i < Lst.size(); ++i) {
		while (StudentsInfo >> Lst[i]) {
			BinStInfo.write(reinterpret_cast<char*>(&Lst[i]), sizeof(LearningStudent));
		}
	}

	BinStInfo.close();

}

void SpecialInf(ifstream& Record, ifstream& StudentsInfo, fstream& SpecialList, const string& SpecialListPath) {

	SpecialList.open(SpecialListPath, ios::out);

	Student Alice;

	LearningStudent Bob;

	vector<Student> st;
	vector<LearningStudent> Lst;

	st.push_back(Alice);
	Lst.push_back(Bob);

	for (ptrdiff_t i = 0; i < st.size(); ++i) {
		while (Record >> st[i] && StudentsInfo >> Lst[i]) {
			SpecialList << st[i].GetSurname() << ' ' << Lst[i].GetMath() << ' ' << Lst[i].GetGeo() << ' ' << Lst[i].GetProgramming() << "\n";
		}
	}

	SpecialList.close();

}

void BinSpecInf(fstream& SpecialList, const string& SpecialListPath, fstream& BinSpec, const string& BinSpecPath) {

	BinSpec.open(BinSpecPath, ios::out | ios::binary);
	SpecialList.open(SpecialListPath, ios::in);

	Base obj;

	vector<Base> Bs;

	Bs.push_back(obj);

	for (ptrdiff_t i = 0; i < Bs.size(); ++i) {
		while (SpecialList >> Bs[i]) {
			BinSpec.write(reinterpret_cast<char*>(&Bs[i]), sizeof(Base));
		}
	}

	BinSpec.close();
	SpecialList.close();
}

void GetAvg(fstream& SpecialList, const string& SpecialListPath, fstream& AvgMarks, const string& AvgMarksPath) {

	SpecialList.open(SpecialListPath, ios::in);
	AvgMarks.open(AvgMarksPath, ios::out);

	Base b;

	vector<Base> bs;

	bs.push_back(b);

	for (ptrdiff_t i = 0; i < bs.size(); ++i) {
		while (SpecialList >> bs[i]) {
			AvgMarks << (bs[i].GetGeo() + bs[i].GetMath() + bs[i].GetProgramming()) / 3 << '\n';
		}
	}

	SpecialList.close();
	AvgMarks.close();

}

void GetAvgBin(fstream& AvgMarks, string AvgMarksPath, fstream& BinAvgMarks, string BinAvgMarksPath) {

	AvgMarks.open(AvgMarksPath, ios::in);
	BinAvgMarks.open(BinAvgMarksPath, ios::out);

	AvgGrade Avg;

	vector<AvgGrade> GetAvgMark;

	GetAvgMark.push_back(Avg);

	for (ptrdiff_t i = 0; i < GetAvgMark.size(); ++i) {
		while (AvgMarks >> GetAvgMark[i]) {
			BinAvgMarks.write(reinterpret_cast<char*>(&GetAvgMark[i]), sizeof(AvgGrade));
		}
	}

	AvgMarks.close();
	BinAvgMarks.close();

}

void Recording(ifstream& Record, ifstream& StudentsInfo, string ListPath, fstream& List) { // d

	List.open(ListPath, ios::out);

	Student St;
	LearningStudent Lst;

	vector<Student> ForStudent;
	vector<LearningStudent> ForLearningStudent;

	ForStudent.push_back(St);
	ForLearningStudent.push_back(Lst);


	for (ptrdiff_t i = 0; i < ForStudent.size(); ++i) {
		while (Record >> ForStudent[i] && StudentsInfo >> ForLearningStudent[i]) {
			List << ForStudent[i].GetSurname() << " " << ForLearningStudent[i].GetGroup() << " " << ForStudent[i].GetRecord_Book() << "\n";
		}
	}

	List.close();


}

void BinRecording(string ListPath, fstream& List, fstream& BinList, string BinListPath) {

	//asscociation

	List.open(ListPath, ios::in);
	BinList.open(BinListPath, ios::out);

	Association Assoc;

	vector<Association> v;

	v.push_back(Assoc);

	for (ptrdiff_t i = 0; i < v.size(); ++i) {
		while (List >> v[i]) {
			BinList.write(reinterpret_cast<char*>(&v[i]), sizeof(Association));
		}
	}

	List.close();
	BinList.close();

}

void Create(fstream& cr, string CreatePath, fstream& AvgMarks, string AvgMarksPath, fstream& List, string ListPath) {

	cr.open(CreatePath, ios::out);
	AvgMarks.open(AvgMarksPath, ios::in);
	List.open(ListPath, ios::in);

	Association obj;

	vector<Association> v;

	v.push_back(obj);

	AvgGrade Grade;

	vector<AvgGrade> Marks;

	Marks.push_back(Grade);

	for (ptrdiff_t i = 0; i < Marks.size(); ++i) {
		while (AvgMarks >> Marks[i] && List >> v[i]) {
			cr << Marks[i] << ' ' << v[i] << '\n';
		}
	}

	cr.close();
	AvgMarks.close();
	List.close();

}

void BinCreate(fstream& cr, string CreatePath, fstream& BinCr, string BinCreatePath) {

	cr.open(CreatePath, ios::in);
	BinCr.open(BinCreatePath, ios::out);

	Derived obj;

	vector<Derived> v;

	v.push_back(obj);

	for (ptrdiff_t i = 0; i < v.size(); ++i) {
		while (cr >> v[i]) {
			BinCr.write(reinterpret_cast<char*>(&v[i]), sizeof(Derived));
		}
	}

	cr.close();
	BinCr.close();
}

void Lists(fstream& cr, string CreatePath) {

	cr.open(CreatePath, ios::in);

	cout << "Just only list which consist of avg grade surname group and Record Book " << "\n" << "\n";

	Derived obj;

	vector<Derived> UnAchievers;

	UnAchievers.push_back(obj);

	for (ptrdiff_t i = 0; i < UnAchievers.size(); ++i) {
		while (cr >> UnAchievers[i]) {
			cout << UnAchievers[i] << "\n";
		}
	}


	cr.close();

	system("pause");
	system("cls");
}

void ListOfUnderachievers(fstream& cr, string CreatePath, vector<Derived>& Derr, vector<Derived>& Search, vector<Derived>& Group, vector<Derived>& Io, vector<Derived>& Honor) {

	cout << "List of Underachievers: " << "\n" << "\n";

	cr.open(CreatePath, ios::in);

	copy(istream_iterator<Derived>(cr), istream_iterator<Derived>(), back_inserter(Derr));
	copy(Derr.begin(), Derr.end(), back_inserter(Group));
	copy(Derr.begin(), Derr.end(), back_inserter(Io));
	copy(Derr.begin(), Derr.end(), back_inserter(Honor));


	Derr.erase(remove_if(Derr.begin(), Derr.end(), [&](Derived& obj) {
		return obj.GetMark() > 5;
		}), Derr.end());

	copy(Derr.begin(), Derr.end(), back_inserter(Search));

	for (auto&& x : Derr) {
		cout << x << "\n";
	}

	cr.close();

	cout << "\n" << "\n";

	system("pause");
	system("cls");

}

//f

void SortedByGroup(vector<Derived>& Search, vector<Derived>& ForEach) {

	cout << "Sorted by group: " << "\n" << "\n";

	sort(Search.begin(), Search.end(), [](Derived& A, Derived& B) {

		return A.GetGroup() < B.GetGroup();

		; });

	copy(Search.begin(), Search.end(), back_inserter(ForEach));

	for (auto&& x : Search) {
		cout << x << "\n";
	}
	system("pause");
	system("cls");
}

void SortedByGroupAndSurname(vector<Derived>& ForEach) {

	cout << "Sorted by surname: " << "\n" << "\n";

	sort(ForEach.begin(), ForEach.end(), [](Derived& A, Derived& B) {

		return A.GetSurname() < B.GetSurname();

		 });

	for (auto&& x : ForEach) {
		cout << x << "\n";
	}
	system("pause");
	system("cls");
}

void Print(vector<Derived>& Using) {
	for (ptrdiff_t i = 0; i < Using.size(); ++i) {
		cout << Using[i] << "\n";
	}
}

void print(vector<Derived>& Useful) {
	for (ptrdiff_t i = 0; i < Useful.size(); ++i) {
		cout << Useful[i] << "\n";
	}
}

void SortGroupAlph(vector<Derived>& Group, vector<Derived>& Using) {

	cout << "Input Group, you would like to see ? . . . " << "\n\n";

	size_t n;

	cin >> n;

	if (n <= 0) {
		throw "It is can`t be the group";
	}


	copy_if(Group.begin(), Group.end(), back_inserter(Using), [&n](Derived& obj) {
		return obj.GetGroup() == n;
		; });

	sort(Using.begin(), Using.end(), [](Derived& A, Derived& B) {
		return A.GetSurname() < B.GetSurname()
			; });

	cout << '\n';
	Print(Using);	



	system("pause");
	system("cls");

}

void SortGroupAvg(vector<Derived>& Io, vector<Derived>& Useful) {

	cout << "Input group, and see how it look like? . . . " << '\n\n';


	size_t n;

	cin >> n;

	if (n <= 0) {
		throw "It is can`t be the group";
	}

	copy_if(Io.begin(), Io.end(), back_inserter(Useful), [&n](Derived& obj) {
		return obj.GetGroup() == n;
		; });
	sort(Useful.begin(), Useful.end(), [](Derived& A, Derived& B) {
		return A.GetMark() < B.GetMark()
			; });
	print(Useful);
	system("pause");
	system("cls");
}

void ListOfHonors(vector<Derived>& Honor) {

	Honor.erase(remove_if(Honor.begin(), Honor.end(), [&](Derived& obj) {
		return obj.GetMark() < 8;
		}), Honor.end());

	cout << "The list of honor is " << "\n" << "\n";

	copy(Honor.begin(), Honor.end(), ostream_iterator<Derived>(cout, "\n"));

}



int main() {

	try
	{
		ifstream Record("Record Book.txt", ios::in);
		ifstream StudentsInfo("Students Info.txt", ios::in);

		fstream BinRec;
		string BinRecPath = "BinRecord.bin";

		fstream BinStInfo;
		string BinStPath = "BinStInfo.bin";

		fstream SpecialList;
		string SpecialListPath = "SpecialList.txt";

		fstream BinSpec;
		string BinSpecPath = "BinSpec.bin";

		fstream AvgMarks;
		string AvgMarksPath = "AvgMarks.txt";

		fstream BinAvgMarks;
		string BinAvgMarksPath = "BinAvgMarks.bin";

		fstream List;
		string ListPath = "List.txt";


		fstream BinList;
		string BinListPath = "BinList.bin";

		fstream cr;
		string CreatePath = "Create.txt";

		fstream BinCr;
		string BinCreatePath = "BinCreate.bin";

		fstream d;
		string Dpath = "d.txt";


		vector<Derived> Derr;
		vector<Derived> Search;
		vector<Derived> Group;
		vector<Derived> Io;
		vector<Derived> Honor;
		vector<Derived> ForEach;
		vector<Derived> Using;
		vector<Derived> Useful;
	
		CheckRecord(Record);
		CheckStudentsInfo(StudentsInfo);
		Recording(Record,StudentsInfo,ListPath,List);
		Create(cr,CreatePath,AvgMarks,AvgMarksPath,List,ListPath);
		Lists(cr,CreatePath);
		ListOfUnderachievers(cr, CreatePath, Derr, Search, Group, Io, Honor);
		SortedByGroup(Search, ForEach);
		SortedByGroupAndSurname(ForEach);
		SortGroupAlph(Group, Using);
		ListOfHonors(Honor); 
			
		
	}
	catch (...)
	{
		cout << "Something get wrong . . ." << '\n';
	}

	cout << '\n';
	system("pause");
	return EXIT_SUCCESS;
}