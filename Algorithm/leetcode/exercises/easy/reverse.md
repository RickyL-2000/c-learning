# 整数反转

## my solution 1    (19/7/10)   60+ min

我真的尽力了....

fail x 8

    class Solution {
    public:
        int reverse(int x) {
            try {
                int sign = 1;
                if (x < 0) {
                    x = -x;
                    sign = -1;
                }
                vector<int> places;
                while (x != 0) {
                    places.push_back(x % 10);
                    x /= 10;
                }      
                for (int i = 0; i < places.size(); ++i) {
                    for (int j = i+1; j < places.size(); ++j) {
                        places[i] *= 10;
                    }
                    x += places[i];
                }
                x *= sign;
                return x;
            } catch (runtime_error err) {
                return 0;
            } catch (overflow_error err) {
                return 0;
            } catch (underflow_error err) {
                return 0;
            }
        }
    };

本来以为 try catch 应该就是这么用的了...还专门学了一遍 try catch...

然而看来并不是这样的......

说起来，除了溢出以外，我的算法也不尽人意，尤其是我还用了一个 vector 来存储每一位上的数字。后来想想其实可以不用这么麻烦，还浪费内存，直接把数字反过来加到ans里就可以了（即算每一位和压入新的数同时进行）。

关键是这个overflow的异常该怎么处理啊...... :(((((((


## reference solution 1

time: 8 ms

memory: 8.3 mb

    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) //这个7是2147483647的最后一位
                return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) //这个-8是-2147483648的最后一位
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }

想法是，既然rev*10有可能会溢出，那么不如直接考虑rev和INT_MAX/10之间的关系

然而我还是觉得这个算法有问题：如果


## reference solution 2

    int reverse(int x) {
        long temp = 0;
       
        while(x != 0){
            int pop = x % 10;
            temp = temp * 10 + pop;
            
            if(temp > Integer.MAX_VALUE || temp < Integer.MIN_VALUE){
                return 0;
            }
            x /= 10;
        }
        return (int)temp;
    }

这种解法就有点cheat的意思了，它先把temp声明为long型的整数，然后再回来检查是否溢出了int的整数范围...


## reference solution 3    反转字符串

    class Solution {
    public:
        int reverse(int x) {
            long long_x;
            string str_x=to_string(x);//将数字转换成字符串
            int pos=str_x.find_first_not_of("-");
            //找到第一个与‘-’不匹配的字符位置
            
            std::reverse(str_x.begin()+pos,str_x.end());
            //将除符号位的数字进行反转

            stringstream out(str_x);
            out >> long_x;//将string转换成long存储在long_x中
            if(long_x>INT_MAX || long_x<INT_MIN)
                return 0;
            return long_x;    
        }
    };
