### 代码说明

ρ攻击的目的和生日攻击类似，也是寻求一个基于sm3哈希值的弱碰撞，但是寻找的方式是通过ρ递推表达式来依次尝试。
这里我使用了类似查表攻击似的数据结构，一边存表一边查表（可以使用多线程进一步优化脚本性能），以便可以在较短时间内找到一个前16bit的hash弱碰撞。
如果寻找更长bit的碰撞，寻找时间也会相应变长。
实验结果可见，寻找16bit碰撞中生日攻击所需要的时间少于ρ攻击，但是如果加长碰撞的bit长度，ρ攻击会比生日攻击展现出更好的效率。

### 运行指导

将源码clone到本地运行main函数即可运行ρ攻击脚本。

软件环境：Visual Studio 2019

硬件环境：PC机

### 运行结果
![sm3_openssl运行结果.png](https://github.com/Mitchell45/repo-course/blob/main/images%20of%20outcome/rho_attack%E8%BF%90%E8%A1%8C%E7%BB%93%E6%9E%9C.png)

### 贡献说明

本项目由于海涛同学（[Mitchell45 (github.com)](https://github.com/Mitchell45)）负责。
