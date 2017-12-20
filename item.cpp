#include <iostream>
#include <string>
#include "item.h";
using namespace std;
// item methods------------------------------------------------------------------
void item::checkout()
{
	checkedin = false;
}
void item::returnbook()
{
	checkedin = true;
}
void item::setTitle(string t)
{
	title = t;
}
void item::setId(int num)
{
	id = num;
}
// book methods ----------------------------------------------------------------------//
books::books()
{
	title = "";
	id = 0;
	checkedin = true;
	Author_name = "";

}
void books::setbooks(int idnum, string bname, string Aname)
{
	title = bname;
	id = idnum;
	checkedin = true;
	Author_name = Aname;
}
ostream& operator<< (ostream& osbook, const books& bookobject)
{
	osbook << "Title: " << bookobject.title << "\t" << "Author Name: " << bookobject.Author_name << "\t" << "The Id "
		<< bookobject.id << "\t" << "book status " << bookobject.checkedin << endl;
	return osbook;
}
bool books::operator==(const books& otherbook) const
{
	return (Author_name == otherbook.Author_name && title == otherbook.title && id == otherbook.id);
}
string books::gettitle()
{
	return title;
}
string books::getAuthor()
{
   return Author_name;
}
void books::setAuthor(string name)
{
	Author_name = name;
}

// journals methods ----------------------------------------------------------------------//
journals::journals()
{
	title = "";
	id = 0;
	checkedin = false;
	volume = 0;

}
void journals::setjournals(int idnum, string bname, int vol)
{
	title = bname;
	id = idnum;
	checkedin = true;
	volume = vol;
}
ostream& operator<< (ostream& osbook, const journals& journalobject)
{
	osbook << "Title: " << journalobject.title << "\t" << "Volume: " << journalobject.volume << "\t" << "The Id "
		<< journalobject.id << "\t" << "book status: " << journalobject.checkedin << endl;
	return osbook;
}
bool journals::operator==(const journals& otherjourn) const
{
	return (volume == otherjourn.volume && title == otherjourn.title && id == otherjourn.id);
}
string journals::gettitle()
{
	return title;
}
void journals::setvolume(int vol)
{
	volume = vol;
}

// magazine methods -----------------------------------------------------------------//
magazines::magazines()
{
	title = "";
	id = 0;
	checkedin = false;
	Issue_number = 0;
}
void magazines::setmagazines(int idnum, string bname, int issue)
{
	title = bname;
	id = idnum;
	checkedin = true;
	Issue_number = issue;
}
ostream& operator<< (ostream& osmag, const magazines& magobject)
{
	osmag << "Title: " << magobject.title << "\t" << "Issuenumber: " <<magobject.Issue_number << "\t" << " The Id "
		<< magobject.id << "\t" << "book status " << magobject.checkedin << endl;
	return osmag;
}
bool magazines::operator==(const magazines& othermag) const
{
	return (Issue_number == othermag.Issue_number && title == othermag.title && id == othermag.id);
}
string magazines::gettitle()
{
	return title;
}
void magazines::setIssue(int issue)
{
	Issue_number = issue;
}