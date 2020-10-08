#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

// converting string to integer array
//  int* str2int_array(string str){
//    int str_length = str.length();
//    int arr[str_length];
//    for (int i = 0; i < str_length; i++) {
//        arr[i] = str[i]-'0';
//    }
//    return arr;
// }

int main() {
// /* Get a random bitstring from the user
    string line;
    ifstream myfile ("RandomBitString.txt");
    if (myfile.is_open()){
    while ( getline (myfile,line) ){
        cout << line << '\n';
      }
    myfile.close();
    }
    else cout << "Unable to open file";
    int l_str = line.length();

    cout << "bitstring length: " << l_str <<'\n' ;

   int bit_str[l_str];
   for (int i = 0; i < l_str; i++) {
       bit_str[i] = line[i]-'0';
       cout << bit_str[i];
   }
   cout << "\n";
// */
   
    // bool bit_str[l_str]; // bitstring

    // int pBbit_str[100];
    // int* pBbit_str;
    // pBbit_str = str2int_array(line);
    // for (int i=0; i<l_str; i++){
    // cout << pBbit_str[i]<< '\t';
    // // pBbit_str++;
    // }

//     int num = 10;
// cout << &num << endl;
// int *pNum = &num;
// cout << pNum << endl;
// cout << *pNum << endl;

//    cout << "4th: " << randNoInt[4] << endl;


// /* 
    // const int l_str = 256; // bitstring length
    // bool bit_str[l_str]; // bitstring
    // srand((unsigned) time(0));

    int R = 1; // number of runs
    int n_1 = 0; // number of ones
    for (int i = 0; i < l_str; i++) {

        // bit_str[i] = rand() % 2;

        printf("%d ", bit_str[i]);
        if ((i+1) % 64 == 0) {
            printf("\n");
        }

        if(i != 0){
            if(bit_str[i] != bit_str[i-1]){
                R++;
            }
        }
        if(bit_str[i]==1){
            n_1++;
        }
    }
    int n_0 = l_str - n_1; // number of zeros

    cout << "\nNumber of Runs: " << R << endl;
    cout << "Number of ones: " << n_1 << endl;
    cout << "Number of zeros: " << n_0 << endl;


    double mu = 2*n_1*n_0/l_str + 1; // mean
    double var = 2*n_1*n_0*(2*n_1*n_0 - l_str)/(pow(l_str,2)*(l_str-1)); // variance
    double st = sqrt(var);

    double z_ts = (R-mu)/st; // test statistic
    cout << "Test statistics: " << z_ts << endl;

    if(abs(z_ts)>1.96){
        cout << "Alert! Did not pass the run test. No safe wallet.\n";
    }
    else{
        cout << "Passed the run test. Safe to generate keys.\n";
    }
// */
return 0;
}