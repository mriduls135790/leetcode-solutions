class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int before[]={0,31,59,90,120,151,181,212,243,273,304,334};
        auto toDays=[&](string date){
            int month=stoi(date.substr(0,2));
            int day=stoi(date.substr(3,2));
            return before[month-1]+day;
        };
        int start=max(toDays(arriveAlice),toDays(arriveBob));
        int end=min(toDays(leaveAlice),toDays(leaveBob));
        return max(0,end-start+1);
    }
};