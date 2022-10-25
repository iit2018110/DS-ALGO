struct Interval
{
    int s, e;
};
 
bool mycomp(Interval a, Interval b)
{ return a.s < b.s; }
 
void mergeIntervals(Interval arr[], int n)
{

    sort(arr, arr+n, mycomp);
 
    int index = 0; 

    for (int i=1; i<n; i++)
    {
        if (arr[index].e >=  arr[i].s)
        {
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else {
            index++;
            arr[index] = arr[i];
        }   
    }
 
    cout << "\n The Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}
 