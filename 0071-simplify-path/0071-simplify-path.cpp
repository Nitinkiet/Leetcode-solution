class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i=0, j=0;
        while(i<path.length())  {
            if(path[i] == '/')  {i++;continue;}
            string temp = "";
            j=i;
            while(j<path.length() && path[j] != '/')   {
                temp.push_back(path[j]);
                j++;
            }
            i=j;
            if(temp == ".") continue;
            else if(temp == ".." && st.empty())   continue;
            else if(temp == ".." && !st.empty())   st.pop();
            else st.push(temp);
        }

        string ans = "";
        while(!st.empty())  {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.length() == 0)   return "/";
        return ans;
    }
};