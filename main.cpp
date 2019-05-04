#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, string & file);
void writeFile(linkedlist & list, string & file);

int main() {
linkedlist list;
string file="list.txt";
readFile(list, file);

cout<<"The average is "<<list.average()<<endl;
writeFile(list, file);
    return 0;
}

void readFile(linkedlist & list, string & file) {
int num;
char blank;
ifstream inData(file);
while(inData>>num)
{
	inData.get(blank);
	if(inData.eof())
		break;
    list.insertInOrder(num);
}
inData.close();
}

void writeFile(linkedlist & list, string & file)
{
  ofstream outData(file);
  list.writeInorder(outData);
  list.writeReversed(outData);
  outData.close();
}
