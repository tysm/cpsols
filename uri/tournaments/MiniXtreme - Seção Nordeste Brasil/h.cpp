#include <cpplib/stdinc.hpp>

int lps(string str)
{
   int n = str.size();
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems


   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++){
       if(str[i] == 'a')
           L[i][i] = 0;
        else
          L[i][i] = 1;
   }

    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if(str[i] == 'a' or str[j] == 'a'){
               L[i][j] = max(L[i][j-1], L[i+1][j]);
                continue;
            }
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}


int32_t main(){
    desync();
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}

