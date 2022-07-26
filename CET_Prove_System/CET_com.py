from md5 import *
from CET_com import *
from RSA import *

#安全的比特位数
bit_length=1024
#数据库
database={'202000460001':444,'202000460002':268,'202000460003':666,'202000460004':649,'202000460005':699,'202000460006':458,'202000460007':403,'202000460008':411,'202000460009':463,'202000460010':612,'202000460011':394,'202000460012':588}

#成绩单 类
class transcript():
    def __init__(self,id,n,e,m,c) -> None:
        #防止id公开
        self.id_hash=str_md5(id)
        self.grade=get_grade(id)
        self.n=n
        self.e=e
        self.m=m
        self.c=c

#查询数据库
def get_grade(id):
    if database.get(id,-1)!=-1:
        return database[id]
    else:
        return -1

#申请证书
def get_transcript(id):
    if get_grade(id)!=-1:
        #分发公私钥对
        n,e,d=GetKey(bit_length)
        m=RandomPrime(bit_length)
        return transcript(id,n,e,m,enCrypto(m,n,d))
    else:
        print("this student isn't exsist!")

