class Solution {
  public:
    string minSum(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    string num1 = "", num2 = "";
    
    // Distribute digits alternatively
    for(int i = 0; i < arr.size(); i++){
        if(i % 2 == 0) num1 += to_string(arr[i]);
        else num2 += to_string(arr[i]);
    }
    
    // Now we add num1 and num2 as strings
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string result = "";
    
    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0) sum += num1[i--] - '0';
        if(j >= 0) sum += num2[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    
    reverse(result.begin(), result.end());
    
    // Remove leading zeros
    int k = 0;
    while(k < result.size() - 1 && result[k] == '0') k++;
    
    return result.substr(k);
}

};