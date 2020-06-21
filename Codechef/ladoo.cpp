#include <iostream>
#include<string>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    
    for (int i = 0; i < T; i++) {
        int count;
        string origin;
        cin>>count;
        cin>>origin;
        
        int min_points = origin == "INDIAN"? 200: 400;
        int score = 0;
        
        for (int j = 0; j < count; j++) {
            string activity, activity_str;
            int num;
            cin>>activity;
            // vector<string> strs;
            // boost::split(strs, activity_str, boost::is_any_of(" "));
            // activity = strs[0];
            
            if (activity == "CONTEST_WON") {
                cin>>num;
                score = score + 300 + (20-num > 0? 20-num: 0);
            } 
            else if (activity == "TOP_CONTRIBUTOR") {
                score += 300;
            }
            else if (activity == "BUG_FOUND") {
                cin>>num;
                score += num;
            } 
            else if (activity == "CONTEST_HOSTED") {
                score += 50;
            }
        }
        

        cout << score/min_points << endl;
    
    }
	return 0;
}
