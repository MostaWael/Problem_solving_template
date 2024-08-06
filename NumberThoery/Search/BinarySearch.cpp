int Binary_search(vector<int>& nums, int val){
  int start = 0, end=nums.size() -1;
  
  while(start <= end){
    int mid = start + (end - start) /2; //to fix overflow error  
    if(nums[mid] == val){
      return mid;
    }if(nums[mid] < val){
      start = mid + 1;
    }else if (nums[mid] > val){
      end = mid - 1;
    }
  }

  return -1;
}
