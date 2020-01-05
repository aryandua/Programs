//H is a map: map<char, int>
int func(string s) {
	const int M = 14000605;
    int len = s.size();
    int hash = 0;
    for (int i = len - 1; i >= 0; i--) {
        hash = (2*hash + H[s[i]]) % M;
    }
    return hash;
}