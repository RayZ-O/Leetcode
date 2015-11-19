// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

class Solution {
    vector<string> split(string& str) {
        stringstream ss(str);
        vector<string> res;
        string elem;
        while (getline(ss, elem, '/')) {
            if (elem == "" || elem == ".")
                continue;
            if (elem == "..") {
                if (!res.empty())
                    res.pop_back();
                continue;
            }
            res.push_back(elem);
        }
        return res;
    }
public:
    string simplifyPath(string path) {
        if (path.empty())
            return "";
        vector<string> parts = split(path);
        string res;
        for (auto& s : parts) {
            res += '/' + s;
        }
        return res.empty() ? "/" : res;
    }
};
