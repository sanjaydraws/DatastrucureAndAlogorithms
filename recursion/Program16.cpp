class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)return false;
        int no_of_one = 0,pos = 1,ones_pos = 0;
        while(num){
            if(num&1)no_of_one+=1,one_pos = pos;
            num>>=1,pos+=1;
        }
        return no_of_one==1&&one_pos&1;
    }
};