#include <iostream>
#include <vector>
using namespace std;

vector<int> computeSuffixSums(const vector<int>& arr) {
    int n = arr.size();
    vector<int> suffixSums(n);
    
    // Start from the last element
    suffixSums[n - 1] = arr[n - 1];
    
    // Build suffix sums array
    for (int i = n - 2; i >= 0; --i) {
        suffixSums[i] = arr[i] + suffixSums[i + 1];
    }
    
    return suffixSums;
}

int main() {
    // Example input
    vector<int> arr = {1, 2, 3, 4, 5};
    
    // Compute suffix sums
    vector<int> suffixSums = computeSuffixSums(arr);
    
    // Output the result
    cout << "Suffix sums: ";
    for (int sum : suffixSums) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}
