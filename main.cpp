#include <iostream> 
#include <string>;
#include <vector>;
#include "item.h"
using namespace std;

template<class items>
void list(items A, int numof)
{
	cout << endl;
	for (int i = 0; i < numof; i++)
	{
		cout << A[i] << endl;
	}
}

int search(string name, books b[], journals j[], magazines m[], int numofb, int numofm, int numofj)
{
	bool itemfound = false;
	for (int i = 0; i <= numofb; i++)
	{
		if (b[i].gettitle() == name)
		{
			cout << "your item was found! her is its information" << endl;
			cout << b[i] << endl;
			itemfound = true;
			return i;
		}
	}
	for (int i = 0; i <= numofj; i++)
	{
		//string a = j[i].gettitle();
		if (j[i].gettitle() == name)
		{
			cout << "your item was found! her is its information" << endl;
			cout << j[i] << endl;
			itemfound = true;
			return i;
		}
		
	}
	for (int i = 0; i <= numofm; i++)
	{
		//string a = m[i].gettitle();
		if (m[i].gettitle() == name)
		{
			cout << "your item was found! her is its information" << endl;
			cout << m[i] << endl;
			itemfound = true;
			return i;
		}
		
	}
	if (itemfound == false)
	{
		cout << "we do not carry this item" << endl;
		return 0;
	}

}

int booksearch(string Author, books b[],int numofb)
{
	bool itemfound = false;
	for (int i = 0; i < numofb; i++)
	{
		string a = b[i].getAuthor();
		if (a == Author)
		{
			cout << "your book has been found! here is its information!" << endl;
			cout << b[i] << endl;
			itemfound = true;
			return i;
		}
	}
	if (itemfound == false)
	{
		cout << "we do not carry any items by this author" << endl;
		return 0;
	}
}

int newbook(books b[], string title, string Author, int id, int numof)
{
	int i = 0;
	bool added = true;
	while (b[i].getAuthor() != "")
	{
		i++;
	}
	b[i].setAuthor(Author);
	b[i].setId(id);
	b[i].setTitle(title);
	b[i].returnbook();
	for (int a = 0; a < numof; a++)
	{
		if (b[i] == b[a])
		{
			cout << "that book already exists" << endl;
			b[i].setbooks(0, "", "");
			added = false;
			return 0;
		}
	}
	for (int a = 0; a < numof; a++)
	{
		if (b[i].getAuthor() == b[a].getAuthor())
		{
			cout << "there is already a book by this author you cannot add another one" << endl;
			b[i].setbooks(0, "", "");
			added = false;
			return 0;
		}
	}
	if (added = true)
	{
		cout << "your book has been added!" << endl;
	}


}
int newjournal(journals j[], string title, int vol, int id, int numof)
{
	bool added = true;
	int i = 0;
	while (j[i].gettitle() != "")
	{
		i++;
	}
	j[i].setvolume(vol);
	j[i].setId(id);
	j[i].setTitle(title);
	j[i].returnbook();

	for (int a = 0; a < numof; a++)
	{
		if (j[i] == j[a])
		{
			cout << "that journal already exists" << endl;
			j[i].setjournals(0, "", 0);
			added = false;
			return 0;
		}
	}
	if (added = true)
	{
		cout << "your journal has been added!" << endl;
	}
}

int newmagazine(magazines m[], string title, int vol, int id, int numof)
{ 
	bool added = true;
	int i = 0;
	while (m[i].gettitle() != "")
	{
		i++;
	}
	m[i].setIssue(vol);
	m[i].setId(id);
	m[i].setTitle(title);
	m[i].returnbook();

	for (int a = 0; a < numof; a++)
	{
		if (m[i] == m[a])
		{
			cout << "that magazine already exists" << endl;
			m[i].setmagazines(0, "", 0);
			added = false;
			return 0;
		}
	}
	if (added == true)
	{
		cout << "your magazine has been added!" << endl;
	}
}

