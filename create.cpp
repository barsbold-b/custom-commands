#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iterator>
using namespace std;

bool endsWith(string checker, string str);
string createCppFileName(string fileName);
string getTime();
string getCppBoilerPlate();

int main(int argc, char *argv[]){
	if(argc > 1){
	stringstream sstrm(argv[1]);
	string fileName;

	sstrm >> fileName;
	fileName = endsWith(fileName, ".cpp") ? fileName : createCppFileName(fileName);
	fstream file;
	ifstream isFileExisting;
	isFileExisting.open(fileName);

	if(isFileExisting){
		cout << fileName << " file is existing. Do you want to overwrite (y/N) ";
		string isSure;
		getline(cin, isSure);
		if(isSure == "n" || isSure == ""){
			cout << "Did not create " << fileName << " file.\n";
			return 0;
		}
		if(isSure == "y"){
			cout << "Overwriting the file... \n";
		}
		else{
			cout << "wrong option\n";
			return 0;
		}
		isFileExisting.close();
	}
	else isFileExisting.close();

	file.open(fileName, ios::out);
	
	if(!file){
		cout << "Error was occured when creating file.\n";
		return 1;
	}
	file << getCppBoilerPlate();
	file.close();
	cout << "Created " + fileName + " file.\n";
	}
	else{
		cout << "Missing some args...\n";
	}
}

bool endsWith(string checker, string str){
	string::iterator itr = checker.end() - 1;
	int i = str.length() - 1;
	while(i){
		if(*itr != str[i]) return false;
		--i;
		--itr;
	}
	return true;
}

string createCppFileName(string fileName){
	return fileName + ".cpp";
}

string getTime(){
	time_t now = time(0);
	return ctime(&now);
}

string getCppBoilerPlate(){
	string templateStr = "// When I create this file, only god and I knew"
											 " how it worked.\n// Now, only god knows it.\n"
											 "// Created by Barsbold at " + getTime() + "\n\n"
											 "#include<iostream>\n"
											 "using namespace std;\n\n"
											 "int main(){\n"
											 "\tcout << \"Hello, World!\\n\";\n\n"
											 "\treturn 0;\n"
											 "}\n";
	return templateStr;
}

