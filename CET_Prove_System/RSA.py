#coding:utf-8

import random

#求最大公因子的函数
def gcd(a,b):
    if a!=0 and b!=0:
        #将负数转化为正数
        if a<0:
            a=-a
        if b<0:
            b=-b
        #从较小的数中倒序遍历出最大公因子
        if a>b:
            #倒序寻找最大公因子
            for i in range(b,0,-1):
                if a%i==0 and b%i==0:
                    return i
        elif a==b:
            return a
        else:
            #倒序寻找最大公因子
            for i in range(a,0,-1):
                if a%i==0 and b%i==0:
                    return i
    else:
        return -1
#print('gcd(144,96)=',gcd(144,96))

#求模逆的扩展欧几里得算法函数
def EXgcd(a,b,x=[1],y=[1]):
    if b==0:
        x[0]=1
        y[0]=0
        return a
    gcd=EXgcd(b,a%b,x,y)
    k=int(a/b)
    temp=x[0]
    x[0]=y[0]
    y[0]=temp-k*y[0]
    return gcd
#x=[0]
#y=[0]
#print('EXgcd(15,6)=',EXgcd(15,6,x,y))
#print('x=',x,'y=',y)

#rabin-miller素性检测算法函数
def MillerRabin(n):
    if n in {2,3,5,7,11,13}:
        return True
    elif n==1 or n%2==0 or n%3==0 or n%5==0 or n%7==0 or n%11==0 or n%13==0:
        return False
    k=0#判断向右移动位数
    d=n-1#对u分解
    while d%2==0:
        k+=1
        d/=2
    m=d
    a=random.randint(2,n-1)
    r=pow(a,int(m),int(n))#r=a**m%n
    if r==1:
        return True
    else:
        for i in range(k):
            if r==n-1:#r%n==-1
                return True
            else:
                r=pow(r,2,n)
        return False

#生成大素数算法
def RandomPrime(length):#参数为比特位长度
    n=random.randint(2**(length-1),2**length)
    while(not MillerRabin(n)):
        n=random.randint(2**(length-1),2**length)
    return n 


#生成RSA公私钥对
def GetKey(length):#参数是比特位长度
    #生成两个指定大小的素数
    p=RandomPrime(length)
    q=RandomPrime(length)
    #print('p=',p,'q=',q)
    n=p*q
    #生成公钥e
    e=RandomPrime(random.randint(10,length%20+11))
    #保证e与(p-1)*(q-1)互素，便于使用扩展欧几里得求其逆
    while gcd(e,(p-1)*(q-1))!=1 or e>=(p-1)*(q-1):
        e=RandomPrime(random.randint(10,length%20+11))
    #利用扩展欧几里得求逆，d即为私钥
    d=[0]
    d_=[0]
    temp=EXgcd((p-1)*(q-1),e,d_,d)
    #函数返回n,公钥e和私钥d构成的列表
    return n,e,d[0]


#RSA加密和解密函数
def enCrypto(plainText,n,e):
    return pow(plainText,e,n)
def deCrypto(cryptoText,n,d):
    return pow(cryptoText,d,n)
