#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int d_actual, m_actual, y_actual;
    cin >> d_actual >> m_actual >> y_actual;
    int d_exp, m_exp, y_exp;
    cin >> d_exp >> m_exp >> y_exp;
    
    if(y_actual > y_exp)
        cout << 10000 ;
    else
        if(y_actual == y_exp)
        {
        if(m_actual > m_exp)
            cout << (m_actual - m_exp)*500 ;
        else
            if(m_actual == m_exp){
            if(d_actual > d_exp)
                cout << (d_actual - d_exp)*15 ;
            else
                cout << 0;
            }
        else
            cout << 0;
    }
    else
        cout << 0;
    return 0;
}

