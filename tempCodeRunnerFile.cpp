int main()
{
	int p,q;
    cin >> p >> q;
    vector<int> arr(p);
    unordered_map<int,int> mp;
    for(int i=0;i<p;i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int pairs = 0;
    for(int i=0;i<p;i++){
        if(arr[i]-q!=arr[i] && mp.count(arr[i]-q)){
            pairs++;
            mp[arr[i]]--;
            if(mp[arr[i]]==0) mp.erase(arr[i]);
        }
    }
    cout << pairs;
	return 0;
}