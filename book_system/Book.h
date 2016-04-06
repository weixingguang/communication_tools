class Book
{
	private:
		string strBookName;
		string strAuthor;
		string strISBN;
		float  fPrice;
	public:
		Book(string, string, string, float);
		string GetBookName();
		string GetAuthor();
		string GetISBN();
		float  GetPrice();

		string SetBookName(string BookName);
		string SetAuthor(string Author);
		string SetISBN(string ISBN);
		float SetPrice(float Price);
};

Book::Book(string BookName, string Author, string ISBN, float Price)
{
	strBookName = BookName;
	strAuthor   = Author;
	strISBN     = ISBN;
	fPrice      = Price;
}

string Book::GetBookName()
{
	return strBookName;
}

string Book::SetBookName(string BookName)
{
	strBookName = BookName;
	return strBookName;
}

string Book::GetAuthor()
{
	return strAuthor;
}

string Book::SetAuthor(string Author)
{
	strAuthor = Author;
	return strAuthor;
}

string Book::GetISBN()
{
	return strISBN;
}

string Book::SetISBN(string ISBN)
{
	strISBN = ISBN;
	return strISBN;
}

float Book::GetPrice()
{
	return fPrice;
}

float Book::SetPrice(float Price)
{
	fPrice = Price;
	return fPrice;
}

