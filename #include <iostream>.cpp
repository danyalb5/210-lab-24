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
    set<string> st;
    string filename= "data.txt";

    // Reading race
    auto read_time = time_operation([&]() { read_data(st, filename); });

    // Sorting race (sets are already sorted)
    int sort_time_set = -1; // Sorting not needed, so we don't measure time

    // Insertion race
    auto insert_time_set = time_operation([&]() { insert_data(st); });

    // Deletion race
    auto delete_time_set = time_operation([&]() { delete_data(st); });

    // Print results
    cout << " Operation    Set(ms)" << endl;
    cout << "------------------------" << endl;
    cout << "    Read      " << read_time << endl;
    cout << "   Sort       " << sort_time_set << endl;
    cout << "  Insert      " << insert_time_set << endl;
    cout << "  Delete      " << delete_time_set << endl;

    return 0;
}

// Function to measure execution time
template <typename Func>
long long time_operation(Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

// Function to read data into the set
void read_data(set<string>& st, const string& filename) {
    ifstream file(filename);
    string code;
    while (file >> code) {
        st.insert(code);
    }
}

// Function to insert "TESTCODE" into the set
void insert_data(set<string>& st) {
    string testValue = "TESTCODE";
    st.insert(testValue); // Inserts in set, automatically positioned
}

// Function to delete "TESTCODE" from the set
void delete_data(set<string>& st) {
    st.erase("TESTCODE");
}









/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/