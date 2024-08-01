
The age is always represented by exactly two digits in the string.

## Approach

The solution uses string manipulation to extract the age from each detail string and counts how many of these ages are greater than 60.

1. **String Parsing**:
   - Iterate through each detail string in the input list.
   - Extract the age substring from the appropriate position.
   - Convert the age substring to an integer.

2. **Counting Seniors**:
   - Check if the extracted age is greater than 60.
   - Increment the counter if the condition is met.

## Functions

- **countSeniors**: Main function to count the number of seniors given a list of detail strings. It extracts the age from each string and counts the number of senior citizens.

## Edge Cases

- No detail strings in the input list (should return `0`).
- All ages are less than or equal to 60 (should return `0`).
- Mixed ages (should correctly count only those greater than 60).

## Time Complexity

- **Time Complexity**: \(O(N)\), where \(N\) is the number of detail strings. Each string is processed once.

## Space Complexity

- **Space Complexity**: \(O(1)\), as the solution uses a fixed amount of additional space.

## Usage

The `main` function demonstrates how to use the `countSeniors` function. It initializes a list of detail strings, calls the `countSeniors` function, and prints the result.

```cpp
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& x : details) {
            int age = stoi(x.substr(11, 2));
            ans += age > 60;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> details = {
        "JohnDoe:123456:61:otherDetails",
        "JaneDoe:654321:59:otherDetails",
        "AliceSmith:112233:62:otherDetails",
        "BobJohnson:332211:60:otherDetails"
    };
    int seniorCount = solution.countSeniors(details);
    cout << "Number of seniors: " << seniorCount << endl;
    return 0;
}