int main()
{
	// so make parameters of how many books or whatever there are and then increment it if they add any thing 
	int numofb = 5;
	int numofj = 5;
	int numofm = 5;
	books b[100];
	journals j[100];
	magazines m[100];
	b[0].setbooks(892, "chickens", "Prise");
	b[1].setbooks(292, "tieing my shoes", "Vengas");
	b[2].setbooks(3931, "the thirst", "Saijan");
	b[3].setbooks(93829, "last halloween", "McGillis");
	b[4].setbooks(2314, "typing 101", "Patel");

	j[0].setjournals(1287, "Economics", 2);
	j[1].setjournals(123, "Romanticism", 8);
	j[2].setjournals(82374, "Politics", 1);
	j[3].setjournals(1037, "Urban form", 4);
	j[4].setjournals(024, "Modernity", 17);

	m[0].setmagazines(33, "American girl", 6);
	m[1].setmagazines(31, "Seventeen", 56);
	m[2].setmagazines(0721, "Teen Nick", 16);
	m[3].setmagazines(321, "Sports illustrated", 23);
	m[4].setmagazines(37021, "Time", 51);

	


	int start = 0;
	string choice;
	string choice2;
	string choice3;
	string title;
	int addnum;
	string addtitle;
	string addauthor;
	int addvol;
	int addissue;
	cout << "LIBRARY MANAGEMENT PROGRAM" << endl;
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
	cout << endl;
	cout << "GENERAL  INFORMATION" << endl;
	cout << "--------------------------------------------------------------------------------------------------------- " << endl;
	cout << "-If the book is checked in the program will show a one next to it." << endl;
	cout << "-We only carry one copy of each item and one item by each author" << endl;
	cout << "-If the item is not checked in you cannot check it out" << endl;
	cout << "-There are currently 5 of each type of library item in the catalog and there are 95 spaces available" << endl;
	cout << "-In total the library can hold no more then 100 of each item" << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "MENU" << endl;
	cout << "----------------" << endl;
	cout << "1     Search Catalog" << endl;
	cout << "2     Check out" << endl;
	cout << "3     Return" << endl;
	cout << "4     Add a new item" << endl;
	cout << "5     Exit" << endl;


	while (start != 6)
	{
		cout << endl;
		cout << "please enter a number to choose an option" << endl;
		cout << "if you dont enter a valid option you will continue to be prompted" << endl;
		cin >> start;
		cout << endl;
		if (start == 1)
		{
			cout << "would you like to see a list of a certain library item first?" << endl;
			cout << "enter yes or no" << endl;
			cin >> choice;
			while (choice != "yes" && choice != "no")
			{
				cout << "please enter a valid input" << endl;
				cin >> choice;
			}
				if (choice == "yes")
				{
					cout << "which item type you you like to see? you can choose between books journals and magazines" << endl;
					cin >> choice2;
					while (choice2 != "books" && choice2 != "journals" && choice2 != "magazines")
					{
						cout << "please enter a valid input" << endl;
						cin >> choice2;
					}
					if (choice2 == "books")
					{
						list(b, numofb);
					}
					else if (choice2 == "journals")
					{
						list(j, numofj);
					}
					else if (choice2 == "magazines")
					{
						list(m, numofm);
					}
				}
				else if (choice == "no")
				{
					cout << "if you are searching for a book then you can search using the author" << endl;
					cout << "would you like to this? enter yes or no" << endl;
					cin >> choice3;
					while (choice3 != "yes" && choice3 != "no")
					{
						cout << "please enter a valid input" << endl;
						cin >> choice3;
					}
					if (choice3 == "yes")
					{
						string author;
						cout << "enter the author" << endl;
						cin >> author;
						booksearch(author, b, numofb);
					}
					else if (choice3 == "no")
					{
						cout << "please enter the title of the item you are searching for" << endl;
						cin >> title;
						search(title, b, j, m, numofb, numofm, numofj);
					}

				}
			}
		else if (start == 2)
		{
			string itemtype2;
			cout << "if you want to check out an item you must search for it first" << endl;
			cout << "please enter the title" << endl;
			cin >> title;
			cout << "please enter the item type" << endl;
			int a = search(title, b, j, m, numofb, numofm, numofj);
			cout << "you item will now be checked out after you enter the type of item it is" << endl;
			cout << "please enter book, magazine or journal" << endl;
			cin >> itemtype2;
			while (itemtype2 != "book" && itemtype2 != "magazine" && itemtype2 != "journal")
			{
				cout << "please enter valid input" << endl;
			}
			cout << endl;
			if (itemtype2 == "book")
			{
				b[a].checkout();
				cout << b[a] << endl;
			}
			else if (itemtype2 == "magazine")
			{
				m[a].checkout();
				cout << m[a] << endl;
			}
			else if (itemtype2 == "journal")
			{
				j[a].checkout();
				cout << j[a] << endl;
			}
		}
		else if (start == 3)
		{
			string itemtype2;
			cout << "if you want to check out an item you must search for it first" << endl;
			cout << "please enter the title" << endl;
			cin >> title;
			cout << "please enter the type of item: book, magazine or journal" << endl;
			cin >> itemtype2;
			while (itemtype2 != "book" && itemtype2 != "magazine" && itemtype2 != "journal")
			{
				cout << "please enter valid input" << endl;
			}
			cout << endl;
			int a = search(title, b, j, m, numofb, numofm, numofj);
			cout << "you item will now be returned if the item does not need to be returned the status will not change" << endl;
			if (itemtype2 == "book")
			{
				b[a].returnbook();
				cout << b[a] << endl;
			}
			else if (itemtype2 == "magazine")
			{
				m[a].returnbook();
				cout << m[a] << endl;
			}
			else if (itemtype2 == "journal")
			{
				j[a].returnbook();
				cout << j[a] << endl;
			}
		}
		else if (start == 4)
		{
			string itemtype;
			cout << "which type of item would you like to add? please enter book, journal or magazine" << endl;
			cin >> itemtype;
			while (itemtype != "book" && itemtype != "journal" && itemtype != "magazine")
			{
				cout << "please enter a valid input" << endl;
				cin >> itemtype;
			}
			if (itemtype == "book")
			{
				cout << "enter an id number" << endl;
				cin >> addnum;
				cout << "enter the book title" << endl;
				cin.ignore();
				getline(cin, addtitle);
				cout << "enter the last name of the book author" << endl;
				cin >> addauthor;
				newbook(b, addtitle, addauthor, addnum, numofb);
				numofb++;
			}
			else if (itemtype == "journal")
			{
				cout << "enter an id number" << endl;
				cin >> addnum;
				cout << "enter the journal title" << endl;
				cin.ignore();
				getline(cin, addtitle);
				cout << "enter the book volume" << endl;
				cin >> addvol;
				newjournal(j, addtitle, addvol, addnum,numofj);
				numofj++;
			}
			else if (itemtype == "magazine")
			{
				cout << "enter an id number" << endl;
				cin >> addnum;
				cout << "enter the magazine title" << endl;
				cin.ignore();
				getline(cin, addtitle);
				cout << "enter the issue number" << endl;
				cin >> addissue;
				newmagazine(m, addtitle, addissue, addnum,numofm);
				numofm++;
			}
		}
		else if (start == 5)
		{
			cout << "you have decided to exit the program" << endl;
			start = 6;
		}

	}

	 
	return 0;
}