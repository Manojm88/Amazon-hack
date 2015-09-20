
#include"Item.h"
Item::Item(int id, string name,string value)
{
	this->id =id;
	set_field(name,value);
}

Item::Item()
{
}

void Item::set_field(string field_name, string value)
{
	if(field_name=="title")
	{
		if (!this->title.empty())
		{
			Condition cdtn(field_name,value);
				cdtn.check_condition(this->id);
		}
		this->title=value;
	}
	else if (field_name=="authors")
	{
		if (!this->author.empty())
		{
			Condition cdtn(field_name,value);
				cdtn.check_condition(this->id);
		}
		this->author=value;
	}
	else if(field_name=="release date")
	{
		if (!this->date.empty())
		{
			Condition cdtn(field_name,value);
				cdtn.check_condition(this->id);
		}
		this->date=value;
	}
	else if(field_name=="list price")
	{
		if (!this->price)
		{
			Condition cdtn(field_name,value);
				cdtn.check_condition(this->id);
		}
		this->price=std::stod(value);
	}
	else
		if (!this->publisher.empty())
		{
			Condition cdtn(field_name,value);
				cdtn.check_condition(this->id);
		}
		this->publisher=value;
}