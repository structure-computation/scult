#ifndef _SCTIME_H_
#define _SCTIME_H_


#ifdef _WIN32
#include <Winsock2.h>
struct TicTac {
    TicTac(){}
    void init() {res=0.0;}
    void start() { dwStart = GetTickCount();actif=1; }
    double stop() {
        dwStop = GetTickCount();
        if (actif != 0) res += (dwStop-dwStart)/1e3;
        printf("%f",res);
        actif=0;res=0.0;
        return 0;
    }
    void pause() {
        dwStop = GetTickCount();
        res += (dwStop-dwStart)/1e3;
        actif=0;
    }
    void print() {
        printf("%f",res);
    }
    struct timeval start1, stop1;
    DWORD dwStart,dwStop ;
    double res;
    int actif;
};
#else
#include <sched.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <stdio.h>

struct TicTac {
    TicTac(){}
    void start() { gettimeofday( &start1,&toto);actif=1; }
    void stop() {
        gettimeofday( &stop1,&toto);
        if (actif == 1) res += ((double)stop1.tv_sec-(double)start1.tv_sec)+((double)stop1.tv_usec-(double)start1.tv_usec) / 1e6;
        actif=0;
        printf("%f",res);
        res=0.0;
    }
    void pause() {         
        gettimeofday( &stop1,&toto);
        res += ((double)stop1.tv_sec-(double)start1.tv_sec)+((double)stop1.tv_usec-(double)start1.tv_usec) / 1e6;
        actif=0;
    }
    void print() {
        printf("%f",res);
    }
    void init() {res=0.0;}
    
    struct timeval start1, stop1;
    struct timezone toto;
    double res;    
    int actif;
};
#endif

#endif //_SCTIME_H_