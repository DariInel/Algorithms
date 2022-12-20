#include <iostream>
using namespace std;
long long play1[1000001], play2[1000001];
long long n = 0, m = 0, count = 0, count1 = 5, count2 = 5;
int main()
{
    for(int i = 0; i < 5; i++){
        cin >> play1[i];
    }
    for(int  i = 0; i < 5; i++){
        cin >> play2[i];
    }
    while(n != count1 && m != count2 && count != 1000000){
        if (play1[n] == 0 && play2[m] == 9){
            play1[count1] = play1[n];
            count1++;
            play1[count1] = play2[m];
            count1++;
            n++;
            m++;
        }
        else
            if (play1[n] == 9 && play2[m] == 0){
                play2[count2] = play1[n];
                count2++;
                play2[count2] = play2[m];
                count2++;
                n++;
                m++;
            }
            else
                if (play1[n] > play2[m]){
                    play1[count1] = play1[n];
                    count1++;
                    play1[count1] = play2[m];
                    count1++;
                    n++;
                    m++;
                }
                else
                    if (play1[n] < play2[m]){
                        play2[count2] = play1[n];
                        count2++;
                        play2[count2] = play2[m];
                        count2++;
                        n++;
                        m++;
                    }
        count++;
    }
    if (n == count1)
        cout << "second" << ' ' << count;
    else
        if (m == count2)
          cout << "first" << ' ' << count;
        else
            if (count == 1000000)
              cout << "botva";
    return 0;
}
