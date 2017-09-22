/* Jack O'Toole Sep 2017
	Program to generate guitar chords,ie notes for 6 strings and
	the fret. 
	The second objective is to then generate different versions of the chord,
	 starting with different route note positions and finally inversions.
	 */
# include "iostream"
using namespace std;

int a = 0,a_ = 1,b = 2,c = 3,c_ = 4,d = 5, d_ = 6,
	e = 7,f = 8,f_ = 9,g = 10,g_ = 11;  
// patterns for chord structure, could this be rules???
int mjor[3]= {0,4,7};
int mnor[3]= {0,3,7};
int seventh[4]= {0,4,7,10};

/*struct  chords{ // don't know about this idea
	int mj;
	int mn;
	int sth;
};*/

int main(int argc, char const *argv[])
{
	//a chord needs a root
	int root;
	char a_root;  // A...Z = 65 ... 90, 97...122 for lower case
	cout << "Chord Root ?" << endl;
	cin >> a_root;
	root = a_root;
	printf("%d \n", root);
	return 0;
}