#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class SortVisualizer {
public:
    // Visualizes the array as bars [cite: 24]
    void display(const vector<int>& arr, int active1 = -1, int active2 = -1) {
        system("clear"); // Use "cls" for Windows
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << "\t";
            for (int j = 0; j < arr[i]; j++) {
                if (i == active1 || i == active2) cout << "█"; 
                else cout << "░";
            }
            cout << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(150));
    }

    // Bubble Sort with performance monitoring [cite: 25]
    void bubbleSort(vector<int> arr) {
        auto start = chrono::high_resolution_clock::now();
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                display(arr, j, j + 1);
                if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            }
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "\nTime Complexity: O(n^2) | Execution Time: " << elapsed.count() << "s" << endl;
    }
};

int main() {
    SortVisualizer visualizer;
    vector<int> data = {5, 12, 8, 3, 10, 6};
    visualizer.bubbleSort(data);
    return 0;
}
