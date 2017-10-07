/* Jack O'Toole Sep 2017
	Program to generate guitar chords,ie notes for 6 strings and
	the fret. 
	The second objective is to then generate different versions of the chord,
	 starting with different route note positions and finally inversions.
*/
# include "iostream"
#include <cstdlib>
#include <string>

using namespace std;

//int a = 0,a_ = 1,b = 2,c = 3,c_ = 4,d = 5, d_ = 6,
//	e = 7,f = 8,f_ = 9,g = 10,g_ = 11;  
// patterns for chord structure, could this be rules???
//#define chord  int ;


enum chord {mjr,mnr,flat7,mjr7,nineth, mjr9};
//enum strings {first,second,third,fourth,fifth,sixth};


struct notePosition{
	int val;
	int strng; 
	int fret;
};

//global variables
int noteValue[150];// e=0 f=1,g=3,a=5,b=7,c=8,d=10
struct notePosition EString[20],AString[20],DString[20],GString[20],BString[20],eString[20];

//functions
int  aToNoteValue(char c);
void displayNotePositions(notePosition *notes);
void initializeNotes();
int* getNoteValuesforChord( chord aChord, char root);
void getChordValues(int *values,notePosition *notepositions);

//notePosition* getChord(int *values);

//----------------------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
	//initialize noteValue and position data ie range of notes on a guitar
	initializeNotes();

	
	//a chord needs a root
	int root;
	char a_root;  // A...Z = 65 ... 90, 97...122 for lower case
	int *NoteValuesForChord;
    notePosition notepositions[50];

	cout << "Chord Root ?" << endl;
	cin >> a_root;
	a_root = tolower(a_root);
	root = aToNoteValue(a_root);// for testing using "G"

	NoteValuesForChord =  getNoteValuesforChord(mjr,root);
	printf("%lu \n",sizeof(NoteValuesForChord) );
	for (int i = 0; i < 10; ++i)
	{
		printf("%d, ", NoteValuesForChord[i]);	/* code */
	}

	 getChordValues(NoteValuesForChord,notepositions);
	/*{int i = 0;
		while (notepositions[i].val != 0){
			printf("String %d, Fret %d \n", notepositions[i].strng,notepositions[i].fret);
			i++;
		} 
	}
	 */
	for (int i = 0; i < 50; ++i)
	{
		printf("String %d, Fret %d \n", notepositions[i].strng,notepositions[i].fret);/* code */
	}

	 displayNotePositions(notepositions);
	
	
	
	return 0;
}
//----------------------------------------------------------------------------------------------
int aToNoteValue(char c){
	// convert a keyboard character to a note vale
	// a97,b98,c99,d100,e101
	int i = c;
	switch (i){
		case 97 : return 5;//  a 
		case 98 : return 7;//  b
		case 99 : return 8;//  c
		case 100: return 10;// d
		case 101: return 0;//  e
		case 102: return 1;//  f
		case 103: return 3;//  g
		default:  return 0;
	}
}
//----------------------------------------------------------------------------------------------
notePosition* getChord(int *values){
	// first position chord
	static notePosition *chord;
	//notePosition root;
	// root e string  eg "a root" = 5,9,12,17,21,24,29,33,36,0
	for (int i = 0; i < 20; ++i)
	{
		/* code */
		if (eString[i].val == values[0]) {
			// found root position estring[i]
			chord[0]= eString[i];
		}
	}
	for (int i = 0; i < sizeof(values); ++i)
	{
		/* check against the other strings for the other notes in the chord,
		    within 3 frets. */
		for (int j = 0; j < chord[0].fret+3; ++j)
		{
			//if(AString.val == values[j])
		}
	}
	return chord;
}
//----------------------------------------------------------------------------------------------
void displayNotePositions(notePosition *notes){
	
	string str[6];
    for (int j = 0; j < 6; ++j){
    	for (int i = 0; i < 3*25; ++i){
	    	str[j].append("-");
		}
    }  // six strings filled with dashes "-"

	for (int i = 0; i < 6; ++i)
	{
		printf("%s\n", str[i].c_str());
	}

		
	{	
		int a_str,fret;
		int i= 0;
		
		
		while((notes[i].val!=0) && (i < 50)){
			a_str  = notes[i].strng-1;//change string to zero base array ref
			fret = notes[i].fret;
			string temp = to_string(fret);
			// replace "-" with temp, tricky
			int pos = fret*3;
			int len = temp.length();
			printf("string temp =  %s \n", temp.c_str());
			str[a_str].replace(pos,len,temp);
			i++;
		}
	}

	for (int i = 0; i <6; ++i)
	{
		printf("%s\n", str[i].c_str());
	}
	
}
//----------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------
void getChordValues(int *values, notePosition *notepositions){
	// values are the notes available to make a chord, now retrieve
	// a set of corresponding notepositions
	//static notePosition result[50];
	int count = 0;
	for(int i = 0;i < sizeof(values); i++){
		//6th string
		for (int j = 0; j < 20; ++j){// for each string
		/* find a string position matching the value */
			if (EString[j].val == values[i]) {
			notepositions[count] = EString[j];
			count++;
			}
		
			if (AString[j].val == values[i]) {
			notepositions[count] = AString[j];
			count++;
			}
		
			if (DString[j].val == values[i]) {
			notepositions[count] = DString[j];
			count++;
			}
		
			if (GString[j].val == values[i]) {
			notepositions[count] = GString[j];
			count++;
			}
		
			if (BString[j].val == values[i]) {
			notepositions[count] = BString[j];
			count++;
			}
		
			if (eString[j].val == values[i]) {
			notepositions[count] = eString[j];
			count++;
			}
		}
		
	}
	printf("count = %i \n",count );
	printf("sizeof(notepositions) = %lu \n",sizeof(notepositions));
	//return result;
}
//----------------------------------------------------------------------------------------------
int* getNoteValuesforChord(chord aChord, char root){
	int result[6];
	static int values[100];
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
			default:;
		}
		return values;
	}
//----------------------------------------------------------------------------------------------