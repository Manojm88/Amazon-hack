#include"stdafx.h"
#include<string>
#include<list>
#include<hash_map>

//hash_map<field_name,hash_map<condition,list<subscriber>>subscriber_map> field_map;
using namespace std;
class Condition
{
private:
	string field_name;
	string condition;
	string value;
	int id;
public:
	Condition(string field_name, string value);
	Condition();
	void send_notification(list<string>,int id);
	void check_condition(int item_id);
private:
	int GenerateID(string field_name, string value);
	void BuildConditionHash();
};