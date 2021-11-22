#pragma once
#include<iostream>
#include<vector>
#include <bitset>

using namespace std;

//class Serach//穷举求最小操作数点,用位运算求解
//{
//public:
//    int minFlips(vector<vector<int>>& mat);
//    void Transform();
//    int min_result;
//    vector<vector<int>>result;
//};
//
//class first_line//首行穷举
//{
//public:
//	first_line(int b) :n(b) {
//		now_press.resize(n);
//		start.resize(n,vector<int>(n));
//		end_result.resize(n, vector<int>(n));
//		first_search(0);
//		presson2();
//	}
//	void first_search(int level);//穷举第一行
//	vector<int> presson1(vector<int>v);//得到第一行的状态
//	vector<vector<int>> presson2();//根据第一行的状态去点后面的行
//
//	vector<vector<int>>start;//初始状态,全部初始化为1
//	vector<vector<int>>result;//存储结果(存储的是穷举的结果)
//	vector<vector<int>>end_result;//最终按压的结果
//	vector<int>now_press;//存储临时结果
//	vector<vector<int>>a;//邻接矩阵
//	int n;//n*n的矩阵
//};

class equation//方程组求解
{
public:
	equation(int a) :n(a) {
		now_result.resize(n*n);
		A.resize(n*n, vector<int>((n*n+1)));
		initA(A, n);
		end_result.resize(n, vector<int>(n));
		solution();
		transform();
	}

	void transform();
	void solution();
	void initA(vector<vector<int>>& A, int n);
	void presson(int i, int j);

	int n;
	vector<int>now_result;
	vector<vector<int>>A;
	vector<vector<int>>end_result;
};

class first_equation
{
public:

};
