#include "BookShelf.h"

int main()
{
	Book book;

	book.ShowBookInfo();

	book.SetBookName("wxg");
	book.SetAuthor("wxg");
	book.SetISBN("123456789");
	book.SetPrice(11.1);

	book.ShowBookInfo();

	Position position;
	position.xNum = 0;
	position.yNum = 0;

	BookSeries bookseries(book, 3, 3, position);
	bookseries.ShowBookSeriesInfo();
	bookseries.SetTotalNum(11);
	bookseries.SetAvailNum(1);
	position.yNum = 1;
	bookseries.SetBookPosition(position);
	cout<<endl;
	bookseries.ShowBookSeriesInfo();

	BookShelf bookshelf();

	return 0;
}
