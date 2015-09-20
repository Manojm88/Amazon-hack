#include"stdafx.h"
#include<string>
#include<list>
#include<hash_map>
#include<iostream>

#include "Condition.h"

using namespace std;

hash_map<int , std::list<string>> conditions;
std::list<string> list1;
std::list<string> list2;

Condition::Condition(string field_name, string value)
{
	this->field_name = field_name;
	this->value = value;
	BuildConditionHash();
}

Condition::Condition()
{
}

void Condition::BuildConditionHash()
{
	list1.push_back("Tim");
	list1.push_back("Matt");
	list2.push_back("Jhon");
	list2.push_back("Perl");
	conditions[11] = list1;
	conditions[52] = list2;
}

void Condition::check_condition(int item_id)
{
	int id = GenerateID(field_name,value);
	if (id != 0)
		send_notification(conditions[id],item_id);
}

void Condition::send_notification(list<string> mylist,int item_id)
{
	std::cout <<"Message sent ";
	cout<<"\nFor subscribers, ";
	for (std::list<string>::iterator it=mylist.begin(); it != mylist.end(); ++it)
	{
		cout << ' ' << *it<<"\n";
	}
}

int Condition::GenerateID(string field_name, string value)
{
	if(field_name == "title")
	{
		if (value == "c++")
		{
			this->id = 11;
			return this->id;
		}
	}
	if (field_name == "authors")
	{
		if (value == "Matt")
		{
			this->id = 21;
			return this->id;
		}
	}
	if (field_name == "publisher")
	{
		if (value == "Braien")
		{
			this->id = 31;
			return this->id;
		}
	}
	if (field_name == "release date")
	{
		if (value == "10-09-2012")
		{
			this->id = 41;
			return this->id;
		}
	}
	if (field_name == "list price")
	{
		if(std::stod(value) < 10)
		{
			this->id = 51;
			return this->id;
		}
	}
	return 0;
}