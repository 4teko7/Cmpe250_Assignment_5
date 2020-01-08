/*
Student Name: Bilal
Student Number: 2017400264
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
using namespace std;
void parseInput(ifstream& inFile, long long int &  N, long long int &  M,  vector <long long int> & prices);
void sort(vector<long long int> & prices, vector<long long int> & pricesSorted);
void calculate(ofstream & outFile, vector<long long int> & pricesSorted, long long int & N, long long int & M);
int main(int argc, char* argv[]){

    if (argc != 3) {
        // cerr should be used for errors
        cerr << "Run the code with the following command: ./cmpe250-assignment4 [input_file] [output_file]" << endl;
        return 1;
    }

    // Open the input and output files, check for failures
    ifstream inFile(argv[1]);
    if (!inFile) { // operator! is synonymous to .fail(), checking if there was a failure
        cerr << "There was a problem opening \"" << argv[1] << "\" as input file" << endl;
        return 1;
    }

    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "There was a problem opening \"" << argv[2] << "\" as output file" << endl;
        return 1;
    }
    long long int N,M;
    vector<long long int> prices(200001,0);
    vector<long long int> pricesSorted;
    parseInput(inFile, N, M, prices);
    sort(prices,pricesSorted);
    calculate(outFile,pricesSorted,N,M);
    outFile.close();
    return 0;
}


void calculate(ofstream & outFile, vector<long long int> & pricesSorted, long long int & N, long long int & M){
    long long int count = 0;
    if(N > 0)
    outFile << pricesSorted[0] << " ";
    for(long long int i = 1; i < N; i++){
      if(i > M){
          pricesSorted[i] += pricesSorted[i-1] - pricesSorted[count-1] + pricesSorted[count++] ;
      }else if (i == M){
          pricesSorted[i] += pricesSorted[i-1] + pricesSorted[count++];
      }else
        pricesSorted[i] += pricesSorted[i-1];

      outFile << pricesSorted[i] << " ";
    }

}


void sort(vector<long long int> & prices, vector<long long int> & pricesSorted){
    long long int count = 0;
    for(long long int i = 0; i < prices.size(); i++){
        if(prices[i] == 0) continue;

        pricesSorted.push_back(i);
        prices[i]--;
        i--;
        continue;

    }

}
void parseInput(ifstream& inFile, long long int &  N, long long int &  M,  vector <long long int> & prices){
    string line, tmp;
    getline(inFile, line);
    istringstream linestream(line);
    getline(linestream, tmp, ' ');
    N = stoi(tmp);
    getline(linestream, tmp, ' ');
    M = stoi(tmp);
    long long int temp;
    for(long long int i = 0; i < N; i++){
        inFile >> temp;
        prices[temp]++;
    }
    }