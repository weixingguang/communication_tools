#include "People.h"

int main()
{
	int static BOOKNUM = 10;
	Position position[ BOOKNUM ];
	Book book[ BOOKNUM ];
	BookSeries bookseries[ BOOKNUM ];

	vector<BookSeries> bookvec;

	book[0] = Book("physical","yjj","1111111111",23.3);
	book[1] = Book("math","ljy","2222222222",27.3);
	book[2] = Book("chemical","ly","3333333333",25.3);
	book[3] = Book("chinese","fy","4444444444",37.3);
	book[4] = Book("english","yh","5555555555",13.3);
	book[5] = Book("biography","tlz","6666666666",47.3);
	book[6] = Book("computer","xrt","7777777777",53.3);
	book[7] = Book("communication","lh","8888888888",57.3);
	book[8] = Book("art","xgc","9999999999",28.3);
	book[9] = Book("gym","gym","0000000000",12.3);

	for (int index = 0; index < BOOKNUM; index++)
	{
		position[index] = {0, index};
		bookseries[index] = BookSeries(book[index], 5, 5, position[index]);
		bookvec.push_back(bookseries[index]);
	}

	BookShelf bookshelf = BookShelf(bookvec, 100, BOOKNUM);

	People people = People("wxg",100);
	people.BuyBook(bookshelf,"physical");
	people.BuyBook(bookshelf,"math");
	people.BuyBook(bookshelf,"chemical");
	people.BuyBook(bookshelf,"chinese");

}
