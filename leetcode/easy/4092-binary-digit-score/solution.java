class Solution {
    public int calculateBit(int num){
        int bit = 0;
        while(num > 0){
            if((num & 1) == 1){
                bit++;
            }
            num = num >> 1;
        }
        return bit;
    }
    public int calculateScore(int a, int b) {
        int s1 = calculateBit(a);
        int s2 = calculateBit(b);
        if(s1 >= s2){
            return s1*s2;
        }else{
            return s2/s1;
        }
    }
}