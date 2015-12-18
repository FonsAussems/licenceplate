#include <iostream>
#include <string>
#include <regex>

using namespace std;

string  parray[15] =
{
	"[a-zA-Z]{2}[0-9]{2}[0-9]{2}", // 0 XX-99-99
	"[0-9]{2}[0-9]{2}[a-zA-Z]{2}", // 1 99-99-XX
	"[0-9]{2}[a-zA-Z]{2}[1-9]{2}", // 2 99-XX-99
	"[a-zA-Z]{2}[0-9]{2}[a-zA-Z]{2}", // 3 XX-99-XX
	"[a-zA-Z]{2}[a-zA-Z]{2}[0-9]{2}", // 4 XX-XX-99
	"[0-9]{2}[a-zA-Z]{2}[a-zA-Z]{2}", // 5 99-XX-XX
	"[0-9]{2}[a-zA-Z]{3}[0-9]{1}", // 6 99-XXX-9
	"[0-9]{1}[a-zA-Z]{3}[0-9]{2}", // 7 9-XXX-99
	"[a-zA-Z]{2}[0-9]{3}[a-zA-Z]{1}", // 8 XX-999-X
	"[a-zA-Z]{1}[0-9]{3}[a-zA-Z]{2}", // 9 X-999-XX
	"[a-zA-Z]{3}[0-9]{2}[a-zA-Z]{1}", // 10 XXX-99-X
	"[a-zA-Z]{1}[0-9]{2}[a-zA-Z]{3}", // 11 X-99-XXX
	"[0-9]{1}[a-zA-Z]{2}[0-9]{3}", // 12 9-XX-999
	"[0-9]{3}[a-zA-Z]{2}[0-9]{1}", // 13 999-XX-9
	"CD[ABFJNST0-9]{1,3}" // 14 diplomats CDX9 CDX99
};  

string tokenteken(string);
int indeling(string);

string toupcase(string);

int main()
{

	cout << tokenteken("XX9999") << endl;  //0
	cout << tokenteken("9999XX") << endl;  //1
	cout << tokenteken("99XX99") << endl;  //2
	cout << tokenteken("XX99XX") << endl;  //3
	cout << tokenteken("XXXX99") << endl;  //4
	cout << tokenteken("99XXXX") << endl;  //5
	cout << tokenteken("99XXX9") << endl;  //6
	cout << tokenteken("9XXX99") << endl;  //7
	cout << tokenteken("XX999X") << endl;  //8
	cout << tokenteken("X99XXX") << endl;  //9
	cout << tokenteken("XXX99X") << endl;  //10
	cout << tokenteken("X99XXX") << endl;  //11
	cout << tokenteken("9XX999") << endl;  //12
	cout << tokenteken("999XX9") << endl;  //13
	cout << tokenteken("CD102") << endl;  //14
	cout << tokenteken("111111") << endl;  //15
	cout << tokenteken("AAAAAA") << endl;  //16
	cin.get();
	return 0;
};

int indeling(string k)
{
	int nummer=-1;
	for (int i = 0; i <= 14; i++)
	{
		if (regex_match(k, regex(parray[i])))
		{
			nummer = i;
			break;
		}
	}
	return nummer;
}

 string tokenteken(string kenteken)
{
    string rkenteken = "";
	kenteken = toupcase(kenteken);
	int wkenteken = indeling(kenteken);
	switch (indeling(kenteken))
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: rkenteken = kenteken.insert(2, "-"); rkenteken = kenteken.insert(5, "-"); break;
	case 6:
	case 8: rkenteken = kenteken.insert(2, "-"); rkenteken = kenteken.insert(6, "-"); break;
	case 7:
	case 9: rkenteken = kenteken.insert(1, "-"); rkenteken = kenteken.insert(5, "-"); break;
	case 10:
	case 13: rkenteken = kenteken.insert(3, "-"); rkenteken = kenteken.insert(6, "-"); break;
	case 11:
	case 12: rkenteken = kenteken.insert(1, "-"); rkenteken = kenteken.insert(4, "-"); break;
	case 14: rkenteken = kenteken; break;
	default: rkenteken = "ERROR";
	}
	
	return rkenteken;
}

 string toupcase(string ustring)
{
	string rs;
	for each (char c in ustring)
	{
		rs +=toupper(c);
	}
	return rs;
}

