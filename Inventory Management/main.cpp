#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <stdexcept>
#include <nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

class InventoryFilter{

    private:
        json data;
    public:

    void loadData(){
        ifstream file("inventory.json");
        if(!file.is_open()){
            throw runtime_error("Unable to open inventory.json");
        }
        // Read the file 
        file>>data;
    }

    void getMaxMemory(){

        string ans_ip;
        int curr_max=INT_MIN;

        // Iterate and find the item with the maximum storage/memory
        for (auto& item : data["inventory"]){

            string memory = item["memory"];
            // stoi("2GB")   → 2 , it recognises the digit part correctly
            int memoryValue = stoi(memory);

            if(memoryValue>curr_max){
                curr_max=memoryValue;
                ans_ip=item["ip"];
            }
        }

        cout<<ans_ip<<endl;
        cout<<data["inventory"][ans_ip]<<endl;

        return;
    }

    void getMaxCPU(){
        
        string ans_ip;
        double maxVal=0.0;

        for(auto &it : data["inventory"]){

            string cpu=it["cpu"];
            double cpuVal=stod(cpu); // string to double

            if(cpuVal>maxVal){
                maxVal=cpuVal;
                ans_ip=it["ip"];
            }
        }

        cout<<ans_ip<<endl;
        cout<<data["inventory"][ans_ip]<<endl;

        return;
    }

    void getAllWindows(){

        for(auto &it : data["inventory"]){
            if(it["os"]=="Windows"){
                cout<<it["ip"]<<":"<<endl;
                cout<<it<<endl;
                cout<<endl;
            }
        }

        return;
    }

    void getAllLinux(){

        for(auto &it : data["inventory"]){
            if(it["os"]=="Linux"){
                cout<<it["ip"]<<":"<<endl;
                cout<<it<<endl;
                cout<<endl;
            }
        }

        return;
    }
};


int main(){

    InventoryFilter obj;

    try{
        obj.loadData();

        cout<<"Enter the filter parameter: 0 for Memory, 1 for CPU, 2 for Windows and 3 for Linux"<<endl;
        int n;

        if (!(cin >> n)) {
            throw runtime_error("Invalid or missing input");
        }

        if(n==0){
            // get the servers with maximum storage
            obj.getMaxMemory( );
        }
        else if(n==1){
            // get the servers with maximum compute power
            obj.getMaxCPU();
        }
        else if(n==2){
            // get the servers with windows os 
            obj.getAllWindows();
        }
        else if(n==3){
            // get the servers with linux os
            obj.getAllLinux();
        }
        else{
            // Throw an exception if the input is invalid or empty
            throw runtime_error("Input is either invalid or empty");
        }
    }
    catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
    }

    return 0;
}


/*
ifstream variableName("address of the file");
ifstream can read json files, as json is just a txt file

getline(input_stream, string_variable);
The return type of `getline()` is std::istream& returns a reference to the input stream.
Why does this work?
That's why you can write:
while (getline(file, line)) {
    cout << line << endl;
}
`getline()` returns the stream, and the stream can be evaluated as true/false:
true → a line was successfully read
false → EOF or an error occurred

ofstream variableName("address");

 */