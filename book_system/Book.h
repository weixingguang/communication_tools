#include <iostream>
using namespace std;

class Book
{
	public:
		string GetBookName();
		string GetAuthor();
		string GetISBN();
		float  GetPrice();

		string SetBookName(string BookName);
		string SetAuthor(string Author);
		string SetISBN(string ISBN);
		float SetPrice(float Price);

		void ShowBookInfo();

		Book(string, string, string, float);

	private:
		string strBookName;
		string strAuthor;
		string strISBN;
		float  fPrice;
};

// Constructor, initialize a book
Book::Book(string BookName = "Communication", string Author = "Liuyang", string ISBN = "18810562759", float Price = 23.4)
{
	strBookName = BookName;
	strAuthor   = Author;
	strISBN     = ISBN;
	fPrice      = Price;
}


// show book information
void Book::ShowBookInfo()
{
	cout << "BookName : " << strBookName <<endl;
	cout << "Author   : " << strAuthor <<endl;
	cout << "BookISBN : " << strISBN <<endl;
	cout << "Price    : " << fPrice <<endl;
}

// get the name of this book
string Book::GetBookName()
{
	return strBookName;
}

// set the name of this book
string Book::SetBookName(string BookName)
{
	strBookName = BookName;
	return strBookName;
}

// get the author of this book
string Book::GetAuthor()
{
	return strAuthor;
}

// set the author of this book
string Book::SetAuthor(string Author)
{
	strAuthor = Author;
	return strAuthor;
}

// get the ISBN of this book
string Book::GetISBN()
{
	return strISBN;
}

// set the ISBN of this book
string Book::SetISBN(string ISBN)
{
	strISBN = ISBN;
	return strISBN;
}

// get the Price of this book
float Book::GetPrice()
{
	return fPrice;
}

// set the Price of this book
float Book::SetPrice(float Price)
{
	fPrice = Price;
	return fPrice;
}

