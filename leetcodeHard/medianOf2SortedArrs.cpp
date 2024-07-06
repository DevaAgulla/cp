 double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1 > n2)return findMedianSortedArrays(arr2,arr1);

        int low = 0;
        int high = n1;
        int n = n1+n2;
        int left = n/2;
        while(low<=high){
            int mid1 = (low+high)>>1;
            int mid2 = left-mid1;
            // if(mid2 >n2){
            //     low = mid1+1;
            //     continue;
            // }
            // if(mid2 < 0){
            //     high = mid1-1;
            //     continue;
            // }
            int l1 = INT_MIN,l2 = INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1>=0 and mid1<n1)r1 = arr1[mid1];
            if(mid2>=0 and mid2<n2)r2 = arr2[mid2];
            if(mid1>=1 and mid1<=n1)l1 = arr1[mid1-1];
            if(mid2>=1 and mid2<=n2)l2 = arr2[mid2-1];
            if(l1<=r2 and l2<=r1){
                if(n%2==1) {
                    return min(r1,r2);
                }
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1 > r2)high = mid1-1;
            else low = mid1+1;
        }
        return 0;
    }
