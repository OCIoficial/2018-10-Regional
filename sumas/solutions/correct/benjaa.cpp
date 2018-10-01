/*
 * No estoy seguro que funcione, así que hay que revisar bien.
 * Se le pueden hacer unos arreglos para que pase más rápido.
 *  Ej: revisar si la suma es mayor al último valor
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print_stuff(int n, vector<long long > nums){
    cout << n  << " ";
    int c = 0;
    for(long long elem : nums){
        cout << elem << " ";
        if(++c == n)
            break;
    }
    cout << nums[nums.size() - 1] << endl;
    exit(0);
}

void do_the_thing(string seq, vector<int > index){
    // Index has the starting index of each one of the N numbers, the sum, and an extra one 
    // to flag the end of the string
    vector<long long > nums(index.size() - 1);
    for(int i = 0; i < index.size() - 1; i++){
        if(index[i+1] - index[i] > 9){
            // If the number is bigger than a long long
            nums[i] = -1;
            break;
        }
        nums[i] = stoll(seq.substr(index[i], index[i+1] - index[i]));
    }
    while(true){
        long long sum = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == -1){
                sum = -1;
                break;
            }
            sum += nums[i];
        }
        if(sum != -1 && sum == nums[nums.size() - 1]) print_stuff(index.size() - 2, nums);
        // From right to left we find a pointer we can move one space to the right
        for(int i = index.size() - 2; i >= 0; i--){
            if(i == 0) 
                // We only reach the first index after trying everything 
                return;
            if(index[i] < index[i + 1] - 1){
                // We can move this one
                index[i]++;
                // Now we want to reset all the index to the right of i
                for(int j = i + 1; j < index.size() - 1; j++)
                    index[j] = index[j - 1] + 1;
                // Recompute all the numbers to the right
                for(int j = i - 1; j < index.size() - 1; j++){
                    if(index[j+1] - index[j] > 9){
                        // If the number is bigger than a long long
                        nums[j] = -1;
                        break;
                    }
                    nums[j] = stoll(seq.substr(index[j], index[j+1] - index[j]));
                }
                break;
            }
        }    
    }
}

void find_seq(string &input){
    int nums = stoi(input.substr(0, 1)); 
    vector<int > index(nums + 1, 0);
    for(int i = 0; i < index.size(); i++)
        index[i] = i; 
    index.push_back(input.size() - 1);
    do_the_thing(input.substr(1, 30), index);
    nums = stoi(input.substr(0, 2));
    index.resize(nums + 1);
    for(int i = 0; i < index.size(); i++)
        index[i] = i; 
    index.push_back(input.size() - 2);
    do_the_thing(input.substr(2, 30), index);
}

int main(){
    string input;
    cin >> input;
    find_seq(input); 
}
