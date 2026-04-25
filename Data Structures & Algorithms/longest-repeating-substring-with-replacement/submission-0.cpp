class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // Add current character  to window :
            int ch = s[right];
            freq[ch - 'A']++;

            // update maxFreq;
            maxFreq = max(maxFreq, freq[ch - 'A']);

            // check if window is valid :
            int windowLen = right - left + 1;
            int replacementNeeded = windowLen - maxFreq;

            // if invalid shrink window from left :
            if (replacementNeeded > k) {
                char leftChar = s[left];
                freq[leftChar - 'A']--;
                left++;
            }
            // update answer :
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
