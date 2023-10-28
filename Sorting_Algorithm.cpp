void bubble_sort(vector<long long> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1;j++){
            if(arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

void selectionSort(vector<long long> &arr){ //depending in set all the elements to the start
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]<arr[j]){
                    swap(arr[i],arr[j]);
                }
        }
    }
}

void insertionSort(vector<long long> &arr){
    for(int i=1, i<arr.size();i++){
        int cur=arr[i],j=i-1;
        while(j>=0 && arr[j]>cur){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=cur;
    }
}


void countSort(vector<long long> &arr){
    //get the max element in the vector
    long long mx=*max_element(arr.begin(),arr.end());

    vector<long long>freq(mx+1,0);

    for(long long x : arr)
        freq[x]++;

    //print the freq element

    long long i=0;
    for(int val=0; val<=mx; val++){
        while(freq[val]--){
            arr[i++]=val;
        }
    }
}

// count sort for negative element

void countSortShifting(vector<long long> &arr){
    long long mn = *min_element(arr.begin(),arr.end());
    long long shift = (mn<0) ? -mn : 0;

    for(long long &x : arr){
        x+=shift;
    }

    //after shift

    long long mx = *max_element(arr.begin(),arr.end());
    vector<long long>freq(mx+1,0);
    for(long long x : arr)
        freq[x]++;

    long long i=0;
    for(int val=0; val<=mx; val++){
        while(freq[val]--){
            arr[i++]=val-shift;
        }
    }

}

void countSort(vector<string>& arr){

    map<string,int>freq;

    for(string& s : arr) freq[s]++;

    int i=0;

    for(auto& p : freq)

        while(p.second--)

            arr[i++]=p.first;

}


void RadixSort(vector <ll> &a)
{
    ll sh = max(0LL, -*min_element(a.begin(), a.end()));
    for (auto &i : a) i+=sh;
    ll pw = 1;
    for (int it = 0; it < 19; it++) {
        vector <ll> pos[10]{};
        for (auto &i : a) {
            pos[i/pw%10].push_back(i);
        }
        for (int i = 0, j = 0; i <= 9; i++) {
            for (auto &k : pos[i]) {
                a[j++] = k;
            }
        }
        pw*=10;
    }
    for (auto &i : a) i-=sh;
}


void mergeElemns(vector<int> &a, int l, int r){
    // divide the array to left part and right part
    auto L = vector<int> (a.begin()+l, a.begin()+(l+r)/2+1);
    auto R = vector<int> (a.begin()+(l+r)/2+1, a.begin()+r+1);

    L.push_back(2e9); // to prevent overflow in any array
    R.push_back(2e9); // to prevent overflow in any array

    int ptr1=0,ptr2=0;
    // here i sort the two pecies
    for(int i = l; i <= r ;i++){
        if(L[ptr1] < R[ptr2]){
            a[i] = L[ptr1++];
        }else{
            a[i] = R[ptr2++];
        }
    }

}


void mergeSort(vector<int> &a,int l,int r){
    // we will create the dividing recure first
    //the base case
    if (l==r){
        return;
    }
    // here i will divide into two parts until i get to one element
    mergeSort(a,l,(l+r)/2);
    mergeSort(a,(l+r)/2+1,r);

    mergeElemns(a,l,r); // after i reach the one elements i start merge it
}



/*
Quick Sort
*/

int partitioning(vector<int> &arr,int iBegin, int jEnd){
    int i = iBegin;
    int j = jEnd;

    int pivLoc = i;
    while(true){ //this will stop when sort the pos
        // we check if only pivLoc < j
        // we reduce the pos of j
        while(arr[pivLoc]<=arr[j] && pivLoc!=j){ // try to find the pos from the end
            j--;
        }
        if (pivLoc == j){
            break;
        }else if (arr[pivLoc] > arr[j]){
            swap(arr[j],arr[pivLoc]);
            pivLoc=j;
        }

        while(arr[pivLoc]>=arr[i] && pivLoc !=i){ //try to find the pos from the start
            i++;
        }
        if(pivLoc == i){
            break;
        }else if(arr[pivLoc] < arr[i]){
            swap(arr[i],arr[pivLoc]);
            pivLoc=i;
        }
        return pivLoc;
    }

}

/*
    searching for the lowest and biggest of the povit
    and swap it
    and keep do it until the 'j' be lowest than i
    and swap 'j' with the povit
    and it will give you the correct povit location
*/

int partitioning2(vector<int> &arr,int l,int h){
    int p = arr[l];
    int i = l;
    int j = h;

    while(i<j){
        do{
            i++;
        }while(arr[i]<=p)
        do{
            j--;
        }while(arr[j]>p)

        if(i < j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[l],arr[j]);
    return j;
}

void quickSort(vector<int> &arr,int l , int h){

    if(l<h){
        int piv = partitioning(arr,l,r);
        quickSort(arr,l,piv - 1); //right side
        quickSort(arr,piv + 1,h); //left side
    }
}

