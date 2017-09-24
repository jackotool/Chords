/* Jack O'Toole Sep 2017
	Program to generate guitar chords,ie notes for 6 strings and
	the fret. 
	The second objective is to then generate different versions of the chord,
	 starting with different route note positions and finally inversions.
	 */
# include "iostream"
using namespace std;

//int a = 0,a_ = 1,b = 2,c = 3,c_ = 4,d = 5, d_ = 6,
//	e = 7,f = 8,f_ = 9,g = 10,g_ = 11;  
// patterns for chord structure, could this be rules???
//#define chord  int ;


enum chord {mjr,mnr,flat7,mjr7,nineth, mjr9};


struct notePosition{
	int val;
	int strng; 
	int fret;
};

int noteValue[150];// e=0 f=1,g=3,a=5,b=7,c=8,d=10
struct notePosition EString[20],AString[20],DString[20],GString[20],BString[20],eString[20];

void initializeNotes();
int* getNoteValuesforChord( chord aChord, char root);

int main(int argc, char const *argv[])
{
	//initialize noteValue and position data ie range of notes on a guitar
	initializeNotes();

	
	//a chord needs a root
	int root;
	char a_root;  // A...Z = 65 ... 90, 97...122 for lower case
	int *NoteValuesForChord;

	cout << "Chord Root ?" << endl;
	cin >> a_root;
	root = 3;// for testing using "G"

	NoteValuesForChord =  getNoteValuesforChord(mjr,root);
	printf("%d \n", NoteValuesForChord[1]);
	return 0;
}

void initializeNotes(){
	for (int i = 0; i < 150; ++i)
	{
		noteValue[i] = i;
	}

	for (int i = 0; i < 19; ++i)
	{
		/* inital the note value struct for each string */
		EString[i].val = noteValue[i];//0,1,3,4,5,6,7,8,etc
		EString[i].strng = 6;
		EString[i].fret  =i;

		AString[i].val = noteValue[i+5];//5,6,7,8,9,10,12...
		AString[i].strng = 5;
		AString[i].fret  =i;

		DString[i].val = noteValue[i+10];//10,11,12,13,14,15...
		DString[i].strng = 4;
		DString[i].fret  =i;

		GString[i].val = noteValue[i+15];//15,16,17,18,19,20,21...
		GString[i].strng = 3;
		GString[i].fret  =i;

		BString[i].val = noteValue[i+19];//19,20,21,22,23,24,25..
		BString[i].strng = 2;
		BString[i].fret  =i;

		eString[i].val = noteValue[i+ 24];//24,25,26,27,28,29,30,31......
		eString[i].strng = 1;
		eString[i].fret  =i;

	}

}

int* getNoteValuesforChord(chord aChord, char root){
	int result[6];
	int values[100];
	switch (aChord){//major,minor,flat7,major7a,nineth, major9
		case mjr: {// 1,5,8  root, root+4, root+7
			int i = root,j=0;
			// first octave
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+4]; j++;
				values[j] = noteValue[i+7]; j++;
			// second octave
				i += 12;
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+4]; j++;
				values[j] = noteValue[i+7]; j++;
			// third octave
				i += 12;
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+4]; j++;
				values[j] = noteValue[i+7]; j++;
			}
			break;
			case mnr: {// 1,5,8  root, root+4, root+7
			int i = root,j=0;
			// first octave
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+3]; j++;
				values[j] = noteValue[i+7]; j++;
			// second octave
				i += 12;
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+3]; j++;
				values[j] = noteValue[i+7]; j++;
			// third octave
				i += 12;
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+3]; j++;
				values[j] = noteValue[i+7]; j++;
			}
			break;
			case flat7: {// 1,5,8  root, root+4, root+7
			int i = root,j=0;
			// first octave
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+4]; j++;
				values[j] = noteValue[i+7]; j++;
				values[j] = noteValue[i+10]; j++;
			// second octave
				i += 12;
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+4]; j++;
				values[j] = noteValue[i+7]; j++;
				values[j] = noteValue[i+10]; j++;
			// third octave
				values[j] = noteValue[i]; j++;
				values[j] = noteValue[i+4]; j++;
				values[j] = noteValue[i+7]; j++;
				values[j] = noteValue[i+10]; j++;
			}
			break;
		}
		return values;
	}
