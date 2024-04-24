class Solution
{
public:
    unordered_map<int, vector<int>> next;
    unordered_set<int> inPath;
    unordered_set<int> v;

    bool hasCyclic(int node)
    {
        if (inPath.count(node))
            return true;
        if (v.count(node))
            return false;

        inPath.insert(node); // recored current node
        v.insert(node);

        for (auto &n : next[node])
            if (hasCyclic(n))
                return true;
        inPath.erase(node);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto a : prerequisites)
            next[a[0]].push_back(a[1]);

        for (int i = 0; i < numCourses; i++)
        {
            if (hasCyclic(i))
                return false;
        }
        return true;
    }
};