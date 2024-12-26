//Ques1
#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(int k, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findFirstOccurrence(k, arr);
    return 0;
}
//Ques 2
#include <iostream>
#include <vector>
using namespace std;

bool isPresent(int k, vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            return true;
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << (isPresent(k, arr) ? "true" : "false");
    return 0;
}
//Ques3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> indices;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = targetIndices(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
//Ques4
#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << searchInsert(nums, target);
    return 0;
}
//Ques5
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> order;
    for (int i = 0; i < arr2.size(); i++) {
        order[arr2[i]] = i;
    }
    sort(arr1.begin(), arr1.end(), [&](int a, int b) {
        if (order.count(a) && order.count(b)) {
            return order[a] < order[b];
        } else if (order.count(a)) {
            return true;
        } else if (order.count(b)) {
            return false;
        } else {
            return a < b;
        }
    });
    return arr1;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    vector<int> result = relativeSortArray(arr1, arr2);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
//Ques6
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int moves = 0;
    for (int i = 0; i < seats.size(); i++) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> seats(n), students(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }
    cout << minMovesToSeat(seats, students) << endl;
    return 0;
}
//Ques7
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = sortedSquares(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
//Ques8
#include <iostream>
#include <vector>
using namespace std;

vector<int> findCommonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int i = 0, j = 0, k = 0;
    vector<int> result;
    
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++; j++; k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    
    if (result.empty()) {
        result.push_back(-1);
    }
    return result;
}

int main() {
    int n1, n2, n3;
    
    cout << "Enter the size of the first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter the size of the second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    cout << "Enter the size of the third array: ";
    cin >> n3;
    vector<int> arr3(n3);
    cout << "Enter the elements of the third array: ";
    for (int i = 0; i < n3; i++) {
        cin >> arr3[i];
    }

    vector<int> result = findCommonElements(arr1, arr2, arr3);
    
    if (result[0] == -1) {
        cout << -1 << endl;
    } else {
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
//Ques9
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> odd, even;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            even.push_back(nums[i]);
        } else {
            odd.push_back(nums[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());
    
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            nums[i] = even[evenIndex++];
        } else {
            nums[i] = odd[oddIndex++];
        }
    }
    
    return nums;
}

