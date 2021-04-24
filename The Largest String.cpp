string getLargestString(string s, int k) {
// vector containing frequency
    // of each character.
    vector<int> frequency_array(26, 0);
 
    // assigning frequency to
    for (int i = 0;
         i < s.length(); i++) {
 
        frequency_array[s[i] - 'a']++;
    }
 
    // empty string of string class type
    string ans = "";
 
    // loop to iterate over
    // maximum priority first.
    for (int i = 25; i >= 0;) {
 
        // if frequency is greater than
        // or equal to k.
        if (frequency_array[i] > k) {
 
            // temporary variable to operate
            // in-place of k.
            int temp = k;
            string st(1, i + 'a');
            while (temp > 0) {
 
                // concatenating with the
                // resultant string ans.
                ans += st;
                temp--;
            }
 
            frequency_array[i] -= k;
 
            // handling k case by adjusting
            // with just smaller priority
            // element.
            int j = i - 1;
            while (frequency_array[j]
                       <= 0
                   && j >= 0) {
                j--;
            }
 
            // condition to verify if index
            // j does have frequency
            // greater than 0;
            if (frequency_array[j] > 0
                && j >= 0) {
                string str(1, j + 'a');
                ans += str;
                frequency_array[j] -= 1;
            }
            else {
 
                // if no such element is found
                // than string can not be
                // processed further.
                break;
            }
        }
 
        // if frequency is greater than 0
        // and less than k.
        else if (frequency_array[i] > 0) {
 
            // here we don't need to fix K
            // consecutive element criteria.
            int temp = frequency_array[i];
            frequency_array[i] -= temp;
            string st(1, i + 'a');
            while (temp > 0) {
                ans += st;
                temp--;
            }
        }
 
        // otherwise check for next
        // possible element.
        else {
            i--;
        }
    }
    return ans;
}
