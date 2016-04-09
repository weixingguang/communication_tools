#include "People.h"

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

	vector<BookSeries> vec;
	vec.push_back(bookseries);

	BookShelf bookshelf(vec,100,10);
	bookshelf.ShowShelfInfo();

	
	Book book1;
	BookSeries bookseries1(book1, 5, 5, position);
	bookshelf.AddBookSeries(bookseries1);
	bookshelf.ShowShelfInfo();

	Book book2;
	book2.SetBookName("physical");
	BookSeries bookseries2(book2, 5, 5, position);
	bookshelf.AddBookSeries(bookseries2);
	bookshelf.ShowShelfInfo();

	BookSeries *bookseries3;
	bookseries3 = bookshelf.BookSearch("physical");
	bookseries3->ShowBookSeriesInfo();
	bookseries3 = bookshelf.BookSearch("wxg");
	bookseries3->ShowBookSeriesInfo();

	bool result = bookshelf.InBookShelf("Wxg");
	cout << result <<endl;

	bookshelf.DelBookSeries("physical");
	bookshelf.ShowShelfInfo();
	result = bookshelf.InBookShelf("physical");
	cout << result <<endl;

	People people = People("wxg",100);
	cout<< people.GetName() << people.GetMoney() << endl;
	people.BuyBook(bookshelf, "wxg");
	people.SetName("xgc");
	people.SetMoney(1);
	cout<< people.GetName() << people.GetMoney() << endl;

	return 0;
}