int main() {
    vector<int> nums = {4, 1, 2, 3};
    vector<int> result = rearrangeArray(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
//Ques10
#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(const vector<long long>& v, long long X) {
    int low = 0, high = v.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == X) {
            res = mid;
            high = mid - 1;
        } else if (v[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int lastOccurrence(const vector<long long>& v, long long X) {
    int low = 0, high = v.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == X) {
            res = mid;
            low = mid + 1;
        } else if (v[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

vector<int> findFirstAndLastOccurrence(vector<long long>& v, long long X) {
    int first = firstOccurrence(v, X);
    int last = lastOccurrence(v, X);
    return {first, last};
}

int main() {
    int N;
    cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    long long X;
    cin >> X;
    
    vector<int> result = findFirstAndLastOccurrence(v, X);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
//Ques11
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = matrix[mid / n][mid % n];

        if (midVal == target) {
            return true;
        } else if (midVal < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;

    target = 13;
    cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
//Ques12
#include <iostream>
#include <vector>
using namespace std;

int findFirstPosition(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int findLastPosition(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    result[0] = findFirstPosition(nums, target);
    if (result[0] != -1) {
        result[1] = findLastPosition(nums, target);
    }
    return result;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    target = 6;
    result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    nums = {};
    target = 0;
    result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
//Ques13
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return nums[left];
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "The minimum element is: " << findMin(nums) << endl;
    
    return 0;
}
//Ques14
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestMissingPositive(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The smallest missing positive number is: " << smallestMissingPositive(arr) << endl;
    
    return 0;
}
//Ques15
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int closestToZero(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    
    int left = 0, right = n - 1;
    int closestSum = arr[left] + arr[right];
    
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        
        if (abs(currentSum) < abs(closestSum) || (abs(currentSum) == abs(closestSum) && currentSum > closestSum)) {
            closestSum = currentSum;
        }
        
        if (currentSum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    return closestSum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The maximum sum closest to zero is: " << closestToZero(arr, n) << endl;
    
    return 0;
}
//Ques16
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> topologicalSort(const unordered_map<int, vector<int>>& graph, vector<int>& inDegree, int totalNodes) {
    queue<int> q;
    vector<int> order;
    
    for (int i = 0; i < totalNodes; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        
        for (int neighbor : graph.at(node)) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return (order.size() == totalNodes) ? order : vector<int>();
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    unordered_map<int, vector<int>> itemGraph, groupGraph;
    vector<int> itemInDegree(n, 0), groupInDegree(m, 0);
    unordered_map<int, vector<int>> groupToItems;
    
    for (int i = 0; i < n; ++i) {
        groupToItems[group[i]].push_back(i);
        for (int before : beforeItems[i]) {
            itemGraph[before].push_back(i);
            itemInDegree[i]++;
            
            if (group[i] != group[before]) {
                groupGraph[group[before]].push_back(group[i]);
                groupInDegree[group[i]]++;
            }
        }
    }
    
    vector<int> itemOrder = topologicalSort(itemGraph, itemInDegree, n);
    if (itemOrder.empty()) return {};
    
    vector<int> groupOrder = topologicalSort(groupGraph, groupInDegree, m);
    if (groupOrder.empty()) return {};
    
    unordered_map<int, vector<int>> orderedGroupItems;
    for (int item : itemOrder) {
        orderedGroupItems[group[item]].push_back(item);
    }
    
    vector<int> result;
    for (int g : groupOrder) {
        result.insert(result.end(), orderedGroupItems[g].begin(), orderedGroupItems[g].end());
    }
    
    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of items (n): ";
    cin >> n;
    cout << "Enter the number of groups (m): ";
    cin >> m;

    vector<int> group(n);
    cout << "Enter the group array: ";
    for (int i = 0; i < n; ++i) {
        cin >> group[i];
    }

    vector<vector<int>> beforeItems(n);
    cout << "Enter the beforeItems array (one list per line):\n";
    for (int i = 0; i < n; ++i) {
        int count;
        cout << "Number of dependencies for item " << i << ": ";
        cin >> count;
        beforeItems[i].resize(count);
        for (int j = 0; j < count; ++j) {
            cin >> beforeItems[i][j];
        }
    }

    vector<int> result = sortItems(n, m, group, beforeItems);
    if (result.empty()) {
        cout << "Result: []\n";
    } else {
        cout << "Result: ";
        for (int item : result) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
//Quess17
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int kthSmallestSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
    set<vector<int>> visited;
    vector<int> indices(m, 0);
    int initialSum = 0;
    for (int i = 0; i < m; ++i) {
        initialSum += mat[i][0];
    }
    pq.push({initialSum, indices});
    visited.insert(indices);

    while (!pq.empty() && k--) {
        auto [sum, currIndices] = pq.top();
        pq.pop();
        if (k == 0) return sum;
        for (int i = 0; i < m; ++i) {
            if (currIndices[i] + 1 < n) {
                vector<int> newIndices = currIndices;
                newIndices[i]++;
                int newSum = sum - mat[i][currIndices[i]] + mat[i][newIndices[i]];
                if (visited.insert(newIndices).second) {
                    pq.push({newSum, newIndices});
                }
            }
        }
    }
    return -1;
}

int main() {
    int m, n, k;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    cin >> k;
    cout << kthSmallestSum(mat, k) << endl;
    return 0;
}
//Ques18
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for (auto list : lists) {
        if (list) {
            pq.push(list);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        current->next = node;
        current = current->next;
        if (node->next) {
            pq.push(node->next);
        }
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    vector<ListNode*> lists(k);
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }
        lists[i] = dummy->next;
    }

    ListNode* result = mergeKLists(lists);
    printList(result);

    return 0;
}
//Ques19
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    vector<int> maxLeft(n), minRight(n);
    
    maxLeft[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        maxLeft[i] = max(maxLeft[i - 1], arr[i]);
    }
    
    minRight[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minRight[i] = min(minRight[i + 1], arr[i]);
    }
    
    int chunks = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (maxLeft[i] <= minRight[i + 1]) {
            ++chunks;
        }
    }
    
    return chunks;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << maxChunksToSorted(arr) << endl;
    return 0;
}
//Ques20
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0, maxVal = 0;
    for (int i = 0; i < arr.size(); ++i) {
        maxVal = max(maxVal, arr[i]);
        if (maxVal == i) {
            ++chunks;
        }
    }
    return chunks;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << maxChunksToSorted(arr) << endl;
    return 0;
}
