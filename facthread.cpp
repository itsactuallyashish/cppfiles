#include <iostream>
#include<thread>
#include<string>
#include<mutex>
#include<fstream>
#include<chrono>
#include<condition_variable>
#include<future>
using namespace std;
std:: condition_variable cond;
std:: mutex mu;

int fact(shared_future<int> f){
    int res=1;
    int n=f.get();
    for(int i=n;i>1;i--){
        res*=i;
    }
    cout<< "result is" << res<<endl;
    return res;
}

int main(){
    int x;
    // thread t(fact ,4,ref(x));
    // t.join();
    // std::future<int> fu=async (fact,4);
    promise<int>p;
    future<int> f=p.get_future();
    shared_future<int> sf=f.share();// for broadcast kind of model
    std::future<int> fu=async (launch::async,fact,sf);
    std::future<int> fu2=async (launch::async,fact,sf);
    std::future<int> fu3=async (launch::async,fact,sf);
    std::future<int> fu4=async (launch::async,fact,sf);
    p.set_value(4);
    // x=fu.get();
    
    return 0;
}

