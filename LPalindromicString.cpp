#include <iostream>

#include <vector>

using namespace std;

int main(){

    string s = "babad";

    // string palindromic = "";

    // vector<string> arr ={};


    // for(int i=0; i<a.size()-1; ++i){
    //     palindromic = a[i];

    //     for(int j=i+1; j<a.size(); ++j){
            
    //         if(a[i] != a[j]){
    //             palindromic = palindromic + a[j];
    //         }else{
    //             break;
    //         }
            
    //     }
    //     cout << "Last palindromic char is -------->" << a[palindromic.size()] << "\n";
    //     cout << "Palindromic size is " << palindromic.size() <<"\n" ;
    //     if(a[i] == a[palindromic.size()]){
    //             palindromic = palindromic + a[palindromic.size()];
    //         }
    //     cout<< "In palindromic -->" << palindromic<<endl;

    //     if(a[i] != palindromic[palindromic.size()-1] ){
    //         palindromic = "";
    //     }else{
    //         arr.push_back(palindromic);
    //         cout<< arr.size()<< endl;
    //         palindromic = "";
    //     }

    // }

    // // cout << "last "<< palindromic[palindromic.size()-1 ] <<"\n";
    // string LongestPalinS = "";
    // int count = 0;
    // int maxCount = 0;
    // for(int i=0; i<arr.size(); ++i){
        

    //     if(arr[i].size()>count){
    //         LongestPalinS = arr[i];
    //     }
    //     count = arr[i].size();
    // }

    // cout << LongestPalinS ;

     int len=s.size();

     int start=0;//回文串起始位置
     int max=1;//回文串最大长度
     vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                cout << "condition meet --> "<< 
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }

        cout << s.substr(start,max)<< "\n";




    return 0;
}