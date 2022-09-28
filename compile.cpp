// When I create this file, only god and I knew how it worked.
// Now, only god knows it.
// Created by Barsbold at Sun Sep 25 16:00:41 2022


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool endsWith(string checker, string str);
string createFileName(string str);
string trimExtension(string fileName);

int main(int argc, char* argv[]){
	if(argc > 1) {
		stringstream ss(argv[1]);
		string fileName;
		ss >> fileName;
		if(!endsWith(fileName, ".cpp")) fileName = createFileName(fileName);
		string command = "g++ -std=c++17 " + fileName + " -o " + trimExtension(fileName);
		int status = system(command.c_str());
		if(status == 0)
			cout << "\033[36m"
					 << fileName
					 << " file is compiled into "
					 << trimExtension(fileName)
					 << " file.\033[0m\n";
		else return 1;

		if(argc == 3){
			cout << "\033[1;35mExecuting...\033[0m\n";
			if(strcmp(argv[2], "-e") == 0){
				string exe = "./" + trimExtension(fileName);
				system(exe.c_str());
			}
		}
		return 0;
	}
	else {
		cout << "\033[31;1mSome argument is missing.\033[0m\n";
		return 1;
	}
}

bool endsWith(string checker, string str){
	string::iterator itr = checker.end() - 1;
	int i = str.length() - 1;
	while(i){
		if(*itr != str[i]) return false;
		--i, --itr;
	}
	return true;
}
string createFileName(string str){
	return str + ".cpp";
}
string trimExtension(string fileName){
	string str = "";
	string::iterator itr = fileName.begin();
	int i = 0;
	while(*itr != '.'){
		str += *itr;
		++itr;
	}
	return str;
}
