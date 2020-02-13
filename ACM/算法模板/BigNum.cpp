#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
struct BigNum {
	#define lim 100000
	#define N   10000
	int val[N], len, sign;
	void clear() {
		len = 0; sign = 0;
		memset(val,0,sizeof(val));
	}
	void Char_to_Num (char *ch) {
		int l, st;
		if (ch[0] == '-'){ st = 1; sign = 1;}
		else { st = 0; sign = 0;}
		val[len = 0] = 0; l = strlen(ch);
		for (int i = l - 1, x = 1; i >= st; --i) {
			val[len] += x * (ch[i] - '0');
			if (((l - 1) - i + 1) % 5 == 0 && i > st) {
				val[++len] = 0; x = 1;
			}
			else x *= 10;
		}
		val[len + 1] = 0;
	}
	void Print() {
		if (sign)putchar('-');
		printf ("%d", val[len]);
		for (int i = len - 1, x; i >= 0; --i) {
			x = (val[i]) ? (val[i]) : (1);
			for (; x * 10 < lim; x *= 10) putchar('0');
			printf ("%d", val[i]);
		}
	}
	friend bool operator > (BigNum a, BigNum b) {
		if (a.sign != b.sign) return (a.sign == 0);
		if (a.sign == 0) {
			if (a.len != b.len)return a.len > b.len;
			for (int i = a.len; i >= 0; --i)
				if (a.val[i] > b.val[i]) return true;
				else if (a.val[i] < b.val[i]) return false;
			return false;
		}
		else {
			if (a.len != b.len)return a.len > b.len;
			for (int i = a.len; i >= 0; --i)
				if (a.val[i] < b.val[i]) return true;
				else if (a.val[i] > b.val[i]) return false;
			return false;
		}
	}
	friend BigNum operator + (BigNum a, BigNum b) {
		if (a.sign != b.sign) {
			b.sign = a.sign;
			return a - b;
		}
		int l = max(a.len, b.len);
		for (int i = 0; i <= l; ++i) {
			if (i + 1 > a.len) a.val[i + 1] = 0;
			if (i + 1 > b.len) b.val[i + 1] = 0;
			a.val[i] += b.val[i];
			a.val[i + 1] += a.val[i] / lim;
			a.val[i] %= lim;
		}
		for (a.len = l; a.val[a.len + 1]; a.len++);
		return a;
	}
	friend BigNum operator - (BigNum a, BigNum b) {
		if (a.sign != b.sign) {
			b.sign = a.sign;
			return a + b;
		}
		BigNum c; c.clear(); c.sign = a.sign;
		if (b > a) { c = a; a = b; b = c; c.sign ^= 1;}
		for (int i = 0, j; i <= a.len; ++i) {
			if (i > b.len) b.val[i] = 0;
			if (a.val[i] < b.val[i]) {
				a.val[i] += lim;
				for (j = i + 1; a.val[j] == 0; ++j) 
					a.val[j] = lim / 10 - 1;
				a.val[j]--;
			}
			c.val[i] = a.val[i] - b.val[i];
		}
		for (c.len = a.len; !c.val[c.len]; c.len--);
		return c;
	}
	friend BigNum operator / (BigNum a, BigNum b) {
		BigNum c; c.clear();
		if (a.sign ^ b.sign) c.sign = 1;
		else c.sign = 0;
		while (a > b) {
			a = a - b;
			c = c + 1
		}
	}
}a, b;
char ch[100000];
int main (){
	scanf ("%s", ch); a.Char_to_Num(ch);
	scanf ("%s", ch); b.Char_to_Num(ch);
	(a + b).Print();printf("\n");
	(a - b).Print();printf("\n");
	return 0;
}
