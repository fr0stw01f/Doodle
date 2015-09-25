#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> words {"Hello", "from", "GCC", __VERSION__, "!"};
	for_each(begin(words), end(words), [](auto& word){
		cout << word << " ";
	});	
	cout << endl;
}
