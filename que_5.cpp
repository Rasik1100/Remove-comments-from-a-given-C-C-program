// Name     : Rasik Mahajan
// id       : 201701055
// Course   : Compiler Design
// Question : 5/6
// Lab_no.  : 1

#include<bits/stdc++.h>
using namespace std;

#define len length()
#define pb push_back
#define sz size()

bool is_space(string line){
	bool tmp=true;
	for(int i=0;i<line.len;i++)
		if(line[i]!=' ')
			tmp=false;
	return tmp;
}

vector<int> f(vector<string>& code){
	bool cmt=false;
	vector<int> ptr;
	vector<string> alt;
	string tmp="";
	for(int i=0;i<code.sz;i++){
		tmp="";
		for(int j=0;j<code[i].len;j++){
			if(j+1<code[i].len && code[i][j]=='/' && code[i][j+1]=='/'){
				ptr.pb(i);
				break;	
			}
			if(j+1<code[i].len && code[i][j]=='/' && code[i][j+1]=='*'){
				cmt=true;
				j++;
				ptr.pb(i);
			}
			else if(cmt && j+1<code[i].len && code[i][j]=='*' && code[i][j+1]=='/'){                
				cmt=false;
				j++;
				ptr.pb(i);
			}
			else if(cmt==0)
				tmp+=code[i][j];
		}
		if(tmp!="" && !is_space(tmp))
			alt.pb(tmp);
	}
	code.clear();
	code=alt;
	return 
}

int main(){
	int n;
	cout << "Question 5" << endl;
	cout << "Number's of line of code : " ;
	cin >> n;
	vector<string> code(n);
	vector<int> line;
	cin.ignore();
	for(int i=0;i<n;i++)
		getline(cin,code[i]);
	line=f(code);
	cout << endl << "Output:" << endl;
	for(int i=0;i<code.sz;i++)
		cout << code[i] << endl;
	if(code.sz==0)
		cout << "Whole given code is commented";
	cout << "Following lines are commented : ";
	for(int i=0;i<line.sz;i++)
		cout << line[i] << " ";
	return 0;
}
