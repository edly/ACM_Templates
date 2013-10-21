/*
  Name: KM �㷨 
  Author: ASEMBL
  Date: 01/08/12 14:24
  Description: ����ͼ���Ȩƥ�� N^3
  Note:     ���㷨ִ�й����е���һʱ�̣�������һ����(i,j),  A[i] + B[j] >= w[i,j]ʼ�ճ���
            ���㣺 ����A��ţ�����B��ţ�ʹ�ö��һ������· ��value = min{ A[i]+B[j]-w[i][j] | i��ͼ�ڣ�j����ͼ�� }
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

const int MAXN = 301;
const int inf = 1000000000 ;

int N , M ;
int g[MAXN][MAXN] , from[MAXN];
int A[MAXN] , B[MAXN] , visx[MAXN] , visy[MAXN] , visnumber , slack[MAXN] ;

int dfs( int u )
{
    if ( visx[u] == visnumber )
        return 0;
    visx[u] = visnumber ;
    
    for ( int v = 0 ; v < N ; ++v )
        if ( A[u] + B[v] == g[u][v] )
        {
            visy[v] = visnumber ;
            if ( from[v] == -1 || dfs( from[v] ) )
            {
                from[v] = u ;
                return 1 ;
            }
        }
        else
            slack[v] = min( slack[v] , A[u] + B[v] - g[u][v] );
    
    return 0;
}
void KM()
{
    memset( from , -1 , sizeof from );
    for ( int i = 0 ; i < N ; ++i )
    {
        A[i] = B[i] = 0 ;
        for ( int j = 0 ; j < N ; ++j )
            A[i] = max( A[i] , g[i][j] ) ;
    }
    
    for ( int i = 0 ; i < N ; ++i )
    {
        while ( 1 )
        {
            ++visnumber ;
            for ( int j = 0 ; j < N ; ++j )
                slack[j] = inf ;
            
            if ( dfs(i) )
                break ;
            
            int less = inf ;
            for ( int j = 0 ; j < N ; ++j )
                if ( from[j] == -1 || visx[ from[j] ] != visnumber )
                    if ( slack[j] < less )
                        less = slack[j] ;
            
            for ( int j = 0 ; j < N ; ++j )
            {
                if ( visx[j] == visnumber )
                    A[j] -= less ;
                if ( from[j] != -1 && visx[ from[j] ] == visnumber )
                    B[j] += less ;
            }
        }
    }
}


int main()
{
    visnumber = 0 ;
    while ( scanf("%d",&N) == 1 )
    {
        for ( int i = 0 ; i < N ; ++i )
            for ( int j = 0 ; j < N ; ++j )
                scanf("%d",&g[i][j]);
        KM();
        int ans = 0 ;
        for ( int i = 0 ; i < N ; ++i )
            ans += A[i] + B[i] ;
        printf("%d\n",ans);
    }
    return 0;
}
