#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int size=flowerbed.size();
        for(int i=0;i<size;i++){

            bool leftEmpty=false;
            if (i==0||flowerbed[i-1]==0){
                leftEmpty=true;
            }
            bool rightEmpty=false;
            if(i==size-1||flowerbed[i+1]==0){
                rightEmpty=true;}
            if(flowerbed[i]==0&&leftEmpty && rightEmpty){
                flowerbed[i]=1;
                count++;// how many 1s can be placed
            }



        }
        bool result;
        if (count>=n) {result=true;}
        else  {result= false;}
        return result;
    }
};