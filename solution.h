#pragma once
#include<iostream>
#include<vector>
#include <bitset>

using namespace std;

//class Serach//�������С��������,��λ�������
//{
//public:
//    int minFlips(vector<vector<int>>& mat);
//    void Transform();
//    int min_result;
//    vector<vector<int>>result;
//};
//
//class first_line//�������
//{
//public:
//	first_line(int b) :n(b) {
//		now_press.resize(n);
//		start.resize(n,vector<int>(n));
//		end_result.resize(n, vector<int>(n));
//		first_search(0);
//		presson2();
//	}
//	void first_search(int level);//��ٵ�һ��
//	vector<int> presson1(vector<int>v);//�õ���һ�е�״̬
//	vector<vector<int>> presson2();//���ݵ�һ�е�״̬ȥ��������
//
//	vector<vector<int>>start;//��ʼ״̬,ȫ����ʼ��Ϊ1
//	vector<vector<int>>result;//�洢���(�洢������ٵĽ��)
//	vector<vector<int>>end_result;//���հ�ѹ�Ľ��
//	vector<int>now_press;//�洢��ʱ���
//	vector<vector<int>>a;//�ڽӾ���
//	int n;//n*n�ľ���
//};

class equation//���������
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
