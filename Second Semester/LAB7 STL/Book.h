#ifndef _BOOK_H
#define _BOOK_H
#include "Author.h"


class Book
{
private:
	unsigned int udk;
	list<Author> authors;
	string title;
	unsigned int year;

	void clone(const Book&);

public:
	Book();
	Book(unsigned int, string, unsigned int, list<Author>);
	Book(const Book&);
	~Book();

	Book& operator = (const Book&);

	void setAuthors(list<Author>&);
	void setTitle(string&);
	void setUdc(unsigned int&);
	void setYear(unsigned int&);

	unsigned int GetUdk() const;
	string GetTitle() const;
	unsigned int GetYear() const;
	//void GetList(list<Author>&);
	list<Author> GetList();

	bool operator < (const Book&) const;
	bool operator > (const Book&) const;
	bool operator == (const Book&) const;


	
	friend istream& operator >> (istream& in, Book&);
	friend ostream& operator << (ostream& out, const Book&);
};

#endif
