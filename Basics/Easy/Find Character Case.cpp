#include<iostream>
using namespace std;

int main() {
	char ch ;
	cin>>ch;
	if(isupper(ch)) cout<<1;
	else if(islower(ch)) cout<<0;
	else cout<<-1;
	return 0;
}


#include<iostream>
using namespace std;

int main() {
	char ch;
	cin >> ch;

	if(ch >= 'A' && ch <= 'Z') {
		cout << "1";
	}
	else if(ch >= 'a' && ch <= 'z') {
		cout << "0";
	}
	else {
		cout << "-1";
	}
	
}


https://www.codingninjas.com/studio/problems/find-character-case_58513?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=DISCUSS&count=25&page=2&search=&sort_entity=order&sort_order=ASC

