#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    public:
        vector<int> prefixProds;
        
        ProductOfNumbers() {
        }
        
        void add(int num) { 
            if (num == 0) {
                prefixProds.clear();
            } else {
                if (prefixProds.empty()) {
                    prefixProds.push_back(num);
                } else {
                    prefixProds.push_back(prefixProds.back() * num);
                }
            }
        }
        
        int getProduct(int k) {
            if (k > prefixProds.size()) {
                return 0;
            }
            if (k == prefixProds.size()) {
                return prefixProds.back();
            }
            return prefixProds.back() / prefixProds[prefixProds.size() - k - 1];
        }
    };
    