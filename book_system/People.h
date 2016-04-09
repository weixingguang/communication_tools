#include "BookShelf.h"

class People
{
	public:
		string GetName();
		float  GetMoney();

		string SetName(string name);
		float  SetMoney(float money);

		People(string name, float money);

		bool BuyBook(BookShelf bookshelf, string bookname);

	private:
		string strName;
		float  fMoney;
};

// constructor, initialize a People
People::People(string name, float money)
{
	strName = name;
	fMoney  = money;
}

bool People::BuyBook(BookShelf bookshelf, string bookname)
{
	if (bookshelf.InBookShelf(bookname))
	{
		if( fMoney >= (bookshelf.BookSearch(bookname))->GetBook().GetPrice() )
		{
			int availnum = (bookshelf.BookSearch(bookname))->GetAvailNum();
			availnum = (bookshelf.BookSearch(bookname))->SetAvailNum(--availnum);

			fMoney -= (bookshelf.BookSearch(bookname))->GetBook().GetPrice();
		cout << "Buying book : << " << bookname << " >>   successfully!" << endl;

			if ( availnum == 0)
				bookshelf.DelBookSeries(bookname);
		}
		else
		{
		cout << "Buying book : " << bookname << "Failed!" << endl;
		cout << "You don't have enough Money! " << endl;
		return false;
		}
	}
	else
	{
		cout << "Buying book : " << bookname << "Failed!" << endl;
		cout << "There is no this book in here! " << endl;
		return false;
	}
}

// get the name of this people
string People::GetName()
{
	return strName;
}

// get the remaining money of this people
float People::GetMoney()
{
	return fMoney;
}

// set the name of this people
string People::SetName(string name)
{
	strName = name;
	return strName;
}

// set the money of this people
float People::SetMoney(float money)
{
	fMoney = money;
	return fMoney;
}
