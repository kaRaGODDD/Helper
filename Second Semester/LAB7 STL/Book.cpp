#include "Book.h"



void Book::clone(const Book& right)
{
	udk = right.udk;
	title = right.title;
	year = right.year;
	authors.clear();
	authors.assign(right.authors.begin(), right.authors.end());
}

Book::Book() :
	udk(0), title("empty"), year(0)
{}

Book::Book(unsigned int udk_, std::string title_, unsigned int year_, std::list<Author> authors_) :
	udk(udk_), title(title_), year(year_)
{
	authors.assign(authors_.begin(), authors_.end());
	authors.sort();
}

Book::Book(const Book& right)
{
	clone(right);
}

Book::~Book()
{
}

Book& Book::operator=(const Book& right)
{
	if (this != &right) {
		clone(right);
	}
	return *this;
}

void Book::setAuthors(std::list<Author>& right)
{
	authors.clear();
	authors.assign(right.begin(), right.end());
}

void Book::setTitle(std::string& title)
{
	this->title = title;
}

void Book::setUdc(unsigned int& right)
{
	this->udk = right;
}

void Book::setYear(unsigned int& right)
{
	this->year = right;
}



unsigned int Book::GetUdk() const
{
	return udk;
}

string Book::GetTitle() const
{
	return title;
}

unsigned int Book::GetYear() const
{
	return year;
}

list<Author> Book::GetList() 
{
	return authors;
}

//void Book::GetList(list<Author>& right)
//{
//	right.clear();
//	right.assign(authors.begin(), authors.end());
//}






//void Book::GetList(t) const
//{
//	/*right.clear();
//	right.assign(authors.begin(), authors.end());*/
//}



bool Book::operator < (const Book& B) const
{
	return title.compare(B.title) < 0;
}

bool Book::operator > (const Book& B) const
{
	return title.compare(B.title) > 0;
}

bool Book::operator == (const Book& B) const
{
	return title.compare(B.title) == 0;
}



ostream& operator<<(ostream& out, const Book& right)
{
	out << "Udc: " << right.udk << "\n";

	cout << "List of authors: " << "\n";

	for (auto x : right.authors) {
		out << x << "\n";
	}

	out << "Title: " << right.title << "\n";

	out << "Year: " << right.year << "\n";

	out << "\n\n";
	return out;
}


istream& operator>>(istream& in, Book& right)
{
	cout << "Input udk: " << "\n";
	in >> right.udk;
	if (right.udk < 0) {
		throw exception("It is can`t be udk");
	}
	cout << "Input name of the book" << "\n";
	getline(in, right.title);
	if (right.title.size() == 0) {
		throw exception("It is can`t be the name of the title");
	}
	cout << "Input year\n;";
	in >> right.year;
	if (right.year <= 0) {
		throw exception("It is can`t be the year");
	}
	int n;
	cout << "Input amount of the authors";
	cin >> n;
	Author author;
	for (size_t i = 0; i < n; ++i)
	{
		in >> author;
		right.authors.push_back(move(author));
	}
	return in;
}