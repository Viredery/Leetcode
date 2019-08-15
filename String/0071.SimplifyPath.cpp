class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
            return "";
        vector<string> paths;
        size_t start = path.find_first_of('/') + 1;
        while (start < path.size()) {
            size_t end = path.find_first_of('/', start);
            string dir = end != string::npos ? 
                    path.substr(start, end-start) : path.substr(start);
        
            if (dir.empty() || dir == ".")
                ;
            else if (dir == "..") {
                if (!paths.empty())
                    paths.pop_back();
            } else
                paths.push_back(dir);
            if (end == string::npos)
                break;
            start = end + 1;
        }

        string res = "/";
        for (int i = 0; i != paths.size(); i++) {
            res += paths[i];
            if (i != paths.size() - 1)
                res += "/";
        }
        return res;
    }
};
