#include <unordered_map>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;


double round_robin(vector<int> arrival, vector<int> excution, int q_time)
{
    int cur_time = 0;
    vector<int> start_time(arrival.size(), 0); //不是任务开始的时间，是任务开始等待的时间
    start_time = arrival;
    int cur_task = -1;
    int next_task = 0;
    int wait_time = 0;
    int start_ex_time = 0;
    
    queue<int> q;
    
    while(!q.empty() || next_task < arrival.size())
    {
        

        for(int i = next_task; i < arrival.size(); i++)
        {
            if(arrival[i] == cur_time)
            {
                q.push(i);
                //wait_time[i] = cur_time;
            }
        }
        
        if(q.empty() && cur_task == -1) //当前空闲,且队列为空，什么都不用做
        {
            cur_time++;
            continue;
        }
        else if(cur_task == -1 && !q.empty()){//这就是一开始的情况，队列不为空
            cur_task = q.front(); //安排一个任务开始执行
            q.pop();
            start_ex_time = cur_time;
            wait_time += cur_time - start_time[cur_task];
            excution[cur_task]--;
            if(q.empty())
            {
                next_task++;
            }
            else
                next_task = q.front();
        }
        else{
            if(cur_time - start_ex_time >= q_time && excution[cur_task] > 0) {//应该切换任务了,当前任务未结束
                if(q.empty()) //队空就继续做这个任务
                {
                    start_ex_time = cur_time;
                    excution[cur_task]--;
                    cur_time++;
                    continue;
                }
                //如果队不空说明要强制切换任务了
                q.push(cur_task);
                start_time[cur_task] = cur_time;//被挤下去的任务又开始等待了
                
                start_ex_time = cur_time;
                cur_task = next_task;
                wait_time += cur_time - start_time[cur_task];
                q.pop();
                next_task = q.front();	//队一定不为空，至少还有当前被挤下去的任务
                excution[cur_task]--;
            }
            else if(excution[cur_task] == 0) { //因为当前任务结束了所以切换任务
                if(q.empty()) //队空说明CPU进入空闲状态
                {
                    cur_task = -1;
                    cur_time++;
                    continue;
                }
                //安排队里的下一任务执行
                start_ex_time = cur_time;
                cur_task = next_task;
                excution[cur_task]--;
                wait_time += cur_time - start_time[cur_task];
                q.pop();
                if(q.empty())
                    next_task = cur_task+1;
                else
                    next_task = q.front();
            }
            else { //有任务正在执行，而且不需要切换任务
                if(excution[cur_task]>0)
                    excution[cur_task]--;
            }
        }
        cout << "excution info: ";
        for(int i = 0;i < arrival.size(); i++)
            cout << excution[i] <<", ";
        cout<<endl;
        if(!q.empty())
        {
            cout << "queue head: " << q.front()<< endl;
            cout << "queue tail: " << q.back()<< endl;
        }
        else
            cout << "queue is empty!"<<endl;
        cout << "wait time: " << wait_time<<endl;
        cout <<"***********************"<<endl;
        cur_time++;

    }
    double avg_wait_time = double(wait_time)/arrival.size();
    cout << avg_wait_time << endl;
    return avg_wait_time;
}


int main()
{
    int at[] = {2,2,6,7};
    int ex[] = {4,1,3,2};
    int len = 4;
    vector<int> a;
    vector<int> e;
    for(int i = 0; i < len; i++) {
        a.push_back(at[i]);
        e.push_back(ex[i]);
    }
    round_robin(a, e, 3);
}