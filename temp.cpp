// Understanding end().
#include <iostream>
#include <list>
using namespace std;
int main()
{
list<int> lst; // create an empty list
int i;
for(i=0; i<10; i++) lst.push_back(i);
cout << "List printed forwards:\n";
list<int>::iterator p = lst.begin();
while(p != lst.end()) {
cout << *p << " ";
p++;
}
cout << "\n\n";
cout << "List printed backwards:\n";
p = lst.end();
while(p != lst.begin()) {
p--; // decrement pointer before using
cout << *p << " ";
}
return 0;
}
