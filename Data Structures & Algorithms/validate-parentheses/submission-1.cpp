class Solution {
public:
    bool isValid(string s) {
        // Fast I/O to speed up runtime execution
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        if (n % 2 != 0) return false;

        // Raw array acting as a stack avoids dynamic memory allocations
        char st[n]; 
        int top = -1;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') st[++top] = ')';
            else if (c == '{') st[++top] = '}';
            else if (c == '[') st[++top] = ']';
            else if (top == -1 || st[top--] != c) return false;
        }

        return top == -1;
    }
};
