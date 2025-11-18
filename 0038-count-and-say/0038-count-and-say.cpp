class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
    string say=countAndSay(n-1); 
    //now we do the processing
    int i=0;
    string res="";
     while(i<say.size())
     {
        char currchar=say[i];
        int count=0;
        while(i < say.size() &&say[i]==currchar)
        {
            count++;
            i++;
        }
        res+=to_string(count);
        res+=currchar;
     }
     
     return res;
    }
};