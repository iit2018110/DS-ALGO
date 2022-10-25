string intToRoman(int num) {
    string m[] = {"", "M", "MM", "MMM"};
    string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    string thous = m[(num/1000)%10];
    string hund = c[(num/100)%10];
    string tens = x[(num/10)%10];
    string ones = i[num%10];
    
    string ans = thous + hund + tens + ones;
    
    return  ans;
}