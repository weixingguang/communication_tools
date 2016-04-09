#include "BookSeries.h"
#include <vector>

class BookShelf
{
	public:
		BookSeries* BookSearch(string bookname);
		bool InBookShelf(string bookname);
		void ShowShelfInfo();

		void AddBookSeries(BookSeries bookseries);
		void DelBookSeries(string bookname);

		int GetCapacity();
		int GetBookNum();
		int GetFreeNum();
		vector<BookSeries> GetBooks();

		int SetCapacity(int capacity);
		int SetBookNum(int booknum);
		int SetFreeNum(int freenum);

		BookShelf(vector<BookSeries> book, int, int);

	private:
		vector<BookSeries> Books;
		int				 iCapacity;
		int				 iBookNum;
		int				 iFreeNum;
};

// constructor, initialize a bookshelf
BookShelf::BookShelf(vector<BookSeries> bookseries, int capacity, int booknum)
{
	Books = bookseries;
	iCapacity = capacity;
	iBookNum = booknum;
	iFreeNum = iCapacity - iBookNum;
}

// search a book in this bookshelf and return it
BookSeries* BookShelf::BookSearch(string bookname)
{
	for (vector<BookSeries>::iterator iter = Books.begin();
			iter != Books.end(); iter++)
	{
		if ((*iter).GetBook().GetBookName() == bookname)
			return &(*iter);
	}

	return NULL;
}

// determine whether a book is in this bookshelf 
bool BookShelf::InBookShelf(string bookname)
{
	if (BookSearch(bookname) != NULL)
		return true;
	else
		return false; 
}

// add a bookseries in this bookshelf
void BookShelf::AddBookSeries(BookSeries bookseries)
{
	Books.push_back(bookseries);
}

// delete a bookseries in this bookshelf
void BookShelf::DelBookSeries(string bookname)
{
	for (vector<BookSeries>::iterator iter = Books.begin();
			iter != Books.end(); iter++)
	{
		if ((*iter).GetBook().GetBookName() == bookname)
		{
			Books.erase(iter);
			break;
		}
	}
}


// show the information of this bookshelf
void BookShelf::ShowShelfInfo()
{
	cout<< "******************************Book Shelf*********************************" <<endl;
	cout<< "BookShelf Capacity : " << iCapacity <<endl;
	cout<< "BookShelf BookNum  : " << iBookNum << "   BookShelf FreeNum : " << iFreeNum <<endl;
		cout << "-------------------------" << endl;
	for (vector<BookSeries>::iterator iter = Books.begin(); iter != Books.end(); iter++)
	{
		(*iter).ShowBookSeriesInfo();
		cout << "-------------------------" << endl;
	}
	cout<< "*************************************************************************" <<endl;
}

// get the capacity of this bookshelf
int BookShelf::GetCapacity()
{
	return iCapacity;
}

// get the book num of this bookshelf
int BookShelf::GetBookNum()
{
	return iBookNum;
}

// get the free num of this bookshelf
int BookShelf::GetFreeNum()
{
	return iFreeNum;
}

// get the book vector
vector<BookSeries> BookShelf::GetBooks()
{
	return Books;
}

// set the capacity of this bookshelf
int BookShelf::SetCapacity(int capacity)
{
	iCapacity = capacity;
	return iCapacity;
}

// set the book num  of this bookshelf
int BookShelf::SetBookNum(int booknum)
{
	iBookNum = booknum;
	return iBookNum;
}

// set the free num of this bookshelf
int BookShelf::SetFreeNum(int freenum)
{
	iFreeNum = freenum;
	return iFreeNum;
}
