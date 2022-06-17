#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

std::vector<int> v;

int half;
int w=0;
//class for storing points and their distances
class Coor{
public:
int x=0;
int y=0;
float result=0;
};
//function for sorting
bool compare(Coor& first, Coor& second)
{
    cout<<"comparing"<<first.result<<"and"<<second.result;
    return first.result>second.result;
}

int main()
{

    //Taking input from file and storing it in vector
    string filename("input.txt");
    int number;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    while (input_file >> number) {

    v.push_back(number);

}

    half=v.size()/2;
    int k,a,b;
    Coor arrayOfObjects[half];
    int z=0;

    ofstream fout;
    fout.open("output.txt");

    for(int i=0;i<=half-1;i++)
    {
        k=2*i;

        a=(v[k])*(v[k]);
        b=(v[k+1])*(v[k+1]);
        Coor arrayOfObjects[i];

        //storing values inside the objects
        arrayOfObjects[i].x=v[k];
        arrayOfObjects[i].y=v[k+1];
        arrayOfObjects[i].result=sqrt(a+b);

        //Writing inside the file
        fout<<v[k]<<" "<<v[k+1]<<" "<<sqrt(a+b)<<endl;
        w++;
            //code for sorting
//         if(i==half-1)
//     std::sort (arrayOfObjects, arrayOfObjects+half,compare);

        //print all the objects
        cout<<arrayOfObjects[i].x<<"\n";
        cout<<arrayOfObjects[i].y<<endl;
        cout<<arrayOfObjects[i].result<<endl;

    }

        fout.close();

    cout << endl;
    input_file.close();

    return EXIT_SUCCESS;
}

