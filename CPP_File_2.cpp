
#include "Header.h"

bool is_num_power_to_Two(int num){

	while(num%2 == 0){
		num = num/2;
	}

	if(num == 1){
		return true;
	}else{
		return false;
	}

}

int Get_Num_Ops(int n){

	int num_of_ops = 0 , cnt = 0 , power = 0;

	bool bool1 = is_num_power_to_Two(n);

	if (bool1) {
		return 1;
	}

	int n_copy = n;

	while(n != 0){

		for(int d = 0 ; d < 2 ; ++d){

			if(d == 0){
				n = n - 2 ;
			}else{
				n = n + 2 ;
			}

			if(n == 0){
				++num_of_ops;
				break;
			}

			bool bool1 = is_num_power_to_Two(n);

			if (bool1 && d == 0) {

				++num_of_ops;
				n = n_copy - n;
				n_copy = n;

				bool bool1 = is_num_power_to_Two(n);

				if (bool1) {
					++num_of_ops;
					goto end1;
				}

			}

		}
		
	}

	end1:

	return num_of_ops;

}

int Test_function_1(int n){

	int num_of_ops;

	if(n%2 != 0){

		int num_of_ops1 , num_of_ops2 ;

		num_of_ops1 = Get_Num_Ops(n + 1);

		num_of_ops2 = Get_Num_Ops(n - 1);

		if(num_of_ops1 < num_of_ops2){
			num_of_ops = num_of_ops1 + 1;
		}else{
			num_of_ops = num_of_ops2 + 1;
		}

	}else{
		num_of_ops = Get_Num_Ops(n);
	}

	return num_of_ops;

}

// A recursive binary search function. It returns location of x in given array arr[low..high] 
// is present, otherwise -1
int binarySearch(vector<int> &arr, int low, int high, int x) {

    if (high >= low) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);

    }

  	return -1;

}

int Test_Function_1() {

    vector<int> arr = { 2, 3, 44, 10, 40 , 99 , 66 , 5 , 82 , 12 , 92 , 55 };
	sort(arr.begin(), arr.end());
    int query = 44;
    int n = arr.size();
    int result = binarySearch(arr, 0, n - 1, query);
    if (result == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result;
    return 0;

}

int main(){
	
	int n_ops = Test_function_1(72);
	cout << "n_ops = " << n_ops << endl;
	
}
