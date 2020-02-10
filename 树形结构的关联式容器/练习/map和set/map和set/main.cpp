#include <iostream>
#include <map>
#include <vector>
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


//lc 884
//vector<string> uncommonFromSentences(string A, string B) {
//	vector<string> ret;
//	map<string, int> mp;
//	string tmp;
//	int i = 0;
//	int len = A.size();
//	while (i < len){
//		while (A[i] != ' ' && i < len){
//			tmp += A[i];
//			++i;
//		}
//		++mp[tmp];
//		tmp = "";
//		++i;
//	}
//	i = 0;
//	len = B.size();
//	while (i < len){
//		while (B[i] != ' ' && i < len){
//			tmp += B[i];
//			++i;
//		}
//		++mp[tmp];
//		tmp = "";
//		++i;
//	}
//	for (auto& e : mp){
//		if (e.second == 1){
//			ret.push_back(e.first);
//		}
//	}
//	return ret;
//}


int main(){




	/*string a = "what a be";
	string b = "what c be";
	uncommonFromSentences(a, b);
	*/

	/*string tmp;
	tmp += "acb";
	tmp = "";
	vector<string> tmp2;
	tmp2.push_back("abc");
	tmp2.clear();*/
	return 0;
}