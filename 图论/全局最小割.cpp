/*����ͼ����������s��t, ����Ҫô������С���������ͬ����, Ҫô����ͬһ����.
����Ǻ���, ��ô�ϲ�s��t�󲢲�Ӱ����С��. ������ô��˼��, ���ÿ�������ͼ��ĳ����֮�����С��, Ȼ����´𰸺�ϲ������ټ�������С��, �͵õ����մ���.
�ر�ע�⼸���ط�, ���ϵĺü���Stoer-Wagner�汾������һЩС����:

1. �㷨����"���������"ʱ���µĲ�����ͨ�����ϵ�����, ������֮�����ıߵ�Ȩֵ��, �����б߶��ǵ�λȨֵʱ�����ۼƶ�.

2. "������A�������Ϊs��t", ���϶�s�����ֽ���, һ����t֮ǰһ���ӽ�ȥ�ĵ�, ����t��ǰ���ڵ�, Ҳ�������ѡ��������ߵ���һ��. �����ǵ�һ��!
*/
const int MAXN = 501 , MAXM = 100001 ;
#define typec long long
const typec inf = 1000000000000000LL , maxw = 1000000000000LL ;
typec g[MAXN][MAXN] , dis[MAXN] ;
int used[MAXN] , v[MAXN] ;
int n , m ;
typec mincut( int n )
{
    typec res = inf ;
    for ( int i = 0 ; i < n ; ++i )
		v[i] = i;
	while ( n > 1 )
    {
        used[ v[0] ] = 1 ;
        for ( int i = 1 ; i < n ; ++i )
        {
            used[v[i]] = 0 ;
            dis[v[i]] = g[v[0]][v[i]];
        }
        int last = 0 ;
        for ( int i = 1 ; i < n ; ++i )
        {
            int maxs = -1 ;
            for ( int j = 1 ; j < n ; ++j )
                if ( used[v[j]] == 0 )
                    if ( maxs == -1 || dis[v[j]] > dis[v[maxs]] )
                        maxs = j ;
            used[v[maxs]] = 1 ;
            if ( i == n-1 )
            {
                if ( res > dis[v[maxs]] )
                    res = dis[v[maxs]] ;
                for ( int j = 0 ; j < n ; ++j )
                {
                    g[v[last]][v[j]] += g[v[maxs]][v[j]];
                    g[v[j]][v[last]] += g[v[j]][v[maxs]];
                }
                v[maxs] = v[--n] ;
                break;
            }
            last = maxs ;
            for ( int j = 1 ; j < n ; ++j )
                if ( used[v[j]] == 0 )
                    dis[v[j]] += g[ v[maxs] ][ v[j] ] ;
        }
    }
    return res ;
}

int main()
{
	while ( scanf("%d%d",&n,&m) == 2 )
	{
//		if ( n == 0  && m == 0  )
//			break;
		memset( g , 0 , sizeof g ) ;
		for ( int i = 0 ; i < m ; ++i )
		{
			int sc , sv , vv ;
			scanf("%d%d%d",&sc,&sv,&vv);
//	        --sc , --sv ;
			g[sc][sv] += vv ;
			g[sv][sc] += vv ;
		}
		cout << mincut(n) << '\n' ;
	}
	return 0;
}
