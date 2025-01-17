#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct CreatorInfo
    {
        long long totalViews = 0;    // Tổng lượt xem của creator
        string mostViewedId = "";   // ID của video có lượt xem cao nhất
        int maxView = -1e9;      // Lượt xem cao nhất của một video
    };

    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        // Bước 1: Lưu trữ thông tin của từng creator
        unordered_map<string, CreatorInfo> creatorData;
        int n = creators.size();

        for (int i = 0; i < n; ++i)
        {
            string creator = creators[i];
            string id = ids[i];
            int view = views[i];

            // Cập nhật tổng lượt xem
            creatorData[creator].totalViews += view;

            // Cập nhật video có lượt xem cao nhất
            if (view > creatorData[creator].maxView || 
                (view == creatorData[creator].maxView && id < creatorData[creator].mostViewedId))
            {
                creatorData[creator].maxView = view;
                creatorData[creator].mostViewedId = id;
            }
        }

        // Bước 2: Tìm tổng lượt xem lớn nhất
        long long maxViews = 0;
        for (auto entry : creatorData)
        {
            maxViews = max(maxViews, entry.second.totalViews);
        }

        // Bước 3: Thu thập kết quả cho những creator có tổng lượt xem lớn nhất
        vector<vector<string>> result;
        for (auto entry : creatorData)
        {
            if (entry.second.totalViews == maxViews)
            {
                result.push_back({entry.first, entry.second.mostViewedId});
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> creators = {"a", "b"};
    vector<string> ids = {"a", "b"};
    vector<int> views = {0, 0};
    vector<vector<string>> res = sol.mostPopularCreator(creators, ids, views);
    for (auto item : res)
    {
        cout << item[0] << ' ' << item[1] << '\n';
    }
}