#include <iostream>
#include <unordered_set>
#include <unordered_map>

struct path
{
    int max_height;
    std::string sequence;
};
int main()
{
    int N;
    std::cin >> N;
    for (int n = 0; n < N; ++n)
    {
        int M;
        std::cin >> M;
        std::unordered_set<int> heights;
        heights.insert(0);
        std::unordered_map<int, path> paths;
        paths[0] = {0, ""};
        for (int m = 0; m < M; ++m)
        {
            int dist;
            std::cin >> dist;
            std::unordered_set<int> new_heights;
            std::unordered_map<int, path> new_paths;
            for (const auto &h : heights)
            {
                int h1 = h + dist;
                int mh1 = std::max(h1, paths[h].max_height);
                new_heights.insert(h1);
                auto it = new_paths.find(h1);
                if (it == new_paths.end() || it->second.max_height > mh1)
                {
                    new_paths[h1] = {mh1, paths[h].sequence + "U"};
                }

                int h2 = h - dist;
                if (h2 < 0)
                    continue;
                int mh2 = std::max(h2, paths[h].max_height);
                new_heights.insert(h2);
                auto it2 = new_paths.find(h2);
                if (it2 == new_paths.end() || it2->second.max_height > mh2)
                {
                    new_paths[h2] = {mh2, paths[h].sequence + "D"};
                }
            }
            heights = new_heights;
            paths = new_paths;
        }
        auto it = paths.find(0);
        if (it == paths.end())
        {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
        else
        {
            std::cout << it->second.sequence << std::endl;
        }
    }
}