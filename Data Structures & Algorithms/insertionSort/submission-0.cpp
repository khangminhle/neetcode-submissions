// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> result;


        for(int i = 0; i < pairs.size(); i++) {
            int currentIndex = i;

            while(currentIndex > 0) {
                if(pairs[currentIndex].key < pairs[currentIndex-1].key) {
                    int tempKey = pairs[currentIndex].key;
                    string tempValue = pairs[currentIndex].value;

                    pairs[currentIndex].key = pairs[currentIndex-1].key;
                    pairs[currentIndex].value = pairs[currentIndex-1].value;
                    pairs[currentIndex-1].key = tempKey;
                    pairs[currentIndex-1].value = tempValue;
                }

                currentIndex = currentIndex-1;
            }

            result.push_back(pairs);
        }
            
        return result;
    }
};
