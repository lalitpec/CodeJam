#include<stdio.h>
#include<string.h>

//#define INPUTFILE "input.txt"
//#define INPUTFILE "B-small-attempt1.in"
#define INPUTFILE "B-large.in"
#define OUTPUTFILE "output.txt"
//#define INPUTFILE "lazy_loading.txt"
//#define OUTPUTFILE "output_final.txt"
//#define INPUTFILE "progress_pie_example_input.txt"
//#define OUTPUTFILE "progress_pie_example_output.txt"
#define MAXCASES 100
#define MAXLEN 20

int numofcases;
//int numlen[MAXLEN], sortarr[MAXLEN][MAXCASES];// strarr[100][MAXCASES];
//char strarr[MAXLEN][MAXCASES];
int numlen[MAXCASES], sortarr[MAXCASES][MAXLEN];// strarr[100][MAXCASES];
char strarr[MAXCASES][MAXLEN];

static FILE *in;
static FILE *out;

void getinput() {
	int i,j;
	fscanf(in,"%d",&numofcases);

	for(i = 0; i<numofcases; i++) {
		fscanf(in,"%s", &strarr[i]);
		numlen[i] = strlen(strarr[i]);
	}
/*
	for(i = 0; i<numofcases; i++) {
		fscanf(in,"%s", (char*)&strarr[i]);
		numlen[i] = strlen((char*)strarr[i]);
	}
*/
}

void printinput() {
	int i,j;
	printf("numofcases - %d\n",numofcases);
	for (i = 0; i<numofcases; i++) {
		printf("strlen #%d = %d\n", i+1, numlen[i]);
		printf("str = %s\n", strarr[i]);
	}
	for (i = 0; i<numofcases; i++) {
		printf("strlen #%d = %d\n", i+1, numlen[i]);
		printf("intprint = ");
		for (j = 0; j<numlen[i]; j++) {
			printf("%d ", strarr[i][j]);
		}
		printf("\n");
	}
/*
	for(i = 0; i<numofcases; i++) {
		printf("numofitems #%d - %d\n", i + 1,  numofitems[i]);
		for(j = 0; j<numofitems[i]; j++) {
			printf("%d ", weightarr[j][i]);
		}
		printf("\n");
	}
	*/
}
/*
void bucketsort(int curcase) {
	int i,j,count;
	for(i = 0; i<BUCKETSORTRANGE; i++) { //initialize the sort array
		sortarr[i] = 0; }
	for(i = 0; i<numofitems[curcase]; i++) { //fill the bucket
		sortarr[weightarr[i][curcase] - BUCKETSORTLOW]++; 
	}
	
	for(i = 0,count = 0; i<BUCKETSORTRANGE; i++) { // sort the array
		for(j = 0; j<sortarr[i]; j++) {
			if(sortarr[i] > 0) {
				weightarr[count][curcase] = i + BUCKETSORTLOW;
				count++;
			}
		}
	}
}

void tripnumber(int curcase) {
	int numoftrips = 0, i,count = 0;
	float frac;
	count = numofitems[curcase];

	for(i = numofitems[curcase]; i<0; i++) { // get all the cases sorted
		frac = (float)MAXWEIGHT/(float)weightarr[i][curcase]; //ratio of maxweight by maxweight of array
		count++;
		count += (int)frac; //consumed weights are the new highest in the array times smallest 
		numoftrips++;
		if(count<=0)
			break;
	}
	outputarr[curcase] = numoftrips;

}
*/
void printsolution() {
	int i,j;
	for(i = 0; i<numofcases; i++) { // print all the solutions
		printf("Case #%d: ", i+1);
		for (j = 0; j<numlen[i];j++) {
			if(j==0 && sortarr[i][j] == 0)
				continue;
			printf("%d", sortarr[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i<numofcases; i++) { // print all the solutions
		fprintf(out,"Case #%d: ", i+1);
		for (j = 0; j<numlen[i];j++) {
			if(j==0 && sortarr[i][j] == 0)
				continue;
			fprintf(out,"%d", sortarr[i][j]);
		}
		fprintf(out,"\n");
	}

//		fprintf(out,"Case #%d: %d\n", i+1, outputarr[i]);
//		fprintf(out,"Case #%d: %d\n", i+1, outputarr[i]);
	
}

void fillwithnines(int curcase, int curpos) {
//printf("inside fillwithnine, curcase = %d,curpos = %d\n",curcase,curpos);
	int i;
	for (i = 0; i<numlen[curcase] - curpos; i++) {
		sortarr[curcase][i+curpos] = 9;
	}
}

void sortout(int curcase) {
//printf ("inside sortout, curcase = %d, numlen = %d\n",curcase, numlen[curcase]);
	int i, prev, start;
	if (numlen[curcase] == 1) {
		sortarr[curcase][0] = strarr[curcase][0] - 48;
//		printf("ended bec length 1\n");
		return;
	}

	for(prev=0,i=1, start=0; i<numlen[curcase];i++,prev++) {
//		printf("in for loop\n");
//		printf("case1, prev = %d, i = %d, prev value = %d, i value = %d\n",prev, i, strarr[curcase][prev], strarr[curcase][i]);
		if(strarr[curcase][prev] > strarr[curcase][i]){
//			printf("case1, prev = %d, i = %d, prev value = %d, i value = %d\n",prev, i, strarr[curcase][prev], strarr[curcase][i]);
			sortarr[curcase][start] = strarr[curcase][prev] - 49;
			fillwithnines(curcase,start+1);
			return;
		}
		else if(strarr[curcase][prev] < strarr[curcase][i]){
			sortarr[curcase][prev] = strarr[curcase][prev] - 48;
			start = i;
		}
		else if(strarr[curcase][prev] == strarr[curcase][i]){
			sortarr[curcase][prev] = strarr[curcase][prev] - 48;
		}
	}
	sortarr[curcase][numlen[curcase]-1] = strarr[curcase][numlen[curcase]-1] - 48;
}

void getsolution() {
	int i;

	for(i = 0; i<numofcases; i++) { // get all the cases sorted
		sortout(i);
	}
/*
	for (i = 0; i<numofcases; i++) { // fill the solution array
		tripnumber(i);
	}
*/
}

int main() {
	in = fopen(INPUTFILE, "r");
	out = fopen(OUTPUTFILE, "w");
	getinput();
//	printinput();
	getsolution();
//	printinput();
	printsolution();
	return 0;
}

