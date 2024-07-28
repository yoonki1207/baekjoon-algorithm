#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int y = (c*d - a*f)/(b * d - e * a);
    int x;
    if(a!=0) {
        x = (c - b * y) / a;
    } else {
        y = c / b;
        x = (f - e*y)/d;
    }
    cout << x << ' ' << y << endl;
    return 0;
}