int T(int num) {
    int x = 0;
    for (long long i = 1; i <= num; i++) {
        for (long long j = 1; j <= num; j++) {
            if (i*i + j*j == num) {
                x++;
            }
        }
    }
    return x;
}

int I(int num) {
    int x = 0;
    for (; num > 0; num /= 10) {
        if (num % 10 == 0) {
            x++;
        }
    }
    return x;
}

int M(int num) {
    int x = 0;
    for (; num > 0; num /= 10) {
        x++;
    }
    return x;
}

int E(int num) {
    int x = 0;
    for (; num > 0; num /= 10) {
        x += num % 10;
    }
    return x;
}

int main() {
    int input;
    cin >> input;
    if (T(input) == 12 && 
        I(input) == 4 && 
        M(input) == 8 && 
        E(input) == 16 && 
        input % 2 == 1) {
        cout << "We're in the endgame now" << endl;
    } else {
        cout << "we lost :(" << endl;
    }
    return 0;
}