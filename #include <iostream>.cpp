#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

template <typename Func>
long long time_operation(Func func);
void read_data(vector<string>& vec, list <string>& 1st, set<string>& st, const string& filename);
void sort_data(vector<string>& vec, list<string>& lst, set<string>& st);
void insert_data(vector<string>& vec, list<string>& lst, set<string>& st);
void delete_data(vector<string>& vec, list<string>& lst, set<string>& st);


int main() {
    vector<string> vec;
    list<string> 1st;
    set<string> st;

    string filename= "data.txt";

    //Reading Race
    auto read_time = time_operation([&])() { read_data(vec, 1st, st, filename); };
    
    //sorting race
    auto sort_time_vector = time_operation([&]() { sort(vec.begin(), vec.end()); });
    auto sort_time_list = time_operation([&]() { lst.sort(); });
    int sort_time_set = -1; 

    //inserrtion race
    auto insert_time_vector = time_operation([&]() { insert_data(vec, lst, st); });

    //Deletion race 
    auto delete_time_vector = time_operation([&]() { delete_data(vec, lst, st); });

    // Print results
    cout << " Operation    Vector(ms)  List(ms)  Set(ms)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "    Read      " << read_time << "      " << read_time << "      " << read_time << endl;
    cout << "   Sort       " << sort_time_vector << "       " << sort_time_list << "       " << sort_time_set << endl;
    cout << "  Insert      " << insert_time_vector << "       " << insert_time_vector << "       " << insert_time_vector << endl;
    cout << "  Delete      " << delete_time_vector << "       " << delete_time_vector << "       " << delete_time_vector << endl;


    

    return 0;
}

//Function to measure execuition time 
template <typename Func>
long long time_operation(Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clocl::now();
    return duration_cast <milliseconds>(end - start).count();
}

//Function to read data into the data structures

void read_data(vector<string>& vec, list<string>& 1st, set<string>& st, const string& filename) {
    ifstream file(filename);
    string code;
    while (file >> code) {
        vec.push_back(code);
        lst.push_back(code);
        st.insert(code);

    }
}
//Function to sort data in the vector and in the list 
void sort_data(vector<string>& vec, list<string>& lst, set<string>& st) {
    sort(vec.begin(), vec.end());
    lst.sort();
}

// Function to insert "TESTCODE" in the middle of each data structure
void insert_data(vector<string>& vec, list<string>& lst, set<string>& st) {
    string testValue = "TESTCODE";
    
    // Insert in the middle of vector
    vec.insert(vec.begin() + vec.size() / 2, testValue);

    // Insert in the middle of list
    auto listIt = lst.begin();
    advance(listIt, lst.size() / 2);
    lst.insert(listIt, testValue);

    // Insert in set (does not care about position because it’s ordered)
    st.insert(testValue);
}

// Function to delete the middle element from each data structure
void delete_data(vector<string>& vec, list<string>& lst, set<string>& st) {
    // Delete from middle of vector
    vec.erase(vec.begin() + vec.size() / 2);

    // Delete from middle of list
    auto listIt = lst.begin();
    advance(listIt, lst.size() / 2);
    lst.erase(listIt);

    // Delete from set (remove the TESTCODE)
    st.erase("TESTCODE");
}









/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/