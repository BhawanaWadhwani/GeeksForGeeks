//custom function
//count the max no of meetings that can be held. Given start time of one can't be equal to end time of another

//step 1 - sort in ascending order of fininshing time, so we will always consider that activity that has minimum finishing time.
//step 2 - iterate and check if the start time of another activity/meeting is greater than finish time of previous activity/meeting.

bool compare(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second<p2.second;
}
int maxMeetings(int start[], int end[], int n) {
    // Your code here
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),compare);
    int count=1;
    int returning=v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first>returning)
        {
            count++;
            returning=v[i].second;
        }
    }
    return count;
}
