#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0)
            return;
        nextP(nums);
        copy(nums.begin(),nums.end(),ostream_iterator<int>(cout));
        return;
    }
    
private:
    void nextP(vector<int>& num)
    {
        vector<int>::iterator it;
        for(it = num.end(); it > num.begin(); it--)
        {
            if(*it > *(it-1))
                break;
        }
        //cout<<*it<<endl;
        if(it == num.begin())
        {
            sort(num.begin(),num.end());
            return;
        }
        
        int j;
        for(j = int(num.size())-1; j>0;j--)
        {
            //cout<<"it-1: "<<*(it-1)<<endl;
            //cout<<"num[j]: "<<num[j]<<endl;
            if(*(it-1) < num[j])
                break;
        }
        //cout<<j<<endl;
        int temp = *(it-1);
        *(it-1) = num[j];
        num[j] = temp;
        //copy(num.begin(),num.end(),ostream_iterator<int>(cout));
        //cout<<endl;
        sort(it,num.end());
        //copy(num.begin(),num.end(),ostream_iterator<int>(cout));
    }
    
};



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    
    Solution *s = new Solution();
    s->nextPermutation(input);
}
