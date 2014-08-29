#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void parse(string& s, long& g, int& sickle, int& k)
{
	int idx = s.find_first_of('.');
	string s1 = s.substr(0, idx);
	int start = idx + 1;
	int lidx = s.find_first_of('.', start);
	string s2 = s.substr(start, lidx - start);
	start = lidx+1;
	string s3 = s.substr(start);

	stringstream ss;
	ss << s1;
	ss >> g;
	ss.clear();
	ss << s2;
	ss >> sickle;
	ss.clear();
	ss << s3;
	ss >> k;
}
int main()
{
	long g1, g2, g;
	int s1, s2, s, k1, k2, k;
	string a,b;
	cin >> a >> b;
	parse(a, g1, s1, k1);
	parse(b, g2, s2, k2);
	k = (k1 + k2) % 29;
	int c = (k1 + k2) / 29;
	s = s1 + s2 + c;
	c = s / 17;
	s %= 17;
	g = g1 + g2 + c;
	cout << g << "." << s << "." << k << endl;
	system("pause");
}