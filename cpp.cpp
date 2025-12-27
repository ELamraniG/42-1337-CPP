
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace	std;
void solve(string strings[10], string digits, string s,int digit_pos,vector<string> &sol)
{
	if (digit_pos == digits.size())
	{
		sol.push_back(s);
		return ;
	}
	for (int i = 0; i < strings[digits[digit_pos] - '0'].length(); i++)
	{
		s += strings[digits[digit_pos] - '0'][i];
		solve(strings, digits, s,digit_pos + 1,sol);
		s.pop_back();
	}
}
int	main(int ac, char **av)
{
	string	strings[10];

	strings[0] = "";
	strings[1] = "";
	strings[2] = "abc";
	strings[3] = "def";
	strings[4] = "ghi";
	strings[5] = "jkl";
	strings[6] = "mno";
	strings[7] = "pqrs";
	strings[8] = "tuv";
	strings[9] = "wxyz";
	string s = "";
	
	vector<string> soll;
	solve(strings, av[1], s,0,soll);
	// for (int i = 0;i < soll.size();i++)
	// 	cout<<soll[i]<<std::endl;
}
