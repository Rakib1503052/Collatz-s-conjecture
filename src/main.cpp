#include <iostream>
#include <stdio.h>
#include <future>
#include <utility>
#include <numeric>
#include <algorithm>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;
using ivec = vector<unsigned int64_t>;
using li = unsigned int64_t;

pair<li,li> collatz(li n);

int main()
{
    int nstart,nend,threads;
    li *nmax, *step;
    future<pair<li,li>> *f;
    ivec y1,y2,x;

    cout<<"Set start : ";
    cin>>nstart;
    cout<<"Set end : ";
    cin>>nend;
    cout<<"Set threads : ";
    cin>>threads;

    nmax = new li[threads];
    step = new li[threads];
    f = new future<pair<li,li>>[threads];

    y1.resize(threads);
    y2.resize(threads);
    x.resize(threads);

    plt::subplot(1,2,1);
    plt::title("Max");
    plt::xlim(nstart,nend);
    plt::subplot(1,2,2);
    plt::title("Step");
    plt::xlim(nstart,nend);

    cout<<"-------------------"<<endl;

    for(int i=nstart; i<=nend; i+=(threads*1))
    {
        for(int t = 0; t < threads; t++)
        {
            f[t] = async(launch::async, collatz, i+t);
        }
        for(int t = 0; t < threads; t++)
        {
            tie(nmax[t],step[t]) = f[t].get();
        }

        copy(nmax,nmax+threads,y1.begin());
        copy(step,step+threads,y2.begin());
        iota(x.begin(),x.end(),i);
        plt::subplot(1,2,1);
        plt::scatter(x,y1,2, {{"c","#000000"},{"marker","o"}});
        plt::subplot(1,2,2);
        plt::scatter(x,y2,2, {{"c","#000000"},{"marker","o"}});
        plt::pause(0.001);

        printf("\rComputing. Progress %5.2f %%...", (double(i-nstart)/(nend-nstart)*100));
    }
    printf("\rComputing. Progress 100 %%...");
    cout<<"\nCompleted."<<endl;
    char cname[64];
    sprintf(cname,"%d_to_%d.png",nstart,nend);
    string sname(cname);
    plt::save(sname);
    plt::show();

    delete[] nmax;
    delete[] step;
    delete[] f;

    return 1;
}

pair<li,li> collatz(li n)
{
    li nmax = n, step = 0;
    while(n > 1)
    {
        n = (n%2==0) ? n/2 : 3*n+1;
        nmax = nmax<n ? n : nmax;
        step++;
    }
    return make_pair(nmax,step);
}
