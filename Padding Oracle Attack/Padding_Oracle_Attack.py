#测量填充长度
'''b=1
for i in range(16):
    input1=cipher[:64+2*i]+'00'+cipher[66+2*i:128]
    output1=subprocess.call(['dec_oracle',input1])
    input2=cipher[:64+2*i]+'01'+cipher[66+2*i:128]
    output2=subprocess.call(['dec_oracle',input2])
    input3=cipher[:64+2*i]+'02'+cipher[66+2*i:128]
    output3=subprocess.call(['dec_oracle',input3])
    if output1==500 or output2==500 or output3==500:
        b=16-i
        break
print(b)'''
#明文空间
plain=''
#密文
cipher='e51aa00fb3277fddcbb05a6c3e8dd94fb9939fdba367e22d7313565e88352fd62e2dcc48be365f1b4902fffb6fbf01fbb5f6e8ea566e56bdb203de9b788ae71a'
#调用库
import subprocess
from itertools import permutations
from Crypto.Util.number import *
#爆破字典
all_letters="0123456789abcdef"

#破解c1
a=''#中间变量
for i in range(16):
    for j in permutations(all_letters, 2):
        j=''.join(j)
        if i>0:
            input='00'*(15-i)+j+hex(int((hex(i+1)[2:].zfill(2))*i,16)^int(a,16))[2:].zfill(2*i)+cipher[32:64]
        else:
            input='00'*15+j+cipher[32:64]
        output=subprocess.call(['dec_oracle',input])
        if output==200:
            #print("success!")
            a=hex(int(input[30-2*i:32-2*i],16)^int(hex(i+1)[2:].zfill(2),16))[2:].zfill(2)+a
            break
#print(a)
#print(hex(int(a,16)^int(cipher[:32],16))[2:])
plain+=hex(int(a,16)^int(cipher[:32],16))[2:]
#print(bytes().fromhex(hex(int(a,16)^int(cipher[:32],16))[2:]))

#破解c2
a=''#中间变量
for i in range(16):
    for j in permutations(all_letters, 2):
        j=''.join(j)
        if i>0:
            input='00'*(15-i)+j+hex(int((hex(i+1)[2:].zfill(2))*i,16)^int(a,16))[2:].zfill(2*i)+cipher[64:96]
        else:
            input='00'*15+j+cipher[64:96]
        output=subprocess.call(['dec_oracle',input])
        if output==200:
            #print("success!")
            a=hex(int(input[30-2*i:32-2*i],16)^int(hex(i+1)[2:].zfill(2),16))[2:].zfill(2)+a
            break
#print(a)
plain+=hex(int(a,16)^int(cipher[32:64],16))[2:]

#破解c3
a=''#中间变量
for i in range(16):
    for j in permutations(all_letters, 2):
        j=''.join(j)
        if i>0:
            input='00'*(15-i)+j+hex(int((hex(i+1)[2:].zfill(2))*i,16)^int(a,16))[2:].zfill(2*i)+cipher[96:128]
        else:
            input='00'*15+j+cipher[96:128]
        output=subprocess.call(['dec_oracle',input])
        if output==200:
            #print("success!")
            a=hex(int(input[30-2*i:32-2*i],16)^int(hex(i+1)[2:].zfill(2),16))[2:].zfill(2)+a
            break
#print(a)
plain+=hex(int(a,16)^int(cipher[64:96],16))[2:]

#输出flag
print(long_to_bytes(int(plain,16)))
