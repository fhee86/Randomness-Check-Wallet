#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <random>

using namespace std;

int main() {
// /* Get a random bitstring as an input.txt from the user
    string line;
    ifstream myfile ("RandomBitString.txt");
    if (myfile.is_open()){
    while ( getline (myfile,line) ){
        // cout << line << '\n';
      }
    myfile.close();
    }
    else cout << "Unable to open file";
    int l_str = line.length();

    cout << "bitstring length: " << l_str <<'\n' ;

   int bit_str[l_str];
   for (int i = 0; i < l_str; i++) {
       bit_str[i] = line[i]-'0';
    //    cout << bit_str[i];
   }
   cout << "\n";
// */

int w_cnt = 0;
int loop_cnt = 0;
// while (w_cnt == 0) {
    // Pseudorandom Number Generation
    // const int l_str = 256; // bitstring length
    // bool bit_str[l_str]; // bitstring
    
    // srand((unsigned) time(0)); // Ordinary PRNG
    
    // Cryptographically Secure Pseudorandom Number Generator (CSPRNG)
    // uniform_int_distribution<int> d(0, 1); // CSPRNG
    // random_device rd2("/dev/random"); // CSPRNG, much slower on Linux

    int R = 1; // number of runs
    int n_1 = 0; // number of ones
    for (int i = 0; i < l_str; i++) {

        // bit_str[i] = rand() % 2; // Ordinary PRNG
        // bit_str[i] = d(rd2); // CSPRNG 

        printf("%d", bit_str[i]);
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

    // cout << "\nNumber of Runs: " << R << endl;
    // cout << "Number of ones: " << n_1 << endl;
    // cout << "Number of zeros: " << n_0 << endl;

    double mu = 2*n_1*n_0/l_str + 1; // mean
    double var = 2*n_1*n_0*(2*n_1*n_0 - l_str)/(pow(l_str,2)*(l_str-1)); // variance
    double st = sqrt(var);

    double z_ts = (R-mu)/st; // test statistic
    // cout << "Test statistics: " << z_ts << endl;

    if(abs(z_ts)>1.96){
        cout << "\nAlert! Did not pass the statistical test. Not safe to generate the keys.\n";
        w_cnt = 0;
    }
    else{
        cout << "\nPassed the statistical test. Generate the keys. \n";
        w_cnt = 1;
    }
    loop_cnt++;
// }
cout << '\n' << loop_cnt << endl;

return 0;
}