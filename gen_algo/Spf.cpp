// TC-> O(Mlog(logM)) , sieve

// precompute sfp ; 

const int MAX_VAL = 1000001;
int spf[MAX_VAL];

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


// TC-> O(Mlog(logM))

const int N = 1000001;

vector<bool> is_prime(N, true);

void sieve() {
    // 0 and 1 are not prime numbers.
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i < N; i++) {
       
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}