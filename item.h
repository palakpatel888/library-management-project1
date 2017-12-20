#include <iostream>
#include <string>
using namespace std;

class item
{
public:
	void checkout();
	void returnbook();
	void setid(int);
	void setTitle(string);
	void setId(int);
protected:
	int id; 
	string title;
	bool checkedin;
};

class books: public item
{
public:
	books();
	void setbooks(int, string, string);
	friend ostream& operator<< (ostream&, const books&);
	bool operator==(const books& otherbook) const;
	string gettitle();
	string getAuthor();
	void setAuthor(string);

private:
	string Author_name;
};


class journals: public item
{
public:
	journals();
	void setjournals(int, string, int);
	friend ostream& operator<< (ostream&, const journals&);
	bool operator==(const journals& otherjourn) const;
	string gettitle();
	void setvolume(int);


private:
	int volume;
};



class magazines: public item
{
public:
	magazines();
	void setmagazines(int, string, int);
	friend ostream& operator<< (ostream&, const magazines&);
	bool operator==(const magazines& othermag) const;
	string gettitle();
	void setIssue(int);

private:
	int Issue_number;
};