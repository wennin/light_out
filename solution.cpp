#include"solution.h"

//������٣���λ���������
//int Serach::minFlips(vector<vector<int>>& mat){
//    int n = mat.size(); // �ƾ�������
//    int m = mat[0].size(); // �ƾ�������
//    result.resize(n);
//    for (int i = 0; i < n; i++)
//    {
//        result[i].resize(m);
//    }
//    int start = 0; // �洢��ʼ�Ƶ�״̬
//    int plan = 0; // ��ǰӦ�õĵ�Ʒ���
//    int min_press = -1; // �洢���ٵĲ������� �����ɽ��򷵻�-1
//
//    for (int i = 0; i < n * m; i++) // ��ʼ״̬����
//    {
//        start = start << 1;
//        start += mat[i / m][i % m];
//    }
//
//    while (plan < pow(2, n * m)) // �������е�Ʒ��� �� 2^(mn) ��
//    {
//        int now_press = 0; // �洢��ǰ��Ʒ�����������
//        int num = plan;
//        while (num)//�ҵ����ڵĲ������Ƕ���
//        {
//            ++now_press;
//            num &= (num - 1);
//        }
//        // ����÷�����������������֮ǰ��Ĳ������� ֱ�������÷���
//        if (min_press != -1 && min_press <= now_press)
//        {
//            plan += 1;
//            continue;
//        }
//
//        int temp = start ^ plan; // ��temp��ʼ��Ϊ��ʼ״̬�·�ת�÷���ѡ���������Щ�ƺ�Ľ��
//        for (int i = 0; i < n * m; i++) // ����plan
//        {
//            if (plan & (1 << n * m - i - 1)) // ��תѡ���������Щ���������ҵĵ�
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
//        if (temp == 0) // ��tempΪ0ʱ ����ȫ�� ��һ����
//        {
//            min_press = now_press;
//            min_result = plan;
//        }
//        plan += 1; // ������һ����Ʒ���
//    }
//    return min_press;
//}
////�Ѷ�����ת��Ϊ������
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
//            temp.push_back(((min_result >> i) & 1));//��1��λ������ǰ��λ����Ϊ0
//            //cout << ((min_result >> i) & 1);//���������
//            i--;
//        }
//        result[k++] = temp;
//        temp.clear();
//    }
//}

//�������
//vector<vector<int>>start;//��ʼ״̬
//vector<vector<int>>result;//�洢���
//vector<int>now_press;//�洢��ʱ���
//vector<vector<int>>a;//�ڽӾ���
//int n;//n*n�ľ���
//vector<vector<int>>end_result;//���հ�ѹ�Ľ��

//void first_line::first_search(int level)
//{
//    if (level == n)//��һ�еĵ�ȫ�������
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
//        //�ж����һ�е�״̬
//        for (int j = 0; j < n; j++)
//        {
//            if (!start[n - 1][j])
//            {
//                end_result.clear();
//                start.clear();//���Ԫ�أ������տռ䣬size==0
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

//���������
//��ʼ���ڽӾ���
void equation::initA(vector<vector<int>>& A, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        A[i][i] = 1;
        A[i][n*n] = 1;//����������

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

void equation::presson(int a,int b)//�õ�a������Ԫ��b��
{
    for (int i = 0; i <= n*n; i++)//ĳһ����Ԫ
    {
        A[b][i] = A[b][i] ^ A[a][i];
    }
}

void equation::solution()
{
    int m = n * n;
    for (int i = 0; i < m; i++)//i�����������
    {
        for (int j = m-1; j > i; j--)
        {
            if (A[j][i] == 1)//�����һ�п�ʼ������Ԫ
            {
                int k = i;//�ڶ�����Ԫ��ʱ�򣬵�һ�оͲ�����������
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
    //���
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