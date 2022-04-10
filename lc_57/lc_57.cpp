class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int left = newInterval[0];
        int right = newInterval[1];
        if(left > intervals.back()[1]){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> result;
        if(right < intervals[0][0]){
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin(), intervals.end());
            return result;
        }

        for(vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); ++it){
            if(left >= (*it)[0] && left <= (*it)[1]){
                left = (*it)[0];
            }
            if(right >= (*it)[0] && right <= (*it)[1]){
                right = (*it)[1];
            }
        }
        for(vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); ++it){
            if((*it)[0] >= left){
                result.push_back({left, right});
                for(vector<vector<int>>::iterator it2 = it; it2 != intervals.end(); ++it2){
                    if((*it2)[0] > right){
                        result.push_back(*it2);
                    }
                }
                break;
            }
            else{
                result.push_back(*it);
            }
        }
        return result;

    }
};