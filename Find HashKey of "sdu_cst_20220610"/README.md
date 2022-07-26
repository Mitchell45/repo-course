### 代码说明
在所有可能的姓名+学号的字符串集合下，找到一个MD5散列值为"sdu_cst_20220610"的键。
通过不断构建随机姓+随机名+固定学号前缀+随机学号后缀组成的合法键进行MD5散列求值，与目标散列值比较，相等则求解成功。
在本项目运行中可以发现，MD5散列的不可逆性大大影响了已知value求解key的效率。

### 运行指导

将源码clone到本地运行FindHashKey.py即可开始。

软件环境：Visual Studio 2019

硬件环境：PC机

### 运行结果
![Find_HashKey运行结果.png](https://github.com/Mitchell45/repo-course/blob/main/images%20of%20outcome/Find_HashKey%E8%BF%90%E8%A1%8C%E7%BB%93%E6%9E%9C.png)

### 贡献说明

本项目由于海涛同学（[Mitchell45 (github.com)](https://github.com/Mitchell45)）负责。
