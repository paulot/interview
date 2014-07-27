
template <class T>
struct Order {
    bool operator()(T const& a, T const& b) const {
        return a < b;
    }
};

/*
template <class T>
int search(vector<T> &arr, T item) {
    int n     = arr.size();
    int pivot = n / 2;
    int end   = n - 1;
    int start = 0;

    while(start <= end) {
        if(arr[pivot] == item)
            return pivot;
        if(arr[start] == item)
            return start;
        if(arr[end] == item)
            return end;
        if(arr[pivot] > item) {
            // Item is on the smaller half
            start++;
            end = pivot - 1;
            pivot = (end + start) / 2;
        } else {
            // Item is on the bigger half
            end--;
            start = pivot + 1;
            pivot = (end + start) / 2;
        }
    }
    return -1;
}
*/

