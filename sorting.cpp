#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

const uint N = 1000000;
const uint MaxNum = 1000;

void getRandomVector(vector<int> *vect1){
	for(int i=0; i<N; i++){
		vect1->push_back( rand()% MaxNum); //random from 0-99
	}
}

int getMaxDigits(vector<int> *vect1){
	int max = 0;
	int maxDigits = 0;
	for(int i=0; i<vect1->size(); i++){
		if(max < (*vect1)[i]) max = (*vect1)[i];
	}

	while(max >= 9){
		max /=10;
		maxDigits++;
	}

	return maxDigits;
}

void printList(vector<int> buckets[]){
	for(int i=0; i<10; i++){
		for(int j=0; j<buckets[i].size(); j++){
			 cout << buckets[i][j] << endl;
		}
	}
	cout << endl;
}

int radix(vector<int> *vect1, int maxDigits){
	int place = 1;
	int mod = 10*place;
	int divide = 1*place;


	for(int i=0; i<maxDigits; i++){
		vector<int> buckets[10];// array of 10 elements of type vector of ints
		for(int j=0; j<vect1->size(); j++){
			int bucketIndex = ( (*vect1)[j] % mod) / divide;
			buckets[bucketIndex].push_back( (*vect1)[j] );
		}

		vect1->clear();
		
		for(int j=0; j<10; j++){
			for(int k=0; k<buckets[j].size(); k++){
				vect1->push_back( buckets[j][k] );
			}
			
		}

		place*=10;
		mod = 10*place;
		divide = 1*place;
		//printList(buckets);
	}
}

int main(int argc, char *argv[]){
	vector<int> vect1;
	clock_t t;
	
	getRandomVector(&vect1);
	int maxDigits = getMaxDigits(&vect1);
	
	//Time the radix sort 
	t = clock();
	radix(&vect1, maxDigits);
	t = clock() - t;
	cout << t << endl;

	getRandomVector(&vect1);

	//Time the std::sort
	t = clock();
	sort(vect1.begin(), vect1.end());
	t = clock() - t;
	cout << t << endl;

	return 0;
}