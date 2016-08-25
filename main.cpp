#include <iostream>
#include <Request.h>
#include <thread>
#include <zconf.h>
#include <future>

using namespace std;

#include <mutex>
#include <condition_variable>
#include <deque>

template <typename T>
class queue
{
private:
    std::mutex              d_mutex;
    std::condition_variable d_condition;
    std::deque<T>           d_queue;
public:
    void push(T const& value) {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            d_queue.push_front(value);
        }
        this->d_condition.notify_one();
    }
    T pop() {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
        T rc(std::move(this->d_queue.back()));
        this->d_queue.pop_back();
        return rc;
    }
};

struct queue_data
{
    string message;
};

queue<queue_data> q;

pthread_mutex_t end_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var = PTHREAD_COND_INITIALIZER;
bool quit = false;

void loop()
{
    queue_data data = q.pop();
    cout << data.message;
    /*pthread_mutex_lock( &end_mutex );
    while (!quit)
        pthread_cond_wait( &condition_var, &end_mutex );*/
}

void test()
{
    int i = 100;
    while(i > 0)
    {
        usleep(500000);

        queue_data data;
        data.message = to_string(i);
        q.push(data);
        //cout << str;
        i--;
    }
    /*pthread_mutex_lock( &end_mutex );
    quit = true;
    pthread_cond_signal(&condition_var);
    pthread_mutex_unlock(&end_mutex);*/
    cout << "after";
}

int main()
{
    cout << "test";
    /*Request *request = new Request(GET);
    std::cout << request->getMethod();*/

    thread t1(test);
    //t1.join();

    loop();
    t1.detach();
    return 0;
}