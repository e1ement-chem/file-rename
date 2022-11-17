#include<string.h>
#include<iostream>
using namespace std;
int main(int argc,char** argv){
	string path=argv[1];
	int l=path.length();
	int index=0;
	for(int i=0;i<l;i++)
		if(path[i]=='.') index=i;
	if(index==0)
	{
		path.append(".");
		path.append(argv[2]);
		rename(argv[1],path.c_str());
	}
	else{
		path.erase(index+1);
		path.append(argv[2]);
		rename(argv[1],path.c_str());
	}
	return 0;
}
