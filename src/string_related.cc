#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    /// check if a char is alphabet letter
    cout<< isalpha('A')<<endl;
    /// check if a char is lower letter
    cout<< islower('A')<<endl;
    /// check if a char is upper letter
    cout<< isupper('A')<<endl;

    /// convert a char letter to upper/lower case
    cout<< toupper('a')<<endl;
    cout<< tolower('A')<<endl;

    /// create a string with some letters
    cout << string(100,'a')<<endl;

    /// example of using unordered_map
    unordered_map<char,int> hash{};
    string s = "abcdea";
    for (auto let: s){
        hash[let]++;
    }

    /// example of iterating through unordered_map using
    /// iterator
    for (auto it = hash.begin(); it != hash.end(); it++){
        cout <<it->first <<"|"<< it->second<<endl;
    }
}