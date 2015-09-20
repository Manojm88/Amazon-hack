#include "StdAfx.h"
#include<string>
#include "Condition.h"
using namespace std;

class Item{
public:
 int id;
private:
 string title;
 string author;
 string date;
 double price;
 string publisher;
public:
	Item(int id, string name,string value);
	Item();
	void set_field(string field_name, string value);
	void set_title(string title);
	void set_author(string author);
	void set_date(string date);
	void set_price(double price);
	void set_publisher( string publisher);
 };
