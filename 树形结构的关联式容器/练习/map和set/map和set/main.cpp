#include <iostream>
#include <map>
using namespace std;

//lc 350
//vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//	map<int, int> m1;
//	vector<int> ret;
//	for (auto& e : nums1){
//		++m1[e];
//	}
//	for (auto& e : nums2){
//		if (m1[e]){
//			--m1[e];
//			ret.push_back(e);
//		}
//	}
//	return ret;
//}

//lc 217
//bool containsDuplicate(vector<int>& nums) {
//	unordered_map<int, int> m;
//	for (auto& e : nums){
//		if (++m[e] > 1){
//			return true;
//		}
//	}
//	// for(auto& e : m){
//	//     if(e.second > 1){
//	//         return true;
//	//     }
//	// }
//	return false;
//
//	// map<int,int> map;
//	// for(int i =0; i<nums.size();i++)
//	//     if(map.count(nums[i])!=NULL) 
//	//         return true;
//	//     else 
//	//         map[nums[i]]+=1;
//	// return false;
//}

//lc 349
//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//	unordered_set<int> s1, s2;
//	//»•÷ÿ
//	for (auto& e : nums1){
//		s1.insert(e);
//	}
//	vector<int> ret;
//	for (auto& e : nums2){
//		s2.insert(e);
//	}
//	//±È¿˙s1
//	for (auto& e : s1){
//		if (s2.count(e)){
//			ret.push_back(e);
//		}
//	}
//	return ret;
//}


//lc 961
//int repeatedNTimes(vector<int>& A) {
//	map<int, int> m;
//	for (auto e : A){
//		++m[e];
//	}
//	for (auto& e : m){
//		if (e.second == A.size() / 2){
//			return e.first;
//		}
//	}
//	return 0;
//}

//lc 692
//vector<string> topKFrequent(vector<string>& words, int k) {
//	map<string, int> m;
//	for (int i = 0; i < words.size(); ++i){
//		++m[words[i]];
//	}
//	multimap<int, string, greater<int>> mp;
//	for (auto e : m){
//		mp.insert(make_pair(e.second, e.first));
//	}
//	vector<string> ret;
//	for (auto e : mp){
//		ret.push_back(e.second);
//		if (--k == 0){
//			break;
//		}
//	}
//	return ret;
//}


int main(){
	string tmp;
	tmp += "acb";
	tmp = "";

	return 0;
}