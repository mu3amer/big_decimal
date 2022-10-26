BigDecimalInt operator-(const BigDecimalInt& abba,const BigDecimalInt& baab){
	BigDecimalInt temp;
	temp = abba;
	temp -= baab;
	return temp;
}

//functions increment methods
BigDecimalInt &operator+=(BigDecimalInt &abba,const BigDecimalInt& baab){
    int t = 0, s, i;
    int n = size(abba), m = size(baab);
    if(m > n)
        abba.integral_numbers.append(m - n, 0);
    n = size(abba);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (abba.integral_numbers[i] + baab.integral_numbers[i]) + t;
        else
            s = abba.integral_numbers[i] + t;
        t = s / 10;
        abba.integral_numbers[i] = (s % 10);
    }
    if(t)
        abba.integral_numbers.push_back(t);
    return abba;
}
BigDecimalInt &operator-=(BigDecimalInt&abba,const BigDecimalInt &baab){
    if(abba < baab)
        throw("UNDERFLOW");
    int n = size(abba), m = size(baab);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = abba.integral_numbers[i] - baab.integral_numbers[i]+ t;
        else
            s = abba.integral_numbers[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        abba.integral_numbers[i] = s;
    }
    while(n > 1 && abba.integral_numbers[n - 1] == 0)
        abba.integral_numbers.pop_back(),
        n--;
    return abba;
}

//Checking operators
bool operator>(const BigDecimalInt& abba, const BigDecimalInt& baab){
	return baab < abba;
}
