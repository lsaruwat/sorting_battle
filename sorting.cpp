#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getRandomVector(vector<int> *vect1){
	for(int i=0; i<20; i++){
		vect1->push_back( rand()% 100); //random from 0-99
	}
}

int radix(vector<int> *vect1){
	int place = 1;
	int mod = 10*place;
	int divide = 1*place;

	vector<int> buckets[10];// array of 10 elements of type vector of ints


	for(int i=0; i<vect1->size(); i++){
		int bucketIndex = ( (*vect1)[i] % mod) / divide;
		buckets[bucketIndex].push_back( (*vect1)[i]);
	}

	for(int i=0; i<10; i++){
		for(int j=0; j<buckets[i].size(); j++){
			if(buckets[i][j] != buckets[i].back() ) cout << buckets[i][j] << endl;
		}
	}

}

int main(int argc, char *argv[]){
	vector<int> vect1;
	getRandomVector(&vect1);

	radix(&vect1);

	return 0;
}