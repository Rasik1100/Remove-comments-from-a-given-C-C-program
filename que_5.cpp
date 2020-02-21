// Name        : Rasik Mahajan
// Description : Program to remove the comments from the C/C++ Programs 


#include<bits/stdc++.h>
using namespace std;

#define len length()
#define pb push_back
#define sz size()

// Function to check whether the given line have only whitespaces or not 
bool is_space(string line){     
	bool tmp=true;
	for(int i=0;i<line.len;i++)
		if(!isspace(line[i]))
			tmp=false;
	return tmp;
}

void function_call(vector<string>& code){
	// flag to indicate whether multiple line comment
	// have started or not.
	bool cmt=false;                   
	
	vector<string> alt;       // To store the uncommented lines of code
	string tmp="";		  // To store the uncommented code for a particular line
	
	// Traverse the given program	
	for(int i=0;i<code.sz;i++){          // Iterating through each line
		tmp="";
		for(int j=0;j<code[i].len;j++){  //  Parsing the ith line of code
			
			//If "//" is found the ignore the whole line
			if(j+1<code[i].len && code[i][j]=='/' && code[i][j+1]=='/'){  
				break;	
			}
			
			// If "/*" is found then make cmt flag as true
			// and we don't have to check each time about the cmt flag 
			// when we found "/*" because "/*" might be present 
			// within the comment
			if(j+1<code[i].len && code[i][j]=='/' && code[i][j+1]=='*'){
				cmt=true;
				j++;
			}
			
			// if we found "*/" then make cmt flag as false	
			else if(cmt && j+1<code[i].len && code[i][j]=='*' && code[i][j+1]=='/'){                
				cmt=false;
				j++;
			}
			
			// if there is no comment flag is on then just store that
			// part of line.
			else if(cmt==0)
				tmp+=code[i][j];
		}
		
		// Store only those lines in the vector which
		// is not empty and not contains just
		// the white spaces
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
	cout << "Given Program\n";
	for(int i=0;i<n;i++){
		cout << code[i] << endl;
	}
	function_call(code);
	cout << endl << "Modified Program\n" << endl;
	for(int i=0;i<code.sz;i++)
		cout << code[i] << endl;
	if(code.sz==0)
		cout << "Whole given code is commented";
	return 0;
}
