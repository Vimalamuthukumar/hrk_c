void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=m-1;
    int k=n-1;
    int j=m+n-1;
    while(j>=0) {
        if(k<0) 
        {
            break;
        }
        if(i>=0&&nums1[i]>nums2[k]) {
            nums1[j]=nums1[i];
            i--;
        }
        else 
        {
            nums1[j]=nums2[k];
            k--;
        }
        j--;
    }
}