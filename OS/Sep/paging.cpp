#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;

#define ERROR_CODE -1

class Process{
    int pid;
    int size;
    int pageReq;
    int *pageTab;
    static int pidCounter;
    void allocatePTab()
    {
        bool boolArray[pageReq]= {false};
        srand(time(NULL));
        for (int i = 0; i < pageReq; i++)
        {
            int frame = rand() % pageReq;
            if(boolArray[frame])
                do{
                    frame = rand() % pageReq;
                }while(boolArray[frame]);

                pageTab[i] = frame;
                boolArray[frame] = true;
        }
    }

    void setPageReq(const int &f_size)
    {
        if (size % f_size == 0)
            this->pageReq = size / f_size;
        else
            this->pageReq = (size / f_size) + 1;
        pageTab = new int[pageReq];
        allocatePTab();
    }

  public:
    int getPid(){
        return pid;
    }
    
    int getFrame(const int &page_num){
        if(page_num > pageReq){
            cout<<"\nError:No such Page";
            exit(ERROR_CODE);
        }
        return pageTab[page_num];
    }

    void displayPageTab(){
        for(int i = 0; i < pageReq; i++)
        {
            cout<<i<<"-->"<<pageTab[i];
            cout<<"\n";
        }
    }

    static Process allocate(const int &pid,const int &process_size ,const int &frame_size){
        Process p;
        p.pid = pid;
        p.size = process_size;
        p.setPageReq(frame_size);
        return p;
    }
};

int Process::pidCounter = 620;

main(int argc, char const *argv[])
{
    Process p1 = Process::allocate(654,4096,1024);
    Process p2 = Process::allocate(98,3024,1024);
    cout<<"\nProcess created with pid :"<<p2.getPid()<<"\n";
    p2.displayPageTab();
    return 0;
}
