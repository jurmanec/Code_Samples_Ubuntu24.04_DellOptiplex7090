#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

void printNums(const vector<int> &nums) {
    for (auto i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";    
    }
    cout << endl;
}

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    vector<int> nums = {1, 2, 3};
    cout << nums[0] << endl;
    cout << nums[1] << endl;
    cout << nums[2] << endl;
    
    // unlike an array, the vector type is dynamic. 
    nums[3] = 4;
    cout << nums[3] << endl;
    cout << nums[0] <<", "<< nums[nums.size()-1]<<endl; 
    printNums(nums);

    nums.push_back(4);
    printNums(nums);
    nums.pop_back();
    printNums(nums);
}