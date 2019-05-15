#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class CSVRow
{
    private:
        vector<string>    m_data;  // to maintain data of cell
    public:
        string operator[](size_t index) // http://www.cplusplus.com/reference/string/string/operator[]
        {
            return m_data[index];
        }
        size_t size()  // size_t data type-> used to represent size of objects or variable in bytes
        {
            return m_data.size();
        }
        void readNextRow(istream& str)  // to read the rows and using stringstream to break them in individual cells and push into m_data
        {
            string line;
            getline(str, line);

            stringstream   lineStream(line);
            string         cell;

            m_data.clear();
            while(getline(lineStream, cell, ','))
            {
                m_data.push_back(cell);
            }
            // This checks for a trailing comma with no data after it.
            if (!lineStream && cell.empty())
            {
                // If there was a trailing comma then add an empty element.
                m_data.push_back("");
            }
        }

};

istream& operator>>(istream& str, CSVRow& data) // operator overloading inorder to read data using Csvrow object and which returns string.
{
    data.readNextRow(str);
    return str;
}


int main(int argc, char* argv[])
{
    // argc = number of arguments including program name.
    //argv  = all the arguments in char* array.

    int t,time;
    t = atoi(argv[1]);  // ascii to integer
    time = t;


    map<string,int> argList;  // maintaing frequency of filenames recorded from arguments
    int file_count = 0;
    for(int i=0;i<argc-2;i++){
        ++argList[argv[i+2]];
        file_count++;
    }

    map<string,int>::iterator itr = argList.begin();
    int count = itr->second;
       cout<<"Unique_Identifiers "<<"Time Stamp       "<<" Price"<<endl;

    CSVRow row;     // object of CSVRow

    for(int i=0;i<file_count;i++){   // runs for unique number of files given in argument

    ifstream  file(itr->first);      // opens the file to read.

     t = t*itr->second;              // how many times to read from one file which is opened
    while(file >> row && t > 0)      // reads for time interval given by user
    {
        if(row[0]=="ETH-AUD" || row[0]=="unique_identifier")  // reads data with unique_identifiers ZEC-AUD, LTC-AUD and BTC-AUD only
            continue;

        cout <<row[0]<<"            "<<row[1]<<"  "<<row[2]<<endl;
        t--;
    }
    t = time;
    itr++;
    }
}
