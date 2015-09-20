// The API: int read4(char *buf) reads 4 characters at a time from a file.

// The return value is the actual number of characters read. For example, it returns 3
// if there is only 3 characters left in the file.

// By using the read4 API, implement the function int read(char *buf, int n) that reads
// n characters from the file.

// Note:
// The read function will only be called once for each test case.


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int sum = 0;
        while (n >= 4) {
            int t = read4(buf);
            if (t < 4) {
                return sum + t;
            }
            n -= 4;
            buf += 4;
            sum += 4;
        }
        int t = read4(buf);
        sum += t >= n ? n : t;
        return sum;
    }
};
