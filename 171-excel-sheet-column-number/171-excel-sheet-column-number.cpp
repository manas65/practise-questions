class Solution {
public:
    
    int titleToNumber(string columnTitle) {
        int sum=0;
        for(char ch:columnTitle){
            char lch=tolower(ch);
            sum*=26;
            sum+=lch -'a'+1;        
        }
        return sum;
    }
};