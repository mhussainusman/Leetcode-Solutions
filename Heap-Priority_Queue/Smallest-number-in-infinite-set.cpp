#include<iostream>
#include<set>
using namespace std;

class SmallestInfiniteSet {
public:
    int curr;
    set<int>box;

    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        if (!box.empty()){
        int smallest=*box.begin();
        box.erase(box.begin());
        return smallest;
        } 
        return curr++;
    }
    
    void addBack(int num) {
        if(num<curr)box.insert(num);
    }
};

