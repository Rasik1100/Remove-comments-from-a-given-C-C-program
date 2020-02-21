// Name        : Rasik Mahajan
// Description : Program to remove the comments from the C/C++ Programs 

#include<bits/stdc++.h>
using namespace std;

#define len length()
#define pb push_back
#define sz size()

bool is_space(string line){
	bool tmp=true;
	for(int i=0;i<line.len;i++)
		if(!isspace(line[i]))
			tmp=false;
	return tmp;
}

void function_call(vector<string>& code){
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
	return ;
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
	function_call(code);
	cout << endl << "Output:" << endl;
	for(int i=0;i<code.sz;i++)
		cout << code[i] << endl;
	if(code.sz==0)
		cout << "Whole given code is commented";
	return 0;
}
