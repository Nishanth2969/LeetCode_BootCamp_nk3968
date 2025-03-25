class Solution {
public:
    string decodeString(string s) {
        stack<int> a;
        stack<string> b;
        string c;
        int d = 0;
        for(char e : s){
            if(isdigit(e)) d = d * 10 + (e - '0');
            else if(e == '['){ a.push(d); b.push(c); d = 0; c = ""; }
            else if(e == ']'){
                int f = a.top(); a.pop();
                string g = b.top(); b.pop();
                for(int i = 0; i < f; i++) g += c;
                c = g;
            } else c.push_back(e);
        }
        return c;
    }
};
