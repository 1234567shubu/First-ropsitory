/*******************************************************************************************
	Convert the Number into the words in US style using a C++ program

********************************************************************************************/
#include<iostream>
using namespace std;

string str1[] = { " ","One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine"  };
string str2[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Forteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string str3[] = { " "," ", "Twenty","Thirty","Forty","Fifty", "Sixty","Seventy","Eighty","Ninety" };
string str4[] = {" ", " ", "Thousand","Milion","Bilion","Trilion" };

// a function to validate the number
int checkIsNo(string str)
{
	int flag=0;
	for(int i=0; i<str.length();i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			continue;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		return 1;
	}
	else
	{
		throw "Invalid number";
	}
	
}

// get a conversion of a two digit no into words
string getTwoDigitNoInWords(char leftdigit,char rightdigit)
{
	string result="";
    if(leftdigit=='0')
	{
		if( rightdigit !='0' )
		{
			int pos = rightdigit - '0';
			result +=  str1[pos] + " ";
		}
		
	}
	else if(leftdigit=='1')
	{
		int pos = rightdigit - '0';
		result +=  str2[pos] + " ";
	
	}
	else
	{
		int pos = leftdigit - '0';
		result +=  str3[pos] + " ";
		pos = rightdigit - '0';
		result +=  str1[pos] + " ";
	}
	
	return result;
		
}

// to get a conversion of three digit number no into words
string getThreeDigitNoInWords(char leftdigit,char middigit,char rightdigit)
{
	string result="";
	if(leftdigit=='0')
	{
		return getTwoDigitNoInWords(middigit, rightdigit);
	}
	else
	{
		int pos = leftdigit - '0';
	
		result +=   str1[pos] + " Hundred ";
		result +=  getTwoDigitNoInWords(middigit, rightdigit);
	}
	return result;
}


// to get a conversion of a number into words
string notowords(string no)
{
	string result="";
	int flag=0;
	if(no[flag]=='0' && no[flag+1]=='0'&& no[flag+2]=='0' )
	{
		return "Zero";
	}
	
	int dividend = no.length() / 3;

	while(dividend!=0)
	{
		result +=  getThreeDigitNoInWords(no[flag],no[flag+1],no[flag+2] ) + str4[dividend] + " ";

		dividend = dividend - 1;
		flag = flag + 3;
	}
	
	return result;
	
}


//driver function
int main()
{
	string no;
	char stop = 's';
	
	while(1)
	{
		bool invalid = true;
		cout<<"Enter the number which less than equal to 15 digits and its no of digits must be multiple of 3:  ";
		getline(cin,no);
		
		//validation of a number entered
		while(invalid)
		{
			try
			{
				if(!(no.length()<= 15 && checkIsNo(no) && (no.length() % 3 == 0)))
				{
					throw "Invalid number";
				}
				else
				{
					invalid = false;
				}
			}
			catch(const char* e)
			{
				cout<<e<<endl;
				cout<<"Enter the valid number: ";
				getline(cin,no);
				invalid = true;
			}
	
		}
		cout<<"The number into words is:  "<<notowords(no)<<endl;
		
		//cin.clear();
		//cin.ignore(100,'\n');
		cout<<"\n\nPress 's' to stop otherwise press any key to continue: ";
		cin>>stop;
		if(stop=='s')
		{
			break;
		}
		cin.clear();
		cin.ignore(100,'\n');
	}
	return 0;
}

