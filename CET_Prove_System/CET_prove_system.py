#coding:utf-8
from RSA import *
from CET_com import *

def verify(t):
    if deCrypto(t.c,t.n,t.e)==t.m:
        print("verify success!")
        if t.grade>=425:
            print("you have passed CET!")
        else:
            print("you havn't passed CET!")
    else:
        print("failed!")

def main():
    id=str(input("please input your CET test id:"))
    t=get_transcript(id)
    verify(t)

if __name__ == '__main__':
    main()
