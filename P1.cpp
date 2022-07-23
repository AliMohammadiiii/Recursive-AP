#include <iostream>
#include <vector>

using namespace std;

int find_max_height_index(vector<int> heights, int start_index, int end_index) {
    if (start_index == end_index)
        return start_index;

    int middle_index = (start_index + end_index) / 2;
    int left_half_max_index = find_max_height_index(heights, start_index, middle_index);
    int right_half_max_index = find_max_height_index(heights, middle_index + 1, end_index);

    if(heights[right_half_max_index] > heights[left_half_max_index])
        return right_half_max_index;
    else  
        return left_half_max_index;
}

int find_max_height_index(vector<int> heights) {
    return find_max_height_index(heights, 0, heights.size() - 1);
}

vector<int> get_heigts() {
    vector<int> heights;
    int n, temp_height;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp_height;
        heights.push_back(temp_height);
    }

    return heights;
}

int main() {
    vector<int> heights = get_heigts();

    cout << find_max_height_index(heights) + 1;
}