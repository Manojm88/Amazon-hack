#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include<algorithm>
#include "Item.h"
#include<hash_map>
using namespace std;

hash_map<int , Item> itemmap;

 void main()
 {
	 std::ifstream file("file1.csv");
	std::string line;
	//int item;

	if (file.is_open())
	{
		//vector<string> v;
		//istringstream stream (file);
		int i=0;
		int id;
		std::string field;
		std::string value;
		while ( getline(file,line) )
		{
			line.erase(remove(line.begin(),line.end(),'\"'),line.end());
			int initial = 0;
			i = 0;
			for (int j=0, k=0;j<line.length();j++, k++)
			{
				if(line[j] == ',' || j == line.length()-1)
				{
					if(j == line.length()-1)
					{
						value = line.substr(initial,k);k=0;
						Item item_obj(id, field, value);
						if(itemmap[id].id)
						{
							itemmap[id].set_field(field,value);
						}
						else
						{
							itemmap[id] = item_obj;
						}
						
					}
					if (i==0)
					{
						id = std::stod(line.substr(initial,k)); i++;k=0;
					}
					else if(i==1)
					{
						field = line.substr(initial,k-1); i++;k=0;
					}
					initial = j+1;
				}
			}
			
			
		}
	}
 }