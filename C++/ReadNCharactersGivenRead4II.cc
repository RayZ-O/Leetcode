// The API: int read4(char *buf) reads 4 characters at a time from a file.

// The return value is the actual number of characters read. For example, it returns 3 if
// there is only 3 characters left in the file.

// By using the read4 API, implement the function int read(char *buf, int n) that reads n
// characters from the file.

// Note:
// The read function may be called multiple times.

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    queue<int> store;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0;

        while (!store.empty() && n > 0) {
            *buf = store.front();
            store.pop();
            n--;
            sum++;
            buf++;
        }

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
        while (t > n) {
            store.push(buf[n++]);
        }
        return sum;
    }
};
