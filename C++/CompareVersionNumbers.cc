// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37


class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t pos1 = version1.find('.');
        size_t pos2 = version2.find('.');      
        int v1 = stoi(version1.substr(0, pos1));
        int v2 = stoi(version2.substr(0, pos2));
        if (v1 == v2) {
            if (pos1 == string::npos && pos2 == string::npos) return 0;
            else {
                version1 = pos1 == string::npos ? "0" : version1.substr(pos1+1);
                version2 = pos2 == string::npos ? "0" : version2.substr(pos2+1);
                return compareVersion(version1, version2);
            }
        } else {
            return v1 > v2 ? 1 : -1;
        }
    }
};