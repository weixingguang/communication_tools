#include "Book.h"

struct Position
{
	int xNum;
	int yNum;
};

class BookSeries
{
	public:
		Book     GetBook();
		int      GetTotalNum();
		int      GetAvailNum();
		Position GetBookPosition();
		Book     SetBook(Book book);
		int      SetTotalNum(int TotalNum);
		int      SetAvailNum(int AvailNum);
		Position SetBookPosition(Position position);

		BookSeries(Book, int, int, Position);

		void ShowBookSeriesInfo();

	private:
		Book   cBook;
		int    iTotalNum;
		int    iAvailNum;
		Position BookPosition;
};

// constructor, initialize a bookseries
BookSeries::BookSeries(Book book, int TotalNum, int AvailNum, Position position)
{
	cBook       = book;
	iTotalNum   = TotalNum;
	iAvailNum   = AvailNum;
	BookPosition= position;
}

void BookSeries::ShowBookSeriesInfo()
{
	cout << "BookSeries : " << cBook.GetBookName() <<endl;
	cout << "Total Num  : " << iTotalNum <<endl;
	cout << "Avail Num  : " << iAvailNum <<endl;
	cout << "Position   : <" << BookPosition.xNum << " , "<< BookPosition.yNum << ">" <<endl;
}

// get a book
Book BookSeries::GetBook()
{
	return cBook;
}

// get the total num of this book
int BookSeries::GetTotalNum()
{
	return iTotalNum;
}

// get the available num of this book
int BookSeries::GetAvailNum()
{
	return iAvailNum;
}

// get the position of this book
Position BookSeries::GetBookPosition()
{
	return BookPosition;
}

// set a book
Book BookSeries::SetBook(Book book)
{
	cBook = book;
	return cBook;
}

// set the total num of this book
int BookSeries::SetTotalNum(int TotalNum)
{
	iTotalNum = TotalNum;
	return iTotalNum;
}

// set the available num of this book
int BookSeries::SetAvailNum(int AvailNum)
{
	iAvailNum = AvailNum;
	return iAvailNum;
}

// set the position of this book
Position BookSeries::SetBookPosition(Position position)
{
	BookPosition = position;
	return BookPosition;
}
