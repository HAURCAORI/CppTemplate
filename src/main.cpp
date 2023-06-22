#include <iostream>
#include <pthread.h>
#include <stdlib.h>

void *task1(void *X){
    std::cout << "A" << std::endl;
    return nullptr;
}

void *task2(void *X){
    std::cout << "B" << std::endl;
    return nullptr;
}


int main(int argc, char *argv[]) {
    pthread_t ThreadA, ThreadB;

    int N;
    if(argc != 2) {
        std::cout << "error" << std::endl;
        exit(1);
    }

    N = atoi(argv[1]);
    pthread_create(&ThreadA, NULL, task1, &N);
    pthread_create(&ThreadB, NULL, task2, &N);

    
    pthread_join(ThreadB, NULL);
    pthread_join(ThreadA, NULL);

    return 0;
}