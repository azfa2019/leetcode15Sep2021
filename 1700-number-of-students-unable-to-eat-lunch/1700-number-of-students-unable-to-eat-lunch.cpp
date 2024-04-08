class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s1=accumulate(students.begin(),students.end(),0);
        int s0=students.size()-s1;
        for(int san:sandwiches){
            if(san==0 && s0>0) s0--;
            else if(san==1 && s1>0) s1--;
            else break;
        }
        return s0+s1;
    }
};