#include"solution.h"

//整体穷举，用位运算来求解
//int Serach::minFlips(vector<vector<int>>& mat){
//    int n = mat.size(); // 灯矩阵行数
//    int m = mat[0].size(); // 灯矩阵列数
//    result.resize(n);
//    for (int i = 0; i < n; i++)
//    {
//        result[i].resize(m);
//    }
//    int start = 0; // 存储初始灯的状态
//    int plan = 0; // 当前应用的电灯方案
//    int min_press = -1; // 存储最少的操作次数 若不可解则返回-1
//
//    for (int i = 0; i < n * m; i++) // 初始状态生成
//    {
//        start = start << 1;
//        start += mat[i / m][i % m];
//    }
//
//    while (plan < pow(2, n * m)) // 遍历所有点灯方案 共 2^(mn) 种
//    {
//        int now_press = 0; // 存储当前点灯方案操作次数
//        int num = plan;
//        while (num)//找到现在的操作数是多少
//        {
//            ++now_press;
//            num &= (num - 1);
//        }
//        // 如果该方案操作次数超过了之前解的操作次数 直接跳过该方案
//        if (min_press != -1 && min_press <= now_press)
//        {
//            plan += 1;
//            continue;
//        }
//
//        int temp = start ^ plan; // 将temp初始化为初始状态下翻转该方案选择操作的那些灯后的结果
//        for (int i = 0; i < n * m; i++) // 遍历plan
//        {
//            if (plan & (1 << n * m - i - 1)) // 翻转选择操作的那些灯上下左右的灯
//            {
//                if (i / m - 1 >= 0)
//                    temp ^= (1 << (n * m - (m * (i / m - 1) + i % m) - 1));
//                if (i / m + 1 < n)
//                    temp ^= (1 << (n * m - (m * (i / m + 1) + i % m) - 1));
//                if (i % m - 1 >= 0)
//                    temp ^= (1 << (n * m - (m * (i / m) + i % m - 1) - 1));
//                if (i % m + 1 < m)
//                    temp ^= (1 << (n * m - (m * (i / m) + i % m + 1) - 1));
//            }
//        }
//        if (temp == 0) // 当temp为0时 即灯全亮 是一个解
//        {
//            min_press = now_press;
//            min_result = plan;
//        }
//        plan += 1; // 处理下一个点灯方案
//    }
//    return min_press;
//}
////把二进制转换为结果输出
//void Serach::Transform()
//{
//    int n = result.size();
//    int m = result[0].size();
//    int k = 0;
//    vector<int>temp;
//    for (int i = n*m-1; i >= 0; )
//    {
//        for (int j = 0; j < m; j++)
//        {
//            temp.push_back(((min_result >> i) & 1));//与1做位操作，前面位数均为0
//            //cout << ((min_result >> i) & 1);//输出二进制
//            i--;
//        }
//        result[k++] = temp;
//        temp.clear();
//    }
//}

//首行穷举
//vector<vector<int>>start;//初始状态
//vector<vector<int>>result;//存储结果
//vector<int>now_press;//存储临时结果
//vector<vector<int>>a;//邻接矩阵
//int n;//n*n的矩阵
//vector<vector<int>>end_result;//最终按压的结果

//void first_line::first_search(int level)
//{
//    if (level == n)//第一行的点全部穷举完
//    {
//        result.push_back(now_press);
//        return;
//    }
//    now_press[level] = 1;
//    first_search(level + 1);
//    now_press[level] = 0;
//    first_search(level + 1);
//}
//vector<int> first_line::presson1(vector<int>v)
//{
//    vector<int>temp(n);
//    temp[0] = v[1] ^ v[0];
//    temp[n - 1] = v[n - 1] ^ v[n - 2];
//    for (int i = 1; i < n-1; i++)
//    {
//        temp[i] = v[i - 1] ^ v[i] ^ v[i + 1];
//    }
//    return temp;
//}
//
//vector<vector<int>> first_line::presson2()
//{
//    for (int i = 0; i < result.size(); i++)
//    {
//        int flag = 1;
//        start[0] = presson1(result[i]);
//        end_result[0] = result[i];
//        for (int j = 1; j < n; j++)
//        {
//            for (int k = 0; k < n; k++)
//            {
//                if (!start[j - 1][k])
//                {
//                    end_result[j][k] = 1;
//                }
//            }
//            start[j][0] = end_result[j][0] ^ end_result[j][1] ^ end_result[j-1][0];
//            start[j][n - 1] = end_result[j][n - 1] ^ end_result[j-1][n - 1] ^ end_result[j][n - 2];
//            for (int k = 1; k < n - 1; k++)
//                start[j][k] = end_result[j][k] ^ end_result[j-1][k] ^ end_result[j][k - 1] ^ end_result[j][k + 1];
//        }
//        //判断最后一行的状态
//        for (int j = 0; j < n; j++)
//        {
//            if (!start[n - 1][j])
//            {
//                end_result.clear();
//                start.clear();//清空元素，不回收空间，size==0
//                start.resize(n, vector<int>(n, 1));
//                end_result.resize(n, vector<int>(n));
//                flag = 0;
//                break;
//            }
//        }
//        if(flag)
//            return end_result;
//    }
//}

//方程组求解
//初始化邻接矩阵
void equation::initA(vector<vector<int>>& A, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        A[i][i] = 1;
        A[i][n*n] = 1;//变成增广矩阵

        if (i / n + 1 < n)
        {
            A[i][n * (i / n + 1) + i % n] = 1;
            A[n * (i / n + 1) + i % n][i] = 1;
        }

        if (i % n + 1 < n)
        {
            A[i][n * (i / n) + i % n + 1] = 1;
            A[n * (i / n) + i % n + 1][i] = 1;
        }
    }
}

void equation::presson(int a,int b)//用第a行来消元第b行
{
    for (int i = 0; i <= n*n; i++)//某一行消元
    {
        A[b][i] = A[b][i] ^ A[a][i];
    }
}

void equation::solution()
{
    int m = n * n;
    for (int i = 0; i < m; i++)//i在这里代表列
    {
        for (int j = m-1; j > i; j--)
        {
            if (A[j][i] == 1)//从最后一行开始往上消元
            {
                int k = i;//第二列消元的时候，第一行就不可以再用了
                 for (; k < m; k++)
                {
                    if (k!=j&&A[k][i] == 1)
                    {
                        presson(k, j);
                        break;
                    }
                }
                if (k == m)
                {
                    vector<int>temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    break;
                }
            }
        }
    }
    //求解
    for (int i = m-1; i >=0; i--)
    {
        int sum_1 = 0;
        for (int j = 0; j < m; j++)
        {
            if (now_result[j] && A[i][j])
                sum_1++;
        }
        if (A[i][m] == 1)
         {
            if (sum_1%2 == 1)continue;
            for (int k = i; k >= 0; k--)
            {
                if (A[i][k] == 1&&!now_result[k])
                {
                    now_result[k] = 1;
                    break;
                }
            }
         }
        else
        {
            if (sum_1 % 2 == 0)continue;
            for (int k = i; k >= 0; k--)
            {
                if (A[i][k] == 1&&!now_result[k])
                {
                    now_result[k] = 1;
                    break;
                }
            }
        }
    }
}

void equation::transform() {
    for (int i = 0; i < now_result.size(); i++)
    {
        end_result[i / n][i % n] = now_result[i];
    }
}