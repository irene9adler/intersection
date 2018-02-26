#include <stdio.h>
#include <algorithm>

using namespace std;

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int * res;
   // int l = returnSize;
    res = (int *)malloc(100000*sizeof(int));

    sort(nums1,nums1+nums1Size);
    sort(nums2,nums2+nums2Size);


    int i=0;
    int j=0;
    int loc=0;
    while((i<nums1Size)&&(j<nums2Size))
    {
        if(nums1[i]<nums2[j]) i++;
        else if(nums1[i]>nums2[j]) j++;
        else
        {
            if(loc==0)
            {
                res[0] = nums1[i];
                loc++;
            }
            else
            {
                if(res[loc-1]!=nums1[i])
              {
                res[loc]=nums1[i];
                loc++;
              }
            }

            i++;
            j++;
        }
    }
    *returnSize = loc;
    return res;

}

int main(void)
{
    int arr1[4] = {1,2,3,4};
    int arr2[3] = {2,3,6};
    int * val;//= (int *)malloc(1000*sizeof(int));
    int len;
    val = intersection(arr1,4,arr2,3,&len);
    printf("len = %d\n",len);
    int i;
    for(i=0;i<len;i++)
    printf("%d ",val[i]);
    free(val);
    return 0;
}
