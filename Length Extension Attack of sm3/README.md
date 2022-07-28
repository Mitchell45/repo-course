### 代码说明

对sm3进行了长度扩展攻击。

sm3_Length_Extension_Attack.h中定义了可以更换初始向量iv的sm3加密模块，可以用于将原始消息的加密结果作为初始iv，以便迭代可以成功伪造签名。

main.cpp中定义了Length_Extension_Attack函数，根据原始消息和扩展消息构造出了一个hash伪造签名，并且运行代码通过了验证构造成功，具体详见代码注释。

### 运行指导

将源码clone到本地运行main.cpp即可开始进行长度扩展攻击。

软件环境：Visual Studio 2019

硬件环境：PC机

### 运行结果
![Length_Extension_Attack运行结果.png](https://github.com/Mitchell45/repo-course/blob/main/images%20of%20outcome/Length_Extension_Attack%E8%BF%90%E8%A1%8C%E7%BB%93%E6%9E%9C.png)

### 贡献说明

本项目由于海涛同学（[Mitchell45 (github.com)](https://github.com/Mitchell45)）负责。
