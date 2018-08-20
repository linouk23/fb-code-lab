vector<int> Solution::stepnum(int A, int B) {
    unordered_map<int, vector<int>> neighbours = {
        {0, {1}},
        {9, {8}}
    };
    for (int digit = 1; digit <= 8; ++digit) {
        neighbours[digit] = { digit - 1, digit + 1 };
    }
    
    queue<int> possibleSteppingNumbersQueue;
    for (int digit = 0; digit <= 9; ++digit) {
        possibleSteppingNumbersQueue.push(digit);
    }
    
    auto isWithinRange = [&](int possibleSteppingNumber) -> bool {
            return A <= possibleSteppingNumber && 
                   B >= possibleSteppingNumber;
    };
    
    vector<int> steppingNumbers;
    while (!possibleSteppingNumbersQueue.empty()) {
        int possibleSteppingNumber = possibleSteppingNumbersQueue.front();
        possibleSteppingNumbersQueue.pop();
        if (isWithinRange(possibleSteppingNumber)) {
            steppingNumbers.emplace_back(possibleSteppingNumber);
        }
        bool shouldContinue = (possibleSteppingNumber == 0 || possibleSteppingNumber > B);
        if (shouldContinue) { continue; }
        int lastDigit = possibleSteppingNumber % 10;
        for (int neighbour : neighbours[lastDigit]) {
            possibleSteppingNumbersQueue.push(10 * possibleSteppingNumber + neighbour);
        }
    }
    return steppingNumbers;
}
