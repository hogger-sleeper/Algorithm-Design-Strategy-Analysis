#include <iostream>
using namespace std;

const int N = 4; // Size of the set
int set[N] = {3, 1, 2, 5};
int target = 6;

void sumOfSubsets(int index, int currSum, string subset)
{
    // Base Case: If current sum matches target
    if (currSum == target)
    {
        cout << "Subset: " << subset << endl;
        return;
    }

    // If index is out of bounds or current sum exceeds target
    if (index == N || currSum > target)
        return;

    // Include current element
    sumOfSubsets(index + 1, currSum + set[index], subset + to_string(set[index]) + " ");

    // Exclude current element
    sumOfSubsets(index + 1, currSum, subset);
}

int main()
{
    cout << "Subsets with sum = " << target << ":\n";
    sumOfSubsets(0, 0, "");
    return 0;
}
/*#include <iostream>
using namespace std;
const int N = 4, target = 9;
int set[N] = {3, 34, 4, 12};
void subsetSum(int i, int sum) {
if (sum == target) {
cout << "Found a subset\n";
return;
}
if (i == N || sum > target) return;
subsetSum(i + 1, sum + set[i]); // include set[i]
subsetSum(i + 1, sum); // exclude set[i]
}
int main() {
subsetSum(0, 0);
return 0;
}2*/