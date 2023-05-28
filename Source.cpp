#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//additional recursive function
int countChars(string s, char c) {
	if (s.length() == 0)
		return 0;
	else if (s.at(0) == c)
		return 1 + countChars(s.substr(1), c);
	else
		return countChars(s.substr(1), c);
}
//main recursive funstion
int get_count_from_str(string file_content, string key) {
	int count = 0;
	while (key.length() != 0) {
		count += countChars(file_content, key.at(0));
		key = key.substr(1);
	}
	return count;
}


string replace_string(string inputStr, string src, string dst)
{
	std::string result(inputStr);
	
	size_t pos = result.find(src);
	while (pos != std::string::npos) {
		result.replace(pos, src.size(), dst);
		pos = result.find(src, pos);
	}

	return result;
}

int main() {

	string key_word = "BASIC";
	string example_string = "This is text about basic language. Basic is the best! Remember that only case sensitive LETTERS could be represented as substrings of the word BASIC. So word basic will have count of 0 matched letters and BASIC will have 5 count!    Best regards,    SIGN ME.txt";

	cout << "Line is:\n" << example_string << endl << endl;
	cout << "Count =" << get_count_from_str(example_string, key_word) << endl;

	cout << "Line is:\n" << replace_string(example_string, key_word, "Delphi") << endl << endl;

	return 0;
}
