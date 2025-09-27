// https://maang.in/contests/attempts/59831?problem_id=946

#include<bits/stdc++.h>
using namespace std;
#define ll long long   

 // TC -> O(Mlog(logM)) + O(nlogM) ; SC -> O(n+M) , M = max_val, 
 

const int MAX_VAL = 1000001;

int spf[MAX_VAL];

// TC-> O(Mlog(logM)) , sieve
void sieve() {
    for (int i = 1; i < MAX_VAL; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAX_VAL; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) { 
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();

    int n;
    std::cin >> n;

    // A map to store the frequency of each canonical form encountered
    map<ll , int> freq;
    ll answer = 0;

 // TC ->O(nlogM) ;
    for (int i = 0; i < n; i++) {
        int current_num;
        cin >> current_num;

        ll  val = 1; 
        ll  req = 1; 
        int temp_num = current_num;

        // Efficiently factorize the number using the pre-computed SPF array
        while (temp_num > 1) {
            int prime_factor = spf[temp_num];
            int count = 0;
            while (temp_num % prime_factor == 0) {
                count++;
                temp_num /= prime_factor;
            }

            int exponent_mod_3 = count % 3;

            if (exponent_mod_3 == 1) {
                val *= prime_factor;
                req *= (ll )prime_factor * prime_factor; 
            } else if (exponent_mod_3 == 2) {
                val *= (ll )prime_factor * prime_factor;
                req *= prime_factor; 
            }
        }

        // Check if we have already seen numbers that can be a partner to the current one
        if (freq.count(req)) {
            answer += freq[req];
        }

        // Increment the frequency of the current number's canonical form
        freq[val]++;
    }

    std::cout << answer << std::endl;

    return 0;
}